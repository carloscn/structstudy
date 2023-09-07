#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <assert.h>
#include "utils.h"

int32_t check_almost_equivalent(const char *word1, const char *word2, bool *result)
{
    int32_t ret = 0;
    size_t w1_len, w2_len;

    UTILS_CHECK_PTR(word1);
    UTILS_CHECK_PTR(word2);
    UTILS_CHECK_PTR(result);
    UTILS_CHECK_LEN(w1_len = strlen(word1));
    UTILS_CHECK_LEN(w2_len = strlen(word2));

    int32_t w1_rom[26] = {0};
    int32_t w2_rom[26] = {0};
    size_t max_len = (w1_len > w2_len)?w1_len:w2_len;

    for (size_t i = 0; i < max_len; i ++) {
        if (i < w1_len) {
            w1_rom[(size_t)(word1[i] - 'a')] ++;
        }

        if (i < w2_len) {
            w2_rom[(size_t)(word2[i] - 'a')] ++;
        }
    }

    for (size_t i = 0; i < 26; i ++) {
        if (utils_int32_abs(w1_rom[i] - w2_rom[i]) > 3) {
            *result = false;
            goto finish;
        }
    }

    *result = true;

finish:
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;
    char str[100] = {0};
    bool count = 0;

    ret = check_almost_equivalent("aaaa", "bccb", &count);
    assert(ret == 0), assert(count == false);

    ret = check_almost_equivalent("abcdeef", "abaaacc", &count);
    assert(ret == 0), assert(count == true);

    ret = check_almost_equivalent("cccddabba", "babababab", &count);
    assert(ret == 0), assert(count == true);

    LOG("All tests pass!");

finish:
    return ret;
}