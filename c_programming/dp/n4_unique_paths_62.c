#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <ctype.h>
#include "utils.h"

static int32_t dp[100][100];

static int32_t unique_paths(int32_t m, int32_t n)
{
    int32_t ret = 0;
    size_t i = 0;
    size_t j = 0;

    if (m > 100 || n > 100 || m == 0 || n == 0) {
        return 0;
    }

    // init dp array
    for (i = 0; i < 100; i ++) {
        dp[0][i] = 1;
        dp[i][0] = 1;
    }

    // dp[m][n] = dp[m-1][n] + dp[m][n-1];
    for (i = 1; i < n; i ++) {
        for (j = 1; j < m; j ++) {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }

    ret = dp[i - 1][j - 1];

    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;
    size_t m = 10;
    size_t n = 10;
    ret = unique_paths(m, n);
    utils_print_two_dim_array_int32_t((int32_t *)dp, m, n, ARRAY_SIZE(dp));
    assert(ret == 48620);

    LOG("test pass!\n");
finish:
    return ret;
}
