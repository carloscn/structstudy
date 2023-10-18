#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>
#include "utils.h"

static int32_t arithmetic_triplets(int32_t *nums, size_t nums_size, int32_t diff)
{
    int32_t ret = 0;

    UTILS_CHECK_PTR(nums);
    UTILS_CHECK_LEN(nums_size);

    for (size_t i = 0; i < nums_size; i ++) {
        for (size_t j = i + 1; j < nums_size; j ++) {
            for (size_t k = j + 1; k < nums_size; k ++) {
                if ((nums[j] - nums[i] == diff) &&
                    (nums[k] - nums[j] == diff)) {
                    ret ++;
                }
            }
        }
    }

finish:
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;
    int32_t array1[] = {0,1,4,6,7,10};
    int32_t array2[] = {4,5,6,7,8,9};

    ret = arithmetic_triplets(array1, ARRAY_SIZE(array1), 3);
    assert(ret == 2);

    ret = arithmetic_triplets(array2, ARRAY_SIZE(array2), 2);
    assert(ret == 2);

    LOG("All tests have passed!\n");

finish:
    return ret;
}