#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

static int32_t gen_pascals_triangle(int64_t **return_array, size_t *n)
{
    int32_t ret = 0;
    size_t i = 0, j = 0;
    int64_t *new_array = NULL;
    int64_t *last_array = NULL;
    size_t depth = 0;

    UTILS_CHECK_PTR(n);

    if (*n > 33 || 0 == *n) {
        ret = -1;
        LOG("input error n is over the 33, or is 0.\n");
        goto finish;
    }

    UTILS_CHECK_PTR(return_array);

    for (i = 0; i < *n; i ++) {
        last_array = new_array;
        new_array = NULL;
        new_array = (int64_t*)malloc(sizeof(int64_t) * (i + 1));
        UTILS_CHECK_PTR(new_array);
        new_array[0] = new_array[i] = 1;
        depth ++;

        if (i < 2) {
            last_array = new_array;
            continue;
        }

        for (j = 1; j <= depth - 2; j ++)
            new_array[j] = last_array[j] + last_array[j - 1];

        if (NULL != last_array)
            free(last_array);
    }

    *return_array = new_array;
    *n = depth;

finish:
    return ret;
}

int main(void)
{
    int32_t ret = 0;
    size_t depth, i = 0;
    int64_t *array = NULL;
    for (i = 1; i < 33; i ++) {
        depth = i;
        LOG("try the depth %zu :\n", depth);
        ret = gen_pascals_triangle(&array, &depth);
        UTILS_CHECK_RET(ret);
        utils_print_int64_array(array, depth, "list: ");
        if (NULL != array) {
            free(array);
            array = NULL;
        }
    }
finish:
    if (NULL != array)
        free(array);
    return ret;
}
