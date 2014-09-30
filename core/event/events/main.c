/* -*- Mode: C; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

#include "webservice.h"

DUDA_REGISTER("Duda QA", "Unit Test");

#include <sys/types.h>
#include <sys/socket.h>
#include <fcntl.h>
#include <netdb.h>
#include <netinet/tcp.h>
#include <errno.h>

/* create a TCP socket */
int net_socket_create()
{
    int fd;

    /* create the socket and set the nonblocking flag status */
    fd = socket(AF_INET, SOCK_STREAM, 0);
    if (fd <= 0) {
        perror("socket");
        return -1;
    }
    monkey->socket_set_tcp_nodelay(fd);
    return fd;
}

int net_connect(int fd, char *host, char *port)
{
    int ret;
    struct addrinfo *hints = NULL;
    struct addrinfo *res = NULL;

    hints = mem->alloc_z(sizeof(struct addrinfo));
    hints->ai_family   = AF_UNSPEC;
    hints->ai_socktype = SOCK_STREAM;

    ret = getaddrinfo(host, port, hints, &res);
    mem->free(hints);

    if (ret != 0) {
        errno = 0;
        msg->err("[network] get address failed: fd=%i host=%s port=%s",
                 fd, host, port);
        return -1;
    }

    ret = connect(fd, res->ai_addr, res->ai_addrlen);
    freeaddrinfo(res);

    return ret;
}

int cb_event_read(int fd, void *data)
{
    int ret;
    char buf[1024];
    duda_request_t *dr = data;

    ret = read(fd, buf, sizeof(buf) - 1);
    if (ret == -1) {
        response->printf(dr, "error: read()\n");
        goto error;
    }

    ret = event->delete(fd);
    if (ret == -1) {
        response->printf(dr, "error: event->delete()\n");
    }
    else {
        response->printf(dr, "event: delete OK\n");
    }

    response->http_status(dr, 200);
    response->printf(dr, "event: read OK\n");
    response->cont(dr);
    response->finalize(dr, NULL);

    return DUDA_EVENT_OWNED;

 error:
    response->http_status(dr, 500);
    response->cont(dr);
    response->finalize(dr, NULL);

    return DUDA_EVENT_OWNED;
}

int cb_event_write(int fd, void *data)
{
    int ret;
    duda_request_t *dr = data;
    char *buf = "HEAD /qa/head/ HTTP/1.0\r\n\r\n";

    /* log the status */
    response->printf(dr, "event: write OK\n");

    /* send a request to the new connection */
    ret = write(fd, buf, strlen(buf));
    if (ret == -1) {
        response->printf(dr, "error: write()\n");
        goto error;
    }

    /* Put the TCP connection in READ mode, we expect a response */
    ret = event->mode(fd, DUDA_EVENT_READ, DUDA_EVENT_LEVEL_TRIGGERED);
    if (ret == -1) {
        response->printf(dr, "error: event->mode(READ)\n");
        goto error;
    }
    else {
        response->printf(dr, "event: mode OK\n");
    }

    return DUDA_EVENT_OWNED;

 error:
    event->delete(fd);
    response->cont(dr);
    response->finalize(dr, NULL);

    return DUDA_EVENT_OWNED;
}

int cb_event_close(int fd, void *data)
{
    return DUDA_EVENT_CLOSE;
}

void cb_step(duda_request_t *dr)
{
    int fd;
    int ret;

    /* create a new TCP socket */
    fd = net_socket_create();
    if (fd == -1) {
        goto error;
    }

    /* Register the new socket into the Polling loop */
    ret = event->add(fd,
                     DUDA_EVENT_WRITE,
                     DUDA_EVENT_LEVEL_TRIGGERED,
                     cb_event_read,
                     cb_event_write,
                     cb_event_close,
                     cb_event_close,
                     NULL,
                     dr);
    if (ret < 0) {
        response->printf(dr, "error: event->add()\n");
        goto error;
    }

    /*
     * Perform a connection to this same server using the new
     * TCP socket. We need to test if the WRITE event is triggered.
     */
    ret = net_connect(fd, "127.0.0.1", "2001");
    if (ret == -1) {
        response->printf(dr, "error: net_connect()\n");
        goto error;
    }

    /* Put this connection to sleep */
    response->wait(dr);
    return;

 error:
    response->http_status(dr, 500);
    response->end(dr, NULL);
}

void cb_lookup(duda_request_t *dr)
{
    int fd;
    int ret;
    struct duda_event_handler *h;

    fd = net_socket_create();
    if (fd == -1) {
        response->printf(dr, "error: net_socket_create()\n");
        goto error;
    }

    ret = event->add(fd,
                     DUDA_EVENT_READ,
                     DUDA_EVENT_LEVEL_TRIGGERED,
                     NULL, NULL, NULL, NULL, NULL, NULL);
    if (ret == -1) {
        response->printf(dr, "error: event->add()\n");
        close(fd);
        goto error;
    }
    else {
        h = event->lookup(fd);
        if (h) {
            response->printf(dr, "event_handler=OK (%p)\n", h);
            event->delete(fd);
        }
        else {
            response->printf(dr, "error: event->lookup\n");
            goto error;
        }
    }

    close(fd);
    response->http_status(dr, 200);
    response->end(dr, NULL);

 error:
    response->http_status(dr, 500);
    response->end(dr, NULL);
}

void cb_head(duda_request_t *dr)
{
    response->http_status(dr, 200);
    response->end(dr, NULL);
}

int duda_main()
{
    router->map("/step/", cb_step);
    router->map("/lookup/", cb_lookup);
    router->map("/head/", cb_head);

    return 0;
}
