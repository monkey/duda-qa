/* -*- Mode: C; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

#include "webservice.h"

DUDA_REGISTER("Duda QA", "Unit Test");

int status_loop_create = -1;
int status_timeout = -1;
int status_channel_create = -1;
int status_channel_rw = -1;
int status_add = -1;
int status_delete = -1;
int status_check_timeout = -1;
int status_check_ch_w = -1;
int status_check_ch_r = -1;
char *status_backend = NULL;

void *cb_worker(void *data)
{
    int i;
    int n;
    int pfd[2];
    int ret;
    int fd_timeout;
    int fd_ch_r = -1;
    int fd_ch_w = -1;
    mk_event_loop_t *evl;

    /* create the event loop */
    evl = event->loop_create(64);
    if (evl) {
        status_loop_create = 0;
    }

    fd_timeout = event->loop_timeout_create(evl, 2);
    if (fd_timeout > 0) {
        status_timeout = 0;
    }

    ret = event->loop_channel_create(evl, &fd_ch_r, &fd_ch_w);
    if (ret == 0) {
        status_channel_create = 0;
    }
    if (fd_ch_r > 0 && fd_ch_w > 0) {
        status_channel_rw = 0;
    }

    pipe(pfd);
    ret = event->loop_add(evl, pfd[0], DUDA_EVENT_READ, NULL);
    if (ret == 0) {
        status_add = 0;
    }

    ret = event->loop_delete(evl, pfd[0]);
    if (ret == 0) {
        status_delete = 0;
    }

    status_backend = event->loop_backend();

    while (1) {
        n = event->loop_wait(evl);
        for (i = 0; i < n; i ++) {
            int fd = evl->events[i].fd;
            uint64_t val;

            if (fd == fd_timeout) {
                ret = read(fd_timeout, &val, sizeof(val));
                if (ret > 0) {
                    status_check_timeout = 0;
                }

                val = 0xdeadbeef;
                ret = write(fd_ch_w, &val, sizeof(val));
                if (ret > 0) {
                    status_check_ch_w = 0;
                }
            }
            else if (fd == fd_ch_r) {
                ret = read(fd_ch_r, &val, sizeof(val));
                if (ret > 0 && val == 0xdeadbeef) {
                    status_check_ch_r = 0;
                }
            }
        }
    }

    return NULL;
}

void cb_test(duda_request_t *dr)
{
    /* silly delay to let the worker timeout do its job */
    sleep(3);

    response->http_status(dr, 200);
    response->printf(dr, "status_loop_create=%i\n", status_loop_create);
    response->printf(dr, "status_timeout=%i\n", status_timeout);
    response->printf(dr, "status_channel_create=%i\n", status_channel_create);
    response->printf(dr, "status_channel_rw=%i\n", status_channel_rw);
    response->printf(dr, "status_add=%i\n", status_add);
    response->printf(dr, "status_delete=%i\n", status_delete);
    response->printf(dr, "status_check_timeout=%i\n", status_check_timeout);
    response->printf(dr, "status_check_ch_w=%i\n", status_check_ch_w);
    response->printf(dr, "status_check_ch_r=%i\n", status_check_ch_r);
    response->printf(dr, "status_backend=%s\n", status_backend);

    response->end(dr, NULL);
}

int duda_main()
{
    worker->spawn(cb_worker, NULL);
    router->map("/test", cb_test);
    return 0;
}
