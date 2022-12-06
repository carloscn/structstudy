#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "utils.h"

static int32_t counting_bits(size_t in, int32_t **out)
{
    int32_t ret = 0;
    size_t i = 0;

    UTILS_CHECK_LEN(in);
    UTILS_CHECK_PTR(out);

    *out = (int32_t *)malloc(sizeof(int32_t) * (in + 1));
    UTILS_CHECK_PTR(*out);

    for (i = 0; i < in + 1; i ++) {
        int32_t count = 0;
        int32_t e = i;
        do {
            count += e & 1;
            e >>= 1;
        } while (e);
        (*out)[i] = count;
    }

finish:
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;
    int32_t *array = NULL;
    size_t i = 0;
    for (i = 0; i < 15; i ++) {
        ret = counting_bits(i, &array);
        UTILS_CHECK_RET(ret);
        if (array != NULL) {
            utils_print_int32_array(array, i, "output: ");
            free(array);
        }
    }

finish:
    return ret;
}