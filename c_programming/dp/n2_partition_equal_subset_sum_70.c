#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "utils.h"
#include "buffer.h"

int32_t partition_equal_subset_sum(const int64_t *array, size_t len, bool *res)
{
    int32_t ret = 0;
    BUFFER_T *a_sub_buffer = NULL;
    BUFFER_T *b_sub_buffer = NULL;
    size_t i, j, k, sub_num;

    UTILS_CHECK_PTR(array);
    UTILS_CHECK_LEN(len);
    UTILS_CHECK_PTR(res);

    a_sub_buffer = buffer_malloc(len);
    UTILS_CHECK_PTR(a_sub_buffer);

    b_sub_buffer = buffer_malloc(len);
    UTILS_CHECK_PTR(b_sub_buffer);

    sub_num = 1 << len;
    for (i = 0; i < sub_num; i ++) {
        j = i;
        k = 0;
        while (j) {
            if (j & 1) {
                ret = buffer_push_tail(a_sub_buffer, array[k]);
                UTILS_CHECK_RET(ret);
            }
            j >>= 1;
            k ++;
        }

        j = sub_num - i - 1;
        k = 0;
        while (j) {
            if (j & 1 == 1) {
                ret = buffer_push_tail(b_sub_buffer, array[k]);
                UTILS_CHECK_RET(ret);
            }
            j >>= 1;
            k ++;
        }

        if (buffer_sum(a_sub_buffer) == buffer_sum(b_sub_buffer)) {
            *res = true;
            printf("the a buffer is : "); buffer_print(a_sub_buffer);
            printf("the b buffer is : "); buffer_print(b_sub_buffer);
            goto finish;
        }
        buffer_clear(a_sub_buffer);
        buffer_clear(b_sub_buffer);
    }

finish:
    buffer_free(a_sub_buffer);
    buffer_free(b_sub_buffer);
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;
    int64_t buffer[] = {1,5,11,5};
    bool res = false;

    ret = partition_equal_subset_sum(buffer, ARRAY_SIZE(buffer), &res);
    UTILS_CHECK_RET(ret);
    LOG("the result is %d\n", res);

finish:
    return ret;
}