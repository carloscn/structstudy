#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include "utils.h"
#include "strlist.h"
#include "stack.h"

static char str_result[] = "00:00";
static char* gen_str(int32_t hou, int32_t min)
{
    if (min < 10) {
        sprintf(str_result, "%d:0%d", hou, min);
    } else {
        sprintf(str_result, "%d:%d", hou, min);
    }
    return str_result;
}

static size_t count1(size_t n)
{
    size_t res = 0;

    while (n != 0) {
        n = n & (n - 1);
        res ++;
    }
    return res;
}

static int32_t binary_watch(size_t turn_on, STRLIST_T *list)
{
    int32_t ret = 0;
    size_t i = 0, j = 0;

    UTILS_CHECK_PTR(list);

    if (0 == turn_on) {
        strlist_add(list, gen_str(0, 0));
        goto finish;
    }

    for (i = 0; i < 12; i ++) {
        for (j = 0; j < 60; j ++) {
            if (count1(i) + count1(j) == turn_on) {
                strlist_add(list, gen_str(i, j));
            }
        }
    }

finish:
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;
    STRLIST_T *strlist = NULL;

    strlist = strlist_malloc();
    UTILS_CHECK_PTR(strlist);

    ret = binary_watch(1, strlist);
    UTILS_CHECK_RET(ret);

    strlist_infolog(strlist);

finish:
    strlist_free(strlist);
    return ret;
}
