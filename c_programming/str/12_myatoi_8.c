#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "utils.h"

#define NUM_MAX ((char)'9')
#define NUM_MIN ((char)'0')
#define NUM_INT_MAX (2147483647)
#define NUM_INT_MAX_COUNT (10)

static int32_t myatoi(const char *str, int32_t *out)
{
    int32_t ret = 0;
    int32_t val = 0;
    int32_t u = 1;
    int32_t overflow_count = 0;

    UTILS_CHECK_PTR(str);
    UTILS_CHECK_PTR(out);

    if (0 == strlen(str))
        goto finish;

    do {
        if (' ' == *str) {
            continue;
        }
        if ('+' == *str) {
            u = 1;
            continue;
        }
        if ('-' == *str) {
            u = -1;
            continue;
        }
        if ((NUM_MAX < *str) ||
            (NUM_MIN > *str)) {
            break;
        }
        if (overflow_count < NUM_INT_MAX_COUNT)
            val = val * 10 + *str - NUM_MIN;
    } while (*(++str) != '\0' && (++overflow_count < NUM_INT_MAX_COUNT));

    *out = val * u;
finish:
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;
    int32_t val = 0;

    ret = myatoi("1234", &val);
    UTILS_CHECK_RET(ret);
    LOG("the val is %d\n", val);

    ret = myatoi("-555555555", &val);
    UTILS_CHECK_RET(ret);
    LOG("the val is %d\n", val);

    ret = myatoi("4193 with words", &val);
    UTILS_CHECK_RET(ret);
    LOG("the val is %d\n", val);

    ret = myatoi("214748364789", &val);
    UTILS_CHECK_RET(ret);
    LOG("the val is %d\n", val);

finish:
    return ret;
}