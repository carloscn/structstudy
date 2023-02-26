#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "utils.h"
#include "strlist.h"

static inline char spec_convert(char a)
{
    if (('!' == a) ||
        ('?' == a) ||
        (';' == a) ||
        ('.' == a) ||
        (' ' == a) ||
        (',' == a) ||
        ('\'' == a)) {
        return '\0';
    } else if ((a < 'Z') || (a > 'A')) {
        return utils_conv_lowercase(a);
    }

    return a;
}

static bool is_in_bans(const char *in, STRLIST_T *banlist)
{
    size_t i = 0;
    size_t in_len = strlen(in);
    size_t len = strlist_get_size(banlist);

    if (in_len == 0) {
        return true;
    }

    for (i = 0; i < len; i ++) {
        if (strcmp(in, strlist_get_str_at(banlist, i)) == 0) {
            LOG("the in is %s, bans is %s\n", in, strlist_get_str_at(banlist, i));
            return true;
        }
    }

    return false;
}

static size_t max_count(STRLIST_T *list)
{
    char *target_str = NULL;
    size_t count = 0;
    size_t max_count = 0;
    size_t i = 0, j = 0;
    size_t index = 0;
    size_t sz = strlist_get_size(list);

    for (i = 0; i < sz; i ++) {
        target_str = strlist_get_str_at(list, i);
        for (j = 0; j <= i; j ++) {
            if (strcmp(target_str, strlist_get_str_at(list, j)) == 0) {
                count ++;
            }
        }
        if (count > max_count) {
            max_count = count;
            index = i;
        }
        count = 0;
    }

    return index;
}

static int32_t most_common_word(const char *paragraph, STRLIST_T *banlist, char *out)
{
    int32_t ret = 0;
    size_t in_len = 0;
    size_t i = 0;
    STRLIST_T *paralist = NULL;
    char *dup_para = NULL;
    char c = 0;
    char *dup_para_header = NULL;
    size_t max_index = 0;

    UTILS_CHECK_PTR(paragraph);
    UTILS_CHECK_PTR(banlist);
    UTILS_CHECK_PTR(out);
    UTILS_CHECK_LEN(in_len = strlen(paragraph));

    paralist = strlist_malloc();
    UTILS_CHECK_PTR(paralist);

    dup_para = strdup(paragraph);
    UTILS_CHECK_PTR(dup_para);

    dup_para_header = dup_para;
    for (i = 0; i < in_len; i ++) {
        c = spec_convert(dup_para[i]);
        dup_para[i] = c;
        if (c == '\0') {
            if (is_in_bans(dup_para_header, banlist) == false) {
                strlist_add(paralist, dup_para_header);
                LOG("add str to list: %s\n", dup_para_header);
            }
            dup_para_header = dup_para + i + 1;
        }
    }

    strlist_infolog(paralist);

    max_index = max_count(paralist);
    strcpy(out, strlist_get_str_at(paralist, max_index));

finish:
    strlist_free(paralist);
    UTILS_SAFE_FREE(dup_para);
    return ret;
}


int32_t main(void)
{
    int32_t ret = 0;
    char *out = NULL;
    STRLIST_T *banlist = NULL;
    char *paragraph = "Bob hit a ball, the hit BALL flew far after it was hit.";

    banlist = strlist_malloc();
    UTILS_CHECK_PTR(banlist);

    strlist_add(banlist, "hit");

    out = (char *)malloc(strlen(paragraph));
    UTILS_CHECK_PTR(out);

    ret = most_common_word(paragraph, banlist, out);
    UTILS_CHECK_RET(ret);

    LOG("the most common word is %s\n", out);

finish:
    strlist_free(banlist);
    UTILS_SAFE_FREE(out);

    return ret;
}