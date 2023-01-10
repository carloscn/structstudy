#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "utils.h"

static size_t arrange_coins(size_t n)
{
    size_t i = 1;
    size_t k = 0;

    while (n > i) {
        k ++;
        n -= i;
        i += k;
    }

    return k;
}

int main(void)
{
    size_t res = 0;
    res = arrange_coins(5);
    LOG("the result is %zu\n", res);
}