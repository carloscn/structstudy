#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "utils.h"
#include "strlist.h"

static char *table[] = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};

static bool is_keyrow(const char *str)
{
    bool ret = false;
    size_t i = 0;
    size_t j = 0;
    size_t len = 0;
    char *result = NULL;
    char *target_table = NULL;

    len = strlen(str);
    for (i = 0; i < 3; i ++) {
        target_table = table[i];
        for (j = 0; j < len; j ++) {
            result = strchr(target_table, utils_conv_lowercase(str[j]));
            if (NULL == result) {
                break;
            }
        }
        if (j == len) {
            ret = true;
            goto finish;
        }
    }

finish:
    return ret;
}

static int32_t key_row(STRLIST_T *strlist_in, STRLIST_T *strlist_out)
{
    int32_t ret = 0;
    size_t i = 0;
    size_t j = 0;
    bool result = false;

    UTILS_CHECK_PTR(strlist_in);
    UTILS_CHECK_PTR(strlist_out);

    for (i = 0; i < strlist_get_size(strlist_in); i ++) {
        result = is_keyrow((const char*) strlist_get_str_at(strlist_in, i));
        if (true == result) {
            strlist_add(strlist_out, strlist_get_str_at(strlist_in, i));
        }
    }

finish:
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;

    STRLIST_T *in = NULL;
    STRLIST_T *out = NULL;

    in = strlist_malloc();
    UTILS_CHECK_PTR(in);

    out = strlist_malloc();
    UTILS_CHECK_PTR(out);

    strlist_add(in, "Hello");
    strlist_add(in, "Alaska");
    strlist_add(in, "Dad");
    strlist_add(in, "Peace");
    strlist_infolog(in);

    ret = key_row(in, out);
    UTILS_CHECK_RET(ret);

    strlist_infolog(out);

finish:
    strlist_free(in);
    strlist_free(out);
    return ret;
}
