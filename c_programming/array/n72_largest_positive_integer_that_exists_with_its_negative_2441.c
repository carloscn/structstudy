#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>
#include "utils.h"

static int32_t find_max_k(int32_t *nums, size_t nums_size)
{
    int32_t ret = 0;

    UTILS_CHECK_PTR(nums);
    UTILS_CHECK_LEN(nums_size);

    ret = utils_sort_int32_array(nums, nums_size, ORDER_BY_DESCEND);
    UTILS_CHECK_RET(ret);

    for (size_t i = 0; (i < nums_size) && (nums[i] > 0); i ++) {
        int32_t max_e = nums[i];
        for (size_t j = nums_size - 1; (j > 0) && (nums[j] < 0); j --) {
            if (max_e == (-nums[j])) {
                ret = max_e;
                goto finish;
            }
        }
    }

    ret = -1;

finish:
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;
    int32_t array1[] = {-1,2,-3,3};
    int32_t array2[] = {-1,10,6,7,-7,1};
    int32_t array3[] = {-10,8,6,7,-2,-3};

    ret = find_max_k(array1, ARRAY_SIZE(array1));
    assert(ret == 3);

    ret = find_max_k(array2, ARRAY_SIZE(array2));
    assert(ret == 7);

    ret = find_max_k(array3, ARRAY_SIZE(array3));
    assert(ret == -1);

    LOG("All tests have passed!\n");

finish:
    return ret;
}