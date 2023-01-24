#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdbool.h>
#include "../utils/utils.h"

static int32_t teemo_attack(int32_t *time_ser, int32_t *len, int32_t duration)
{
    int32_t ret = 0;
    int32_t sum_duration = duration;
    int32_t i = 0;

    UTILS_CHECK_PTR(len);
    UTILS_CHECK_LEN(*len);
    UTILS_CHECK_PTR(time_ser);

    for (i = 0; i < *len - 1; i ++) {
        sum_duration += MIN(time_ser[i + 1] - time_ser[i], duration);
    }

    *len = sum_duration;

finish:
    return ret;
}

int main(void)
{   
    int32_t ret = 0;
    int32_t len = 0;
    int32_t time_ser[] = {1,2};
    len = ARRAY_SIZE(time_ser);
    ret = teemo_attack(time_ser, &len, 2);
    LOG("the result is %d\n", len);

    return 0;
}