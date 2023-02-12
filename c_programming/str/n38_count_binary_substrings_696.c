#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "utils.h"
#include "strlist.h"

static bool count_num(const char *str)
{
    size_t len = strlen(str);
    size_t i = 0;
    size_t count_a = 0;
    size_t count_b = 0;
    bool reversed = false;
    char c = str[0];

    if (len < 2) {
        return false;
    }

    for (i = 0; i < len; i ++) {
        if (reversed == false && c == str[i]) {
            count_a ++;
            c = str[i];
            continue;
        } else {
            reversed = true;
            c = str[i];
        }

        if (reversed == true && c == str[i]) {
            count_b ++;
            c = str[i];
            continue;
        } else {
            return false;
        }
    }

    if (count_a == count_b) {
        return true;
    } else {
        return false;
    }
}

static int32_t count_binary_substr(const char *str, size_t *result)
{
    int32_t ret = 0;
    size_t len = 0;
    bool res = false;
    size_t count = 0;
    size_t i = 0, j = 0;
    char *dup_str = NULL;
    STRLIST_T *list = NULL;

    UTILS_CHECK_PTR(str);
    UTILS_CHECK_PTR(result);
    UTILS_CHECK_LEN(len = strlen(str));

    list = strlist_malloc();
    UTILS_CHECK_PTR(list);

    dup_str = strdup(str);
    UTILS_CHECK_PTR(dup_str);

    len = strlist_append_all_substr(list, dup_str);
    strlist_infolog(list);

    for (i = 2; i < len; i ++) {
        res = count_num(strlist_get_str_at(list, i));
        if (res == true) {
            count ++;
            LOG("found %s\n", strlist_get_str_at(list, i));
        }
    }

    LOG("the reuslt is %zu\n", count);
    *result = count;

finish:
    strlist_free(list);
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;
    size_t sz = 0;

    ret = count_binary_substr("00110011", &sz);
    UTILS_CHECK_RET(ret);
    LOG("the ret is %zu\n", sz);

finish:
    return ret;
}