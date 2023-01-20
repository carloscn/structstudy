#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "utils.h"

static uint64_t number_com(uint64_t num)
{
    uint64_t result = 0;
    size_t i = 0;

    for (i = 0; i < sizeof(uint64_t) * 8; i ++) {
        result |= (((num >> i) & 0x1UL) ? 0ull : 1ull) << i;
    }

    return result;
}

int main(void)
{
    uint64_t res = 0;
    res = number_com(0x5fffffffffffaaaa);
    LOG("the result is %llx\n", res);

    return 0;
}