#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "utils.h"
#include "strlist.h"

static int32_t longest_common_prefix(STRLIST_T *strlist, char **str)
{
    int32_t ret = 0;
    int32_t sl_len = 0;
    size_t i = 0, j = 0;
    char *p = NULL;
    char last_c = '\0';

    UTILS_CHECK_PTR(strlist);
    UTILS_CHECK_PTR(str);

    sl_len = strlist_get_size(strlist);
    if (!sl_len) {
        *str = NULL;
        goto finish;
    }
    do {
        for (i = 0; i < sl_len; i ++) {
            p = strlist_get_str_at(strlist, i);
            if (i == 0) {
                last_c = p[j];
                continue;
            }
            if ((p[j] != last_c) || (p[j] == '\0')) {
                goto end;
            }
            last_c = p[j];
        }
        j ++;
    } while (1);
end:
    *str = NULL;
    *str = (char *)malloc(j + 1);
    UTILS_CHECK_PTR(*str);
    memcpy(*str, p, j);
    (*str)[j] = '\0';

finish:
    return ret;
}


int32_t main(void)
{
    int32_t ret = 0;
    int32_t val = 0;
    char *str = NULL;

    char *str1 = "heeeelll\n";
    char *str2 = "heeeeldll\n";
    char *str3 = "heeeelldll\n";

    STRLIST_T *list = NULL;
    list = strlist_malloc();
    UTILS_CHECK_PTR(list);

    strlist_add(list, str1);
    strlist_add(list, str2);
    strlist_add(list, str3);

    ret = longest_common_prefix(list, &str);
    UTILS_CHECK_RET(ret);

    LOG("the common str is %s\n", str);

finish:
    strlist_free(list);
    if (str != NULL)
        free(str);
    return ret;
}