#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <assert.h>
#include "utils.h"

static bool is_valid(const char *str, bool is_tail)
{
    if (NULL == str) {
        return false;
    }

    size_t len = strlen(str);
    if (0 == len) {
        return false;
    }

    size_t digital_count = 0;
    size_t alpha_count = 0;
    size_t punctuation_count = 0;

    for (size_t i = 0; i < len; i ++) {
        if (isalpha(str[i])) {
            if (digital_count != 0 || punctuation_count != 0) {
                return false;
            }
            alpha_count ++;
        } else if (isdigit(str[i])) {
            if (alpha_count != 0 || punctuation_count != 0) {
                return false;
            }
            digital_count ++;
        } else if (str[i] == '-') {
            if (digital_count != 0 && alpha_count != 0) {
                return false;
            } else if (digital_count == 0 && alpha_count != 0) {
                if (i != len - 1) {
                    alpha_count ++;
                } else {
                    return false;
                }
            } else if (digital_count != 0 && alpha_count == 0) {
                return false;
            }
        } else if (str[i] == '.' || str[i] == '!') {
            if (i == len - 1 && is_tail == true) {
                return true;
            }
            punctuation_count ++;
        } else if (str[i] == ',') {
            if (i == len - 1 && is_tail == false) {
                return true;
            }
            punctuation_count ++;
        } else {
            return false;
        }
    }

    return true;
}

static int32_t count_valid_words(const char *sentence, size_t *count)
{
    int32_t ret = 0;
    size_t len = 0;

    UTILS_CHECK_PTR(sentence);
    UTILS_CHECK_PTR(count);
    UTILS_CHECK_LEN(len = strlen(sentence));

    char temp[100] = {0};
    int32_t i = 0;
    int32_t j = -1;

    *count = 0;
    while (i < len + 1) {
        if (sentence[i] == ' ' || sentence[i] == '\0') {
            if (i - j != 1) {
                memcpy(temp, sentence + j + 1, i - j - 1);
                temp[i - j] = '\0';
                if (is_valid(temp, sentence[i] == '\0')) {
                    (*count) ++;
                }
            }
            j = i;
        }
        i ++;
    }

finish:
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;
    char str[100] = {0};
    size_t count = 0;

    ret = count_valid_words("cat and  dog", &count);
    assert(ret == 0), assert(count == 3);

    ret = count_valid_words("!this  1-s b8d!", &count);
    assert(ret == 0), assert(count == 0);

    ret = count_valid_words("alice and  bob are playing stone-game10", &count);
    assert(ret == 0), assert(count == 5);

    LOG("All tests pass!");

finish:
    return ret;
}