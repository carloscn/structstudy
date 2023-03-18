#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "utils.h"

int32_t fib_num(size_t n)
{
    int32_t dp[] = {0, 1, 1};
    size_t i = 0;

    // dp[i] = dp[i - 1] + dp[i - 2]
    for (i = 0; i < n; i ++) {
        dp[2] = dp[1] + dp[0];
        dp[0] = dp[1];
        dp[1] = dp[2];
    }

    return dp[2];
}

int32_t main(void)
{
    int32_t ret = 0;
    size_t i = 0;

    for (i = 0; i < 30; i ++) {
        ret = fib_num(i);
        LOG("the %zu ret is %d\n", i, ret);
    }

finish:
    return ret;
}