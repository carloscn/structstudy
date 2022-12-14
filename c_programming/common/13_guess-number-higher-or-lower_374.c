#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "utils.h"

static int64_t pick_num = 0;

static void rec_guess(int64_t k, int64_t n)
{
    if (k == pick_num) {
        return;
    }
    k = k + ((k > pick_num) ? (-1 * k / 2) : (k / 2));
    LOG("the guess value is %ld\n", k);
    rec_guess(k, n);
}

static int64_t return_guess(int64_t n)
{
    rec_guess(n/2, n);
}

int main(void)
{
    int64_t res = 0;

    pick_num = 129;
    res = return_guess(10000000);
    LOG("the result is %d\n", res);
}