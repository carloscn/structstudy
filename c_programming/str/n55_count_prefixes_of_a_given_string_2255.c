#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <assert.h>
#include "utils.h"

static bool is_prefix(const char *a, const char *b)
{
    size_t len_a = strlen(a);
    size_t len_b = strlen(b);

    if (len_a > len_b) {
        return false;
    }

    return 0 == strncmp(a, b, len_a);
}

static int32_t count_prefixes(const char *words[], size_t words_size, const char *s)
{
    int32_t ret = 0;
    size_t p_len;

    UTILS_CHECK_PTR(words);
    UTILS_CHECK_PTR(s);
    UTILS_CHECK_LEN(words_size);
    UTILS_CHECK_LEN(p_len = strlen(s));

    for (size_t i = 0; i < words_size; i ++) {
        const char *d_str = words[i];
        UTILS_CHECK_PTR(d_str);
        if (is_prefix(d_str, s)) {
            ret ++;
        }
    }

finish:
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;
    const char *input1[] = {"a","b","c","ab","bc","abc"};
    const char *input2[] = {"a","a"};

    ret = count_prefixes(input1, ARRAY_SIZE(input1), "abc");
    assert(ret == 3);

    ret = count_prefixes(input2, ARRAY_SIZE(input2), "aa");
    assert(ret == 2);

    LOG("All tests pass!");

finish:
    return ret;
}
