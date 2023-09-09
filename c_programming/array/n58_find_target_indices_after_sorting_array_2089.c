#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include "utils.h"

int32_t target_indices(const int32_t *nums, size_t nums_size, int32_t target,
                       int32_t **out, size_t *olen)
{
    int32_t ret = 0;

    UTILS_CHECK_PTR(nums);
    UTILS_CHECK_PTR(out);
    UTILS_CHECK_PTR(olen);
    UTILS_CHECK_LEN(nums_size);

    *out = (int32_t*) malloc(sizeof(int32_t) * nums_size);
    UTILS_CHECK_PTR(*out);

    memcpy(*out, nums, nums_size * sizeof(int32_t));

    for (size_t i = 0; i < nums_size - 1; i ++) {
        for (size_t j = 0; j < nums_size - i - 1; j ++) {
            if ((*out)[j] > (*out)[j + 1]) {
                utils_swap_int32(&((*out)[j]), &((*out)[j + 1]));
            }
        }
    }

    size_t j = 0;
    for (size_t i = 0; i < nums_size; i ++) {
        if ((*out)[i] == target) {
            (*out)[j] = (int32_t) i;
            j ++;
        }
    }

    *olen = j;

finish:
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;
    int32_t array1[] = {1,2,5,2,3};
    int32_t array2[] = {1,2,5,2,3};
    int32_t array3[] = {1,2,5,2,3};
    int32_t *out = NULL;
    size_t olen = 0;

    ret = target_indices(array1, ARRAY_SIZE(array1), 2, &out, &olen);
    assert(ret == 0);
    utils_print_int32_array(out, olen, "test 1:");
    UTILS_SAFE_FREE(out);

    ret = target_indices(array2, ARRAY_SIZE(array2), 3, &out, &olen);
    assert(ret == 0);
    utils_print_int32_array(out, olen, "test 2:");
    UTILS_SAFE_FREE(out);

    ret = target_indices(array3, ARRAY_SIZE(array3), 5, &out, &olen);
    assert(ret == 0);
    utils_print_int32_array(out, olen, "test 3:");
    UTILS_SAFE_FREE(out);

    LOG("All tests have passed!\n");

finish:
    return ret;
}