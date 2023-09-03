#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include "utils.h"

int32_t maximum_difference(int32_t* nums, size_t nums_size)
{
    int32_t ret = -1;

    UTILS_CHECK_PTR(nums);
    UTILS_CHECK_LEN(nums_size);

    size_t i = 0, j = 0;
    int32_t max = nums[1] - nums[0] - 1;

    for (i = 0; i < nums_size; i ++) {
        for (j = i; j < nums_size; j ++) {
            int32_t delta = nums[j] - nums[i];
            if (i < j) {
                max = max < delta ? delta : max;
            }
        }
    }

    ret = max;

finish:
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;
    int32_t array1[] = {7,1,5,4};
    int32_t array2[] = {9,4,3,2};
    int32_t array3[] = {1,5,2,10};

    ret = maximum_difference(array1, ARRAY_SIZE(array1));
    assert(ret == 4);

    ret = maximum_difference(array2, ARRAY_SIZE(array2));
    assert(ret == -1);

    ret = maximum_difference(array3, ARRAY_SIZE(array3));
    assert(ret == 9);

    LOG("All tests have passed!\n");

finish:
    return ret;
}