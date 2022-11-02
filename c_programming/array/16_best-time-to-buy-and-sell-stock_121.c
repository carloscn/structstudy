#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

static int32_t max_profit(int64_t *prices_array, size_t sz)
{
    int32_t ret = 0;
    size_t i = 0;
    int64_t buy_price = 0;
    int64_t sell_price = 0;
    size_t buy_day = 0;
    size_t sell_day = 0;

    UTILS_CHECK_PTR(prices_array);

    if (0 == sz) {
        goto finish;
    }

    // find mini price to buy
    buy_price = prices_array[0];
    for (i = 1; i < sz; i ++) {
        if (buy_price > prices_array[i]) {
            buy_price = prices_array[i];
            buy_day = i;
        }
    }

    LOG("the buy day is %zu, buy price is %lld\n",
        buy_day + 1,
        buy_price);

    // find max price to sell
    if (buy_day < sz - 1) {
        sell_price = prices_array[buy_day + 1];
        for (i = buy_day + 2 ; i < sz; i ++) {
            if (sell_price < prices_array[i]) {
                sell_price = prices_array[i];
                sell_day = i;
            }
        }
        LOG("the sell day is %zu, sell price is %lld, profit is %lld\n",
             sell_day + 1,
             sell_price,
             sell_price - buy_price);
    } else {
        LOG("should not sell\n");
    }

finish:
    return ret;
}

int main(void)
{
    int32_t ret = 0;
    int64_t array1[] = {7,1,5,3,6,4};
    int64_t array2[] = {7,6,4,3,1};

    ret = max_profit(array1, ARRAY_SIZE(array1));
    UTILS_CHECK_RET(ret);

    ret = max_profit(array2, ARRAY_SIZE(array2));
    UTILS_CHECK_RET(ret);

finish:

    return ret;
}
