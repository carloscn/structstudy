#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "utils.h"

static int32_t reverse_str(char *str)
{
    int32_t ret = 0;
    size_t len = 0;
    size_t i = 0;

    UTILS_CHECK_PTR(str);
    UTILS_CHECK_LEN(len = strlen(str));

    for (i = 0; i < len / 2; i ++) {
        utils_swap_char(&(str[i]), &(str[len - i - 1]));
    }

finish:
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;
    char s[100];

    sprintf(s,"%s", "hello this is carlos\n");
    ret = reverse_str(s);
    UTILS_CHECK_RET(ret);
    LOG("out is %s\n", s);
    LOG_LINE_WITH_DOUBLE_TR();

finish:
    return ret;
}
