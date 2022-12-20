#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include "utils.h"

static int32_t is_subsequence(char *str_a, char *str_b, bool *result)
{
    int32_t ret = 0;
    size_t len_a = 0, len_b = 0;

    UTILS_CHECK_PTR(str_a);
    UTILS_CHECK_PTR(str_b);
    UTILS_CHECK_PTR(result);
    UTILS_CHECK_LEN(len_a = strlen(str_a));
    UTILS_CHECK_LEN(len_b = strlen(str_b));

    while (*str_a && *str_b) {
        if (*str_a == *str_b) {
            str_a ++;
        }
        str_b ++;
    }

    *result = *str_a == 0;

finish:
    return ret;
}


int32_t main(void)
{
    int32_t ret = 0;
    size_t index = 0;
    char s[100];
    char b[100];
    bool e = 0;
    sprintf(s,"%s", "abc");
    sprintf(b,"%s", "ahbgdc");

    ret = is_subsequence(s, b, &e);
    UTILS_CHECK_RET(ret);
    LOG("input s = %s,  t = %s,  out is %d\n", s, b, e);
    LOG_LINE_WITH_DOUBLE_TR();

    sprintf(s,"%s", "axc");
    sprintf(b,"%s", "ahbgdc");

    ret = is_subsequence(s, b, &e);
    UTILS_CHECK_RET(ret);
    LOG("input s = %s,  t = %s,  out is %d\n", s, b, e);
    LOG_LINE_WITH_DOUBLE_TR();

finish:
    return ret;
}
