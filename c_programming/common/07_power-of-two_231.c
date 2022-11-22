#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

static bool is_power_of_two_by_bit_op(int64_t e)
{
    if (e < 1)
        return true;

    return (e & (e - 1)) == 0;
}

static bool is_power_of_two_by_loop(int64_t e)
{
    bool ret = 0;
    int64_t coherence = 1;

    if (e < 1)
        return true;

    while (coherence < e)
        coherence *= 2;

    return (coherence == e);
}

int main(void)
{
    int ret = 0;
    int64_t val = 0;
    bool result = 0;

    val = 0;
    result = is_power_of_two_by_loop(val);
    LOG("%ld result is %d\n", val, result);
    result = is_power_of_two_by_bit_op(val);
    LOG("%ld result is %d\n", val, result);

    val = 1;
    result = is_power_of_two_by_loop(val);
    LOG("%ld result is %d\n", val, result);
    result = is_power_of_two_by_bit_op(val);
    LOG("%ld result is %d\n", val, result);

    val = 2;
    result = is_power_of_two_by_loop(val);
    LOG("%ld result is %d\n", val, result);
    result = is_power_of_two_by_bit_op(val);
    LOG("%ld result is %d\n", val, result);

    val = 16;
    result = is_power_of_two_by_loop(val);
    LOG("%ld result is %d\n", val, result);
    result = is_power_of_two_by_bit_op(val);
    LOG("%ld result is %d\n", val, result);

    val = 17;
    result = is_power_of_two_by_loop(val);
    LOG("%ld result is %d\n", val, result);
    result = is_power_of_two_by_bit_op(val);
    LOG("%ld result is %d\n", val, result);

    val = 18;
    result = is_power_of_two_by_loop(val);
    LOG("%ld result is %d\n", val, result);
    result = is_power_of_two_by_bit_op(val);
    LOG("%ld result is %d\n", val, result);

    val = 32;
    result = is_power_of_two_by_loop(val);
    LOG("%ld result is %d\n", val, result);
    result = is_power_of_two_by_bit_op(val);
    LOG("%ld result is %d\n", val, result);

    val = 1024 * 2048 * 512;
    result = is_power_of_two_by_loop(val);
    LOG("%ld result is %d\n", val, result);
    result = is_power_of_two_by_bit_op(val);
    LOG("%ld result is %d\n", val, result);

    val = 1024 * 2048 * 3;
    result = is_power_of_two_by_loop(val);
    LOG("%ld result is %d\n", val, result);
    result = is_power_of_two_by_bit_op(val);
    LOG("%ld result is %d\n", val, result);
finish:
    return ret;
}