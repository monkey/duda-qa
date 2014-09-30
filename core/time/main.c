/* -*- Mode: C; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

#include "webservice.h"

DUDA_REGISTER("Duda QA", "Unit Test");

void cb_test(duda_request_t *dr)
{
    time_t now;
    time_t next;
    time_t tomorrow;
    time_t sec_hour = 3600; 
    time_t sec_day  = 86400;


    now = xtime->now();
    next = xtime->next_hours(2);
    tomorrow = xtime->tomorrow();

    response->printf(dr, "now=%lu\n", now);

    if (next != (now + (sec_hour * 2))) {
        response->printf(dr, "error: next_hours\n");
    }
    else {
        response->printf(dr, "next_hours OK (%lu)\n", next);
    }

    if (tomorrow != (now + sec_day)) {
        response->printf(dr, "error: tomorrow\n");
    }
    else {
        response->printf(dr, "tomorrow OK (%lu)\n", tomorrow);
    }

    response->http_status(dr, 200);
    response->end(dr, NULL);
}

int duda_main()
{
    router->map("/test/", cb_test);
    return 0;
}
