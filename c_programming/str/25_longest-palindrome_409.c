#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include "utils.h"

// abccccddeeffghii

static int32_t longest_palindrome(char *in_str, size_t *o_len)
{
    int32_t ret = 0;
    size_t i = 0, j = 0, in_len = 0;
    size_t count_no_repeat = 0;
    size_t count_repeat = 0;
    char *buffer = NULL;

    UTILS_CHECK_PTR(in_str);
    UTILS_CHECK_PTR(o_len);
    UTILS_CHECK_LEN(in_len = strlen(in_str));

    if (in_len == 1) {
        *o_len = 1;
        goto finish;
    }

    buffer = (char *)calloc(1, in_len);
    UTILS_CHECK_PTR(buffer);

    memcpy(buffer, in_str, in_len);
    // sort in_str
    ret = utils_sort_char_array(buffer, in_len, ORDER_BY_ASCEND);
    UTILS_CHECK_RET(ret);

    while (i < in_len) {
        if (buffer[i] != buffer[i + 1]) {
            count_no_repeat ++;
            i += 1;
        } else {
            count_repeat += 2;
            i += 2;
        }
    }
    if (count_no_repeat != 0) {
        count_repeat ++;
    }

    *o_len = count_repeat;
finish:
    if (buffer != NULL) {
        free(buffer);
    }
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;
    size_t result = 0;

    ret = longest_palindrome("abccccdd", &result);
    UTILS_CHECK_RET(ret);
    LOG("the result is %zu\n", result);

finish:
    return ret;
}
