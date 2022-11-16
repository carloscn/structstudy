#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "utils.h"


static int32_t get_index(char *rom, char c, int32_t count)
{
    int32_t i = 0;

    for (i = 1; i < count; i ++) {
        if (c == rom[i]) {
            return i;
        }
    }
    return -1;
}

static int32_t isomo_convert(const char *str)
{
    int32_t ret = 0, sum = 0;
    int32_t count = 1;
    size_t i = 0, len = 0;
    char rom[26] = {0};

    len = strlen(str);
    for (i = 0; i < len; i ++) {
        sum = sum * 10;
        ret = get_index(rom, str[i], count);
        if (ret == -1) {
            rom[count++] = str[i];
            sum += count;
        } else {
            sum += ret;
        }
    }

    return sum;
}

static int32_t isomo_str(const char *str1, const char *str2, bool *result)
{
    int32_t ret = 0, a = 0, b = 0;
    size_t str_len_1 = 0, str_len_2 = 0;

    UTILS_CHECK_PTR(str1);
    UTILS_CHECK_PTR(str2);

    str_len_1 = strlen(str1);
    str_len_2 = strlen(str2);

    if (str_len_1 != str_len_2) {
        *result = false;
        ret = -1;
        goto finish;
    }

    if (0 == str_len_1) {
        *result = true;
        goto finish;
    }

    a = isomo_convert(str1);
    b = isomo_convert(str2);

    *result = a == b;

finish:
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;
    bool val = 0;

    ret = isomo_str("eggeeemm", "addaaamm", &val);
    UTILS_CHECK_RET(ret);
    LOG("the val is %d\n", val);

    ret = isomo_str("foo", "bar", &val);
    UTILS_CHECK_RET(ret);
    LOG("the val is %d\n", val);

    ret = isomo_str("paper", "title", &val);
    UTILS_CHECK_RET(ret);
    LOG("the val is %d\n", val);


finish:
    return ret;
}