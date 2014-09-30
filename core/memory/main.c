/* -*- Mode: C; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

#include "webservice.h"

DUDA_REGISTER("Duda QA", "Unit Test");

void cb_test(duda_request_t *dr)
{
    char *r;
    char *buf;

    buf = mem->alloc(1024);
    if (!buf) {
        response->printf(dr, "error: alloc()\n");
        goto error;
    }
    strcpy(buf, "abc");
    response->printf(dr, "alloc OK\n");

    /* well, it should not crash */
    mem->free(buf);
    response->printf(dr, "free OK\n");

    /* alloc_z */
    buf = mem->alloc_z(1024);
    if (!buf) {
        response->printf(dr, "error: alloc()\n");
        goto error;
    }
    if (buf[0] != '\0') {
        response->printf(dr, "error: alloc_z() first byte check\n");
        goto error;
    }
    response->printf(dr, "alloc_z OK\n");

    r = mem->realloc(buf, 8192);
    if (!r) {
        response->printf(dr, "error: realloc()\n");
        goto error;
    }
    response->printf(dr, "realloc OK\n");
    mem->free(r);

    response->http_status(dr, 200);
    response->end(dr, NULL);

 error:
    response->http_status(dr, 500);
    response->end(dr, NULL);
}

int duda_main()
{
    router->map("/test/", cb_test);

    return 0;
}
