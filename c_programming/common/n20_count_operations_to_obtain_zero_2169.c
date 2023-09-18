#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include "utils.h"

int32_t count_operations(int32_t num1, int32_t num2)
{
    int32_t ret = 0;

    while (num1 != 0 && num2 != 0) {
        if (num1 >= num2) {
            num1 = num1 - num2;
        } else {
            num2 = num2 - num1;
        }
        ret ++;
    }

    return ret;
}

int32_t main(void)
{
    int32_t ret = false;

    ret = count_operations(2, 3);
    assert(ret == 3);

    ret = count_operations(10, 10);
    assert(ret == 1);

    LOG("All tests have passed!\n");

finish:
    return 0;
}
