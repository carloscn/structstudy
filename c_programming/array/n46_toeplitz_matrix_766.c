#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "utils.h"

static int32_t toeplitz_martrix(const int64_t *array, size_t width, size_t depth, bool *result)
{
    int32_t ret = 0;
    size_t i = 0, j = 0;
    int64_t e = 0;
    size_t len = width * depth;

    UTILS_CHECK_PTR(array);
    UTILS_CHECK_PTR(result);
    UTILS_CHECK_LEN(len);

    // hor
    for (i = 0; i < width - 1; i ++) {
        e = array[i];
        for (j = i; j < len; j += width + 1) {
            if (e != array[j]) {
                *result = false;
                LOG("found hor %lld and %lld\n", e, array[j]);
                goto finish;
            }
        }
    }

    // ver
    for (i = width; i < len - 1; i += width) {
        e = array[i];
        for (j = i; j < len; j += width + 1) {
            if (e != array[j]) {
                *result = false;
                LOG("found ver %lld and %lld\n", e, array[j]);
                goto finish;
            }
        }
    }

    *result = true;

finish:
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;
    int64_t mat[3][4] = {
                {1,2,3,4},
                {5,1,2,3},
                {9,5,1,2}};
    bool res = false;

    ret = toeplitz_martrix((const int64_t *)mat, 4, 3, &res);
    UTILS_CHECK_RET(ret);
    LOG("the result is %d\n", res);

finish:
    return ret;
}