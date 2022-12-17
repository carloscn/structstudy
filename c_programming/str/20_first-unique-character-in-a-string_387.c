#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "utils.h"

static int32_t first_char(char *str, size_t *index)
{
    char e = 0;
    size_t i = 0;
    size_t j = 0;
    size_t len = 0;
    int32_t ret = 0;

    UTILS_CHECK_PTR(str);
    UTILS_CHECK_PTR(index);
    UTILS_CHECK_LEN(len = strlen(str));

    *index = 0xffff;

    for (i = 0; i < len; i ++) {
        e = str[i];
        for (j = 0; j < len; j ++) {
            if (e == str[j] && i != j) {
                break;
            }
        }
        if (j == len) {
            *index = i;
            break;
        }
    }

finish:
    return ret;
}


int32_t main(void)
{
    int32_t ret = 0;
    size_t index = 0;
    char s[100];
    char b[100];

    sprintf(s,"%s", "leetcode");
    sprintf(b,"%s", "loveleetcode");
    ret = first_char(s, &index);
    UTILS_CHECK_RET(ret);
    LOG("out is %zu\n", index);
    LOG_LINE_WITH_DOUBLE_TR();

    ret = first_char(b, &index);
    UTILS_CHECK_RET(ret);
    LOG("out is %zu\n", index);
    LOG_LINE_WITH_DOUBLE_TR();

finish:
    return ret;
}
