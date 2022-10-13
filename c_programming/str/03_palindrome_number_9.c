#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include "utils.h"


#define METHOD_STR      0
#define METHOD_VALUE    1

static bool is_palindrome(int32_t x)
{
    size_t x_len = 0, i = 0;
    bool ret = true;

    if (x < 0) {
        return false;
    }

#if METHOD_STR
    char *x_str = NULL;
    // get len  “12534”
    x_len = utils_get_num_len(x);

    if (x_len == 1) {
        return true;
    }

    // convert to string.
    x_str = (char *)malloc(x_len + 1);
    UTILS_CHECK_PTR(x_str);
    sprintf(x_str, "%d", x);

    for (i = 0; i < (x_len >> 1); i ++) {
        if (x_str[i] != x_str[x_len - i - 1]) {
            ret = false;
            goto finish;
        }
    }
#elif METHOD_VALUE
    int32_t cacu_invert_val = 0;
    int32_t cacu_x_val = x;
    while(cacu_x_val != 0) {
        cacu_invert_val = (cacu_invert_val * 10) + (cacu_x_val % 10);
        cacu_x_val /= 10;
    }
    ret = (cacu_invert_val == x);
#endif

finish:
#if METHOD_STR
    if (x_str != NULL)
        free(x_str);
#endif
    return ret;
}

int main(void)
{
    int32_t ret = 0;
    int32_t test_input_1 = 121,     \
            test_input_2 = -121,    \
            test_input_3 = 10,      \
            test_input_4 = 0,      \
            test_input_5 = 2345432;

    bool result = false;

    result = is_palindrome(test_input_1);
    UTILS_CHECK_TEST_RESULT(result, true);
    result = is_palindrome(test_input_2);
    UTILS_CHECK_TEST_RESULT(result, false);
    result = is_palindrome(test_input_3);
    UTILS_CHECK_TEST_RESULT(result, false);
    result = is_palindrome(test_input_4);
    UTILS_CHECK_TEST_RESULT(result, true);
    result = is_palindrome(test_input_5);
    UTILS_CHECK_TEST_RESULT(result, true);

    return ret;
}