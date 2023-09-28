#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>
#include <assert.h>
#include "utils.h"

static int32_t remove_digit(const char *number, char digit, char *out)
{
    int32_t ret = 0;
    size_t len;

    UTILS_CHECK_PTR(number);
    UTILS_CHECK_PTR(out);
    UTILS_CHECK_LEN(len = strlen(number));

    char buffer[15] = {0};
    int32_t max_number = INT32_MIN;
    for (size_t i = 0; i < len; i ++) {
        if (number[i] == digit) {
            size_t n = 0;
            for (size_t j = 0; j < len + 1; j ++) {
                if (j != i) {
                    buffer[n] = number[j];
                    n ++;
                }
            }
            int32_t number = atoi(buffer);
            max_number = (max_number > number) ? max_number : number;
        }
    }

    sprintf(out, "%d", max_number);

finish:
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;
    char out[1024] = {0};

    char result1[] = "12";
    ret = remove_digit("123", '3', out);
    assert(ret == 0);
    for (size_t i = 0; i < strlen(out); i ++) {
        assert(out[i] == result1[i]);
    }

    char result2[] = "51";
    ret = remove_digit("551", '5', out);
    assert(ret == 0);
    for (size_t i = 0; i < strlen(out); i ++) {
        assert(out[i] == result2[i]);
    }

    LOG("All tests pass!");

finish:
    return ret;
}
