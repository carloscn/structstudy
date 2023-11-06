#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>
#include "utils.h"

static int32_t difference_of_sum(int32_t* nums, size_t nums_size)
{
    int32_t ret = 0;

    UTILS_CHECK_PTR(nums);
    UTILS_CHECK_LEN(nums_size);

    for (size_t i = 0; i < nums_size; i ++) {
        int32_t t = 0, e = nums[i];
        while (e != 0) {
            t += e % 10;
            e /= 10;
        }
        ret += nums[i] - t;
    }

finish:
    return utils_int32_abs(ret);
}

int32_t main(void)
{
    int32_t ret = 0;
    int32_t array1[] = {1,15,6,3};
    int32_t array2[] = {1,2,3,4};

    ret = difference_of_sum(array1, ARRAY_SIZE(array1));
    assert(ret == 9);

    ret = difference_of_sum(array2, ARRAY_SIZE(array2));
    assert(ret == 0);

    LOG("All tests have passed!\n");

finish:
    return ret;
}