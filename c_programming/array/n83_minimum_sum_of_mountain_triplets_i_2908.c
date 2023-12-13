#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>
#include "utils.h"

static int32_t minimum_sum(int32_t *nums, size_t nums_size)
{
    int32_t ret = -1;

    UTILS_CHECK_PTR(nums);
    UTILS_CHECK_CONDITION((nums_size < 3), 0, "nums len is small!\n");

    int32_t min = 0;
    int32_t minimum_sum = INT32_MAX;
    for (size_t i = 0; i < nums_size; i ++) {
        for (size_t j = i + 1; j < nums_size; j ++) {
            for (size_t k = j + 1; k < nums_size; k ++) {
                if ((i < j) && (j < k) && (nums[i] < nums[j]) && (nums[k] < nums[j])) {
                    min = nums[i] + nums[j] + nums[k];
                    minimum_sum = UTILS_MIN(minimum_sum, min);
                }
            }
        }
    }

    ret = (minimum_sum == INT32_MAX) ? -1 : minimum_sum;

finish:
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;
    int32_t array1[] = {8,6,1,5,3};
    int32_t array2[] = {5,4,8,7,10,2};
    int32_t array3[] = {6,5,4,3,4,5};

    ret = minimum_sum(array1, ARRAY_SIZE(array1));
    assert(ret == 9);

    ret = minimum_sum(array2, ARRAY_SIZE(array2));
    assert(ret == 13);

    ret = minimum_sum(array3, ARRAY_SIZE(array3));
    assert(ret == -1);

    LOG("All tests have passed!\n");

finish:
    return ret;
}

// gcc -I./utils/ ./utils/utils.c ./array/n83_minimum_sum_of_mountain_triplets_i_2908.c && ./a.exe