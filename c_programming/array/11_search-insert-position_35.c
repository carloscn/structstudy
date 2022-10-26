#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "utils.h"

// note, the array must over 1 size at least.
static int32_t search_insert_position(int64_t *array,
                                      size_t array_size,
                                      size_t *o_len,
                                      int64_t target)
{
    int32_t ret = 0;
    size_t i = 0;

    UTILS_CHECK_PTR(array);
    UTILS_CHECK_PTR(o_len);

    if (0 == array_size) {
        goto finish;
    }

    for (i = array_size - 1; i >= 0; i --) {
        // check condition of boundary
        if ((i == array_size - 1) && (array[i] <= target)) {
            array[++i] = target;
            break;
        }

        // normal insertion
        array[i + 1] = array[i];
        if ((array[i] >= target) && (array[i-1] <= target)) {
            array[i] = target;
            break;
        }
    }

    *o_len = i;

finish:
    return ret;
}

int main(void)
{
    int32_t ret = 0;

    int64_t test_nums_1[] = {0,0,1,1,1,2,3,3,4,5,5,5,6,6,6,6,7,8,8,8,10,10,0};
    int64_t test_nums_2[] = {7,12,15,19,0};
    int64_t test_nums_3[] = {0,0,1,1,1,2,2,3,3,0};
    int64_t test_nums_4[] = {0,1,2,3,4,0};
    size_t len_out = 0;
    int64_t target = 0;

    target = 2;
    ret = search_insert_position(test_nums_1, ARRAY_SIZE(test_nums_1) - 1, &len_out, target);
    UTILS_CHECK_RET(ret);
    LOG("the output pos %zd, insert target = %lld\n", len_out, target);
    utils_print_int64_array(test_nums_1, ARRAY_SIZE(test_nums_1), "the output array :");
    LOG_LINE_WITH_TR();

    target = 6;
    ret = search_insert_position(test_nums_2, ARRAY_SIZE(test_nums_2) - 1, &len_out, target);
    UTILS_CHECK_RET(ret);
    LOG("the output pos %zd, insert target = %lld\n", len_out, target);
    utils_print_int64_array(test_nums_2, ARRAY_SIZE(test_nums_2), "the output array :");
    LOG_LINE_WITH_TR();

    target = 3;
    ret = search_insert_position(test_nums_3, ARRAY_SIZE(test_nums_3) - 1, &len_out, target);
    UTILS_CHECK_RET(ret);
    LOG("the output pos %zd, insert target = %lld\n", len_out, target);
    utils_print_int64_array(test_nums_3, ARRAY_SIZE(test_nums_3), "the output array :");
    LOG_LINE_WITH_TR();

    target = 5;
    ret = search_insert_position(test_nums_4, ARRAY_SIZE(test_nums_4) - 1, &len_out, target);
    UTILS_CHECK_RET(ret);
    LOG("the output pos %zd, insert target = %lld\n", len_out, target);
    utils_print_int64_array(test_nums_4, ARRAY_SIZE(test_nums_4), "the output array :");
    LOG_LINE_WITH_TR();

finish:
    return ret;
}
