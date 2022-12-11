#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "utils.h"

static int32_t array_append_with_duplicate_removal(int64_t *array, size_t *index, int64_t e)
{
    int32_t ret = 0;
    size_t i = 0;

    UTILS_CHECK_PTR(array);
    UTILS_CHECK_PTR(index);

    for (i = 0; i < *index; i ++) {
        if (e == array[i]) {
            goto finish;
        }
    }
    array[*index] = e;
    *index += 1;

finish:
    return ret;
}

static int32_t out_intersection(const int64_t *a_array, size_t a_len,
                                const int64_t *b_array, size_t b_len,
                                int64_t **o_array, size_t *o_len)
{
    int32_t ret = 0;
    size_t i = 0, j = 0;
    int64_t e = 0;
    int64_t *array = NULL;
    size_t index = 0;

    UTILS_CHECK_PTR(a_array);
    UTILS_CHECK_PTR(b_array);
    UTILS_CHECK_PTR(o_array);

    array = (int64_t *)calloc(1, sizeof(int64_t) * a_len);
    UTILS_CHECK_PTR(array);

    for (i = 0; i < a_len; i ++) {
        e = a_array[i];
        for (j = 0; j < b_len; j ++) {
            if (e == b_array[j]) {
                ret = array_append_with_duplicate_removal(array, &index, e);
                UTILS_CHECK_RET(ret);
            }
        }
    }

    *o_array = array;
    *o_len = index;

finish:
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;
    int64_t array1[] = {0,1,2,3,4,5,6};
    int64_t array2[] = {1,2,3,4,5,6,7,8,9,1,1,10,11,12,13};
    size_t i = 0;
    size_t o_len = 0;
    int64_t *o_array = NULL;

    ret = out_intersection(array1, ARRAY_SIZE(array1), array2, ARRAY_SIZE(array2), &o_array, &o_len);
    UTILS_CHECK_RET(ret);

    utils_print_int64_array(o_array, o_len, "output : ");

    if (o_array != NULL) {
        free(o_array);
    }
finish:
    return ret;
}