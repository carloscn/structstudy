#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "utils.h"

static size_t return_str_len(const char *str)
{
    size_t i = 0;
    int32_t ret = 0;
    size_t ret_len = 0;
    size_t str_len = 0;
    char *buf = NULL;

    UTILS_CHECK_PTR(str);
    str_len = strlen(str);

    buf = (char *)malloc(strlen(str) + 1);
    UTILS_CHECK_PTR(buf);
    strcpy(buf, str);

    // strip spaces on tail
    while(buf[str_len - 1] == ' ') {
        buf[str_len - 1] = 0;
        str_len --;
    }

    // count number
    str_len = strlen(buf);
    if (0 == str_len) {
        goto finish;
    }
    for (i = str_len - 1; i > 0; i --) {
        if (buf[i] != ' ') {
            ret_len ++;
        } else {
            goto finish;
        }
    }

finish:
    if (buf != NULL) {
        free(buf);
    }
    return ret_len;
}

int main(void)
{
    int32_t ret = 0;
    size_t ret_len = 0;

    const char *test_str_1 = "Hello World";
    const char *test_str_2 = "   fly me   to   the moon  ";
    const char *test_str_3 = "luffy is still joyboy";
    const char *test_str_4 = " ";

    ret_len = return_str_len(test_str_1);
    UTILS_CHECK_TEST_RESULT(ret_len, 5);

    ret_len = return_str_len(test_str_2);
    UTILS_CHECK_TEST_RESULT(ret_len, 4);

    ret_len = return_str_len(test_str_3);
    UTILS_CHECK_TEST_RESULT(ret_len, 6);

    ret_len = return_str_len(test_str_4);
    UTILS_CHECK_TEST_RESULT(ret_len, 0);

    return ret;
}
