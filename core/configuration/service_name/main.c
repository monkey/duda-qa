/* -*- Mode: C; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

#include "webservice.h"

DUDA_REGISTER("Duda QA", "Unit Test");

void cb_test(duda_request_t *dr)
{
    response->http_status(dr, 200);
    response->end(dr, NULL);
}

int duda_main()
{
    conf->service_name("new_name");
    router->map("/test/", cb_test);
    return 0;
}
