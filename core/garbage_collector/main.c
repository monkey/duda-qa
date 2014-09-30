/* -*- Mode: C; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

#include "webservice.h"

DUDA_REGISTER("Duda QA", "Unit Test");

void cb_step(duda_request_t *dr)
{
    int ret;
    char *buf;

    buf = mem->alloc_z(1024);
    ret = gc->add(dr, buf);
    response->http_status(dr, 200);
    response->printf(dr, "gc_add=%i\n", ret);
    response->end(dr, NULL);
}

int duda_main()
{
    router->map("/step/", cb_step);
    return 0;
}
