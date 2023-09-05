#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <assert.h>
#include "utils.h"

int32_t are_number_ascending(const char *s, bool *result)
{
    int32_t ret = 0;
    size_t i = 0;
    size_t len = 0;
    int32_t last_num = -1;

    UTILS_CHECK_PTR(s);
    UTILS_CHECK_PTR(result);
    UTILS_CHECK_LEN(len = strlen(s));

    while (i < len) {
        if (isdigit(s[i])) {
            char temp[16] = {0};
            int32_t current_num = 0;
            size_t j = 0;
            while (s[i] != ' ' && i < len) {
                temp[j ++] = s[i ++];
            }
            temp[j] = '\0';
            current_num = atoi(temp);
            if (last_num < current_num) {
                last_num = current_num;
                continue;
            }
            *result = false;
            goto finish;
        }
        i ++;
    }

    *result = true;

finish:
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;
    char str[100] = {0};
    bool res = false;

    ret = are_number_ascending("1 box has 3 blue 4 red 6 green and 12 yellow marbles", &res);
    assert(ret == 0), assert(res == true);

    ret = are_number_ascending("hello world 5 x 5", &res);
    assert(ret == 0), assert(res == false);

    ret = are_number_ascending("sunset is at 7 51 pm overnight lows will be in the low 50 and 60 s", &res);
    assert(ret == 0), assert(res == false);

    LOG("All tests pass!");

finish:
    return ret;
}