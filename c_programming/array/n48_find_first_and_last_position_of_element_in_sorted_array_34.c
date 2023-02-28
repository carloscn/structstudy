#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "utils.h"

static int32_t find_first(const int32_t *array, size_t sz, int32_t target, int32_t *out)
{
    int32_t ret = 0;
    int32_t left = 0, right = sz - 1;
    int32_t mid = left + (right - left) / 2;
    int32_t i = 0;
    bool is_left = false;
    bool is_right = false;

    UTILS_CHECK_PTR(array);
    UTILS_CHECK_PTR(out);
    out[0] = -1;
    out[1] = -1;

    UTILS_CHECK_LEN(sz);

    while (left <= right) {
        if (array[mid] < target) {
            left = mid;
        } else if (array[mid] > target) {
            right = mid;
        } else {
            break;
        }
        mid = left + (right - left) / 2;
    }

    if (mid == 0 || mid == sz - 1 ) {
        goto finish;
    }

    left = right = mid;
    while (is_left == false || is_right == false) {
        if (array[mid] == array[left]) {
            left --;
        } else {
            out[0] = left + 1;
            is_left = true;
        }

        if (array[mid] == array[right]) {
            right ++;
        } else {
            out[1] = right - 1;
            is_right = true;
        }
    }

finish:
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;
    int32_t array[] = {5,7,7,7,7,7,7,7,7,7,8,8,8,8,8,8,8,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,10};
    int32_t out[2] = {0};

    ret = find_first((const int32_t *)array, ARRAY_SIZE(array), 8, out);
    UTILS_CHECK_RET(ret);

    LOG("the output is [%d, %d]\n", out[0], out[1]);

finish:
    return ret;
}