#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include "buffer.h"
#include "utils.h"

#define U_OF(__c) ((char)((__c) + 'A'))

int32_t excel_sheet_column_title(size_t num)
{
    int32_t ret = 0;
    int64_t val = 0;
    BUFFER_T *buffer = NULL;
    size_t len = num;

    buffer = buffer_malloc(16);
    UTILS_CHECK_PTR(buffer);

    while (len--) {
        ret = buffer_push_tail(buffer, (int64_t)U_OF(len % 26));
        UTILS_CHECK_RET(ret);
        len = len / 26;
    }

    // print the string.
    printf("input n = %zu, the result is : ", num);
    len = buffer_get_current_len(buffer);
    while (--len) {
        ret = buffer_get_by_index(buffer, len, &val);
        UTILS_CHECK_RET(ret);
        printf("%c", (char)val);
    }
    printf("\n");

finish:
    buffer_free(buffer);
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;

    ret = excel_sheet_column_title(1);
    UTILS_CHECK_RET(ret);

    ret = excel_sheet_column_title(28);
    UTILS_CHECK_RET(ret);

    ret = excel_sheet_column_title(701);
    UTILS_CHECK_RET(ret);

    ret = excel_sheet_column_title(2147483647);
    UTILS_CHECK_RET(ret);

finish:
    return ret;
}