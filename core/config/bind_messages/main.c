/* -*- Mode: C; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

#include "webservice.h"

DUDA_REGISTER("Duda QA", "Unit Test");

void cb_write(duda_request_t *dr)
{
    fprintf(stderr, "test to stderr\n");
    fprintf(stdout, "test to stdout\n");
    fflush(stderr);
    fflush(stdout);

    msg->warn("message using API");
    response->http_status(dr, 200);
    response->end(dr, NULL);
}

int duda_main()
{
    conf->bind_messages();

    router->map("/write/", cb_write);
    return 0;
}
