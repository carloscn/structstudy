#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>
#include "utils.h"

static int32_t min_number(int32_t* nums1, size_t nums1_size, int32_t* nums2, size_t nums2_size)
{
    int32_t ret = 0;

    UTILS_CHECK_PTR(nums1);
    UTILS_CHECK_PTR(nums2);

    int32_t min_1 = INT32_MAX;
    int32_t min_2 = INT32_MAX;
    int32_t common = INT32_MAX;
    if ((0 == nums1_size) &&
        (0 == nums2_size)) {
        goto finish;
    }

    for (size_t i = 0; i < nums1_size; i ++) {
        int32_t e = nums1[i];
        min_1 = UTILS_MIN(e, min_1);
        for (size_t j = 0; j < nums2_size; j ++) {
            min_2 = UTILS_MIN(nums2[j], min_2);
            if (e == nums2[j]) {
                common = (common > e) ? e : common;
            }
        }
    }

    if (common == INT32_MAX) {
        if (min_1 > min_2) {
            ret = min_2 * 10 + min_1;
        } else {
            ret = min_1 * 10 + min_2;
        }
    } else {
        ret = common;
    }

finish:
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;
    int32_t array1[] = {4,1,3};
    int32_t array2[] = {5,7};
    int32_t array3[] = {3,5,2,6};
    int32_t array4[] = {3,1,7};

    ret = min_number(array1, ARRAY_SIZE(array1), array2, ARRAY_SIZE(array2));
    assert(ret == 15);

    ret = min_number(array3, ARRAY_SIZE(array3), array4, ARRAY_SIZE(array4));
    assert(ret == 3);

    LOG("All tests have passed!\n");

finish:
    return ret;
}

// gcc -I./utils/ ./utils/utils.c ./array/n79_form_smallest_number_from_two_digit_arrays_2605.c && ./a.exe