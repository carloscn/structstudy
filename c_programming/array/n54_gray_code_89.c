#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "utils.h"

static inline void bit_reverse(char *ch) {
    *ch = (*ch == '0') ? '1' : '0';
}

static size_t bits_2_unsigned(char *str)
{
    size_t i = 0;
    size_t result = 0;

    while (str[i] != '\0') {
        result = result * 2 + (str[i] - '0');
        i ++;
    }

    return result;
}

int32_t gray_code(size_t n, size_t *array, size_t *o_len)
{
    int32_t ret = 0;
    char *s_buf = NULL;

    UTILS_CHECK_PTR(array);
    UTILS_CHECK_PTR(o_len);

    size_t i = 0;
    size_t len = 1;

    for (i = 0; i < n; i ++) {
        len *= 2;
    }
    len ++;

    s_buf = malloc(len);
    UTILS_CHECK_PTR(s_buf);

    s_buf[len] = '\0';
    memset(s_buf, '0', len);

    for (i = 0; i < len - 1; i ++) {
        if (i & 1) {
            bit_reverse(s_buf + len - 1);
        } else {
            for (size_t j = len - 1; j > 0; j --) {
                if (s_buf[j] == '1') {
                    bit_reverse(s_buf + j - 1);
                    break;
                }
            }
        }
        array[i] = bits_2_unsigned(s_buf);
    }

    *o_len = len - 1;

finish:
    UTILS_SAFE_FREE(s_buf);
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;

    size_t array[1024];
    size_t len = 0;

    ret = gray_code(2, array, &len);
    UTILS_CHECK_RET(ret);

    utils_print_size_t_array(array, len, "out: ");

finish:
    return ret;
}