#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

struct triangle_t {
    size_t depth;
    int64_t *array_list[30];
};

static int32_t gen_pascals_triangle(struct triangle_t* triangle, size_t n)
{
    int32_t ret = 0;
    size_t i = 0, j = 0;
    int64_t *new_array = NULL;

    if (n > 30 || 0 == n) {
        ret = -1;
        LOG("input error n is over the 30, or is 0.\n");
        goto finish;
    }

    UTILS_CHECK_PTR(triangle);
    triangle->depth = 0;

    for (i = 0; i < n; i ++) {
        new_array = NULL;
        new_array = (int64_t*)malloc(sizeof(int64_t) * (i + 1));
        UTILS_CHECK_PTR(new_array);

        new_array[0] = new_array[i] = 1;
        triangle->array_list[i] = new_array;
        triangle->depth ++;

        if (i < 2)
            continue;

        for (j = 1; j <= triangle->depth - 2; j ++) {
            new_array[j] = (triangle->array_list[i - 1])[j] + \
                           (triangle->array_list[i - 1])[j - 1];
        }
    }

finish:
    return ret;
}

static void free_triangle(struct triangle_t* triangle)
{
    size_t i = 0;

    if (NULL == triangle) {
        return;
    }

    for (i = 0; i < triangle->depth; i ++) {
        if (NULL != triangle->array_list[i])
            free(triangle->array_list[i]);
    }

    triangle->depth = 0;
}

int main(void)
{
    int32_t ret = 0;
    size_t i = 0;
    struct triangle_t tran;

    ret = gen_pascals_triangle(&tran, 30);
    UTILS_CHECK_RET(ret);

    for (i = 0; i < tran.depth; i ++) {
        utils_print_int64_array(tran.array_list[i], i + 1, "list: ");
    }

finish:
    free_triangle(&tran);
    return ret;
}
