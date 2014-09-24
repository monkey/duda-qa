/* -*- Mode: C; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

#include "webservice.h"

DUDA_REGISTER("Duda QA", "Unit Test");

void cb_cookie_get(duda_request_t *dr)
{
    int len = 20;
    int ret;
    char *val = mem->alloc(len);

    ret = cookie->get(dr, "unit", &val, &len);
    if (ret != 0) {
        response->http_status(dr, 500);
        response->end(dr, NULL);
    }

    response->http_status(dr, 200);
    response->printf(dr, "get=%i\n", ret);
    response->printf(dr, "len=%i\n", len);
    response->printf(dr, "value=%s\n", val);
    response->end(dr, NULL);
}

void cb_cookie_destroy(duda_request_t *dr)
{
    cookie->destroy(dr, "unit", 4);
    response->http_status(dr, 200);
    response->end(dr, NULL);
}

void cb_cookie_set_expire(duda_request_t *dr)
{
    cookie->set(dr, "unit", 4, "test", 4, time(NULL) + 20);

    response->http_status(dr, 200);
    response->end(dr, NULL);
}

void cb_cookie_set_no_expire(duda_request_t *dr)
{
    cookie->set(dr, "unit", 4, "test", 4, 0);

    response->http_status(dr, 200);
    response->end(dr, NULL);
}

void cb_cookie_cmp(duda_request_t *dr)
{
    int ret;

    ret = cookie->cmp(dr, "unit", "test");
    if (ret == 0) {
        response->http_status(dr, 200);
    }
    else {
        response->http_status(dr, 500);
    }

    response->end(dr, NULL);
}

int duda_main()
{
    /* get() */
    router->map("/get/", cb_cookie_get);

    /* destroy() */
    router->map("/destroy/", cb_cookie_destroy);

    /* set() (expire & w/ expire) */
    router->map("/set_expire/", cb_cookie_set_expire);
    router->map("/set_no_expire/", cb_cookie_set_no_expire);

    /* cmp() OK & Fail */
    router->map("/cmp/", cb_cookie_cmp);

    return 0;
}
