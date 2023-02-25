#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "utils.h"

static int32_t is_totate_string(const char *str_a, const char *str_b, bool *result)
{
    int32_t ret = 0;
    size_t a_len, b_len;
    char *joint_str = NULL;

    UTILS_CHECK_PTR(str_a);
    UTILS_CHECK_PTR(str_b);
    UTILS_CHECK_PTR(result);
    UTILS_CHECK_LEN(a_len = strlen(str_a));
    UTILS_CHECK_LEN(b_len = strlen(str_b));
    
    joint_str = (char *)calloc(sizeof(char), a_len + a_len + 1);
    UTILS_CHECK_PTR(joint_str);
    
    strcat(joint_str, str_a);
    strcat(joint_str, str_a);

    *result = strstr(joint_str, str_b) != NULL;
    
finish:
    UTILS_SAFE_FREE(joint_str);
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;
    bool result = 0;
    ret = is_totate_string("abcde", "cdeab", &result);
    UTILS_CHECK_RET(ret);

    LOG("the result is %d\n", result);

    ret = is_totate_string("abcde", "cwdeab", &result);
    UTILS_CHECK_RET(ret);

    LOG("the result is %d\n", result);

finish:
    return ret;
}