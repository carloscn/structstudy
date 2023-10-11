#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>
#include <assert.h>
#include "utils.h"

static int32_t strongPasswordCheckerII(const char *password, bool *result)
{
    int32_t ret = 0;
    size_t len;

    UTILS_CHECK_PTR(password);
    UTILS_CHECK_PTR(result);
    UTILS_CHECK_LEN(len = strlen(password));

    if (len < 8) {
        *result = false;
        goto finish;
    }

    uint8_t flag = 0;
    for (size_t i = 0; i < len; i ++) {
        if (islower(password[i])) {
            flag |= 1;
        } else if (isupper(password[i])) {
            flag |= 1 << 1;
        } else if (isdigit(password[i])) {
            flag |= 1 << 2;
        } else if (ispunct(password[i])) {
            flag |= 1 << 3;
        }
        if (i < len && password[i] == password[i + 1]) {
            *result = false;
            goto finish;
        }
    }

    if (flag != 0x0Fu) {
        *result = false;
        goto finish;
    }

finish:
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;
    bool out;

    ret = strongPasswordCheckerII("IloveLe3tcode!", &out);
    assert(ret == 0), assert(out == true);

    ret = strongPasswordCheckerII("Me+You--IsMyDream", &out);
    assert(ret == 0), assert(out == false);

    ret = strongPasswordCheckerII("1aB!", &out);
    assert(ret == 0), assert(out == false);

    LOG("All tests pass!");

finish:
    return ret;
}
