#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "utils.h"

static inline bool is_char(uint32_t val)
{
    if ((val >= 'a' && val <= 'z') ||
        (val >= 'A' && val <= 'Z')) {
        return true;
    }
    return false;
}

static int32_t number_of_word(char *str, size_t *out)
{
    int32_t ret = 0;
    size_t str_len = 0;
    size_t i = 0;
    size_t i_count = 0;
    size_t n_count = 0;

    UTILS_CHECK_PTR(str);
    UTILS_CHECK_PTR(out);
    UTILS_CHECK_LEN(str_len = strlen(str));

    for (i = 0; i < str_len; i ++) {
        if (is_char((uint32_t)str[i])) {
            i_count ++;
        } else {
            n_count = (i_count == 0) ?
                      (n_count):
                      (i_count = 0, n_count + 1);
        }
    }
    *out = (i_count != 0) ? (n_count + 1) : (n_count);

finish:
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;
    char str1[100];
    size_t out = 0;

    sprintf(str1, "%s", "Hello, my name is John!!!!");
    ret = number_of_word(str1, &out);
    UTILS_CHECK_RET(ret);

    LOG("the %s out is %zu\n", str1, out);

finish:
    return ret;
}
