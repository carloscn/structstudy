#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include "utils.h"

int32_t count_even(int32_t num)
{
    int32_t ret = 0;

    if (0 == num) {
        return ret;
    }

    for (int32_t i = 1; i <= num; i ++) {
        int32_t e = 0;
        int32_t s = 0;
        int32_t j = i;
        while (j != 0) {
            e = j % 10;
            j = j / 10;
            s += e;
        }
        if (!(s & 1)) {
            ret += 1;
        }
    }

    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;

    ret = count_even(4);
    assert(ret == 2);

    ret = count_even(30);
    assert(ret == 14);

    LOG("All tests have passed!\n");

finish:
    return 0;
}