/* -*- Mode: C; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

#include "webservice.h"

DUDA_REGISTER("Duda QA", "Unit Test");

void cb_debug(duda_request_t *dr)
{
    console->debug(dr, "unit test for debug() method");
    
    response->http_status(dr, 200);
    response->end(dr, NULL);
}

int duda_main()
{
    router->map("/debug/", cb_debug);
    return 0;
}
