#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include "utils.h"

static int32_t min_max_difference(int32_t num)
{
    int32_t ret = 0;

    if (num < 0) {
        goto finish;
    }

    char buffer[16];
    char cap = '\0';
    sprintf(buffer, "%d", num);
    for (size_t i = 0; i < strlen(buffer); i ++) {
        if ((buffer[i] != '9') && (cap == '\0')) {
            cap = buffer[i];
            buffer[i] = '9';
            continue;
        }
        if (cap == buffer[i]) {
            buffer[i] = '9';
        }
    }
    ret = atoi(buffer);

    sprintf(buffer, "%d", num);
    cap = buffer[0], buffer[0] = '0';
    for (size_t i = 1; i < strlen(buffer); i ++) {
        if (cap == buffer[i]) {
            buffer[i] = '0';
        }
    }
    ret -= atoi(buffer);

finish:
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;

    ret = min_max_difference(11891);
    assert(ret == 99009);

    ret = min_max_difference(90);
    assert(ret == 99);

    LOG("All tests have passed!\n");

finish:
    return 0;
}

// gcc -I./utils/ ./utils/utils.c ./common/n28_maximum_difference_by_remapping_a_digit_2566.c && ./a.exe