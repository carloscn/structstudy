#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>
#include "utils.h"

static int32_t max_div_score(int32_t *nums, size_t nums_size, int32_t *divisors, size_t divisors_size)
{
    int32_t ret = 0;

    UTILS_CHECK_PTR(nums);
    UTILS_CHECK_PTR(divisors);
    UTILS_CHECK_LEN(nums_size);
    UTILS_CHECK_LEN(divisors_size);

    int32_t max_score = INT32_MIN;
    int32_t min_div = INT32_MAX;
    for (size_t i = 0; i < divisors_size; i ++) {
        int32_t score = 0;
        int32_t e = divisors[i];
        for (size_t j = 0; j < nums_size; j ++) {
            if (!(nums[j] % e)) {
                score ++;
            }
        }
        if (score > max_score) {
            max_score = score;
            min_div = e;
        } else if (score == max_score) {
            min_div = UTILS_MIN(min_div, e);
        }
    }

    ret = min_div;

finish:
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;
    int32_t array1[] = {4,7,9,3,9};
    int32_t array2[] = {5,2,3};
    int32_t array3[] = {20,14,21,10};
    int32_t array4[] = {5,7,5};
    int32_t array5[] = {12};
    int32_t array6[] = {10,16};

    ret = max_div_score(array1, ARRAY_SIZE(array1), array2, ARRAY_SIZE(array2));
    assert(ret == 3);

    ret = max_div_score(array3, ARRAY_SIZE(array3), array4, ARRAY_SIZE(array4));
    assert(ret == 5);

    ret = max_div_score(array5, ARRAY_SIZE(array5), array6, ARRAY_SIZE(array6));
    assert(ret == 10);

    LOG("All tests have passed!\n");

finish:
    return ret;
}

// gcc -I./utils/ ./utils/utils.c ./array/n80_find_the_maximum_divisibility_score_2644.c && ./a.exe