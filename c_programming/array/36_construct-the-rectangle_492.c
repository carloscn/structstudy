#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include "../utils/utils.h"

static int32_t con_rec(int64_t area, size_t *l_o, size_t *w_o) 
{
    int32_t ret = 0;
    int64_t dist = 0;
    int64_t i = 0;
    int64_t mid = sqrt(area);

    UTILS_CHECK_PTR(l_o);
    UTILS_CHECK_PTR(w_o);

    for (i = mid; i > 0; i --) {
        if (0 == area % i) {
            dist = i;
            *l_o = area / dist;
            *w_o = dist;
            goto finish;
        }
    }

finish:
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;
    size_t len = 0, wid = 0;

    ret = con_rec(122122, &len, &wid);
    UTILS_CHECK_RET(ret);
    LOG("the result is (%d,%d)\n", len, wid);

finish:
    return ret;
}