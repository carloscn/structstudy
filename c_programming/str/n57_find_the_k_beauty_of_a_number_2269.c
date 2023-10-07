#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>
#include <assert.h>
#include "utils.h"

static int32_t divisor_substrings(int32_t num, int32_t k)
{
    int32_t ret = 0;
    size_t len = 0;
    char num_str[16 + 1] = {'\0'};

    sprintf(num_str, "%d", num);
    len = strlen(num_str);

    if (len < k) {
        goto finish;
    } else if (len == k) {
        ret = 1;
        goto finish;
    }

    for (size_t i = 0; i < len - k + 1; i ++) {
        char buffer[17] = {'\0'};
        int32_t val = 0;
        for (size_t j = 0; j < k; j ++) {
            buffer[j] = num_str[j + i];
        }
        val = atoi(buffer);
        if (val != 0) {
            ret += (num % val) == 0;
        }
    }

finish:
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;

    ret = divisor_substrings(240, 2);
    assert(ret == 2);

    ret = divisor_substrings(430043, 2);
    assert(ret == 2);

    LOG("All tests pass!");

finish:
    return ret;
}
