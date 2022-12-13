#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "utils.h"

static int32_t is_square(int64_t e)
{
    size_t count = 0;
    size_t len = sizeof(int64_t) * 8;

    while (-- len) {
        count += (e >> len) & 0x1U;
        if (count > 1) {
            return false;
        }
    }

    return true;
}


int main(void)
{
    int ret = 0;
    int64_t val = 0;
    bool res = 0;

    res = is_square(1024);
    LOG("the result is %d\n", res);

    res = is_square(4564564564654657);
    LOG("the result is %d\n", res);
finish:
    return ret;
}