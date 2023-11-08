#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include "utils.h"

static int32_t alternate_digit_sum(int32_t n)
{
    int32_t ret = 0;

    if (0 == n) {
        return ret;
    }

    int32_t d = n, i = 0;
    while (d != 0) {
        ret += ((((i ++) & 0x1) ? -1 : 1)) * (d % 10);
        d /= 10;
    }

finish:
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;

    ret = alternate_digit_sum(521);
    assert(ret == 4);

    ret = alternate_digit_sum(111);
    assert(ret == 1);

    ret = alternate_digit_sum(886996);
    assert(ret == 0);

    LOG("All tests have passed!\n");

finish:
    return 0;
}

// gcc -I./utils/ ./utils/utils.c ./common/n27_alternating_digit_sum_2544.c && ./a.exe