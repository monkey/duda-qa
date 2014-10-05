/* -*- Mode: C; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

#include "webservice.h"

DUDA_REGISTER("Duda QA", "Unit Test");

int cid;
int pid;

struct bundle {
    duda_dthread_channel_t *chan;
    duda_request_t *dr;
};

void consumer(void *data)
{
    struct bundle *bdl = data;
    duda_dthread_channel_t *chan = bdl->chan;
    duda_request_t *dr = bdl->dr;

    response->http_status(dr, 200);
    response->printf(dr, "check_status_consumer=%i\n", dthread->status(cid));
    response->printf(dr, "check_status_producer=%i\n", dthread->status(pid));
    response->printf(dr, "check_running=%i (cid=%i)\n", dthread->running(), cid);
    response->printf(dr,
                     "check_get_sender=%i (pid=%i)\n",
                     dthread->chan_get_sender(chan), pid);
    response->printf(dr,
                     "check_get_receiver=%i (cid=%i)\n",
                     dthread->chan_get_receiver(chan), cid);

    while (!dthread->chan_done(chan)) {
        int *n = dthread->chan_recv(chan);
        response->printf(dr, "fib=%d\n", *n);
        mem->free(n);
    }

    dthread->yield();
    response->printf(dr, "check_yield=OK\n");
    response->end(dr, NULL);
}

void producer(void *data)
{
    int i;
    int num1 = 1;
    int num2 = 1;
    duda_dthread_channel_t *chan = data;

    for (i = 0; i < 20; ++i) {
        int *n = mem->alloc(sizeof(int));
        if (i == 0) {
            *n = num1;
        } else if (i == 1) {
            *n = num2;
        } else {
            *n = num1 + num2;
            num1 = num2;
            num2 = *n;
        }
        dthread->chan_send(chan, n);
    }
    dthread->chan_end(chan);
}

void cb_test(duda_request_t *dr)
{
    duda_dthread_channel_t *chan = dthread->chan_create(0);
    struct bundle *bdl = mem->alloc(sizeof(*bdl));

    bdl->chan = chan;
    bdl->dr = dr;

    cid = dthread->create(consumer, bdl);
    pid = dthread->create(producer, chan);

    dthread->chan_set_sender(chan, pid);
    dthread->chan_set_receiver(chan, cid);
    dthread->resume(cid);

    /* second resume for CID just to remove the yield set on the consumer */
    dthread->resume(cid);


    dthread->chan_free(chan);
    mem->free(bdl);
}

int duda_main()
{
    router->map("/test/", cb_test);
    return 0;
}
