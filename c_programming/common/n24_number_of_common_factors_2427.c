#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include "utils.h"

static int32_t common_factors(int32_t a, int32_t b)
{
    int32_t ret = 0;

    int32_t i = 1;
    while (i <= UTILS_MIN(a, b)) {
        if ((a % i == 0) && (b % i) == 0) {
            ret ++;
        }
        i ++;
    }

    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;

    ret = common_factors(12, 6);
    assert(ret == 4);

    ret = common_factors(25, 30);
    assert(ret == 2);
    LOG("All tests have passed!\n");

finish:
    return 0;
}