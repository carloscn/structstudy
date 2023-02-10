#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "utils.h"

static int32_t valid_palindrome_ii(const char *in_str, bool *result)
{
    int32_t ret = 0;
    size_t len = 0, i = 0, j = 0;
    char *str = NULL;
    bool tol = false;

    UTILS_CHECK_PTR(in_str);
    UTILS_CHECK_PTR(result);
    UTILS_CHECK_LEN(len = strlen(in_str));

    j = len - 1;
    str = strdup(in_str);
    UTILS_CHECK_PTR(str);

    *result = false;
    while (i != j) {
        if (str[i] != str[j]) {
            if (tol == false) {
                // try left
                if (str[i + 1] == str[j]) {
                    i++;
                    tol = true;
                    continue;
                }
                // try right
                else if (str[i] == str[j - 1]) {
                    j --;
                    tol = true;
                    continue;
                } else {
                    goto finish;
                }
            } else {
                goto finish;
            }
        }
        i ++;
        j --;
        if (j - i == 1) {
            break;
        }
    }

    *result = true;

finish:
    if (str != NULL)
        free(str);
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;
    bool res = false;
    valid_palindrome_ii("abcddcbqa", &res);
    UTILS_CHECK_RET(ret);

    LOG("the result is %d\n", res);

finish:
    return ret;
}