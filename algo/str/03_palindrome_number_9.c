#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include "utils.h"

static bool is_palindrome(int32_t x)
{
    size_t x_len = 0, i = 0;
    char *x_str = NULL;
    bool ret = true;

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

finish:
    if (x_str != NULL)
        free(x_str);
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