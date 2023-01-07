#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include "utils.h"
#include "strlist.h"

/*
case 1:
   11111
      19

case 2:
   11
   11

case 3:
   99
   99

case 4:
   1111
     99
*/
#define CHAR_TO_INT(__x) ((size_t)((__x) - '0'))
#define INT_TO_CHAR(__x) ((char)((__x) + '0'))

static int32_t str_add(char *str1, char *str2, char *str_out)
{
    int32_t ret = 0;
    size_t str1_len, str2_len, out_len;
    size_t min_len = 0, max_len = 0;
    size_t i = 0;
    size_t carry = 0;
    size_t val = 0;
    char *max_str = NULL, *min_str = NULL;

    UTILS_CHECK_PTR(str1);
    UTILS_CHECK_PTR(str2);
    UTILS_CHECK_PTR(str_out);

    UTILS_CHECK_LEN(str1_len = strlen(str1));
    UTILS_CHECK_LEN(str2_len = strlen(str2));

    if (str1_len > str2_len) {
        max_len = str1_len;
        min_len = str2_len;
        max_str = str1;
        min_str = str2;
    } else {
        max_len = str2_len;
        min_len = str1_len;
        max_str = str2;
        min_str = str1;
    }

    memset(str_out, 0, max_len + 1);

    for (i = 0; i < max_len; i ++) {
        val = (i >= min_len) ? (CHAR_TO_INT(max_str[max_len - i - 1]) + carry) :
                               (CHAR_TO_INT(max_str[max_len - i - 1]) + \
                                CHAR_TO_INT(min_str[min_len - i - 1]) + carry);
        carry = val / 10, val %= 10;
        str_out[i] = INT_TO_CHAR(val);
    }
    str_out[i] = (carry == 0) ? 0 : INT_TO_CHAR(carry);

    out_len = strlen(str_out);
    for (i = 0; i < out_len / 2; i ++) {
        utils_swap_char(str_out + i, str_out + out_len - i - 1);
    }

finish:
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;
    char str1[100];
    char str2[100];
    char str3[100];

    sprintf(str1, "%s", "19999");
    sprintf(str2, "%s", "9999");

    ret = str_add(str1, str2, str3);
    UTILS_CHECK_RET(ret);

    LOG("the %s + %s out is %s\n", str1, str2, str3);

finish:
    return ret;
}
