#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include "utils.h"
#include "strlist.h"

static int32_t fizz_buzz(size_t n)
{
    int32_t ret = 0;
    STRLIST_T *strlist = NULL;
    char buf[5] = {0};

    UTILS_CHECK_LEN(n);

    strlist = strlist_malloc();
    UTILS_CHECK_PTR(strlist);

    for (size_t i = 1; i < n + 1; i ++) {
        if ((i % 3 == 0) && (i % 5 != 0)) {
            strlist_add(strlist, "Fizz");
        } else if ((i % 5 == 0) && (i % 3 != 0)) {
            strlist_add(strlist, "Buzz");
        } else if ((i % 15) == 0) {
            strlist_add(strlist, "FizzBuzz");
        } else {
            sprintf(buf, "%zd", i);
            strlist_add(strlist, buf);
        }
    }
    strlist_infolog(strlist);

finish:
    strlist_free(strlist);
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;

    ret = fizz_buzz(15);
    UTILS_CHECK_RET(ret);

finish:
    return ret;
}
