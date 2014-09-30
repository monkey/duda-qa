/* -*- Mode: C; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

#include "webservice.h"

DUDA_REGISTER("Duda QA", "Unit Test");

void cb_empty(duda_request_t *dr)
{
    int ret;

    ret = qs->count(dr);

    response->http_status(dr, 200);
    response->printf(dr, "count=%i\n", ret);
    response->end(dr, NULL);
}

void cb_param(duda_request_t *dr)
{
    int c;
    int cmp1;
    int cmp2;
    char *buf1;
    char *buf2;
    char *buf3;
    char *buf4;
    char *buf5;

    c = qs->count(dr);
    cmp1 = qs->cmp(dr, "b", "2");
    cmp2 = qs->cmp(dr, "c", "EEE");
    buf1 = qs->get(dr, "c");
    buf2 = qs->get(dr, "C");
    buf3 = qs->get_id(dr, 0);
    buf4 = qs->get_id(dr, 20);
    buf5 = qs->get_id(dr, -1);

    response->http_status(dr, 200);
    response->printf(dr, "count=%i\n", c);
    response->printf(dr, "cmp_1=%i\n", cmp1);
    response->printf(dr, "cmp_2=%i\n", cmp2);
    response->printf(dr, "buf1=%s\n", buf1);
    response->printf(dr, "buf2=%s\n", buf2);
    response->printf(dr, "buf3=%s\n", buf3);
    response->printf(dr, "buf4=%s\n", buf4);
    response->printf(dr, "buf5=%s\n", buf5);
    response->end(dr, NULL);
}

int duda_main()
{
    router->map("/empty/", cb_empty);
    router->map("/param/", cb_param);
    return 0;
}
