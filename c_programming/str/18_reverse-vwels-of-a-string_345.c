#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "utils.h"

static const char *vowel_list = "aeiouAEIOU";

static bool is_vowel(char e)
{
    size_t len = strlen(vowel_list);

    while (-- len) {
        if (e == vowel_list[len]) {
            return true;
        }
    }

    return false;
}

static int32_t reverse_str(char *str)
{
    int32_t ret = 0;
    size_t len = 0;
    size_t i = 0;
    size_t j = 0;
    bool i_lock = false;
    bool j_lock = false;

    UTILS_CHECK_PTR(str);
    UTILS_CHECK_LEN(len = strlen(str));

    j = len - 1;
    do {

        if ((i_lock == false) &&
            is_vowel(str[i])) {
            i_lock = true;
        }

        if ((j_lock == false) &&
            is_vowel(str[j])) {
            j_lock = true;
        }

        if (i_lock && j_lock) {
            i_lock = false;
            j_lock = false;
            utils_swap_char(&(str[i]), &(str[j]));
        }

        i = i_lock ? i : i + 1;
        j = j_lock ? j : j - 1;

    } while (i < j);

finish:
    return ret;
}


int32_t main(void)
{
    int32_t ret = 0;
    char s[100];

    sprintf(s,"%s", "leetcode");
    ret = reverse_str(s);
    UTILS_CHECK_RET(ret);
    LOG("out is %s\n", s);
    LOG_LINE_WITH_DOUBLE_TR();

finish:
    return ret;
}
