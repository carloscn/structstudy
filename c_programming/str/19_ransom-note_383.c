#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "utils.h"

static int32_t is_ransom(char *ransom, char *magzine, bool *result)
{
    int32_t ret = 0;
    size_t ran_len, mag_len;
    size_t i = 0, j = 0;
    char e = 0;
    bool found = false;

    UTILS_CHECK_PTR(ransom);
    UTILS_CHECK_PTR(magzine);
    UTILS_CHECK_PTR(result);
    UTILS_CHECK_LEN(ran_len = strlen(ransom));
    UTILS_CHECK_LEN(mag_len = strlen(magzine));

    for (i = 0; i < ran_len; i ++) {
        found = false;
        e = ransom[i];
        for (j = 0; j < mag_len; j ++) {
            if (e == magzine[j]) {
                magzine[j] = 0;
                found = true;
                break;
            }
        }
        if (found == false) {
            *result = false;
            goto finish;
        }
    }

    *result = true;

finish:
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;
    char s[100];
    char b[100];
    bool res = false;

    sprintf(s,"%s", "abaaabbbb");
    sprintf(b,"%s", "sdfsdsfilsjifjisjgabadfdsaabdsfbfdsfdsfbadcb");
    ret = is_ransom(s, b, &res);
    UTILS_CHECK_RET(ret);
    LOG("out is %d\n", res);
    LOG_LINE_WITH_DOUBLE_TR();

finish:
    return ret;
}
