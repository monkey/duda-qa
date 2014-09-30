/* -*- Mode: C; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

#include "webservice.h"

DUDA_REGISTER("Duda QA", "Unit Test");

void cb_empty(duda_request_t *dr)
{
    int ret;

    ret = param->count(dr);

    response->http_status(dr, 200);
    response->printf(dr, "count=%i\n", ret);
    response->end(dr, NULL);
}

void cb_param(duda_request_t *dr)
{
    int c;
    char *b;

    c = param->count(dr);
    response->http_status(dr, 200);
    response->printf(dr, "count=%i\n", c);
    response->end(dr, NULL);
}

int duda_main()
{
    router->map("/empty/", cb_empty);
    router->map("/param/", cb_param);
    return 0;
}
