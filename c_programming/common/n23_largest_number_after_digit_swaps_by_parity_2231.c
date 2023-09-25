#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include "utils.h"

static int32_t largest_integer(int32_t num)
{
    int32_t ret = 0;
    int32_t rom[32] = {0};

    if (num == 0) {
        goto finish;
    }

    size_t i = 0;
    while (num != 0) {
        rom[i] = num % 10;
        num /= 10;
        i ++;
    }

    for (size_t j = 0; j < i; j ++) {
        for (size_t k = j + 1; k < i; k ++) {
            if (((rom[j] & 0x1) == (rom[k] & 0x1)) &&
                (rom[k] < rom[j])) {
                utils_swap_int32(rom + k, rom + j);
                break;
            }
        }
        int32_t e = 1;
        for (size_t m = 0; m < j; m ++) {
            e *= 10;
        }
        ret += e * rom[j];
    }

finish:
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;

    ret = largest_integer(1234);
    assert(ret == 3412);

    ret = largest_integer(65875);
    assert(ret == 87655);

    LOG("All tests have passed!\n");

finish:
    return 0;
}