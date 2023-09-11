#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <assert.h>
#include "utils.h"

int32_t first_palindrome(const char **words, size_t words_size, char *out_str)
{
    int32_t ret = 0;
    char const *str_e = NULL;

    UTILS_CHECK_PTR(words);
    UTILS_CHECK_PTR(out_str);
    UTILS_CHECK_LEN(words_size);

    out_str[0] = '\0';

    size_t str_len = 0;
    for (size_t i = 0; i < words_size; i ++) {
        str_e = words[i];
        UTILS_CHECK_PTR(str_e);

        str_len = strlen(str_e);
        if (str_len = 0) {
            continue;
        }

        size_t j = 0, k = str_len - 1;
        while (j != k) {
            if (str_e[j ++] != str_e[k --]) {
                break;
            }
        }

        if (i == k) {
            strcpy(out_str, str_e);
            break;
        }
    }

finish:
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;
    char str[100] = {0};
    bool count = 0;

    const char *input1[] = {"abc","car","ada","racecar","cool"};
    ret = first_palindrome(input1, 5, str);
    assert(ret == 0), assert(strcmp(str, "ada"));

    const char *input2[] = {"notapalindrome","racecar"};
    ret = first_palindrome(input2, 2, str);
    assert(ret == 0), assert(strcmp(str, "racecar"));

    const char *input3[] = {"def","ghi"};
    ret = first_palindrome(input3, 2, str);
    assert(ret == 0), assert(str[0] == '\0');

    LOG("All tests pass!");

finish:
    return ret;
}