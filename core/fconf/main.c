/* -*- Mode: C; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

#include "webservice.h"

DUDA_REGISTER("Duda QA", "Unit Test");

void cb_test(duda_request_t *dr)
{
    int ret;
    size_t num;
    char *f;
    char *val;
    struct mk_list *head;
    struct mk_list *list;
    struct duda_config *cfg;
    struct duda_config_section *section;
    struct duda_string_line *line_entry;

    /* read the example file */
    cfg = fconf->read_conf("example.conf");
    if (!cfg) {
        goto error;
    }

    /* read_file() */
    f = fconf->read_file("/etc/profile");
    if (!f) {
        goto error;
    }
    response->printf(dr, f);
    gc->add(dr, f);

    /* section get foo */
    section = fconf->section_get(cfg, "SECTION_FOO");
    if (!section) {
        goto error;
    }
    val = fconf->section_key(section, "name", DUDA_CONFIG_STR);
    response->printf(dr, "section_key: name=%s\n", val);
    gc->add(dr, val);

    /* section foo, get list of values */
    list = (struct mk_list *) fconf->section_key(section, "list", DUDA_CONFIG_LIST);
    if (!list) {
        goto error;
    }

    int i=0;
    mk_list_foreach(head, list) {
        line_entry = mk_list_entry(head, struct duda_string_line, _head);
        response->printf(dr, "line:val:%i=%s\n", i, line_entry->val);
        i++;
    }

    /* section get bar: code as Numeric */
    section = fconf->section_get(cfg, "SECTION_BAR");
    if (!section) {
        goto error;
    }
    num = (size_t) fconf->section_key(section, "code", DUDA_CONFIG_NUM);
    response->printf(dr, "section_key: code=%i\n", num);
    gc->add(dr, val);

    /* section get bar: code as string */
    section = fconf->section_get(cfg, "SECTION_BAR");
    if (!section) {
        goto error;
    }
    val = fconf->section_key(section, "code", DUDA_CONFIG_STR);
    response->printf(dr, "section_key: code=%s\n", val);
    gc->add(dr, val);

    /* check booleans: on/off */
    num = (size_t) fconf->section_key(section, "bool_off", DUDA_CONFIG_BOOL);
    response->printf(dr, "section_key: bool_off=%i\n", num);

    num = (size_t) fconf->section_key(section, "bool_on", DUDA_CONFIG_BOOL);
    response->printf(dr, "section_key: bool_on=%i\n", num);

    /* free config */
    fconf->free_conf(cfg);

    /* get_path() */
    response->printf(dr, "path=%s\n", fconf->get_path());

    /* set a new path: set_path() */
    ret = fconf->set_path("/tmp");
    if (ret != 0) {
        goto error;
    }
    response->printf(dr, "new_path=%s\n", fconf->get_path());

    /* finalize... */
    response->http_status(dr, 200);
    response->end(dr, NULL);

 error:
    response->http_status(dr, 500);
    response->end(dr, NULL);
}

int duda_main()
{
    router->map("/fconf/", cb_test);
    return 0;
}
