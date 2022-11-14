#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"


static int64_t get_happy(int64_t e)
{
    int32_t sum = 0;
    int32_t a = 0;

    while (e != 0) {
        a = e % 10;
        sum += a * a;
        e /= 10;
    }

    return sum;
}

static bool is_happy_number(int64_t e)
{
    int64_t fast_happy = e;
    int64_t slow_happy = e;

    do {
        fast_happy = get_happy(fast_happy);
        fast_happy = get_happy(fast_happy);
        slow_happy = get_happy(slow_happy);
        // LOG("fast happy is %lld\n", fast_happy);
        // LOG("slow happy is %lld\n\n", slow_happy);
    } while (slow_happy != fast_happy);

    return (slow_happy == 1);
}

int main(void)
{
    int ret = 0;
    int32_t val = 0;
    bool result = 0;

    val = 2;
    result = is_happy_number(val);
    UTILS_CHECK_RET(ret);
    LOG("the result is %d\n", result);

    val = 19;
    result = is_happy_number(val);
    UTILS_CHECK_RET(ret);
    LOG("the result is %d\n", result);

    val = 1200;
    result = is_happy_number(val);
    UTILS_CHECK_RET(ret);
    LOG("the result is %d\n", result);

    val = 1000;
    result = is_happy_number(val);
    UTILS_CHECK_RET(ret);
    LOG("the result is %d\n", result);

finish:
    return ret;
}