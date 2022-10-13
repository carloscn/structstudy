#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "utils.h"

static int32_t print_target_sum(const int32_t nums[], size_t len, int32_t target)
{
    int32_t ret = 0;
    size_t index[2] = {0};
    int32_t cacu_target = target;
    int32_t try_val = 0;
    size_t i = 0, j = 0;

    if (0 == len) {
        ret = -1;
        goto finish;
    }

    UTILS_CHECK_PTR(nums);

    for (i = 0; i < len; i ++) {
        try_val = nums[i];
        cacu_target = target - try_val;
        for (j = i + 1; j < len; j ++) {
            if (cacu_target == nums[j]) {
                index[0] = i;
                index[1] = j;
                break;
            }
        }
    }
    LOG("the indexes are (%zd, %zd) \n", index[0], index[1]);

finish:
    return ret;
}

int main(void)
{
    int32_t ret = 0;

    const int32_t test_nums_1[] = {1,2,5,9,6,7,8,6,3,0};
    const int32_t test_nums_2[] = {2,7,11,15};
    const int32_t test_nums_3[] = {3,2,4};
    const int32_t test_nums_4[] = {3,3};

    print_target_sum(test_nums_1, 10, 7);
    print_target_sum(test_nums_2, 4, 9);
    print_target_sum(test_nums_3, 3, 6);
    print_target_sum(test_nums_4, 2, 6);
    return ret;
}
