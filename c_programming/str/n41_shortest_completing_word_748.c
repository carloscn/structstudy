#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "utils.h"
#include "strlist.h"

static int32_t is_contains(const char *in_str, const char *pat, bool *result)
{
    int32_t ret = 0;
    char *buffer = NULL;
    size_t buffer_len;
    size_t pat_len;
    size_t i = 0, j = 0;

    UTILS_CHECK_PTR(in_str);
    UTILS_CHECK_PTR(pat);
    UTILS_CHECK_PTR(result);
    UTILS_CHECK_LEN(buffer_len = strlen(in_str));
    UTILS_CHECK_LEN(pat_len = strlen(pat));

    buffer = (char *)calloc(sizeof(char), buffer_len + 1);
    if (buffer == NULL) {
        return false;
    }
    strcpy(buffer, in_str);

    ret = utils_sort_char_array(buffer, buffer_len, ORDER_BY_ASCEND);
    UTILS_CHECK_RET(ret);

    while (j < buffer_len) {
        if (buffer[j] == pat[i]) {
            i ++;
        }
        j ++;
        if (i == pat_len) {
            *result = true;
            goto finish;
        }
    }
    *result = false;

finish:
    UTILS_SAFE_FREE(buffer);
    return ret;
}


static int32_t shorest_word(STRLIST_T *strlist, const char *pat, size_t *index)
{
    int32_t ret = 0;
    char *pat_buffer = NULL;
    size_t strlist_len = 0;
    size_t pat_len = 0;
    size_t min_len = ~0;
    size_t len = 0;
    size_t i = 0;
    size_t j = 0;
    bool rs = false;
    char *str = NULL;

    UTILS_CHECK_PTR(strlist);
    UTILS_CHECK_PTR(pat);
    UTILS_CHECK_PTR(index);
    UTILS_CHECK_LEN(strlist_len = strlist_get_size(strlist));
    UTILS_CHECK_LEN(pat_len = strlen(pat));

    pat_buffer = (char *)calloc(sizeof(char), pat_len + 1);
    UTILS_CHECK_PTR(pat_buffer);
    strcpy(pat_buffer, pat);

    ret = utils_str_filter_letter(pat_buffer);
    UTILS_CHECK_RET(ret);
    LOG("the buffer is %s\n", pat_buffer);

    pat_len = strlen(pat_buffer);

    ret = utils_str_to_lowercase(pat_buffer);
    UTILS_CHECK_RET(ret);

    LOG("the buffer is %s\n", pat_buffer);

    ret = utils_sort_char_array(pat_buffer, pat_len, ORDER_BY_ASCEND);
    UTILS_CHECK_RET(ret);

    LOG("the buffer is %s\n", pat_buffer);

    for (i = 0; i < strlist_len; i ++) {
        str = strlist_get_str_at(strlist, i);
        ret = is_contains(str, pat_buffer, &rs);
        UTILS_CHECK_RET(ret);
        if (true == rs) {
            len = strlen(str);
            if (min_len > len) {
                min_len = len;
                *index = i;
            }
        }
    }

finish:
    UTILS_SAFE_FREE(pat_buffer);
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;
    STRLIST_T *strlist = NULL;
    size_t out = 0;

    strlist = strlist_malloc();
    UTILS_CHECK_PTR(strlist);
    strlist_add(strlist, "step");
    strlist_add(strlist, "steps");
    strlist_add(strlist, "stripe");
    strlist_add(strlist, "stepple");

    ret = shorest_word(strlist, "1s3 PSt", &out);
    UTILS_CHECK_RET(ret);
    LOG("the result is %s\n", strlist_get_str_at(strlist, out));

    strlist_infolog(strlist);

finish:
    strlist_free(strlist);
    return ret;
}