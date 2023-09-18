#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include "utils.h"

int32_t sort_even_odd(int32_t *nums, size_t nums_size)
{
    int32_t ret = 0;
    int32_t *a_buf = NULL;
    int32_t *b_buf = NULL;

    UTILS_CHECK_PTR(nums);
    UTILS_CHECK_LEN(nums_size);

    a_buf = (int32_t *)malloc(sizeof(int32_t) * (nums_size / 2 + 1));
    UTILS_CHECK_PTR(a_buf);

    b_buf = (int32_t *)malloc(sizeof(int32_t) * (nums_size / 2 + 1));
    UTILS_CHECK_PTR(b_buf);

    for (size_t i = 0; i < nums_size; i ++) {
        if (i % 2 == 0) {
            a_buf[i/2] = nums[i];
        } else {
            b_buf[i/2] = nums[i];
        }
    }

    for (size_t i = 0; i < nums_size/2; i ++) {
        for (size_t j = 0; j < nums_size/2 - i - 1; j ++) {
            if (a_buf[j] > a_buf[j + 1]) {
                utils_swap_int32(a_buf + j, a_buf + j + 1);
            }
            if (b_buf[j] < b_buf[j + 1]) {
                utils_swap_int32(b_buf + j, b_buf + j + 1);
            }
        }
    }

    for (size_t i = 0; i < nums_size / 2; i ++) {
        nums[2 * i] = a_buf[i];
        nums[2 * i + 1] = b_buf[i];
    }

finish:
    UTILS_SAFE_FREE(a_buf);
    UTILS_SAFE_FREE(b_buf);
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;
    int32_t array1[] = {4,1,2,3};
    int32_t array2[] = {2,1};
    int32_t out;

    ret = sort_even_odd(array1, ARRAY_SIZE(array1));
    assert(ret == 0);
    utils_print_int32_array(array1, ARRAY_SIZE(array1), "the out is :");

    ret = sort_even_odd(array2, ARRAY_SIZE(array2));
    assert(ret == 0);
    utils_print_int32_array(array2, ARRAY_SIZE(array2), "the out is :");

    LOG("All tests have passed!\n");

finish:
    return ret;
}