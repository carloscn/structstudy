#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include "utils.h"

static int32_t difference_of_sums(int32_t n, int32_t m)
{
    int32_t ret = 0;

    if ((n == 0) && (m == 0)) {
        goto finish;
    }

    for (int32_t i = 0; i <= n; i ++) {
        if ((i % m) == 0) {
            ret -= i;
        } else {
            ret += i;
        }
    }

finish:
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;

    ret = difference_of_sums(10, 3);
    assert(ret == 19);

    ret = difference_of_sums(5, 6);
    assert(ret == 15);

    ret = difference_of_sums(5, 1);
    assert(ret == -15);

    LOG("All tests have passed!\n");

finish:
    return 0;
}

// gcc -I./utils/ ./utils/utils.c ./common/n30_divisible_and_non_divisible_sums_difference_2984.c && ./a.exe