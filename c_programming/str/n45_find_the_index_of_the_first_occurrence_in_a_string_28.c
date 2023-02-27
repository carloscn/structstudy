#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "utils.h"

static size_t is_compare(const char *in_str, const char *pat, bool *result)
{
    size_t i = 0;
    size_t pat_len = strlen(pat);
    char mat_c = pat[0];
    size_t mat_index = 0;

    *result = true;
    for (i = 0; i < pat_len; i ++) {
        if (in_str[i] == mat_c && mat_index == 0) {
            mat_index = i;
            if (*result == false) {
                goto finish;
            }
        }
        if (*result == false || in_str[i] != pat[i]) {
            *result = false;
            if (mat_index == 0) {
                continue;
            } else {
                goto finish;
            }
        }
    }

finish:
    return mat_index;
}

static int32_t find_sub_str(const char *in_str, const char *pat, int32_t *index)
{
    int32_t ret = 0;
    size_t in_len = 0;
    size_t pat_len = 0;
    size_t i = 0;
    size_t mat_index = 0;
    bool res = false;

    UTILS_CHECK_PTR(in_str);
    UTILS_CHECK_PTR(pat);
    UTILS_CHECK_PTR(index);
    UTILS_CHECK_PTR(pat_len = strlen(pat));
    UTILS_CHECK_PTR(in_len = strlen(in_str));

    while (i < in_len) {
        mat_index = is_compare(in_str + i, pat, &res);
        LOG("find compare %s, the result is %d, the next index is +%d\n", in_str + i, res, mat_index);
        if (res == true) {
            *index = (int32_t)(i + mat_index);
            goto finish;
        }
        i += (mat_index == 0) ? 1 : mat_index;

    }

    *index = -1;

finish:
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;
    int32_t index = 0;

    ret = find_sub_str("adesaddadbutsad", "sad", &index);
    UTILS_CHECK_RET(ret);

    LOG("the output is %d\n", index);

finish:
    return ret;
}