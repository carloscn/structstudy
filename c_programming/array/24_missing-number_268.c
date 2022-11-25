#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "utils.h"

static int32_t miss_number(const int64_t *input,
                           size_t in_len,
                           int64_t *out)
{
    int32_t ret = 0;
    int64_t i = 0;
    int64_t sum_1 = 0;
    int64_t sum_2 = 0;

    UTILS_CHECK_LEN(in_len);
    UTILS_CHECK_PTR(input);
    UTILS_CHECK_PTR(out);

    for (i = 1; i < in_len + 1; i ++) {
        sum_1 += i;
        sum_2 += input[i - 1];
    }

    *out = sum_1 - sum_2;

finish:
    return ret;
}

// 1^1^2^2^3 = 3
static int32_t miss_number_by_xor(const int64_t *input,
                                  size_t in_len,
                                  int64_t *out)
{
    int32_t ret = 0;

    UTILS_CHECK_LEN(in_len);
    UTILS_CHECK_PTR(input);
    UTILS_CHECK_PTR(out);

    *out = in_len;
    while (-- in_len)
        *out ^= input[in_len] ^ in_len;

finish:
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;
    int64_t array1[] = {0,1,3,4,5,6,7,2,9,10};
    int64_t result = 0;

    ret = miss_number(array1, ARRAY_SIZE(array1), &result);
    UTILS_CHECK_RET(ret);
    LOG("the result is %lld\n", result);

    ret = miss_number_by_xor(array1, ARRAY_SIZE(array1), &result);
    UTILS_CHECK_RET(ret);
    LOG("the result is %lld\n", result);

finish:
    return ret;
}