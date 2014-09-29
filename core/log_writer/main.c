/* -*- Mode: C; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

#include "webservice.h"

DUDA_REGISTER("Duda QA", "Unit Test");

duda_logger_t log_test;

void cb_go(duda_request_t *dr)
{

    logger->print(&log_test, "write something\n");

    response->http_status(dr, 200);
    response->end(dr, NULL);
}

int duda_main()
{
    duda_logger_create(&log_test, "my_test");
    router->map("/go/", cb_go);
    return 0;
}
