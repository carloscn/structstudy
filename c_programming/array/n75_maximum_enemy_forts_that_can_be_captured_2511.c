#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>
#include "utils.h"

static int32_t capture_forts(int64_t* forts, size_t forts_size)
{
    int32_t ret = 0;

    UTILS_CHECK_PTR(forts);
    UTILS_CHECK_LEN(forts_size);

    size_t zero_count = 0;
    size_t max_zero_count = 0;
    int32_t e1 = 0;

    for (size_t i = 0; i < forts_size; i ++) {
        if (forts[i] != 0) {
            e1 = forts[i];
        }
        if ((e1 != 0) && (forts[i] == 0)) {
            zero_count ++;
            max_zero_count = UTILS_MAX(zero_count, max_zero_count);
        }
        if ((e1 != 0) && (forts[i] != 0) && (-e1 != forts[i])) {
            zero_count = 0;
            e1 = forts[i];
        }
    }

    ret = max_zero_count;

    LOG("the ret is %d\n", ret);

finish:
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;
    int64_t array1[] = {1,0,0,-1,0,0,0,0,1};
    int64_t array2[] = {1,2,4,7,10};

    ret = capture_forts(array1, ARRAY_SIZE(array1));
    assert(ret == 4);

    ret = capture_forts(array2, ARRAY_SIZE(array2));
    assert(ret == 0);

    LOG("All tests have passed!\n");

finish:
    return ret;
}