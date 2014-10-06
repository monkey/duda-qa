/* -*- Mode: C; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

#include "webservice.h"

DUDA_REGISTER("Duda QA", "Unit Test");

void cb_test(duda_request_t *dr)
{
    int ret;
    long id;
    char *name;

    name = param->get(dr, "name");
    ret  = param->get_number(dr, "id", &id);

    response->http_status(dr, 200);
    response->printf(dr, "name ='%s'\n", name);
    response->printf(dr, "id=%lu ret=%i\n", id, ret);

    response->end(dr, NULL);
}

int duda_main()
{
    router->map("/test/aa/:name/bb/:id/xx/", cb_test);
    return 0;
}
