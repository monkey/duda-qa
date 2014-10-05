/* -*- Mode: C; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

#include "webservice.h"

DUDA_REGISTER("Duda QA", "Unit Test");

void cb_create(duda_request_t *dr)
{
    int ret;

    ret = session->create(dr, "users", "Duda I/O", xtime->tomorrow());

    response->http_status(dr, 200);
    response->printf(dr, "session_create=%i\n", ret);
    response->end(dr, NULL);
}

void cb_destroy(duda_request_t *dr)
{
    int ret;

    ret = session->destroy(dr, "users");

    response->http_status(dr, 200);
    response->printf(dr, "session_destroy=%i\n", ret);
    response->end(dr, NULL);
}

void cb_get(duda_request_t *dr)
{
    char *sval;

    sval = session->get(dr, "users");

    response->http_status(dr, 200);
    response->printf(dr, "session_get='%s'\n", sval);
    response->end(dr, NULL);
}

void cb_isset_ok(duda_request_t *dr)
{
    int ret;

    ret = session->isset(dr, "users");

    response->http_status(dr, 200);
    response->printf(dr, "session_isset_ok=%i\n", ret);
    response->end(dr, NULL);
}

void cb_isset_fail(duda_request_t *dr)
{
    int ret;

    ret = session->isset(dr, "unknown");

    response->http_status(dr, 200);
    response->printf(dr, "session_isset_fail=%i\n", ret);
    response->end(dr, NULL);
}

int duda_main()
{
    int ret;

    ret = session->init("duda_qa");
    if (ret == -1) {
        exit(EXIT_FAILURE);
    }

    router->map("/create/", cb_create);
    router->map("/destroy/", cb_destroy);
    router->map("/get/", cb_get);
    router->map("/isset_ok/", cb_isset_ok);
    router->map("/isset_fail/", cb_isset_fail);

    return 0;
}
