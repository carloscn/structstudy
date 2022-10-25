#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "utils.h"

static int32_t remove_element(int64_t *array,
                              size_t array_size,
                              size_t *o_len,
                              int64_t target)
{
    int32_t ret = 0;
    size_t i = 0;
    size_t pos = 0;

    UTILS_CHECK_PTR(array);
    UTILS_CHECK_PTR(o_len);

    if (0 == array_size) {
        goto finish;
    }

    for (i = 0; i < array_size; i ++) {
        if (target != array[i]) {
            array[pos] = array[i];
            pos ++;
        }
    }

    *o_len = pos;

finish:
    return ret;
}


int main(void)
{
    int32_t ret = 0;

    int64_t test_nums_1[] = {0,0,1,1,1,2,2,2,2,2,2,2,2,2,2,3,3,4,5,5,5,6,6,6,6,7,8,8,8,10,10,15};
    int64_t test_nums_2[] = {1,1,2};
    int64_t test_nums_3[] = {0,0,1,1,1,2,2,3,3,4};
    int64_t test_nums_4[] = {0,1,2,3,4,5};
    size_t len_out = 0;
    int64_t target = 0;

    target = 2;
    ret = remove_element(test_nums_1, ARRAY_SIZE(test_nums_1), &len_out, target);
    UTILS_CHECK_RET(ret);
    LOG("the output pos %zd, remove target = %lld\n", len_out, target);
    utils_print_int64_array(test_nums_1, len_out, "the output array :");
    LOG_LINE_WITH_TR();

    target = 1;
    ret = remove_element(test_nums_2, ARRAY_SIZE(test_nums_2), &len_out, target);
    UTILS_CHECK_RET(ret);
    LOG("the output pos %zd, remove target = %lld\n", len_out, target);
    utils_print_int64_array(test_nums_2, len_out, "the output array :");
    LOG_LINE_WITH_TR();

    target = 3;
    ret = remove_element(test_nums_3, ARRAY_SIZE(test_nums_3), &len_out, target);
    UTILS_CHECK_RET(ret);
    LOG("the output pos %zd, remove target = %lld\n", len_out, target);
    utils_print_int64_array(test_nums_3, len_out, "the output array :");
    LOG_LINE_WITH_TR();

    target = 5;
    ret = remove_element(test_nums_4, ARRAY_SIZE(test_nums_4), &len_out, target);
    UTILS_CHECK_RET(ret);
    LOG("the output pos %zd, remove target = %lld\n", len_out, target);
    utils_print_int64_array(test_nums_4, len_out, "the output array :");
    LOG_LINE_WITH_TR();
finish:
    return ret;
}
