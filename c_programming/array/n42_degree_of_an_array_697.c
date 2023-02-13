#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "utils.h"

static int32_t degree_array(const int64_t *array, size_t len, size_t *out)
{
    int32_t ret = 0;
    int64_t *buffer = NULL;
    size_t *index = NULL;
    size_t i = 0, j = 0;
    size_t ind = 0;
    size_t min_index = 0;
    int64_t e = 0;
    size_t count = 0;
    size_t max_count = 0;

    UTILS_CHECK_LEN(len);
    UTILS_CHECK_PTR(array);
    UTILS_CHECK_PTR(out);

    buffer = (int64_t *)calloc(sizeof(int64_t), len);
    UTILS_CHECK_PTR(buffer);
    memcpy(buffer, array, sizeof(int64_t) * len);

    index = (size_t *)calloc(sizeof(size_t), len);
    UTILS_CHECK_PTR(index);

    for (i = 0; i < len; i ++) {
        index[i] = i;
    }

    for (i = 0; i < len - 1; i ++) {
        for (j = 0; j < len - i - 1; j ++) {
            if (buffer[j] > buffer[j + 1]) {
                utils_swap_int64(buffer + j, buffer + j + 1);
                utils_swap_size_t(index + j, index + j + 1);
            }
        }
    }

    utils_print_int64_array(buffer, len, "the buffer:");
    utils_print_size_t_array(index, len, "index is  :");

    for (i = 0, j = 0; i < len - 1; i ++) {
        if (buffer[i] == buffer[i + 1]) {
            count ++;
            if (count >= 1 && count > max_count) {
                ind = utils_int64_abs(index[i + 1] - index[j]);
                min_index = ind > min_index ? ind : min_index;
                LOG("the min_index is %zu, ind = %zu\n", min_index, ind);
            } else if (count >= 1 && count == max_count) {
                ind = utils_int64_abs(index[i + 1] - index[j]);
                min_index = ind < min_index ? ind : min_index;
                LOG("the min_index is %zu, ind = %zu\n", min_index, ind);
            }
            max_count = count > max_count ? count : max_count;
        } else {
            count = 0;
            j = i + 1;
        }
    }

    *out = min_index + 1;

finish:
    UTILS_SAFE_FREE(buffer);
    UTILS_SAFE_FREE(index);
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;
    int64_t array[] = {1,2,2,3,1,4,2};
    size_t len = 0;

    ret = degree_array(array, ARRAY_SIZE(array), &len);
    UTILS_CHECK_RET(ret);

    LOG("the result is %zu\n", len);

finish:
    return ret;
}