#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

static int32_t reverse_integer(int32_t *e)
{
    int32_t ret = 0;
    int32_t result = 0;
    int32_t val = 0;

    UTILS_CHECK_PTR(e);
    val = *e;

    if (0 == val)
        goto finish;

    while (val != 0) {
        result = val % 10 + result * 10;
        val /= 10;
    }

    *e = result;
finish:
    return ret;
}

int main(void)
{
    int ret = 0;
    size_t i = 0;
    int32_t val = 0;

    val = 123;
    ret = reverse_integer(&val);
    UTILS_CHECK_RET(ret);
    LOG("the result is %d\n", val);

    val = -123456;
    ret = reverse_integer(&val);
    UTILS_CHECK_RET(ret);
    LOG("the result is %d\n", val);

    val = -1;
    ret = reverse_integer(&val);
    UTILS_CHECK_RET(ret);
    LOG("the result is %d\n", val);

    val = 0;
    ret = reverse_integer(&val);
    UTILS_CHECK_RET(ret);
    LOG("the result is %d\n", val);

finish:
    return ret;
}