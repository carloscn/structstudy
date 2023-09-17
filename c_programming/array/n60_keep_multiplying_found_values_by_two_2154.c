#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include "utils.h"

int32_t find_final_value(int32_t* nums, size_t nums_size, int32_t original, int32_t *out)
{
    int32_t ret = 0;

    UTILS_CHECK_PTR(nums);
    UTILS_CHECK_PTR(out);
    UTILS_CHECK_LEN(nums_size);

    for (size_t i = 0; i < nums_size; i ++) {
        for (size_t j = 0; j < nums_size - i - 1; j ++) {
            if (nums[j] > nums[j + 1]) {
                utils_swap_int32(nums + j, nums + j + 1);
            }
        }
    }

    bool flag = false;
    size_t i = 0;
    while (i < nums_size) {
        if (nums[i] == original) {
            original *= 2;
            flag = true;
        }
        i ++;
    }

    *out = flag == true ? original * 2 : original;

    LOG("the output is %d\n", *out);

finish:
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;
    int32_t array1[] = {5,3,6,1,1};
    int32_t array2[] = {2,7,9};
    int32_t out;

    ret = find_final_value(array1, ARRAY_SIZE(array1), 3, &out);
    assert(ret == 0), assert(out == 24);

    ret = find_final_value(array2, ARRAY_SIZE(array2), 4, &out);
    assert(ret == 0), assert(out == 4);

    LOG("All tests have passed!\n");

finish:
    return ret;
}