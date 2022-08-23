#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*
 *         / 0               (n = 0)
 * f(n) = |  1               (n = 1)
 *         \ f(n-1) + f(n-2) (n > 1)
*/
static int32_t fib_1(uint32_t n)
{
    int32_t result[2] = {0, 1};
    if (n < 0) {
        printf("input n shall be bigger than -1\n");
        return -1;
    }
    if (n <= 1) {
        return result[n];
    }
    return fib_1(n-1) + fib_1(n-2);
}

// using the cache results.
static int32_t fib_result[100] = {0, 1, 0};
static int32_t result_count = 2;
static int32_t fib_2(uint32_t n)
{
    if (n < 0) {
        printf("input n shall be bigger than -1\n");
        return -1;
    }
    if (n < result_count) {
        return fib_result[n];
    }
    fib_result[n] = fib_2(n-1) + fib_2(n-2);
    result_count ++;
    return fib_result[n];
}

// loop
static int32_t fib_3(uint32_t n) {

    int32_t result[2] = {0, 1};

    if (n < 0) {
        printf("input n shall be bigger than -1\n");
        return -1;
    }
    if (n <= 1) {
        return result[n];
    }

    size_t i = 0;
    int32_t last_f_n_1 = 0, last_f_n_2 = 1;
    int32_t f_n = 0;
    for (i = 2; i <= n; ++ i) {
        f_n = last_f_n_1 + last_f_n_2;
        last_f_n_1 = last_f_n_2;
        last_f_n_2 = f_n;
    }

    return f_n;
}

int main(void)
{
    clock_t start, end;
    start = clock();
    printf("\nfib_1 = %d\n", fib_1(30));
    end = clock();
    printf("method 1 time = %fs\n", (double)(end - start) / CLOCKS_PER_SEC);

    start = clock();
    printf("\nfib_2 = %d\n", fib_2(30));
    end = clock();
    printf("method 2 time = %fs\n", (double)(end - start) / CLOCKS_PER_SEC);

    start = clock();
    printf("\nfib_3 = %d\n", fib_3(30));
    end = clock();
    printf("method 3 time = %fs\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}