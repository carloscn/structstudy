#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include "utils.h"

bool is_same_after_reversals(int32_t num)
{
    return (num % 10 != 0) || (num < 9);
}

int32_t main(void)
{
    bool ret = false;

    ret = is_same_after_reversals(526);
    assert(ret == true);

    ret = is_same_after_reversals(1800);
    assert(ret == false);

    ret = is_same_after_reversals(0);
    assert(ret == true);

    LOG("All tests have passed!\n");

finish:
    return 0;
}