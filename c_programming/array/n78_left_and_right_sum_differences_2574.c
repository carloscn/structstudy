#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>
#include "utils.h"

int32_t left_right_difference(int32_t *nums, size_t nums_size)
{
    int32_t ret = 0;
    int32_t *left_nums = NULL, *right_nums = NULL;

    UTILS_CHECK_PTR(nums);
    UTILS_CHECK_LEN(nums_size);

    left_nums = (int32_t *)calloc(nums_size, sizeof(int32_t));
    UTILS_CHECK_PTR(left_nums);

    right_nums = (int32_t *)calloc(nums_size, sizeof(int32_t));
    UTILS_CHECK_PTR(right_nums);

    for (size_t i = 0; i < nums_size; i ++) {
        int32_t e = 0;
        for (size_t j = 0; j < i; j ++) {
            e += nums[j];
        }
        left_nums[i] = e;

        e = 0;
        for (size_t j = i + 1; j < nums_size; j ++) {
            e += nums[j];
        }

        right_nums[i] = e;
    }

    for (size_t i = 0; i < nums_size; i ++) {
        nums[i] = utils_int32_abs(left_nums[i] - right_nums[i]);
    }

finish:
    UTILS_SAFE_FREE(left_nums);
    UTILS_SAFE_FREE(right_nums);
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;
    int32_t array1[] = {10,4,8,3};
    int32_t array2[] = {1};

    ret = left_right_difference(array1, ARRAY_SIZE(array1));
    assert(ret == 0);
    utils_print_int32_array(array1, ARRAY_SIZE(array1), "out is ");

    ret = left_right_difference(array2, ARRAY_SIZE(array2));
    assert(ret == 0);
    utils_print_int32_array(array2, ARRAY_SIZE(array2), "out is ");

    LOG("All tests have passed!\n");

finish:
    return ret;
}

// gcc -I./utils/ ./utils/utils.c ./array/n78_left_and_right_sum_differences_2574.c && ./a.exe