/* -*- Mode: C; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

#include "webservice.h"

DUDA_REGISTER("Duda QA", "Unit Test");

duda_global_t gdata;

void cb_test(duda_request_t *dr)
{
    char *buf = NULL;

    buf = global->get(gdata);
    if (!buf) {
        goto error;
    }

    response->http_status(dr, 200);
    response->printf(dr, buf);

    /* before to exit, set a new value for next test */
    mem->free(buf);
    buf = mem->alloc(16);
    global->set(gdata, "set OK\n");

    buf = global->get(gdata);
    if (!buf) {
        goto error;
    }

    response->printf(dr, buf);
    response->end(dr, NULL);

 error:
    response->http_status(dr, 500);
    response->end(dr, NULL);
}

void *cb_global_init(void *data)
{
    char *buffer;
    (void) data;

    /* set a global buffer for the worker */
    buffer = mem->alloc_z(16);
    strcpy(buffer, "global buffer\n");

    return buffer;
}

int duda_main()
{
    global->init(&gdata, cb_global_init, NULL);
    router->map("/test/", cb_test);

    return 0;
}
