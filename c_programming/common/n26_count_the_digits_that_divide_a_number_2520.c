#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include "utils.h"

static int32_t count_digits(int32_t num)
{
    int32_t ret = 0;
    int32_t num_dup = num;

    while (num_dup != 0) {
        ret += ((num % (num_dup % 10)) == 0) ? 1 : 0;
        num_dup /= 10;
    }

finish:
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;

    ret = count_digits(7);
    assert(ret == 1);

    ret = count_digits(121);
    assert(ret == 2);

    ret = count_digits(1248);
    assert(ret == 4);

    LOG("All tests have passed!\n");

finish:
    return 0;
}