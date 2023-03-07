#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "utils.h"
#include "strlist.h"

#define _P(_x) (int32_t)((_x) - '0')
#define _V(_x) (char)((_x) + '0')

static int32_t single_multi(char *a, char b, char *out)
{
    int32_t ret = 0;
    char *ret_str = NULL;
    size_t i = 0;
    size_t len = 0;
    int32_t p = 0;
    int32_t c = 0;

    UTILS_CHECK_PTR(a);
    UTILS_CHECK_PTR(out);
    UTILS_CHECK_LEN(len = strlen(a));

    ret_str = (char *)calloc(sizeof(char), len + 2);
    UTILS_CHECK_PTR(ret_str);

    for (i = 0; i < len; i ++) {
        c = _P(b) * _P(a[len - i - 1]) + c;
        p = c % 10;
        c = c / 10;
        ret_str[i] = _V(p);
    }
    if (c != 0) {
        ret_str[i++] = _V(c);
    }

    ret = utils_str_reverse(ret_str);
    UTILS_CHECK_RET(ret);

    strcpy(out, ret_str);

finish:
    UTILS_SAFE_FREE(ret_str);
    return ret;
}

static int32_t cross_add(char *a, char *b, size_t index, char *out)
{
    int32_t ret = 0;
    char *ret_str = NULL;
    int32_t i = 0, j = 1;
    size_t a_len = 0;
    size_t b_len = 0;
    size_t max_len = 0;
    int32_t p = 0;
    int32_t c = 0;
    int32_t c1 = 0, c2 = 0;

    UTILS_CHECK_PTR(a);
    UTILS_CHECK_PTR(b);
    UTILS_CHECK_PTR(out);
    UTILS_CHECK_LEN(a_len = strlen(a));
    UTILS_CHECK_LEN(b_len = strlen(b));

    max_len = (a_len > b_len) ? a_len : b_len;

    ret_str = (char *)calloc(sizeof(char), max_len + 3);
    UTILS_CHECK_PTR(ret_str);

    b[b_len] = '0';
    for (i = 0, j = 1 - index; i < max_len + 1; i ++, j ++) {
        c1 = (i > a_len - 1) ? 0 : _P(a[a_len - i - 1]);
        c2 = (j > b_len) ? 0 : _P(b[b_len - j]);
        c = c1 + c2 + c;
        p = c % 10;
        c = c / 10;
        ret_str[i] = _V(p);
    }

    while (-- i) {
        if (ret_str[i] == '0') {
            ret_str[i] = '\0';
        } else {
            break;
        }
    }

    ret = utils_str_reverse(ret_str);
    UTILS_CHECK_RET(ret);

    strcpy(out, ret_str);

finish:
    UTILS_SAFE_FREE(ret_str);
    return ret;
}

static int32_t multi_str(const char *a_str, const char *b_str, char *out)
{
    int32_t ret = 0;
    size_t a_len = 0, b_len = 0;
    size_t i = 0;
    char *cacu_buf = NULL;

    UTILS_CHECK_PTR(a_str);
    UTILS_CHECK_PTR(b_str);
    UTILS_CHECK_PTR(out);
    UTILS_CHECK_LEN(a_len = strlen(a_str));
    UTILS_CHECK_LEN(b_len = strlen(b_str));

    if (a_len < b_len) {
        ret = -1;
        goto finish;
    }

    if ((a_len == 1 && a_str[0] == '0') ||
        (b_len == 1 && b_str[0] == '0')) {
        out[0] = '0';
        out[1] = '\0';
    }

    cacu_buf = (char *)calloc(sizeof(char), a_len + 2);
    UTILS_CHECK_PTR(cacu_buf);

    ret = single_multi(a_str, b_str[b_len - 1], cacu_buf);
    UTILS_CHECK_RET(ret);

    for (i = 1; i < b_len; i ++) {
        ret = single_multi(a_str, b_str[b_len - i - 1], out);
        UTILS_CHECK_RET(ret);
        ret = cross_add(cacu_buf, out, i, out);
        strcpy(cacu_buf, out);
    }

finish:
    UTILS_SAFE_FREE(cacu_buf);
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;
    char str[1024];
    char in1[1024];
    char in2[1024];

    strcpy(in1, "1859");
    strcpy(in2, "185");

    ret = multi_str(in1, in2, str);
    UTILS_CHECK_RET(ret);

    LOG("the result is %s\n", str);

finish:
    return ret;
}