#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "utils.h"
#include "strlist.h"

#define DEFAULT_STR_LEN 1024U

static inline void strmake(char *str, int64_t head, int64_t tail)
{
    if (head != tail) {
        sprintf(str, "%ld->%ld", head, tail);
    } else {
        sprintf(str, "%ld", head);
    }
}

static int32_t summary_ranges(int64_t *array,
                              size_t sz,
                              STRLIST_T *out_list)
{
    int32_t ret = 0;
    size_t i = 0;
    int64_t header = 0;
    int64_t coherence = 0;
    char buf[DEFAULT_STR_LEN] = { '0' };

    UTILS_CHECK_LEN(sz);
    UTILS_CHECK_PTR(array);
    UTILS_CHECK_PTR(out_list);

    header = coherence = array[0];
    for (i = 0; i < sz + 1; i ++, coherence ++) {
        if ((i > sz) ||
            (coherence != array[i])) {
            strmake(buf, header, array[i-1]);
            strlist_add(out_list, buf);
            coherence = header = array[i];
        }
    }

finish:
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;
    int64_t array1[] = {9999,10000,10001,10004,10005,10006, 10009, 10010, 10012};
    STRLIST_T *list = NULL;

    list = strlist_malloc();
    UTILS_CHECK_PTR(list);

    ret = summary_ranges(array1, ARRAY_SIZE(array1), list);
    UTILS_CHECK_RET(ret);

    strlist_infolog(list);

finish:
    strlist_free(list);
    return ret;
}