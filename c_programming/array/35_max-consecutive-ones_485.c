#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../utils/utils.h"

static int32_t max_consec(char *array, size_t len, size_t *out)
{
    int32_t ret = 0;
    size_t i = 0;
    size_t count = 0;
    size_t max_count = 0;

    UTILS_CHECK_PTR(array);
    UTILS_CHECK_PTR(out);
    UTILS_CHECK_LEN(len);

    for (i = 0; i < len; i ++) {
        if (1 == array[i]) {
            count ++;
        } else if (0 == array[i]) {
            count = 0;
        } else {
            ret = 1;
            LOG("input error\n");
            goto finish;
        }

        if (max_count <= count) {
            max_count = count;
        }
    }

    *out = max_count;

finish:
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;
    size_t result = 0;
    char array[] = {1,1,1,1,1,0,0,0,1,0,1,0,1,0};

    ret = max_consec(array, ARRAY_SIZE(array), &result);
    UTILS_CHECK_RET(ret);
    LOG("the result is %d\n", result);

finish:
    return ret;
}