#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include "utils.h"


static int32_t get_parentheses_mapping(char c)
{
    switch(c) {
        case '(': return -1;
        case ')': return 1;
        case '{': return -10;
        case '}': return 10;
        case '[': return -100;
        case ']': return 100;
        default: return 1000;
    }
}

static int32_t valid_parentheses(const char *str, bool *result)
{
    int32_t ret = 0;
    int32_t i = 0, j = 0;
    size_t str_len = 0;
    int32_t val = 0;
    int32_t sum = 0;

    UTILS_CHECK_PTR(str);
    UTILS_CHECK_PTR(result);

    str_len = strlen(str);
    if (!str_len) {
        *result = true;
        goto finish;
    }

    for (i = str_len - 1; i > -1; i --) {
        val = get_parentheses_mapping(str[i]);
        if ((val < 0) &&
            ((sum / utils_int32_abs(val)) % 10 == 0)) {
            LOG("cannot find a parenthese is matched, failed on '%c' ,index=%d \n", str[i], i);
            goto end;
        }
        sum += val;
    }

end:
    *result = (sum == 0);
finish:
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;
    int32_t val = 0;
    char *str = NULL;
    bool result = false;

    char *str1 = "()[]{}";
    char *str2 = "([]){}";
    char *str3 = "[)({]}";
    char *str4 = "))){]}";
    char *str5 = "((({](";

    ret = valid_parentheses(str1, &result);
    UTILS_CHECK_RET(ret);
    LOG("the result is %d\n", result);

    ret = valid_parentheses(str2, &result);
    UTILS_CHECK_RET(ret);
    LOG("the result is %d\n", result);

    ret = valid_parentheses(str3, &result);
    UTILS_CHECK_RET(ret);
    LOG("the result is %d\n", result);

    ret = valid_parentheses(str4, &result);
    UTILS_CHECK_RET(ret);
    LOG("the result is %d\n", result);

    ret = valid_parentheses(str5, &result);
    UTILS_CHECK_RET(ret);
    LOG("the result is %d\n", result);
finish:

    return ret;
}