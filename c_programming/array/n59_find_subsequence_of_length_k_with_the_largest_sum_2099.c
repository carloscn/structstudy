#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include "utils.h"

int32_t max_subsequence(int32_t *nums, size_t len, int32_t k, int32_t *out)
{
    int32_t ret = 0;

    UTILS_CHECK_PTR(nums);
    UTILS_CHECK_PTR(out);
    UTILS_CHECK_LEN(len);
    UTILS_CHECK_CONDITION(k > len, -1, "k is oversize!");

    for (size_t i = 0; i < len; i ++) {
        for (size_t j = 0; j < len - i - 1; j ++) {
            if (nums[j] < nums[j + 1]) {
                utils_swap_int32(nums + j, nums + j + 1);
            }
        }
    }

    memcpy(out, nums, sizeof(int32_t) * k);

finish:
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;
    int32_t array1[] = {2,1,3,3};
    int32_t array2[] = {-1,-2,3,4};
    int32_t array3[] = {3,4,3,3};
    int32_t out[1024];
    int32_t k = 0;

    k = 2, ret = max_subsequence(array1, ARRAY_SIZE(array1), k, out);
    assert(ret == 0);
    utils_print_int32_array(out, k, "test 1 : ");

    k = 3, ret = max_subsequence(array2, ARRAY_SIZE(array2), k, out);
    assert(ret == 0);
    utils_print_int32_array(out, k, "test 2 : ");

    k = 2, ret = max_subsequence(array3, ARRAY_SIZE(array3), k, out);
    assert(ret == 0);
    utils_print_int32_array(out, k, "test 3 : ");

    LOG("All tests have passed!\n");

finish:
    return ret;
}