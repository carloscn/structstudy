#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include "buffer.h"
#include "utils.h"

#define METHOD_1 0  /* behind to front. */
#define METHOD_2 1  /* front to behind. */

#define C_OF(__c) ((int64_t)((__c) - 'A' + 1))

// Note, compiling the file, need to add `-lm' because of <math.h>.
// `gcc 09_excel-sheet-column-number_171.c utils.c -lm`
static int32_t excel_sheet_column_number(const char *str)
{
    int32_t ret = 0;
    int64_t out = 0;
    size_t len = 0;
    size_t pos = 0;

    UTILS_CHECK_PTR(str);
    len = strlen(str);

    if (0 == len)
        goto finish;
#if METHOD_1
    do {
        out += C_OF(str[--len]) * pow(26, pos++);
    } while (len);
#elif METHOD_2
    size_t i = 0;
    for (i = 0; i < len; i ++) {
        out = out * 26 + C_OF(str[i]);
    }
#endif
    LOG("the out put is %lld\n", out);
finish:
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;
    int64_t val = 0;

    ret = excel_sheet_column_number("A");
    UTILS_CHECK_RET(ret);

    ret = excel_sheet_column_number("AB");
    UTILS_CHECK_RET(ret);

    ret = excel_sheet_column_number("ZY");
    UTILS_CHECK_RET(ret);

    ret = excel_sheet_column_number("FXSHRXW");
    UTILS_CHECK_RET(ret);

finish:
    return ret;
}