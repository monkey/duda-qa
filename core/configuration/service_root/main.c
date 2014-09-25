/* -*- Mode: C; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

#include "webservice.h"

DUDA_REGISTER("Duda QA", "Unit Test");

void cb_root(duda_request_t *dr)
{
    /* lets add a custom response HTTP header to validate the service */
    response->http_status(dr, 200);
    response->http_header(dr, "X-Duda-QA: OK");
    response->end(dr, NULL);
}

int duda_main()
{
    conf->service_root();
    router->root(cb_root);

    return 0;
}
