#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "utils.h"

static int32_t detect_capital(const char* str, bool *result)
{
    int32_t ret = 0;
    size_t len = 0;
    size_t i = 0;
    size_t c_count = 0;
    size_t l_count = 0;

    UTILS_CHECK_PTR(str);
    UTILS_CHECK_PTR(result);
    UTILS_CHECK_LEN(len = strlen(str));

    for (i = 0; i < len; i ++) {
        if (utils_is_capital(str[i])) {
            c_count ++;
        } else if (utils_is_lowercase(str[i])) {
            l_count ++;
        }
    }

    if (c_count == len && l_count == 0) {
        *result = true;
        goto finish;
    }

    if (c_count == 0 && l_count == len) {
        *result = true;
        goto finish;
    }

    if (c_count == 1 &&
        l_count == len - 1 &&
        utils_is_capital(str[0])) {
        *result = true;
        goto finish;
    }

    *result = false;

finish:
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;
    bool res = false;
    char str[100];

    sprintf(str, "hello");
    ret = detect_capital(str, &res);
    UTILS_CHECK_RET(ret);
    LOG("the %s result is %d\n", str, res);

    sprintf(str, "Hello");
    ret = detect_capital(str, &res);
    UTILS_CHECK_RET(ret);
    LOG("the %s result is %d\n", str, res);

    sprintf(str, "heLLo");
    ret = detect_capital(str, &res);
    UTILS_CHECK_RET(ret);
    LOG("the %s result is %d\n", str, res);

    sprintf(str, "hellO");
    ret = detect_capital(str, &res);
    UTILS_CHECK_RET(ret);
    LOG("the %s result is %d\n", str, res);

    sprintf(str, "HELLO");
    ret = detect_capital(str, &res);
    UTILS_CHECK_RET(ret);
    LOG("the %s result is %d\n", str, res);
finish:
    return ret;
}