#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "utils.h"

static int32_t find_letter(const char *str, char target, char *out)
{
    int32_t ret = 0;
    size_t len = 0;
    size_t left = 0, right = 0, pivot = 0;
    bool condition = true;

    UTILS_CHECK_PTR(str);
    UTILS_CHECK_PTR(out);
    UTILS_CHECK_LEN(len = strlen(str));

    left = 0;
    right = len - 1;

    while (left <= right) {
        pivot = left + (right - left) / 2;
        if (target < str[pivot]) {
            right = pivot - 1;
        } else {
            left = pivot + 1;
        }
    }
    LOG("the left is %zu, right is %zu, len is %zu\n", left, right, len);
    *out = str[left % len];

finish:
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;
    char o = 0;
    ret = find_letter("abdefghijklmnopqrst", 't', &o);
    UTILS_CHECK_RET(ret);

    LOG("the output is %c\n", o);

finish:
    return ret;
}