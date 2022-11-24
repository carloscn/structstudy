#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

static int64_t add_digist(int64_t e)
{
    int64_t sum = 0;
    int64_t a = 0;

    while (e != 0) {
        a = e % 10;
        sum += a;
        e /= 10;
    }

    return sum;
}

int main(void)
{
    int ret = 0;
    int64_t val = 0;

    val = add_digist(123);
    LOG("the val %lld\n", val);

    val = add_digist(1111);
    LOG("the val %lld\n", val);

    val = add_digist(11111);
    LOG("the val %lld\n", val);

    val = add_digist(11119);
    LOG("the val %lld\n", val);
finish:
    return ret;
}