#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "utils.h"

static int32_t contains_duplicate(int64_t *array, size_t sz, int64_t k, bool *result)
{
    int64_t i = 0, j = 0;;
    int32_t ret = 0;
    int64_t e = 0;

    UTILS_CHECK_LEN(sz);
    UTILS_CHECK_PTR(array);
    UTILS_CHECK_PTR(result);

    for (i = 0; i < sz; i ++) {
        e = array[i];
        for (j = i + 1; j < sz; j ++) {
            if ((e == array[j]) &&
                (utils_int64_abs(i - j)) <= k) {
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
    int64_t array1[] = {1,2,3,1};
    int64_t array2[] = {1,0,1,1};
    int64_t array3[] = {1,2,3,1,2,3};
    bool value = 0;

    ret = contains_duplicate(array1, ARRAY_SIZE(array1), 3, &value);
    UTILS_CHECK_RET(ret);
    LOG("the output value is %d\n\n", value);

    ret = contains_duplicate(array2, ARRAY_SIZE(array2), 1, &value);
    UTILS_CHECK_RET(ret);
    LOG("the output value is %d\n\n", value);

    ret = contains_duplicate(array3, ARRAY_SIZE(array3), 2, &value);
    UTILS_CHECK_RET(ret);
    LOG("the output value is %d\n\n", value);

finish:
    return ret;
}