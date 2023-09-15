#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <assert.h>
#include "utils.h"

int32_t divide_string(const char *s, int32_t k, char fill, char *o_list[], size_t *o_len)
{
    int32_t ret = 0;
    size_t in_len = 0;

    UTILS_CHECK_PTR(s);
    UTILS_CHECK_PTR(o_list);
    UTILS_CHECK_PTR(o_len);
    UTILS_CHECK_LEN(in_len = strlen(s));
    UTILS_CHECK_LEN(k);

    size_t j = 0;
    char *new_str = NULL;
    for (size_t i = 0; i < in_len; i ++) {
        if (i % k == 0) {
            UTILS_CHECK_PTR(new_str = (char *)calloc(k + 1, sizeof(char)));
            for (size_t m = 0; m < k; m ++) {
                new_str[m] =  (i + m < in_len) ? s[i + m] : fill;
            }
            o_list[j ++] = new_str;
        }
    }

    *o_len = j;

finish:
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;
    char str[100] = {0};
    char *input[100] = {NULL};
    size_t o_len = 0;

    ret = divide_string("abcdefghij", 3, 'x', input, &o_len);
    assert(ret == 0);
    for (size_t i = 0; i < o_len; i ++) {
        LOG("the result is %zu : %s\n", i, input[i]);
        UTILS_SAFE_FREE(input[i]);
    }

    ret = divide_string("abcdefghi", 3, 'x', input, &o_len);
    assert(ret == 0);
    for (size_t i = 0; i < o_len; i ++) {
        LOG("the result is %zu : %s\n", i, input[i]);
        UTILS_SAFE_FREE(input[i]);
    }

    LOG("All tests pass!");

finish:
    return ret;
}
