#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>
#include <assert.h>
#include "utils.h"

static int32_t repeated_character(char *s, char *out)
{
    int32_t ret = 0;
    size_t len;

    UTILS_CHECK_PTR(s);
    UTILS_CHECK_PTR(out);
    UTILS_CHECK_LEN(len = strlen(s));

    for (size_t i = 0; i < len - 1; i ++) {
        if (s[i] == s[i + 1]) {
            *out = s[i];
            goto finish;
        }
    }

finish:
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;
    char out;

    ret = repeated_character("abccbaacz", &out);
    assert(ret == 0), assert(out == 'c');

    ret = repeated_character("abcdd", &out);
    assert(ret == 0), assert(out == 'd');

    LOG("All tests pass!");

finish:
    return ret;
}
