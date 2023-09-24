#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include "utils.h"

static int32_t min_bit_flips(int32_t start, int32_t goal)
{
    int32_t ret = 0;

    for (size_t i = 0; i < sizeof(int32_t) * 8; i ++) {
        ret += ((start >> i) & 0x1) != \
               ((goal >> i) & 0x1);
    }

finish:
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;

    ret = min_bit_flips(10, 7);
    assert(ret == 3);

    ret = min_bit_flips(3, 4);
    assert(ret == 3);

    LOG("All tests have passed!\n");

finish:
    return 0;
}