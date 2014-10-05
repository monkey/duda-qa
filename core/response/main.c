/* -*- Mode: C; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

#include "webservice.h"

DUDA_REGISTER("Duda QA", "Unit Test");

void cb_flush(duda_request_t *dr)
{
    response->http_status(dr, 200);
    //response->printf(dr, "cb_flush\n");
    //response->send_headers(dr);
    response->flush(dr);
    //response->end(dr, NULL);
}

void cb_http_content_length(duda_request_t *dr)
{
    response->http_status(dr, 200);
    response->http_content_length(dr, 0);
    response->print(dr, "ab", 2);
    response->end(dr, NULL);
}

void cb_http_content_type(duda_request_t *dr)
{
    response->http_status(dr, 200);
    response->http_content_type(dr, "jpg");
    response->end(dr, NULL);
}

void cb_http_header_n(duda_request_t *dr)
{
    response->http_status(dr, 200);
    response->http_header_n(dr, "X-Duda: OK", 10);
    response->end(dr, NULL);
}

void cb_print(duda_request_t *dr)
{
    response->http_status(dr, 200);
    response->print(dr, "PRINT OK", 8);
    response->end(dr, NULL);
}

void cb_headers_off(duda_request_t *dr)
{
    response->headers_off(dr);
    response->printf(dr, "HTTP/5.0 200 OK\r\n");
    response->printf(dr, "Content-Length: 3\r\n\r\n");
    response->printf(dr, "OK\n");
    response->end(dr, NULL);
}

void cb_send_headers(duda_request_t *dr)
{
    int ret;

    response->http_status(dr, 200);
    //response->send_headers(dr);
    //response->http_header(dr, "Content-Length: 19");
    //response->printf(dr, "check_send_headers=%i\n", ret);
    response->end(dr, NULL);
}

void cb_send_file(duda_request_t *dr)
{
    response->http_status(dr, 200);
    response->sendfile(dr, "/etc/lsb-release");
    response->end(dr, NULL);
}

void cb_send_file_range(duda_request_t *dr)
{
    response->http_status(dr, 200);
    response->sendfile_range(dr, "/etc/lsb-release", 1, 2);
    response->printf(dr, "<<<");
    response->end(dr, NULL);
}

int duda_main()
{
    router->map("/flush/", cb_flush);
    router->map("/http_content_length/", cb_http_content_length);
    router->map("/http_content_type/", cb_http_content_type);
    router->map("/http_header_n/", cb_http_header_n);
    router->map("/print/", cb_print);
    router->map("/headers_off/", cb_headers_off);
    router->map("/send_headers/", cb_send_headers);
    router->map("/send_file/", cb_send_file);
    router->map("/send_file_range/", cb_send_file_range);

    return 0;
}
