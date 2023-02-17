#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "utils.h"

// nums = [1, 7, 3, 6, 5, 6]
static int32_t find_pivot_index(int64_t *array, size_t len, size_t *povit)
{
    int32_t ret = 0;
    size_t i = 0;
    size_t j = len - 1;
    int64_t lsum = 0, rsum = 0;

    UTILS_CHECK_LEN(len);
    UTILS_CHECK_PTR(array);
    UTILS_CHECK_PTR(povit);

    lsum = array[i];
    rsum = array[j];
    do {
        if (lsum > rsum) {
            j --;
            rsum += array[j];
        } else if (lsum < rsum) {
            i ++;
            lsum += array[i];
        } else {
            *povit = i + 1;
            goto finish;
        }
    } while (i <= j);

    *povit = ~0;

finish:
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;
    int64_t array[] = {1, 7, 1, 3, 6, 5, 5, 2};
    size_t povit = 0;

    ret = find_pivot_index(array, ARRAY_SIZE(array), &povit);
    UTILS_CHECK_RET(ret);

    LOG("the povit is %zu\n", povit);

finish:
    return ret;
}