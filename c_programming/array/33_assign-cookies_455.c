#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "utils.h"

// kids   cookies
// 1,2,3  1,1
// 1,2    1,1,3
// 1,2    1,1
static int32_t assign_cookies(int64_t *cookies, size_t cookies_len,
                              int64_t *kids, size_t kids_len,
                              size_t *o_len)
{
    int32_t ret = 0;
    size_t i = 0, j = 0;
    size_t meet_count = 0;

    UTILS_CHECK_PTR(cookies);
    UTILS_CHECK_PTR(kids);
    UTILS_CHECK_PTR(o_len);
    UTILS_CHECK_LEN(cookies_len);
    UTILS_CHECK_LEN(kids_len);

    ret = utils_sort_int64_array(cookies, cookies_len, ORDER_BY_ASCEND);
    UTILS_CHECK_RET(ret);

    ret = utils_sort_int64_array(kids, kids_len, ORDER_BY_ASCEND);
    UTILS_CHECK_RET(ret);

    while ((i < cookies_len) && (j < kids_len)) {
        if (cookies[i] >= kids[j]) {
            i ++, j ++;
            meet_count ++;
        } else {
            i ++;
        }
    }
    *o_len = meet_count;

finish:
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;
    int64_t kids[] = {1,2,3};
    int64_t cookies[] = {1,1,1,1,1,1,2,2};
    size_t result = 0;

    ret = assign_cookies(cookies, ARRAY_SIZE(cookies), kids, ARRAY_SIZE(kids), &result);
    UTILS_CHECK_RET(ret);
    LOG("the result is %zu\n", result);

finish:
    return ret;
}