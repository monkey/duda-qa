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

void cb_header_contains(duda_request_t *dr)
{
    response->http_status(dr, 200);
    if (request->header_contains(dr, "X-Duda-QA", " CC ") >= 0) {
        response->printf(dr, "check_header_contains=OK\n");
    }
    response->end(dr, NULL);
}

void cb_header_get(duda_request_t *dr)
{
    char *h_ok;
    char *h_fail;

    response->http_status(dr, 200);
    h_ok = request->header_get(dr, "X-Duda-QA");
    gc->add(dr, h_ok);

    /* supposedly found */
    response->printf(dr, "check_header_get_ok=%s\n", h_ok);

    /* not found */
    h_fail = request->header_get(dr, "X-FAIL");
    response->printf(dr, "check_header_get_fail=%s\n", h_fail);
    response->end(dr, NULL);
}

void cb_is_data_ok(duda_request_t *dr)
{
    response->http_status(dr, 200);
    response->printf(dr, "check_is_data=%s", request->is_data(dr) == MK_TRUE ? "YES" : "NO");
    response->end(dr, NULL);
}

void cb_is_data_fail(duda_request_t *dr)
{
    response->http_status(dr, 200);
    response->printf(dr, "check_is_data=%s", request->is_data(dr) == MK_TRUE ? "YES" : "NO");
    response->end(dr, NULL);
}

void cb_is_delete_ok(duda_request_t *dr)
{
    response->http_status(dr, 200);
    response->printf(dr, "check_is_delete=%s", request->is_delete(dr) == MK_TRUE ? "YES" : "NO");
    response->end(dr, NULL);
}

void cb_is_delete_fail(duda_request_t *dr)
{
    response->http_status(dr, 200);
    response->printf(dr, "check_is_delete=%s", request->is_delete(dr) == MK_TRUE ? "YES" : "NO");
    response->end(dr, NULL);
}

void cb_is_get_ok(duda_request_t *dr)
{
    response->http_status(dr, 200);
    response->printf(dr, "check_is_get=%s", request->is_get(dr) == MK_TRUE ? "YES" : "NO");
    response->end(dr, NULL);
}

void cb_is_get_fail(duda_request_t *dr)
{
    response->http_status(dr, 200);
    response->printf(dr, "check_is_get=%s", request->is_get(dr) == MK_TRUE ? "YES" : "NO");
    response->end(dr, NULL);
}

void cb_is_head_ok(duda_request_t *dr)
{
    response->http_status(dr, 200);
    response->printf(dr, "check_is_head=%s", request->is_head(dr) == MK_TRUE ? "YES" : "NO");
    response->end(dr, NULL);
}

void cb_is_head_fail(duda_request_t *dr)
{
    response->http_status(dr, 200);
    response->printf(dr, "check_is_head=%s", request->is_head(dr) == MK_TRUE ? "YES" : "NO");
    response->end(dr, NULL);
}

void cb_is_post_ok(duda_request_t *dr)
{
    response->http_status(dr, 200);
    response->printf(dr, "check_is_post=%s", request->is_post(dr) == MK_TRUE ? "YES" : "NO");
    response->end(dr, NULL);
}

void cb_is_post_fail(duda_request_t *dr)
{
    response->http_status(dr, 200);
    response->printf(dr, "check_is_post=%s", request->is_post(dr) == MK_TRUE ? "YES" : "NO");
    response->end(dr, NULL);
}

void cb_is_put_ok(duda_request_t *dr)
{
    response->http_status(dr, 200);
    response->printf(dr, "check_is_put=%s", request->is_put(dr) == MK_TRUE ? "YES" : "NO");
    response->end(dr, NULL);
}

void cb_is_put_fail(duda_request_t *dr)
{
    response->http_status(dr, 200);
    response->printf(dr, "check_is_put=%s", request->is_put(dr) == MK_TRUE ? "YES" : "NO");
    response->end(dr, NULL);
}

void cb_val_request_ok(duda_request_t *dr)
{
    response->http_status(dr, 200);
    response->printf(dr, "check_validate_request=%s",
                     request->validate_request(dr) == MK_TRUE ? "YES" : "NO");
    response->end(dr, NULL);
}

void cb_val_socket_ok(duda_request_t *dr)
{
    response->http_status(dr, 200);
    response->printf(dr, "check_validate_socket=%s",
                     request->validate_socket(dr->socket) == MK_TRUE ? "YES" : "NO");
    response->end(dr, NULL);
}

void cb_val_socket_fail(duda_request_t *dr)
{
    response->http_status(dr, 200);
    response->printf(dr, "check_validate_socket=%s",
                     request->validate_socket(1) == MK_TRUE ? "YES" : "NO");
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
    router->map("/header_contains/", cb_header_contains);
    router->map("/header_get/", cb_header_get);
    router->map("/is_data_ok/", cb_is_data_ok);
    router->map("/is_data_fail/", cb_is_data_fail);
    router->map("/is_delete_ok/", cb_is_delete_ok);
    router->map("/is_delete_fail/", cb_is_delete_fail);
    router->map("/is_get_ok/", cb_is_get_ok);
    router->map("/is_get_fail/", cb_is_get_fail);
    router->map("/is_head_ok/", cb_is_head_ok);
    router->map("/is_head_fail/", cb_is_head_fail);
    router->map("/is_post_ok/", cb_is_post_ok);
    router->map("/is_post_fail/", cb_is_post_fail);
    router->map("/is_put_ok/", cb_is_put_ok);
    router->map("/is_put_fail/", cb_is_put_fail);
    router->map("/validate_request_ok/", cb_val_request_ok);
    router->map("/validate_socket_ok/", cb_val_socket_ok);
    router->map("/validate_socket_fail/", cb_val_socket_fail);

    return 0;
}
