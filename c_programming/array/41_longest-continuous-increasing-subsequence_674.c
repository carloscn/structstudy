#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "utils.h"

static int32_t longest_continuous_seq(const int64_t *array, size_t *len)
{
    int32_t ret = 0;
    size_t i = 0;
    size_t count = 0;
    size_t max_count = 0;

    UTILS_CHECK_PTR(array);
    UTILS_CHECK_PTR(len);

    for (i = 1; i < *len; i ++) {
        if (array[i] > array[i - 1]) {
            count ++;
            max_count = (count > max_count) ? count : max_count;
        } else {
            count = 0;
        }
    }

    *len = max_count + 1;

finish:
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;
    int64_t array[] = {1,3,5,4,7};
    size_t len = ARRAY_SIZE(array);

    ret = longest_continuous_seq(array, &len);
    UTILS_CHECK_RET(ret);

    LOG("the max is %zu\n", len);

finish:
    return ret;
}