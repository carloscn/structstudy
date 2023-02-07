#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "utils.h"

static int32_t mis_set(int64_t *array, size_t *len)
{
    int32_t ret = 0;
    size_t i = 0;
    size_t count = 0;

    UTILS_CHECK_PTR(array);
    UTILS_CHECK_PTR(len);
    UTILS_CHECK_LEN(*len);

    for (i = 0; i < *len; i ++) {
        if (array[i] != (i + 1)) {
            array[count++] = array[i];
            array[count++] = i + 1;
        }
    }

    *len = count;

finish:
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;
    int64_t array[] = {1,2,2,4};
    size_t len = ARRAY_SIZE(array);

    ret = mis_set(array, &len);
    UTILS_CHECK_RET(ret);

    utils_print_int64_array(array, len, "output : ");

finish:
    return ret;
}