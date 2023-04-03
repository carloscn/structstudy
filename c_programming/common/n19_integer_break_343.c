#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>
#include "utils.h"

int32_t integer_break(int32_t n)
{
    size_t i = 0;
    int32_t m = sqrt(n);
    int32_t k = ceil(sqrt(n));
    int32_t left = n;
    int32_t left_ceil = n;
    int32_t mul = 1;
    int32_t mul_ceil = 1;

    if (n <= 2) {
        return 1;
    }

    LOG("the m is %d, k = %d\n", m, k);

    for (i = 0; i < n/m - 1; i ++) {
        mul *= m;
        left -= m;
    }

    if (left != 0) {
        mul *= left;
    }

    for (i = 0; i < n/k - 1; i ++) {
        mul_ceil *= k;
        left_ceil -= k;
    }

    if (left_ceil != 0) {
        mul_ceil *= left_ceil;
    }

    return mul_ceil > mul ? (mul_ceil) : (mul);
}

int32_t main(void)
{
    int32_t ret = 0;

    int n, expected;

    // Test case 1
    n = 2;
    expected = 1;
    int result = integer_break(n);
    printf("Test case 1: integerBreak(%d) = %d (expected %d)\n", n, result, expected);

    // Test case 2
    n = 10;
    expected = 36;
    result = integer_break(n);
    printf("Test case 2: integerBreak(%d) = %d (expected %d)\n", n, result, expected);

    // Test case 3
    n = 4;
    expected = 4;
    result = integer_break(n);
    printf("Test case 3: integerBreak(%d) = %d (expected %d)\n", n, result, expected);

    // Test case 4
    n = 5;
    expected = 6;
    result = integer_break(n);
    printf("Test case 4: integerBreak(%d) = %d (expected %d)\n", n, result, expected);

    // Test case 5
    n = 8;
    expected = 18;
    result = integer_break(n);
    printf("Test case 5: integerBreak(%d) = %d (expected %d)\n", n, result, expected);

    // Test case 6
    n = 12;
    expected = 81;
    result = integer_break(n);
    printf("Test case 6: integerBreak(%d) = %d (expected %d)\n", n, result, expected);

    // Test case 7
    n = 15;
    expected = 243;
    result = integer_break(n);
    printf("Test case 7: integerBreak(%d) = %d (expected %d)\n", n, result, expected);

    // Test case 8
    n = 20;
    expected = 1458;
    result = integer_break(n);
    printf("Test case 8: integerBreak(%d) = %d (expected %d)\n", n, result, expected);

    // Test case 9
    n = 25;
    expected = 8748;
    result = integer_break(n);
    printf("Test case 9: integerBreak(%d) = %d (expected %d)\n", n, result, expected);
    return 0;
}
