/* -*- Mode: C; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

#include "webservice.h"

DUDA_REGISTER("Duda QA", "Unit Test");

int duda_main()
{
    /* test to retrieve dashboard */
    console->dashboard("/dash/");
    return 0;
}
