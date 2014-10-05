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

int duda_main()
{

    router->map("/flush/", cb_flush);
    router->map("/http_content_length/", cb_http_content_length);
    router->map("/http_content_type/", cb_http_content_type);
    router->map("/http_header_n/", cb_http_header_n);
    router->map("/print/", cb_print);

    return 0;
}
