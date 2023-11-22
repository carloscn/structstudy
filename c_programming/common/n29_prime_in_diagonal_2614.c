#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include "utils.h"

static bool is_prime(int32_t num)
{
    int32_t n = num, i, flag = 0;

    for (i = 2; i <= n/2; ++ i)  {
        if (n % i == 0) {
            flag = 1;
            break;
        }
    }
    if (n <= 1) {
        flag = 1;
    }

    return flag == 0;
}

static int32_t diagonal_prime(int32_t nums[][3], size_t len)
{
    int32_t ret = 0;

    UTILS_CHECK_PTR(nums);
    UTILS_CHECK_LEN(len);

    ret = INT32_MIN;
    for (size_t i = 0; i < len; i ++) {
        if (is_prime(nums[i][i])) {
            ret = UTILS_MAX(nums[i][i], ret);
        }
        if (is_prime(nums[i][len - i - 1])) {
            ret = UTILS_MAX(nums[i][len - i - 1], ret);
        }
    }

finish:
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;
    int32_t rom1[3][3] =  {{1,2,3},
                          {5,6,7},
                          {9,10,11}};
    int32_t rom2[3][3] =  {{1,2,3},
                          {5,17,7},
                          {9,11,10}};
    ret = diagonal_prime(rom1, 3);
    assert(ret == 11);

    ret = diagonal_prime(rom2, 3);
    assert(ret == 17);

    LOG("All tests have passed!\n");

finish:
    return 0;
}

// gcc -I./utils/ ./utils/utils.c ./common/n29_prime_in_diagonal_2614.c && ./a.exe