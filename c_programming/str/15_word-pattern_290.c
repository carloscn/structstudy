#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "utils.h"
#include "strlist.h"
#include "hash_map.h"

static int32_t word_pattern(char *pattern, char *str)
{
    int32_t ret = 0;
    int64_t e = 0;
    size_t i = 0, pos = 0, pattern_len = 0, p_num = 0, str_len = 0;
    STRLIST_T *strlist = NULL;
    HASH_MAP_T *hash_map = NULL;

    UTILS_CHECK_PTR(pattern);
    UTILS_CHECK_PTR(str);

    pattern_len = strlen(pattern);
    str_len = strlen(str);

    UTILS_CHECK_LEN(pattern_len);
    UTILS_CHECK_LEN(str_len);

    strlist = strlist_malloc();
    UTILS_CHECK_PTR(strlist);

    p_num = (size_t)strlist_add_split_by_char(strlist, str, ' ');
    if (p_num != pattern_len) {
        ret = -1;
        LOG("the pattern len is error, p_num = %zu, pattern_len = %zu\n", p_num, pattern_len);
        goto finish;
    }

    hash_map = hashmap_malloc(HASH_MAP_DEFAULT_SIZE);
    UTILS_CHECK_PTR(hash_map);

    for (i = 0; i < p_num; i ++) {
        ret = hashmap_push(hash_map, strlist_get_str_at(strlist, i), 'a' + pos);
        if (ret < 0) {
            goto finish;
        } else if (ret == 0) {
            pos ++;
        }
        LOG("set map %c <-> %s\n", (char)('a' + pos), strlist_get_str_at(strlist, i));
    }

    for (i = 0; i < pattern_len; i ++) {
        ret = hashmap_get(hash_map, strlist_get_str_at(strlist, i), &e, NULL);
        UTILS_CHECK_RET(ret);
        if (pattern[i] != e) {
            LOG("not match. pattern[%zu] %c != %c\n", i, (char)pattern[i], (char)e);
            goto finish;
        }
    }

    LOG("matched!\n");

finish:
    hashmap_free(hash_map);
    strlist_free(strlist);
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;
    bool val = 0;
    char s[100];
    char t[100];

    sprintf(s,"%s", "aabbccdd");
    sprintf(t,"%s", "dog dog cat cat fish fish bear bear");
    ret = word_pattern(s, t);
    UTILS_CHECK_RET(ret);
    LOG_LINE_WITH_DOUBLE_TR();

    sprintf(s,"%s", "aabbccdd");
    sprintf(t,"%s", "dog dog cat cat fish fish bear fish");
    ret = word_pattern(s, t);
    UTILS_CHECK_RET(ret);

    LOG_LINE_WITH_DOUBLE_TR();
    sprintf(s,"%s", "aaa");
    sprintf(t,"%s", "dog dog cat cat fish fish bear fish");
    ret = word_pattern(s, t);
    UTILS_CHECK_RET(ret);
finish:
    return ret;
}
