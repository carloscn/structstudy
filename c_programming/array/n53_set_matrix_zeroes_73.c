#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "utils.h"

struct pos_t {
    size_t x;
    size_t y;
};

int32_t set_to_zero(int64_t* matrix, size_t len, size_t depth, struct pos_t pos)
{
    int32_t ret = 0;

    UTILS_CHECK_PTR(matrix);
    UTILS_CHECK_LEN(len);
    UTILS_CHECK_LEN(depth);

    size_t i = 0;

    // set row
    for (i = 0; i < len; i ++) {
        *(matrix + pos.y * len + i) = 0;
    }
    // set column
    for (i = 0; i < depth; i ++) {
        *(matrix + i * len + pos.x) = 0;
    }

finish:
    return ret;
}

int32_t set_zeroes(int64_t* matrix, size_t len, size_t depth)
{
    int32_t ret = 0;
    struct pos_t *pos_buffer = NULL;

    UTILS_CHECK_PTR(matrix);
    UTILS_CHECK_LEN(len);
    UTILS_CHECK_LEN(depth);

    size_t i = 0, j = 0;
    size_t k = 0;

    pos_buffer = (struct pos_t *)calloc(len * depth, sizeof(struct pos_t));
    UTILS_CHECK_PTR(pos_buffer);

    for (i = 0; i < depth; i ++) {
        for (j = 0; j < len; j ++) {
            if (0 == *(matrix + i * len + j)) {
                pos_buffer[k].x = j;
                pos_buffer[k ++].y = i;
            }
        }
    }

    for (i = 0; i < k; i ++) {
        ret = set_to_zero(matrix, len, depth, pos_buffer[i]);
        UTILS_CHECK_RET(ret);
    }

finish:
    UTILS_SAFE_FREE(pos_buffer);
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;
    int64_t buffer[] = {1,1,1,1,0,1,1,1,1};
    ret = set_zeroes(buffer, 3, 3);
    UTILS_CHECK_RET(ret);
    utils_print_two_dim_array_int64_t(buffer, 3, 3, 3);

    LOG_LINE_WITH_DOUBLE_TR();

    int64_t buffer1[] = {0,1,2,0,3,4,5,2,1,3,1,5};
    ret = set_zeroes(buffer1, 4, 3);
    UTILS_CHECK_RET(ret);
    utils_print_two_dim_array_int64_t(buffer1, 4, 3, 3);

finish:
    return ret;
}