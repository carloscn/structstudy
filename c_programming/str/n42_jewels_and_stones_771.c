#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "utils.h"

static int32_t jewels_and_stones(const char *jewels, const char *stones, size_t *result)
{
    int32_t ret = 0;
    size_t jew_len = 0;
    size_t sto_len = 0;
    size_t i = 0;
    size_t count = 0;

    UTILS_CHECK_PTR(jewels);
    UTILS_CHECK_PTR(stones);
    UTILS_CHECK_PTR(result);
    UTILS_CHECK_LEN(jew_len = strlen(jewels));
    UTILS_CHECK_LEN(sto_len = strlen(stones));


    for (i = 0; i < sto_len; i ++) {
        if (utils_str_contains_char(jewels, stones[i])) {
            count ++;
        }
    }

    *result = count;

finish:
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;
    size_t count = 0;

    ret = jewels_and_stones("aA", "aAAbbbb", &count);
    UTILS_CHECK_RET(ret);
    LOG("the result is %zu\n", count);

finish:
    return ret;
}