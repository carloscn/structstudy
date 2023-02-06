#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "utils.h"


static int64_t sum(int64_t *array, size_t sz)
{
    int64_t sum = 0;
    size_t i = 0;

    for (i = 0; i < sz; i ++) {
        sum += array[i];
    }

    return sum;
}

static int32_t max_average(int64_t *array, size_t sz, size_t k, int64_t *average_out)
{
    int32_t ret = 0;
    int64_t ave = 0;
    int64_t max_average = 0;
    size_t i = 0, j = 0;

    UTILS_CHECK_PTR(array);
    UTILS_CHECK_LEN(sz);
    UTILS_CHECK_LEN(k);
    UTILS_CHECK_PTR(average_out);

    for (i = 0; i < sz - k; i ++) {
        ave = sum(array + i, k);
        max_average = (ave > max_average) ? ave : max_average;
    }

    *average_out = max_average / k;

finish:
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;
    int64_t max_ave = 0;
    int64_t array[] = {1,12,-5,-6,50,3};

    ret = max_average(array, ARRAY_SIZE(array), 4, &max_ave);
    UTILS_CHECK_RET(ret);
    LOG("the number is %lld\n", max_ave);

finish:
    return ret;
}