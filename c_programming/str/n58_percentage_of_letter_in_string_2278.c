#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>
#include <assert.h>
#include "utils.h"

static int32_t percentage_letter(const char *s, char letter)
{
    int32_t ret = -1;
    size_t len;

    UTILS_CHECK_PTR(s);
    UTILS_CHECK_LEN(len = strlen(s));

    int32_t count = 0;
    for (size_t i = 0; i < len; i ++) {
        if (s[i] == letter) {
            count ++;
        }
    }

    ret = count * 100 / len;

finish:
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;

    ret = percentage_letter("foobar", 'o');
    assert(ret == 33);

    ret = percentage_letter("jjjj", 'k');
    assert(ret == 0);

    LOG("All tests pass!");

finish:
    return ret;
}
