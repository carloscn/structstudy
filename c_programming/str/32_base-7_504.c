#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "utils.h"


static char *convert_to_base7(int32_t num)
{
    int32_t ret = 0;
    char *str = NULL, *str_head = NULL;

    str = (char *)calloc(1, 50);
    UTILS_CHECK_PTR(str);
    str_head = str;

    if (num < 0) {
        ret = utils_int32_abs(num);
    } else {
        ret = num;
    }

    while (ret != 0) {
        *(str ++) = ret % 7 + '0';
        ret /= 7;
    }

    if (num < 0) {
        *(str ++) = '-';
    }

    utils_str_reverse(str_head);

finish:
    return str_head;
}

int32_t main(void)
{
    int32_t ret = 0;
    char *str = NULL;

    str = convert_to_base7(-7);
    UTILS_CHECK_PTR(str);

    LOG("the result is : %s\n", str);

finish:
    if (str != NULL)
        free(str);
    return ret;
}
