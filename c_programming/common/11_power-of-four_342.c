#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "utils.h"

static bool is_pow_4(int64_t e)
{
    if ((e < 4) || (e & (e - 1)))
        return false;

    return (e % 3 == 1);
}

int main(void)
{
    int ret = 0;
    int64_t val = 0;
    bool res = 0;

    res = is_pow_4(2*2*4*4*4 + 1);
    LOG("the result is %d\n", res);

    res = is_pow_4(4*8*4*16*32);
    LOG("the result is %d\n", res);
finish:
    return ret;
}