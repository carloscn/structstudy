#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>
#include <assert.h>
#include "utils.h"

static bool is_vowel(char c)
{
    static const char* vowels = "aeiouAEIOU";
    return strchr(vowels, c) != NULL;
}

int32_t vowel_strings(const char* words[], size_t words_size, size_t left, size_t right)
{
    int32_t ret = 0;

    UTILS_CHECK_PTR(words);
    UTILS_CHECK_LEN(words_size);

    if ((right >= words_size) || (left > right)) {
        ret = -1;
        goto finish;
    }

    for (size_t i = left; i <= right; i ++) {
        const char *e = words[i];
        if (NULL == e) {
            continue;
        }

        size_t len = strlen(e);
        if ((len > 0) && is_vowel(e[0]) && is_vowel(e[len - 1])) {
            ret ++;
        }
    }

finish:
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;
    const char *rom_1[] = {"are","amy","u"};
    const char *rom_2[] = {"hey","aeo","mu","ooo","artro"};

    ret = vowel_strings(rom_1, ARRAY_SIZE(rom_1), 0, 2);
    assert(ret == 2);

    ret = vowel_strings(rom_2, ARRAY_SIZE(rom_2), 1, 4);
    assert(ret == 3);

    LOG("All tests pass!");

finish:
    return ret;
}

// gcc -I./utils/ ./utils/utils.c ./str/n64_count_the_number_of_vowel_strings_in_range_2586.c && ./a.exed