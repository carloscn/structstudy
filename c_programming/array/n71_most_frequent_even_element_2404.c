#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>
#include "utils.h"

static int32_t most_frequent_even(int32_t *nums, size_t nums_size)
{
    int32_t ret = 0;

    UTILS_CHECK_PTR(nums);
    UTILS_CHECK_LEN(nums_size);

    ret = utils_sort_int32_array(nums, nums_size, ORDER_BY_ASCEND);
    UTILS_CHECK_RET(ret);

    size_t count = 0, max_count = 0;
    int32_t record = 0, min_record = INT32_MAX;
    for (size_t i = 1; i < nums_size; i ++) {
        count = (nums[i] != nums[i - 1])? 0 : count + 1;
        if ((max_count < count) &&
            (nums[i] & 0x1) == 0) {
            max_count = count;
            record = nums[i];
            min_record = UTILS_MIN(record, min_record);
        }
    }
    ret = (min_record == INT32_MAX) ? -1 : min_record;

finish:
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;
    int32_t array1[] = {0,1,2,2,4,4,1};
    int32_t array2[] = {4,4,4,9,2,4};
    int32_t array3[] = {29,47,21,41,13,37,25,7};

    ret = most_frequent_even(array1, ARRAY_SIZE(array1));
    assert(ret == 2);

    ret = most_frequent_even(array2, ARRAY_SIZE(array2));
    assert(ret == 4);

    ret = most_frequent_even(array3, ARRAY_SIZE(array3));
    assert(ret == -1);

    LOG("All tests have passed!\n");

finish:
    return ret;
}