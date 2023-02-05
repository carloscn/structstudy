#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "utils.h"

static int32_t reverse_string_ii(char *str, int32_t k)
{
    int32_t ret = 0;
    size_t str_len = 0;
    size_t delta = ((size_t)k) * 2;
    size_t i = 0, j = 0;
    char *dup_str = NULL;

    UTILS_CHECK_PTR(str);
    UTILS_CHECK_LEN(str_len = strlen(str));

    if (k <= 0) {
        ret = -1;
        LOG("input error!\n");
        goto finish;
    }
    dup_str = strdup(str);
    UTILS_CHECK_PTR(dup_str);

    while (i <= str_len) {
        i += delta;
        // if the left chars is less than k, all of the left chars shall be reversed.
        if (str_len - i < k) {
            ret = utils_str_reverse(dup_str + i);
        }
        // if the left chars is less than delta and more than or equal to k.
        else  {
            ret = utils_str_reserve_region(dup_str, i - delta, i - delta + 1);
        }
        UTILS_CHECK_RET(ret);
    }
    strcpy(str, dup_str);

finish:
    if (dup_str != NULL) {
        free(dup_str);
    }
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;
    char str[100] = {0};

    sprintf(str, "abcdefg");
    reverse_string_ii(str, 2);
    UTILS_CHECK_RET(ret);
    LOG("the str is %s\n", str);

finish:
    return ret;
}