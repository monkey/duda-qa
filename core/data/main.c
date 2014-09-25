/* -*- Mode: C; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

#include "webservice.h"

DUDA_REGISTER("Duda QA", "Unit Test");

void cb_data_test(duda_request_t *dr)
{
    char *cur_path;
    char *new_path;
    char *find;

    cur_path = (char *) data->get_path();
    find = data->locate("something");

    /* override new data path for second test on qa.htt */
    data->set_path("/tmp/");
    new_path = (char *) data->get_path();

    response->http_status(dr, 200);
    response->printf(dr, "current=%s\n", cur_path);
    response->printf(dr, "locate=%s\n", find);
    response->printf(dr, "new=%s\n", new_path);
    response->end(dr, NULL);
}

int duda_main()
{
    router->map("/data/", cb_data_test);
    return 0;
}
