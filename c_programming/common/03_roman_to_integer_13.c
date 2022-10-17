#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "utils.h"

static int32_t get_roman_mapping(char c)
{
    switch(c) {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        default:
            return 0;
    }
}

static int32_t roman_2_integer(const char *roman, int32_t *out)
{
    int32_t ret = 0;
    size_t in_str_len = 0;
    size_t i = 0;
    int32_t val = 0;

    UTILS_CHECK_PTR(roman);
    UTILS_CHECK_PTR(out);

    in_str_len = strlen(roman);
    if (in_str_len == 0) {
        *out = 0;
        goto finish;
    }

    val = get_roman_mapping(roman[in_str_len - 1]);
    for (i = in_str_len - 1; i > 0; i --) {
        if (get_roman_mapping(roman[i - 1]) < get_roman_mapping(roman[i])) {
            val -= get_roman_mapping(roman[i - 1]);
        } else {
            val += get_roman_mapping(roman[i - 1]);
        }
    }
    *out = val;

finish:
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;
    int32_t val = 0;
    char str[] = "0000000000000000000000000000";

    strcpy(str, "III");
    ret = roman_2_integer(str, &val);
    UTILS_CHECK_RET(ret);
    LOG("%s covert is %d\n", str, val);

    strcpy(str, "IV");
    ret = roman_2_integer(str, &val);
    UTILS_CHECK_RET(ret);
    LOG("%s covert is %d\n", str, val);

    strcpy(str, "IX");
    ret = roman_2_integer(str, &val);
    UTILS_CHECK_RET(ret);
    LOG("%s covert is %d\n", str, val);

    strcpy(str, "LVIII");
    ret = roman_2_integer(str, &val);
    UTILS_CHECK_RET(ret);
    LOG("%s covert is %d\n", str, val);

    strcpy(str, "MCMXCIV");
    ret = roman_2_integer(str, &val);
    UTILS_CHECK_RET(ret);
    LOG("%s covert is %d\n", str, val);

finish:
    return ret;
}