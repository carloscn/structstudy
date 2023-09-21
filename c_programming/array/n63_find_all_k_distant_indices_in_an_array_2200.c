#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include "utils.h"

int32_t find_k_distant_indices(int32_t *nums, size_t nums_size, int32_t key, int32_t k, size_t *return_size)
{
    int32_t ret = 0;
    int32_t *buffer = NULL;

    UTILS_CHECK_PTR(nums);
    UTILS_CHECK_PTR(return_size);
    UTILS_CHECK_LEN(nums_size);

    buffer = (int32_t *)calloc(sizeof(int32_t), nums_size);
    UTILS_CHECK_PTR(buffer);

    int32_t buffer_sz = 0;
    for (size_t i = 0; i < nums_size; i ++) {
        if (nums[i] == key) {
            buffer[buffer_sz] = i;
            buffer_sz ++;
        }
    }

    int32_t m = 0;
    for (int32_t i = 0; i < nums_size; i ++) {
        for (int32_t j = 0; j < buffer_sz; j ++) {
            if (utils_int32_abs(i - buffer[j]) <= k) {
                nums[m ++] = i;
                break;
            }
        }
    }

    *return_size = (size_t) m;

finish:
    UTILS_SAFE_FREE(buffer);
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;
    int32_t array1[] = {3,4,9,1,3,9,5};
    int32_t array1_ts[] = {1,2,3,4,5,6};
    int32_t array2[] = {2,2,2,2,3};
    int32_t array2_ts[] = {0,1,2,3,4};
    size_t olen;

    ret = find_k_distant_indices(array1, ARRAY_SIZE(array1), 9, 1, &olen);
    assert(ret == 0), assert(ARRAY_SIZE(array1_ts) == olen);
    for (size_t i = 0; i < olen; i ++) {
        assert(array1[i] == array1_ts[i]);
    }

    ret = find_k_distant_indices(array2, ARRAY_SIZE(array2), 2, 2, &olen);
    assert(ret == 0), assert(ARRAY_SIZE(array2_ts) == olen);
    for (size_t i = 0; i < olen; i ++) {
        assert(array2[i] == array2_ts[i]);
    }

    LOG("All tests have passed!\n");

finish:
    return ret;
}