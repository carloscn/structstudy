#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "utils.h"

static int32_t largest_number(const int32_t *array, size_t len, size_t *index)
{
    int32_t ret = 0;
    int32_t *buffer = NULL;
    size_t *index_buffer = NULL;
    size_t i = 0;
    size_t j = 0;

    UTILS_CHECK_PTR(array);
    UTILS_CHECK_PTR(index);
    UTILS_CHECK_LEN(len);

    buffer = (int32_t *)calloc(sizeof(int32_t), len);
    UTILS_CHECK_PTR(buffer);

    index_buffer = (size_t *)calloc(sizeof(size_t), len);
    UTILS_CHECK_PTR(index_buffer);

    memcpy(buffer, array, len * sizeof(int32_t));

    for (i = 0; i < len; i ++) {
        index_buffer[i] = i;
    }

    for (i = 0; i < len; i ++) {
        for (j = 0; j < len - i - 1; j ++) {
            if (buffer[j] < buffer[j + 1]) {
                utils_swap_int32(buffer + j, buffer + j + 1);
                utils_swap_size_t(index_buffer + j, index_buffer + j + 1);
            }
        }
    }

    if (buffer[0] >= buffer[1] * 2) {
        *index = index_buffer[0];
    } else {
        *index = ~0;
    }

finish:
    UTILS_SAFE_FREE(buffer);
    UTILS_SAFE_FREE(index_buffer);
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;
    int32_t array[] = {3,1,6,0};
    size_t index = 0;

    ret = largest_number(array, ARRAY_SIZE(array), &index);
    UTILS_CHECK_RET(ret);

    LOG("The result is %zx\n", index);

finish:
    return ret;
}