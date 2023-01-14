#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "utils.h"

static int32_t find_disa_in_array(int64_t *array, size_t array_len)
{
    int32_t ret = 0;
    int64_t e = 0;
    size_t i = 0;

    UTILS_CHECK_PTR(array);
    UTILS_CHECK_LEN(array_len);

    ret = utils_sort_int64_array(array, array_len, ORDER_BY_ASCEND);
    UTILS_CHECK_RET(ret);

    e = array[0];
    for (i = 0; i < array_len; i ++, e ++) {
        if (e != array[i]) {
            LOG("miss %lld\n", e);
            i --;
        }
    }

finish:
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;
    int64_t array1[] = {9,4,7,5,1};
    int64_t result = 0;

    ret = find_disa_in_array(array1, ARRAY_SIZE(array1));
    UTILS_CHECK_RET(ret);
    LOG("the result is %lld\n", result);

finish:
    return ret;
}