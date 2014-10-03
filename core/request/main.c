/* -*- Mode: C; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

#include "webservice.h"

DUDA_REGISTER("Duda QA", "Unit Test");

/* Should not get here - 400 Forbidden */
void cb_test(duda_request_t *dr)
{
    long len;

    len = request->content_length(dr);
    response->http_status(dr, 200);
    response->printf(dr, "check_content_length=%d\n", len);
    response->end(dr, NULL);
}

void cb_test2(duda_request_t *dr)
{
    long len;

    len = request->content_length(dr);
    response->http_status(dr, 200);
    response->printf(dr, "check_content_length=%d\n", len);
    response->end(dr, NULL);
}

void cb_content_type_ok(duda_request_t *dr)
{
    int check;

    check = request->is_content_type(dr, "application/json");

    response->http_status(dr, 200);
    if (check == MK_TRUE) {
        response->printf(dr, "check_content_type=json");
    }
    response->end(dr, NULL);
}

void cb_content_type_fail(duda_request_t *dr)
{
    int check;

    check = request->is_content_type(dr, "application/json");

    response->http_status(dr, 200);
    if (check == MK_FALSE) {
        response->printf(dr, "check_content_type=EMPTY");
    }
    response->end(dr, NULL);
}

void cb_get_data(duda_request_t *dr)
{
    char *dat;
    unsigned long len;

    dat = request->get_data(dr, &len);
    response->http_status(dr, 200);
    response->printf(dr, "check_data={'key': 'value'}\n", dat);
    response->end(dr, NULL);
}

void cb_header_cmp(duda_request_t *dr)
{
    response->http_status(dr, 200);
    if (request->header_cmp(dr, "X-Duda-QA", "TEST") == 0) {
        response->printf(dr, "check_header_cmp=OK\n");
    }
    response->end(dr, NULL);
}


int duda_main()
{
    router->map("/test/", cb_test);
    router->map("/test2/", cb_test2);
    router->map("/content_type_ok/", cb_content_type_ok);
    router->map("/content_type_fail/", cb_content_type_fail);
    router->map("/get_data/", cb_get_data);
    router->map("/header_cmp/", cb_header_cmp);

    return 0;
}
