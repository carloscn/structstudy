#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <math.h>
#include "utils.h"

static bool convert(char *str, int32_t num)
{
    bool ret = false;
    char *str_rom = NULL;
    if (NULL == str) {
        goto finish;
    }

    size_t len = strlen(str) - 1;
    str_rom = (char*) calloc(1, 2 * strlen(str) + 1);
    if (NULL == str_rom) {
        goto finish;
    }

    size_t i = 0, j = 0, last_pos = 0;
    for (i = 0; i < strlen(str); i ++) {
        str_rom[j ++] = str[i];
        if ((num >> (len - i - 1)) & 0x1 == 1) {
            str_rom[j] = '\0';
            if (atoi(str_rom + last_pos) > 26) {
                goto finish;
            }
            str_rom[j++] = ' ';
            last_pos = j;
        }
    }
    if (atoi(str_rom + last_pos) > 26) {
        goto finish;
    }

    ret = true;
finish:
    UTILS_SAFE_FREE(str_rom);
    return ret;
}

int32_t num_decode(char *s)
{
    int32_t ret = 0;
    size_t len = 0;

    UTILS_CHECK_PTR(s);
    UTILS_CHECK_LEN(len = strlen(s));

    while (*s == '0') {
        s ++;
    }
    len = strlen(s);

    int32_t i = 0;
    for (i = 0; i < pow(2, len - 1); i ++) {
        ret += (int32_t) convert(s, i);
    }

finish:
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;

    ret = num_decode("226");
    assert(ret == 3);

    ret = num_decode("12");
    assert(ret == 2);

    ret = num_decode("06");
    assert(ret == 1);

    LOG("test pass!\n");

finish:
    return ret;
}