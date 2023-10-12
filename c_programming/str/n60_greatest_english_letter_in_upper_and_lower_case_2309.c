#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>
#include <assert.h>
#include "utils.h"

static int32_t greatest_letter(char *s)
{
    int32_t ret = 0;
    size_t len;

    UTILS_CHECK_PTR(s);
    UTILS_CHECK_LEN(len = strlen(s));
    char max = '\0';
    for (size_t i = 0; i < len; i ++) {
        char e = s[i];
        int8_t f = isupper(e)? 1: -1;
        for (size_t j = i + 1; j < len; j ++) {
            char m = s[j];
            if ((int8_t)m == ((int8_t)32 * f + (int8_t)e)) {
                char M = utils_conv_uppercase(m);
                max = max > M ? max : M;
            }
        }
    }

    s[0] = max;
    s[1] = '\0';

finish:
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;
    char str[1024] = {0};

    strcpy(str, "lEeTcOdE");
    ret = greatest_letter(str);
    assert(ret == 0), assert(strlen(str) == 1), assert(str[0] == 'E');

    strcpy(str, "arRAzFif");
    ret = greatest_letter(str);
    assert(ret == 0), assert(strlen(str) == 1), assert(str[0] == 'R');

    strcpy(str, "AbCdEfGhIjK");
    ret = greatest_letter(str);
    assert(ret == 0), assert(strlen(str) == 0), assert(str[0] == '\0');

    LOG("All tests pass!");

finish:
    return ret;
}
