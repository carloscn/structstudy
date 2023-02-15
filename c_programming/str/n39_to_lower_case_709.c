#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "utils.h"

static int32_t to_lower(char *str)
{
    int32_t ret = 0;
    size_t len = 0;

    UTILS_CHECK_PTR(str);
    UTILS_CHECK_LEN(len = strlen(str));

    do  {
        *str = utils_conv_lowercase(*str);
        str ++;
    } while (*str != '\0');

finish:
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;
    char str[1024] = {0};
    sprintf(str, "%s", "HellO!");
    ret = to_lower(str);
    UTILS_CHECK_RET(ret);

    LOG("the result is %s\n", str);

finish:
    return ret;
}