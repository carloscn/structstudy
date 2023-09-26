#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>
#include "utils.h"

static int32_t find_closest_number(int32_t *nums, size_t nums_size)
{
    int32_t ret = 0;

    UTILS_CHECK_PTR(nums);
    UTILS_CHECK_LEN(nums_size);

    int32_t min_dist = abs(nums[0]);
    int32_t min_val = INT32_MIN;
    for (size_t i = 1; i < nums_size; i ++) {
        if (abs(nums[i]) <= min_dist) {
            min_dist = abs(nums[i]);
            if (nums[i] > min_val) {
                min_val = nums[i];
            }
        }
    }

    ret = min_val;

finish:
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;
    int32_t array1[] = {-4,-2,1,4,8};
    int32_t array2[] = {2,-1,1};

    ret = find_closest_number(array1, ARRAY_SIZE(array1));
    assert(ret == 1);

    ret = find_closest_number(array2, ARRAY_SIZE(array2));
    assert(ret == 1);

    LOG("All tests have passed!\n");

finish:
    return ret;
}