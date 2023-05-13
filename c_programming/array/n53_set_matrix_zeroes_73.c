#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "utils.h"

int32_t set_zeroes(int32_t* *matrix, size_t len, size_t depth)
{
    int32_t ret = 0;

    UTILS_CHECK_PTR(matrix);
    UTILS_CHECK_LEN(len);
    UTILS_CHECK_LEN(depth);

    size_t i = 0, j = 0;

    for (i = 0; i < depth; i ++) {
        for (j = 0; j < len; j ++) {

        }
    }

finish:
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;


finish:
    return ret;
}