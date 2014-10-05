/* -*- Mode: C; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

#include "webservice.h"

DUDA_REGISTER("Duda QA", "Unit Test");

int check_worker;
int check_pre_loop;

void cb_pre_loop(void *data)
{
    (void) data;
    check_pre_loop = 1;
}

void *cb_spawn_worker(void *data)
{
    (void) data;
    check_worker = 1;
    return NULL;
}

void cb_test(duda_request_t *dr)
{
    response->http_status(dr, 200);
    response->printf(dr, "check_worker=%i\n", check_worker);
    response->printf(dr, "check_pre_loop=%i\n", check_pre_loop);
    response->end(dr, NULL);
}

int duda_main()
{
    check_worker = -1;
    check_pre_loop = -1;

    worker->pre_loop(cb_pre_loop, NULL);
    worker->spawn(cb_spawn_worker, NULL);

    router->map("/test/", cb_test);
    return 0;
}
