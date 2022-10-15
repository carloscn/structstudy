#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include "utils.h"

static int32_t sort(int64_t *array, size_t sz)
{
    int32_t ret = 0;
    size_t i = 0, index_1 = 0, index_3 = sz - 1;

    if (0 == sz)
        goto finish;
    UTILS_CHECK_PTR(array);

    for (i = 0; i <= index_3; i ++) {
        if (array[i] == 1) {
            utils_swap(array + i, array + index_1);
            index_1 ++;
        } else if (array[i] == 3) {
            utils_swap(array + i, array + index_3);
            index_3 --;
            i --;
        } else {
            continue;
        }
    }

finish:
    return ret;
}

int main(void)
{
    int32_t ret = 0;
    int64_t array[] = {1,3,2,3,1,1,2,1};

    utils_print_int64_array(array, ARRAY_SIZE(array), "input : ");
    ret = sort(array, ARRAY_SIZE(array));
    UTILS_CHECK_RET(ret);
    utils_print_int64_array(array, ARRAY_SIZE(array), "output: ");

finish:
    return ret;
}