#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "utils.h"

static int32_t valid_anagram(char *s, char *t, bool *result)
{
    int32_t ret = 0;
    size_t s_len = 0;
    size_t i = 0, j = 0;
    char temp = 0;

    UTILS_CHECK_PTR(s);
    UTILS_CHECK_PTR(t);
    UTILS_CHECK_PTR(result);

    s_len = strlen(s);

    if (0 == s_len) {
        goto finish;
    }

    if (s_len != strlen(t)) {
        ret = -1;
        LOG("input str lens are not match\n");
        goto finish;
    }

    for (j = 0; j < s_len - 1; j ++) {
        for (i = 0; i < s_len - j - 1; i ++) {
            if (s[i] > s[i + 1])
                temp = s[i], s[i] = s[i + 1], s[i + 1] = temp;
            if (t[i] > t[i + 1])
                temp = t[i], t[i] = t[i + 1], t[i + 1] = temp;
        }
    }

    *result = !strcmp(s, t);

finish:
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;
    bool val = 0;
    char s[100];
    char t[100];

    sprintf(s,"%s", "anagram");
    sprintf(t,"%s", "nagaram");
    ret = valid_anagram(s, t, &val);
    UTILS_CHECK_RET(ret);
    LOG("the val is %d\n", val);

    sprintf(s,"%s", "rats");
    sprintf(t,"%s", "cars");
    ret = valid_anagram(s, t, &val);
    UTILS_CHECK_RET(ret);
    LOG("the val is %d\n", val);

    sprintf(s,"%s", "maagran");
    sprintf(t,"%s", "nagaram");
    ret = valid_anagram(s, t, &val);
    UTILS_CHECK_RET(ret);
    LOG("the val is %d\n", val);


finish:
    return ret;
}