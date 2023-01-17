#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "utils.h"

static size_t hamming_distance(size_t a, size_t b)
{
    size_t i = 0;
    size_t count = 0;

    for (i = 0; i < sizeof(size_t) * 8; i ++) {
        if (((a >> i) & 0x01u) != ((b >> i) & 0x01u)) {
            count ++;
        }
    }

    return count;
}

int main(void)
{
    size_t res = 0;
    res = utils_value_hamming_distance(0x5555, 0xAAAA);
    LOG("the utils result is %zu\n", res);
    res = hamming_distance(0x5555, 0xAAAA);
    LOG("the normal result is %zu\n", res);
    return 0;
}