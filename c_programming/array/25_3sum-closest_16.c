#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "utils.h"

static inline int64_t sum_3(int64_t a, int64_t b, int64_t c)
{
    return a + b + c;
}

static int32_t closest_3sum(int64_t *array, size_t sz, int64_t target, int64_t *result)
{
    int32_t ret = 0;
    int64_t delta = 0;
    int64_t rlt = 0xffff;
    size_t i = 0, j = 0, k = 0;
    size_t pos[3] = {0};

    UTILS_CHECK_LEN(sz);
    UTILS_CHECK_PTR(array);
    UTILS_CHECK_PTR(result);

    for (i = 0; i < sz; i ++) {
        for (j = i + 1; j < sz; j ++) {
            for (k = j + 1; k < sz; k ++) {
                delta = utils_int64_abs(sum_3(array[i], array[j], array[k]) - target);
                if (delta < rlt) {
                    rlt = delta;
                    pos[0] = i, pos[1] = j, pos[2] = k;
                }
            }
        }
    }

    *result = sum_3(array[pos[0]], array[pos[1]], array[pos[2]]);

finish:
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;
    int64_t array1[] = {4,0,5,-5,3,3,0,-4,-5};
    int64_t result = 0;

    ret = closest_3sum(array1, ARRAY_SIZE(array1), -2, &result);
    UTILS_CHECK_RET(ret);
    LOG("the result is %lld\n", result);

finish:
    return ret;
}