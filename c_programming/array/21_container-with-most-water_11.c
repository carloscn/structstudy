#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "utils.h"

static int32_t max_area(int64_t *array, size_t sz, int64_t *out)
{
    int32_t ret = 0;
    int64_t mx_area = 0, area = 0;
    size_t x = 0, y = sz - 1;

    UTILS_CHECK_LEN(sz);
    UTILS_CHECK_PTR(array);

    if (2 >= sz) {
        *out = utils_int64_abs(array[x] - array[y]);
        goto finish;
    }

    while (x != y) {
        area = (y - x) * MIN(array[x], array[y]);
        mx_area = MAX(area, mx_area);
        if (array[x] > array[y]) {
            y --;
        } else if (array[x] < array[y]){
            x ++;
        } else {
            y --;
            x ++;
        }
    }

    *out = mx_area;

finish:
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;
    int64_t array1[] = {1,8,6,2,5,4,8,3,7};
    int64_t array2[] = {2,5,2,5,7,2};
    int64_t array3[] = {1, 1};
    int64_t value = 0;

    ret = max_area(array1, ARRAY_SIZE(array1), &value);
    UTILS_CHECK_RET(ret);
    LOG("the output value is %lld\n\n", value);

    ret = max_area(array2, ARRAY_SIZE(array2), &value);
    UTILS_CHECK_RET(ret);
    LOG("the output value is %lld\n\n", value);

    ret = max_area(array3, ARRAY_SIZE(array3), &value);
    UTILS_CHECK_RET(ret);
    LOG("the output value is %lld\n\n", value);

finish:
    return ret;
}