#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "utils.h"

static bool is_pow_3(int64_t e)
{
    int64_t coherence = 1;
    size_t i = 0;

    if (e < 3) {
        return false;
    }

    while (1) {
        coherence *= 3;
        if (coherence == e) {
            return true;
        } else if (coherence > e) {
            return false;
        }
    }
}

int main(void)
{
    int ret = 0;
    int64_t val = 0;
    bool res = 0;

    res = is_pow_3(3*3*3*3*9 + 1);
    LOG("the result is %d\n", res);

    res = is_pow_3(3*3*3*3*9);
    LOG("the result is %d\n", res);
finish:
    return ret;
}