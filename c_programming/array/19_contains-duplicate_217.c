#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "utils.h"

static int32_t contains_duplicate(int64_t *array, size_t sz, bool *result)
{
    size_t i = 0, j = 0;;
    int32_t ret = 0;
    size_t set_len = 0;
    int64_t e = 0;

    UTILS_CHECK_PTR(array);
    UTILS_CHECK_PTR(result);

    if (0 == sz)
        goto finish;

    for (i = 0; i < sz; i ++) {
        e = array[i];
        for (j = i + 1; j < sz; j ++) {
            if (e == array[j]) {
                *result = true;
                goto finish;
            }
        }
    }

    *result = false;

finish:
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;
    int64_t array1[] = {1,2,3,4,5,6,8,9,10,11,12,13,0};
    int64_t array2[] = {2,5,2,5,7,2};
    int64_t array3[] = {8,8,9,7,7,8,9,9,9,9,9,9};
    bool value = 0;

    ret = contains_duplicate(array1, ARRAY_SIZE(array1), &value);
    UTILS_CHECK_RET(ret);
    LOG("the output value is %d\n\n", value);

    ret = contains_duplicate(array2, ARRAY_SIZE(array2), &value);
    UTILS_CHECK_RET(ret);
    LOG("the output value is %d\n\n", value);

    ret = contains_duplicate(array3, ARRAY_SIZE(array3), &value);
    UTILS_CHECK_RET(ret);
    LOG("the output value is %d\n\n", value);

finish:
    return ret;
}