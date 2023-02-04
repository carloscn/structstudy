#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "utils.h"

static int32_t longest_uncommon_subseq(const char *str_1, const char *str_2, int32_t *out)
{
    int32_t ret = 0;
    size_t sl_a = 0, sl_b = 0;

    UTILS_CHECK_PTR(str_1);
    UTILS_CHECK_PTR(str_2);
    UTILS_CHECK_PTR(out);

    sl_a = strlen(str_1);
    sl_b = strlen(str_2);

    if (strcmp(str_1, str_2) == 0) {
        *out = -1;
        goto finish;
    }

    *out = (sl_a >= sl_b) ? sl_a : sl_b;

finish:
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;
    int32_t len = 0;

    ret = longest_uncommon_subseq("aaa", "aaa", &len);
    UTILS_CHECK_RET(ret);
    LOG("the len is %d\n", len);

finish:
    return ret;
}