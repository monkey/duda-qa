/* -*- Mode: C; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

#include <sys/epoll.h>
#include "webservice.h"

DUDA_REGISTER("Duda QA", "Unit Test");

uint64_t check = 0;

void *_worker(void *data)
{
    int fd;
    int ev_fd;
    int efd;
    int ret;
    int num_fds;
    struct epoll_event ev = {0, {0}};
    struct epoll_event evs[1];

    efd = epoll_create(1);

    /* FIXME: as the new Monkey Event mechanism have not been integrated
     * on Duda DST-2 yet, we will use a direct epoll(2) validation here
     */
    fd = event->create_signal_fd();
    ev.data.fd = fd;
    ev.events = EPOLLERR | EPOLLIN;
    
    ret = epoll_ctl(efd, EPOLL_CTL_ADD, fd, &ev);
    if (ret == -1) {
        perror("epoll_ctl");
        exit(EXIT_FAILURE);
    }

    while (1) {
        num_fds = epoll_wait(efd, evs, 1, -1); 
        if (num_fds > 0) {
            struct epoll_event *e = &evs[0];
            ev_fd = e->data.fd;

            if (ev_fd == fd) {
                uint64_t val;
                ret = read(ev_fd, &val, sizeof(uint64_t));
                if (ret > 0) {
                    check = val;
                }
                else {
                    check = 0;
                }
            }
        }
    }
    return NULL;
}

void cb_send(duda_request_t *dr)
{
    int ret;

    ret=event->signal(0xDEADBEEF);

    response->http_status(dr, 200);
    response->printf(dr, "ret=%i signal=%x\n", ret, check);
    response->end(dr, NULL);
}

void cb_validate(duda_request_t *dr)
{
    response->http_status(dr, 200);
    response->printf(dr, "check=%X\n", check);
    response->end(dr, NULL);
}

int duda_main()
{
    /* the goal of this test is to spawn a separate worker, make it listen
     * on a specific signal file descriptor and send it some message 
     * once a the cb_dispatch() callback is triggered. 
     *
     * Once the worker trap the message, it will modify a global variable, 
     * then through a second callback we verify if the value was modified.
     */
    router->map("/send_signal/", cb_send);
    router->map("/validate/", cb_validate);
    worker->spawn(_worker, NULL);

    return 0;
}
