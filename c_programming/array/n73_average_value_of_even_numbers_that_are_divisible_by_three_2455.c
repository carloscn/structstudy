#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>
#include "utils.h"

static int32_t average_value(int32_t *nums, size_t nums_size)
{
    int32_t ret = 0;

    UTILS_CHECK_PTR(nums);
    UTILS_CHECK_LEN(nums_size);

    int32_t count = 0;
    for (size_t i = 0; i < nums_size; i ++) {
        if ((nums[i] % 3) == 0) {
            ret += nums[i];
            count ++;
        }
    }

    if (count != 0) {
        ret /= count;
    }

finish:
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;
    int32_t array1[] = {1,3,6,10,12,15};
    int32_t array2[] = {1,2,4,7,10};

    ret = average_value(array1, ARRAY_SIZE(array1));
    assert(ret == 9);

    ret = average_value(array2, ARRAY_SIZE(array2));
    assert(ret == 0);

    LOG("All tests have passed!\n");

finish:
    return ret;
}