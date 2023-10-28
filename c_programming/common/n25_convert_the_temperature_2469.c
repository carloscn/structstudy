#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include "utils.h"

static int32_t convert_temperature(double celsius, double *out)
{
    int32_t ret = 0;

    UTILS_CHECK_PTR(out);

    *(out) = celsius + 273.15;
    *(out + 1) = celsius * 1.80 + 32.00;

finish:
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;
    double out[2] = {0.0};

    ret = convert_temperature(36.5, out);
    assert(ret == 0), assert(out[0] == 309.65000), assert(out[1] == 97.70000);

    ret = convert_temperature(122.11, out);
    assert(ret == 0), assert(out[0] == 395.26000), assert(out[1] == 251.79800);

    LOG("All tests have passed!\n");

finish:
    return 0;
}