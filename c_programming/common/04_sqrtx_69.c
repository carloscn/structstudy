#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

static int64_t sqrtx(int64_t val)
{
    int64_t result = 0;
    double c = val, x0 = val;
    double xi = 0;

    if (val <= 0) {
        return 0;
    }

    while (1) {
        xi = 0.5 * (x0 + c/x0);
        if (utils_float_abs(x0 - xi) < 1e-7) {
            break;
        }
        x0 = xi;
    }
    result = (int64_t)x0;

    return result;
}

int main(void)
{
    int ret = 0;
    size_t i = 0;
    int64_t val = 0;
    int64_t test_value_list[] = {4, 64, 100, 99999999, 1, 0, -8};

    for (i = 0; i < ARRAY_SIZE(test_value_list); i ++) {
        val = sqrtx(test_value_list[i]);
        LOG("The input = %lld sqrt result is = %lld \n", test_value_list[i], val);
    }

    return ret;
}