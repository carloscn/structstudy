#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include "utils.h"

#define C_OF(__c) ((int32_t)((__c) - '0'))
#define U_OF(__c) ((char)((__c) + '0'))

static int32_t add_binary(const char *str1,
                          const char *str2,
                          char **out_srt)
{
    int32_t ret = 0;
    int32_t str1_len = 0;
    int32_t str2_len = 0;
    int32_t max_len = 0;
    int32_t i = 0;
    int32_t a = 0, b = 0, c = 0, d = 0;

    UTILS_CHECK_PTR(str1);
    UTILS_CHECK_PTR(str2);
    UTILS_CHECK_PTR(out_srt);

    str1_len = strlen(str1);
    str2_len = strlen(str2);
    max_len = (str1_len > str2_len) ? str1_len : str2_len;

    *out_srt = (char*)calloc(1, max_len + 2);
    UTILS_CHECK_PTR(*out_srt);

    while (max_len --) {
        a = (i < str1_len) ? C_OF(*(str1 + str1_len - i - 1)) : 0;
        b = (i < str2_len) ? C_OF(*(str2 + str2_len - i - 1)) : 0;
        d = (a + b + c) & 1;            // equal to x % 2
        c = (a + b + c) >> 1;           // equal to x / 2
        *(*out_srt + max_len) = U_OF(d);
        i ++;
    }

    if (c) {
        memmove(*out_srt + 1, *out_srt, i + 1);
        **out_srt = U_OF(c);
    }

finish:
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;
    int32_t val = 0;
    char *str = NULL;
    bool result = false;
    size_t i = 0;

    char *str1 = "10110";
    char *str2 =   "010";
    char *str3 = "111111111";
    char *str4 = "000000001";
    char *str5 = "1";
    char *str6 = "1";
    char *str7 = "10101010101010";
    char *str8 =           "0101";
    char *out_str1 = NULL;
    size_t out_str_len = 0;

    ret = add_binary(str1, str2, &out_str1);
    UTILS_CHECK_RET(ret);
    LOG("the result is %s\n", out_str1);
    free(out_str1);
    out_str1 = NULL;
    printf("\n");

    ret = add_binary(str3, str4, &out_str1);
    UTILS_CHECK_RET(ret);
    LOG("the result is %s\n", out_str1);
    free(out_str1);
    out_str1 = NULL;
    printf("\n");

    ret = add_binary(str5, str6, &out_str1);
    UTILS_CHECK_RET(ret);
    LOG("the result is %s\n", out_str1);
    free(out_str1);
    out_str1 = NULL;
    printf("\n");

    ret = add_binary(str7, str8, &out_str1);
    UTILS_CHECK_RET(ret);
    LOG("the result is %s\n", out_str1);
    free(out_str1);
    out_str1 = NULL;
    printf("\n");


finish:
    return ret;
}