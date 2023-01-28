#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include "utils.h"

static int32_t next_greater_element(int32_t *array_1,
                                    size_t *array_1_sz,
                                    const int32_t *array_2,
                                    size_t array_2_sz)
{
    int32_t ret = 0;
    size_t i = 0, j = 0;
    int32_t max = 0;
    int32_t target_val = 0;
    size_t count = 0;

    UTILS_CHECK_PTR(array_1);
    UTILS_CHECK_PTR(array_2);
    UTILS_CHECK_LEN(*array_1_sz);
    UTILS_CHECK_LEN(array_2_sz);

    for (i = 0; i < *array_1_sz; i ++) {
        target_val = array_1[i];
        for (j = 0; j < array_2_sz; j ++) {
            if (target_val == array_2[j]) {
                if ((j < array_2_sz - 1) && (array_2[j + 1] > target_val)) {
                    array_1[count] = array_2[j + 1];
                } else {
                    array_1[count] = -1;
                }
                count ++;
            }
        }
    }

    *array_1_sz = count;

finish:
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;
    int32_t array_1[] = {2,4};
    int32_t array_2[] = {1,2,3,4};
    size_t sz = 0;

    sz = ARRAY_SIZE(array_1);
    ret = next_greater_element(array_1, &sz, array_2, ARRAY_SIZE(array_2));
    UTILS_CHECK_RET(ret);

    utils_print_int32_array(array_1, sz, "the output: ");

finish:
    return ret;
}