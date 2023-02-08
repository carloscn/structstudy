#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "utils.h"

static int32_t is_move_back(const char* vector, bool *out)
{
    int32_t ret = 0;
    size_t i = 0, len = 0;
    int32_t lr = 0;
    int32_t ud = 0;

    UTILS_CHECK_PTR(vector);
    UTILS_CHECK_PTR(out);
    UTILS_CHECK_LEN(len = strlen(vector));

    for (i = 0; i < len; i ++) {
        switch (vector[i]) {
            case 'L':
            case 'l':
            lr ++;
            break;

            case 'R':
            case 'r':
            lr --;
            break;

            case 'U':
            case 'u':
            ud ++;
            break;

            case 'D':
            case 'd':
            ud --;
            break;

            default:
            *out = false;
            goto finish;
            break;
        }
    }

    if (ud == 0 && lr == 0) {
        *out = true;
    } else {
        *out = false;
    }

finish:
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;
    bool res = 0;
    ret = is_move_back("LRUD", &res);
    UTILS_CHECK_RET(ret);

    LOG("the result is %d\n", res);

finish:
    return ret;
}