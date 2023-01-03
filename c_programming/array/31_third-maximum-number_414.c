#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "utils.h"

static int32_t third_max_num(int64_t *array, size_t sz, int64_t *out)
{
    int32_t ret = 0;
    size_t i = 0;
    size_t count = 0;
    int64_t max = -0x7FFFFFFFFFFFFFFF;

    UTILS_CHECK_PTR(array);
    UTILS_CHECK_PTR(out);
    UTILS_CHECK_LEN(sz);

    sz = utils_set_array(array, sz);
    ret = utils_sort_int64_array(array, sz, ORDER_BY_ASCEND);
    UTILS_CHECK_RET(ret);

    switch(sz) {
        case 0:
        case 1:
        ret = -1;
        goto finish;

        case 2:
        *out = array[1];
        goto finish;

        default:
        *out = array[2];
        goto finish;
    }

finish:
    return ret;
}


int32_t main(void)
{
    int32_t ret = 0;
    int64_t array1[] = {-8,-8,1,0,4,5,6};
    int64_t array2[] = {1,2,3,4,5,6,7,8,9,1,1,10,11,12,13};
    int64_t result = 0;

    ret = third_max_num(array1, ARRAY_SIZE(array1), &result);
    UTILS_CHECK_RET(ret);
    LOG("the result is %lld\n", result);

    ret = third_max_num(array2, ARRAY_SIZE(array2), &result);
    UTILS_CHECK_RET(ret);
    LOG("the result is %lld\n", result);

finish:
    return ret;
}