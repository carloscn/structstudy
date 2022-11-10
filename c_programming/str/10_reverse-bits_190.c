#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include "buffer.h"
#include "utils.h"

static int32_t reverse_bits(const char *str, uint32_t *out)
{
    int32_t ret = 0;
    size_t len = 0;
    uint32_t val = 0;

    UTILS_CHECK_PTR(str);
    UTILS_CHECK_PTR(out);

    len = strlen(str);

    if (0 == len)
        goto finish;

    do {
        val += ('1' == str[--len]);
        val <<= (0U != len);
    } while (len);

    *out = val;

finish:
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;
    uint32_t val = 0;

    ret = reverse_bits("00000010100101000001111010011100", &val);
    UTILS_CHECK_RET(ret);
    LOG("the val is %u\n", val);
    utils_print_32_value_by_binary(val);

    ret = reverse_bits("11111111111111111111111111111101", &val);
    UTILS_CHECK_RET(ret);
    LOG("the val is %u\n", val);
    utils_print_32_value_by_binary(val);

    ret = reverse_bits("00000000000000000000000000000000", &val);
    UTILS_CHECK_RET(ret);
    LOG("the val is %u\n", val);
    utils_print_32_value_by_binary(val);

    ret = reverse_bits("11111111111111111111111111110000", &val);
    UTILS_CHECK_RET(ret);
    LOG("the val is %u\n", val);
    utils_print_32_value_by_binary(val);

finish:
    return ret;
}