#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>
#include "utils.h"

static int32_t digit_count(const char *num, bool *result)
{
    int32_t ret = 0;
    size_t len;

    UTILS_CHECK_PTR(num);
    UTILS_CHECK_PTR(result);
    UTILS_CHECK_LEN(len = strlen(num));

    int32_t bucket[11] = {0};

    for (size_t i = 0; i < len; i ++) {
        bucket[(size_t)(num[i] - '0')] ++;
    }

    for (size_t i = 0; i < len; i ++) {
        if ((int32_t)(num[i] - '0') != bucket[i]) {
            *result = false;
            goto finish;
        }
    }

    *result = true;

finish:
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;
    bool result = false;

    ret = digit_count("1210", &result);
    assert(ret == 0), assert(result == true);

    ret = digit_count("030", &result);
    assert(ret == 0), assert(result == false);

    LOG("All tests have passed!\n");

finish:
    return ret;
}