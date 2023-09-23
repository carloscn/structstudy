#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include "utils.h"

static int32_t count_hill_valley(int32_t *nums, size_t nums_size)
{
    int32_t ret = 0;

    UTILS_CHECK_PTR(nums);
    UTILS_CHECK_LEN(nums_size);

    size_t i = 1;
    while (i < nums_size - 1) {
        int32_t m = nums[i];
        int32_t li = i - 1, ri = i + 1;

        while (li > 0 && nums[i] == nums[li]) {
            li --;
        }

        while (ri < nums_size && nums[i] == nums[ri]) {
            ri ++;
        }

        ret += ((nums[i] > nums[li]) && (nums[i] > nums[ri])) ||
               ((nums[i] < nums[li]) && (nums[i] < nums[ri]));

        i = ri;
    }

finish:
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;
    int32_t array1[] = {2,4,1,1,6,5};
    int32_t array2[] = {6,6,5,5,4,1};

    ret = count_hill_valley(array1, ARRAY_SIZE(array1));
    assert(ret == 3);

    ret = count_hill_valley(array2, ARRAY_SIZE(array2));
    assert(ret == 0);

    LOG("All tests have passed!\n");

finish:
    return ret;
}