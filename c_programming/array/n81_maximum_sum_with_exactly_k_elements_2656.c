#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>
#include "utils.h"

static int32_t maximize_sum(int32_t* nums, size_t nums_size, int32_t k)
{
    int32_t ret = 0;

    UTILS_CHECK_PTR(nums);
    UTILS_CHECK_LEN(nums_size);
    UTILS_CHECK_LEN(k);

    for (size_t i = 0; i < k; i ++) {
        int32_t max_num = INT32_MIN;
        size_t max_index = 0;
        int32_t num = 0;
        for (size_t j = 0; j < nums_size; j ++) {
            num = nums[j];
            if (num >= max_num) {
                max_num = num;
                max_index = j;
            }
        }
        ret += max_num;
        nums[max_index] ++;
    }

finish:
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;
    int32_t array1[] = {1,2,3,4,5};
    int32_t array2[] = {5,5,5};

    ret = maximize_sum(array1, ARRAY_SIZE(array1), 3);
    assert(ret == 18);

    ret = maximize_sum(array2, ARRAY_SIZE(array2), 2);
    assert(ret == 11);

    LOG("All tests have passed!\n");

finish:
    return ret;
}

// gcc -I./utils/ ./utils/utils.c ./array/n81_maximum_sum_with_exactly_k_elements_2656.c && ./a.exe