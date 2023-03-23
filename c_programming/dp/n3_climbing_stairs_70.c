#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include "utils.h"

int32_t claim_stairs(size_t n)
{
    int32_t ret = 0;
    size_t i = 0;
    int32_t dp[3] = {0,1,2};

    switch (n) {
        case 0:
            ret = 0;
            break;
        case 1:
            ret = 1;
            break;
        case 2:
            ret = 2;
            break;
        default:
        // dp(x) = dp(x - 1) + dp(x - 2)
        for (i = 0; i < n; i ++) {
            dp[2] = dp[1] + dp[0];
            dp[0] = dp[1];
            dp[1] = dp[2];
        }
        ret = dp[2];
        break;
    }

finish:
    return ret;
}

int main(void)
{
    assert(claim_stairs(0) == 0);
    assert(claim_stairs(1) == 1);
    assert(claim_stairs(2) == 2);
    assert(claim_stairs(3) == 3);
    assert(claim_stairs(4) == 5);
    assert(claim_stairs(5) == 8);
    assert(claim_stairs(6) == 13);

    return 0;
}