#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include "utils.h"

int32_t smallest_equal(int32_t* nums, size_t len, int32_t *index)
{
    int32_t ret = 0;

    UTILS_CHECK_PTR(nums);
    UTILS_CHECK_PTR(index);
    UTILS_CHECK_LEN(len);

    *index = -1;

    for (size_t i = 0; i < len; i ++) {
        if (i % 10 == nums[i]) {
            *index = (int32_t) i;
            goto finish;
        }
    }

finish:
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;
    int32_t array1[] = {0,1,2};
    int32_t array2[] = {4,3,2,1};
    int32_t array3[] = {1,2,3,4,5,6,7,8,9,0};
    int32_t res = 0;

    ret = smallest_equal(array1, ARRAY_SIZE(array1), &res);
    assert(ret == 0), assert(res == 0);

    ret = smallest_equal(array2, ARRAY_SIZE(array2), &res);
    assert(ret == 0), assert(res == 2);

    ret = smallest_equal(array3, ARRAY_SIZE(array3), &res);
    assert(ret == 0), assert(res == -1);

    LOG("All tests have passed!\n");

finish:
    return ret;
}