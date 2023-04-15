#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "utils.h"

static int32_t remove_duplicates(int64_t* nums, size_t *sz)
{
    int32_t ret = 0;
    int64_t comp = 0;
    size_t i = 0, j = 0, count = 1;

    UTILS_CHECK_PTR(sz);
    UTILS_CHECK_LEN(*sz);
    UTILS_CHECK_PTR(nums);

    comp = nums[0];
    for (i = 1; i < *sz; i ++) {
        if (comp == nums[i]) {
            count ++;
            if (count > 2) {
                for (j = i; j < *sz; j ++) {
                    nums[j] = nums[j + 1];
                }
                i --;
                (*sz) --;
            }
        } else {
            comp = nums[i];
            count = 1;
        }
    }

finish:
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;
    int64_t nums1[] = {1,1,1,2,2,3};
    size_t len = UTILS_ARRAY_SIZE(nums1);

    utils_print_int64_array(nums1, len, "ori out: ");
    ret = remove_duplicates(nums1, &len);
    UTILS_CHECK_RET(ret);

    utils_print_int64_array(nums1, len, "dea out: ");

    LOG_LINE_WITH_DOUBLE_TR();

    int64_t nums2[] = {0,0,1,1,1,1,2,3,3};
    len = UTILS_ARRAY_SIZE(nums2);

    utils_print_int64_array(nums2, len, "ori out: ");
    ret = remove_duplicates(nums2, &len);
    UTILS_CHECK_RET(ret);

    utils_print_int64_array(nums2, len, "dea out: ");


finish:
    return ret;
}
