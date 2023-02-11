#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "utils.h"

static bool has_alternating_bits(int32_t n)
{
    bool ret = false;
    bool current_bit_status = false, last_bit_status = false;

    last_bit_status = n & 0x1;
    while (n) {
        n >>= 1;
        current_bit_status = n & 0x1;
        if (current_bit_status == last_bit_status) {
            return false;
        }
        last_bit_status = current_bit_status;
    }

    return true;
}

int32_t main(void)
{
    int32_t ret = 0;
    bool res = false;

    res = has_alternating_bits(0x55);
    LOG("the result is %d\n", res);

    UTILS_CHECK_RET(ret);

finish:
    return ret;
}