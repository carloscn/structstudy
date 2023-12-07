#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>
#include <assert.h>
#include "utils.h"

static int32_t min_length(const char *s)
{
    int32_t ret = 0;
    size_t len;
    char *su = NULL;

    UTILS_CHECK_PTR(s);
    UTILS_CHECK_LEN(len = strlen(s));

    su = (char *)malloc(len + 1);
    UTILS_CHECK_PTR(su);

    strcpy(su, s);
    bool flag = false;
    do {
        size_t i = 0;
        while (i < (len - 1)) {
            if (((su[i] == 'A') && (su[i + 1] == 'B')) ||
                ((su[i] == 'C') && (su[i + 1] == 'D'))) {
                memmove(su + i, su + i + 2, len - i - 2);
                su[len - 2] = '\0';
                flag = true;
                break;
            }
            i ++;
        }
        len = strlen(su);
        ret = (int32_t)len;
    } while (len > 2 && flag == true);

finish:
    UTILS_SAFE_FREE(su);
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;
    const char *in1 = "ABFCACDB";
    const char *in2 = "ACBBD";

    ret = min_length(in1);
    assert(ret == 2);

    ret = min_length(in2);
    assert(ret == 5);

    LOG("All tests pass!");

finish:
    return ret;
}

// gcc -I./utils/ ./utils/utils.c ./str/n65_minimum_string_length_after_removing_substrings_2696.c && ./a.exe