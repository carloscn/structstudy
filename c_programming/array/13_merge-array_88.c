#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "utils.h"

// note, a_len is input and output pointer.
static int32_t merge_array(int64_t *array_a,
                           size_t *a_p_len,
                           const int64_t *array_b,
                           size_t b_len)
{
    int32_t ret = 0;
    int32_t a_len = 0;
    int32_t write_pos = 0;

    UTILS_CHECK_PTR(array_a);
    UTILS_CHECK_PTR(a_p_len);

    a_len = *a_p_len;
    *a_p_len = a_len + b_len;
    if (0 == *a_p_len) {
        goto finish;
    }

    if ((0 == b_len) || (NULL == array_b)) {
        *a_p_len = a_len;
        goto finish;
    }

    write_pos = *a_p_len;
    while (write_pos --) {
        if (((0 != a_len) && (0 == b_len)) ||
            ((0 != a_len) && (0 != b_len) && (array_a[a_len - 1] >= array_b[b_len - 1]))) {
            array_a[write_pos] = array_a[--a_len];
        } else if (((0 == a_len) && (0 != b_len)) ||
                   ((0 != a_len) && (0 != b_len) && (array_a[a_len - 1] < array_b[b_len - 1]))) {
            array_a[write_pos] = array_b[--b_len];
        }
    }

finish:
    return ret;
}

int main(void)
{
    int32_t ret = 0;

    int64_t test_nums_1[] = {1,2,3,0,0,0,0};
    int64_t test_nums_2[] = {0,2,2,4};
    int64_t test_nums_3[] = {1};
    int64_t test_nums_4[] = {0};
    size_t len_out = 0;

    len_out = 3;
    ret = merge_array(test_nums_1, &len_out, test_nums_2, ARRAY_SIZE(test_nums_2));
    UTILS_CHECK_RET(ret);
    utils_print_int64_array(test_nums_1, len_out, "the output array :");
    LOG_LINE_WITH_TR();

    len_out = 1;
    ret = merge_array(test_nums_3, &len_out, NULL, ARRAY_SIZE(test_nums_4));
    UTILS_CHECK_RET(ret);
    utils_print_int64_array(test_nums_3, len_out, "the output array :");
    LOG_LINE_WITH_TR();

finish:
    return ret;
}
