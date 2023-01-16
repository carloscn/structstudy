#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "utils.h"

static int32_t repeat_sub_pattern(char *input_str, bool *result)
{
    int32_t ret = 0;
    size_t str_len = 0;
    char *sub = NULL;

    UTILS_CHECK_PTR(input_str);
    UTILS_CHECK_PTR(result);
    UTILS_CHECK_LEN(str_len = strlen(input_str));

    sub = (char*) malloc(2 * str_len - 1);
    UTILS_CHECK_PTR(sub);

    memset(sub, '\0', 2 * str_len - 1);
    strncat(sub, input_str + 1, str_len - 1);
    LOG("the sub is %s\n", sub);
    strncat(sub, input_str, str_len - 1);
    LOG("the sub is %s\n", sub);

    *result = strstr(sub, input_str);
    LOG("the compare sub is %s and input %s\n", sub, input_str);

finish:
    if (sub != NULL) {
        free(sub);
    }
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;
    char str1[100];
    bool out = 0;

    sprintf(str1, "%s", "abcdefabcdefabcdef");
    ret = repeat_sub_pattern(str1, &out);
    UTILS_CHECK_RET(ret);

    LOG("the %s out is %d\n", str1, out);

finish:
    return ret;
}
