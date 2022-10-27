#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "utils.h"

static int32_t plus_one(int64_t array[], size_t array_size)
{
    int32_t ret = 0;
    int32_t i = 0;

    UTILS_CHECK_PTR(array);

    if (0 == array_size) {
        goto finish;
    }

    for (i = array_size - 1; i >= 0; i --) {
        if (9 == *(array + i)) {
            *(array + i) = 0;
        } else {
            *(array + i) += 1;
            goto finish;
        }
    }

    LOG("Note, the inputted array is overflow, the highest position shall be 1\n");

finish:
    return ret;
}

int main(void)
{
    int32_t ret = 0;

    int64_t test_nums_1[] = {0,0,1,1,1,2,3,3,4,5,5,5,6,6,6,6,7,8,8,8,5,6,1};
    int64_t test_nums_2[] = {7,2,5,8,9};
    int64_t test_nums_3[] = {0,9,9,9,9,9};
    int64_t test_nums_4[] = {0};
    int64_t test_nums_5[] = {9,9,9,9,9,9};
    size_t len_out = 0;

    ret = plus_one(test_nums_1, ARRAY_SIZE(test_nums_1));
    UTILS_CHECK_RET(ret);
    utils_print_int64_array(test_nums_1, ARRAY_SIZE(test_nums_1), "the output array :");
    LOG_LINE_WITH_TR();

    ret = plus_one(test_nums_2, ARRAY_SIZE(test_nums_2));
    UTILS_CHECK_RET(ret);
    utils_print_int64_array(test_nums_2, ARRAY_SIZE(test_nums_2), "the output array :");
    LOG_LINE_WITH_TR();

    ret = plus_one(test_nums_3, ARRAY_SIZE(test_nums_3));
    UTILS_CHECK_RET(ret);
    utils_print_int64_array(test_nums_3, ARRAY_SIZE(test_nums_3), "the output array :");
    LOG_LINE_WITH_TR();

    ret = plus_one(test_nums_4, ARRAY_SIZE(test_nums_4));
    UTILS_CHECK_RET(ret);
    utils_print_int64_array(test_nums_4, ARRAY_SIZE(test_nums_4), "the output array :");
    LOG_LINE_WITH_TR();

    ret = plus_one(test_nums_5, ARRAY_SIZE(test_nums_5));
    UTILS_CHECK_RET(ret);
    utils_print_int64_array(test_nums_5, ARRAY_SIZE(test_nums_5), "the output array :");
    LOG_LINE_WITH_TR();
finish:
    return ret;
}
