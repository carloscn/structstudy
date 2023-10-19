#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>
#include <assert.h>
#include "utils.h"

static int32_t minimum_recolors(const char *blocks, size_t k)
{
    int32_t ret = 0;
    size_t len;

    UTILS_CHECK_PTR(blocks);
    UTILS_CHECK_LEN(len = strlen(blocks));
    UTILS_CHECK_CONDITION(len < k, ret, "len < k");

    size_t max_white = 0, max_black = 0;
    for (size_t i = 0; i < len - k; i ++) {
        size_t count_white = 0, count_black = 0;
        for (size_t j = 0; j < k; j ++) {
            if (blocks[j + i] == 'W') {
                count_white ++;
            } else if  (blocks[j + i] == 'B') {
                count_black ++;
            } else {
                ret = -1;
                return ret;
            }
        }
        max_white = UTILS_MAX(max_white, count_white);
        max_black = UTILS_MAX(max_black, count_black);
        if (max_white >= k || max_black >= k) {
            max_white = 0;
            max_black = 0;
        }
    }

    ret = UTILS_MIN(max_white, max_black);

finish:
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;
    char out;

    ret = minimum_recolors("WBBWWBBWBW", 7);
    assert(ret == 3);

    ret = minimum_recolors("WBWBBBW",2);
    assert(ret == 0);

    LOG("All tests pass!");

finish:
    return ret;
}
