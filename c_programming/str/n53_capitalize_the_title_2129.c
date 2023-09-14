#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <assert.h>
#include "utils.h"

int32_t capitalize_title(char *title)
{
    int32_t ret = 0;
    size_t len = 0;

    UTILS_CHECK_PTR(title);
    UTILS_CHECK_LEN(len = strlen(title));


    size_t word_len = 0;
    for (size_t i = 0; i < len; i ++) {
        if (title[i] != ' ') {
            word_len ++;
        } else {
            break;
        }
    }

    bool next_should_upper = (word_len > 2) ? true : false;
    for (size_t i = 0; i < len; i ++) {
        char e = title[i];
        if (e == ' ') {
            size_t j = i + 1;
            word_len = 0;
            while (title[j] != ' ' && title[j] != '\0') {
                word_len ++, j ++;
            }
            next_should_upper = (word_len > 2) ? true : false;
            continue;
        }

        if (islower(e) && next_should_upper == true) {
            title[i] = utils_conv_uppercase(e);
        }

        if (isupper(e) && next_should_upper == false) {
            title[i] = utils_conv_lowercase(e);
        }

        next_should_upper = false;
    }

finish:
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;
    char str[100] = {0};

    strcpy(str, "capiTalIze tHe titLe");
    ret = capitalize_title(str);
    assert(ret == 0), assert(strcmp(str, "Capitalize The Title") == 0);

    strcpy(str, "First leTTeR of EACH Word");
    ret = capitalize_title(str);
    assert(ret == 0), assert(strcmp(str, "First Letter of Each Word") == 0);

    strcpy(str, "i lOve leetcode");
    ret = capitalize_title(str);
    assert(ret == 0), assert(strcmp(str, "i Love Leetcode") == 0);

    LOG("All tests pass!");

finish:
    return ret;
}
