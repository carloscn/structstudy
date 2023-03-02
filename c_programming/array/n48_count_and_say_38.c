#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "utils.h"

static int32_t gen_str(char *out)
{
    int32_t ret = 0;
    size_t in_len = 0;
    size_t count = 1;
    size_t i = 0;
    char e = 0;
    char c = 0;
    char *in_str = NULL;

    UTILS_CHECK_PTR(out);
    UTILS_CHECK_LEN(in_len = strlen(out));

    in_str = (char *)malloc(in_len);
    UTILS_CHECK_PTR(in_str);
    strcpy(in_str, out);

    for (i = 0; i < in_len; i ++) {
        e = in_str[i];
        c = in_str[i + 1];
        if (e == c) {
            count ++;
        } else {
            *(out ++) = count + '0';
            *(out ++) = e;
            count = 1;
        }
    }

finish:
    UTILS_SAFE_FREE(in_str);
    return ret;
}

static int32_t count_and_say(size_t n, char *in)
{
    int32_t ret = 0;
    size_t i = 0;

    UTILS_CHECK_PTR(in);
    UTILS_CHECK_LEN(n);

    strcpy(in, "1");
    for (i = 1; i < n; i ++) {
        ret = gen_str(in);
        UTILS_CHECK_RET(ret);
    }

finish:
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;
    char out[1024] = {0};

    ret = count_and_say(5, out);
    UTILS_CHECK_RET(ret);

    LOG("the out is %s\n", out);

finish:
    return ret;
}