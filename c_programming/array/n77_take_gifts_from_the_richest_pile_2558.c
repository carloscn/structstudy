#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>
#include "utils.h"

static int64_t pick_gifts(int32_t* gifts, size_t gifts_size, int32_t k)
{
    int64_t ret = 0;

    UTILS_CHECK_PTR(gifts);
    UTILS_CHECK_LEN(gifts_size);
    UTILS_CHECK_LEN(k);

    int32_t i = 0;
    while (i < k) {
        size_t max_index = 0;
        int32_t max_value = INT32_MIN;
        for (size_t j = 0; j < gifts_size; j ++) {
            max_value = (max_value > gifts[j])?
                        (max_value):
                        (max_index = j, gifts[j]);
        }
        gifts[max_index] = (int64_t)utils_sqrt((double)max_value);
        i ++;
    }

    for (size_t j = 0; j < gifts_size; j ++) {
        ret += gifts[j];
    }

finish:
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;
    int32_t array1[] = {25,64,9,4,100};
    int32_t array2[] = {1,1,1,1};

    ret = pick_gifts(array1, ARRAY_SIZE(array1), 4);
    assert(ret == 29);

    ret = pick_gifts(array2, ARRAY_SIZE(array2), 4);
    assert(ret == 4);

    LOG("All tests have passed!\n");

finish:
    return ret;
}

// gcc -I./utils/ ./utils/utils.c ./array/n77_take_gifts_from_the_richest_pile_2558.c && ./a.exe