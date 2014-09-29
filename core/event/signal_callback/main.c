/* -*- Mode: C; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

#include "webservice.h"

DUDA_REGISTER("Duda QA", "Unit Test");

uint64_t val;

void cb_worker_signal(int fd, uint64_t value)
{
    /* Once the signal is received, update a global value */
    val = value;
}

void cb_set_one(duda_request_t *dr)
{
    int ret;

    ret = event->signal(1);

    if (ret != 0) {
        response->http_status(dr, 500);
    }
    else {
        response->http_status(dr, 200);
    }
    response->end(dr, NULL);
}

void cb_val_get(duda_request_t *dr)
{
    response->http_status(dr, 200);
    response->printf(dr, "value=%i\n", val);
    response->end(dr, NULL);
}

int duda_main()
{
    val = 0;

    /* set the callback */
    duda_event_set_signal_callback(cb_worker_signal);

    /* register two callbacks to trigger signals and alter the global value */
    router->map("/set_one/", cb_set_one);
    router->map("/val_get/", cb_val_get);

    return 0;
}
