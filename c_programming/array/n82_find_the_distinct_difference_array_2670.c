#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>
#include "utils.h"

#define MAX_NUM 50

int32_t distinct_difference_array(int32_t *nums, size_t nums_size)
{
    int32_t ret = 0;
    int32_t *rom = NULL;

    UTILS_CHECK_PTR(nums);
    UTILS_CHECK_LEN(nums_size);

    rom = (int32_t *)calloc(nums_size, sizeof(size_t));
    UTILS_CHECK_PTR(rom);

    bool prefix[MAX_NUM + 1] = {0};
    bool suffix[MAX_NUM + 1] = {0};

    for (size_t i = 0; i < nums_size; i ++) {
        suffix[nums[i]] = true;
    }

    for (size_t i = 0; i < nums_size; i ++) {
        suffix[nums[i]] = false;
        prefix[nums[i]] = true;
        size_t prefix_count = 0, suffix_count = 0;
        for (size_t j = 1; j <= MAX_NUM; j ++) {
            prefix_count += prefix[j]?1:0;
            suffix_count += suffix[j]?1:0;
        }
        rom[i] = prefix_count - suffix_count;
    }

    memcpy(nums, rom, sizeof(int32_t) * nums_size);

finish:
    UTILS_SAFE_FREE(rom);
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;
    int32_t array1[] = {1,2,3,4,5};
    int32_t array2[] = {3,2,3,4,2};

    ret = distinct_difference_array(array1, ARRAY_SIZE(array1));
    assert(ret == 0);
    utils_print_int32_array(array1, ARRAY_SIZE(array1), "output is ");

    ret = distinct_difference_array(array2, ARRAY_SIZE(array2));
    assert(ret == 0);
    utils_print_int32_array(array2, ARRAY_SIZE(array2), "output is ");

    LOG("All tests have passed!\n");

finish:
    return ret;
}