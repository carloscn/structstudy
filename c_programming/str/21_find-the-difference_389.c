#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include "utils.h"

// the str memory shall be 1 byte larger than itself to store e.
static void reorder_str(char *str, char e)
{
    size_t len = strlen(str);
    size_t i = 0;
    int32_t ra = 0;
    int32_t rb = 0;

    str[len] = e;
    str[++len] = '\0';

    srand(time(0));
    for (i = 0; i < len; i ++) {
        ra = rand() % len;
        rb = rand() % len;
        utils_swap_char(str + rb, str + ra);
    }
}

static int32_t find_diff(char *str_s, char *str_t, char *o_e)
{
    int32_t ret = 0;
    size_t s_len, t_len, i;
    char e = 0;

    UTILS_CHECK_PTR(str_s);
    UTILS_CHECK_PTR(str_t);
    UTILS_CHECK_PTR(o_e);
    UTILS_CHECK_LEN(s_len = strlen(str_s));
    UTILS_CHECK_LEN(t_len = strlen(str_t));

    if (t_len - s_len != 1) {
        ret = -1;
        LOG("input str len is wrong.\n");
        goto finish;
    }

    for (i = 0; i < s_len; i ++) {
        e ^= str_s[i] ^ str_t[i];
    }
    e ^= str_t[i];

    *o_e = e;

finish:
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;
    size_t index = 0;
    char s[100];
    char b[100];
    char e = 0;
    sprintf(s,"%s", "leetcode");
    sprintf(b,"%s", "leetcode"); reorder_str(b, 'k');

    ret = find_diff(s, b, &e);
    UTILS_CHECK_RET(ret);
    LOG("input s = %s,  t = %s,  out is %c\n", s, b, e);
    LOG_LINE_WITH_DOUBLE_TR();

finish:
    return ret;
}
