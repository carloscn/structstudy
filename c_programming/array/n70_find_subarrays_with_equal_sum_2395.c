#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>
#include "utils.h"

static int32_t find_subarrays(int32_t *nums, size_t nums_size)
{
    int32_t ret = 0;
    int32_t *sum_rom = NULL;

    UTILS_CHECK_PTR(nums);
    UTILS_CHECK_LEN(nums_size);

    sum_rom = (int32_t *)calloc(1 << nums_size, sizeof(int32_t));
    UTILS_CHECK_PTR(sum_rom);

    size_t n = 0;
    for (size_t i = 0; i < nums_size - 1; i ++) {
        for (size_t j = i + 1; j < nums_size; j ++) {
            int32_t sum = nums[i] + nums[j];
            for (size_t k = 0; k < n; k ++) {
                if (sum == sum_rom[k]) {
                    ret ++;
                    goto finish;
                }
            }
            sum_rom[n ++] = sum;
        }
    }

finish:
    UTILS_SAFE_FREE(sum_rom);
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;
    int32_t array1[] = {1,2,4};
    int32_t array2[] = {1,2,3,4,5};
    int32_t array3[] = {0,0,0};

    ret = find_subarrays(array1, ARRAY_SIZE(array1));
    assert(ret == 0);

    ret = find_subarrays(array2, ARRAY_SIZE(array2));
    assert(ret == 1);

    ret = find_subarrays(array3, ARRAY_SIZE(array3));
    assert(ret == 1);

    LOG("All tests have passed!\n");

finish:
    return ret;
}