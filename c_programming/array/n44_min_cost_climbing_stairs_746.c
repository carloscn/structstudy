#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "utils.h"

static int32_t min_cost_climbing(const int32_t *cost, size_t len, int32_t *spend)
{
    int32_t ret = 0;
    size_t i = 0;
    int32_t *dp = NULL;

    UTILS_CHECK_PTR(cost);
    UTILS_CHECK_PTR(spend);
    UTILS_CHECK_LEN(len);

    dp = (int32_t *)calloc(sizeof(uint32_t), len + 1);
    UTILS_CHECK_PTR(dp);

    for (i = 2; i <= len; i ++) {
        dp[i] = UTILS_MIN(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
    }

    *spend = dp[len];
finish:
    UTILS_SAFE_FREE(dp);
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;
    int32_t cost[] = {1,100,1,1,1,100,1,1,100,1};
    int32_t spend = 0;

    ret = min_cost_climbing(cost, ARRAY_SIZE(cost), &spend);
    UTILS_CHECK_RET(ret);
    LOG("the spend is %d\n", spend);

finish:
    return ret;
}