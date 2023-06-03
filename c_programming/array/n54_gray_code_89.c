#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "utils.h"

bool is_gray(size_t a, size_t b)
{
    size_t i = 0;
    size_t r = 0;

    while (a != 0 || b != 0) {
        size_t e_a = (a = a >> i) & 0x1;
        size_t e_b = (b = b >> i) & 0x1;
        i ++;
        r ^= e_a ^ e_b;
    }

    return r == 1;
}

int32_t gray_code(size_t n, size_t *array, size_t *o_len)
{
    int32_t ret = 0;

    UTILS_CHECK_PTR(array);
    UTILS_CHECK_PTR(o_len);

    size_t i = 0;
    size_t len = 1;

    for (i = 0; i < n; i ++) {
        len *= 2;
    }

    size_t j;
    while (i < len) {
        j = i + 1;
        do {
            if (is_gray(i, j)) {
                array[i] = i;
                array[i + 1] = j;
                printf("the i & j is %zu, %zu\n", i, j);
                i += 2;
                break;
            }
            j ++;
        } while (1);
    }

    *o_len = len;

finish:
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;

    size_t array[1024];
    size_t len = 0;

    ret = gray_code(2, array, &len);
    UTILS_CHECK_RET(ret);

    utils_print_size_t_array(array, len, "out: ");

finish:
    return ret;
}