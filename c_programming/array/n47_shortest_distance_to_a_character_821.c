#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "utils.h"

// s = "loveleetcode", c = "e", [3,5,6,11]
static int32_t shortest_distance(const char *in_str, char c, int32_t *array)
{
    int32_t ret = 0;
    size_t in_len = 0;
    size_t *c_index = NULL;
    size_t c_len = 0;
    size_t i = 0;
    size_t j = 0;
    size_t d = 0, min_d = ~0;

    UTILS_CHECK_PTR(in_str);
    UTILS_CHECK_PTR(array);
    UTILS_CHECK_LEN(in_len = strlen(in_str));

    c_index = (size_t *)calloc(sizeof(size_t), in_len);
    UTILS_CHECK_PTR(c_index);

    for (i = 0; i < in_len; i ++) {
        if (c == in_str[i]) {
            c_index[c_len] = i;
            c_len ++;
        }
    }
    UTILS_CHECK_LEN(c_len);

    for (i = 0; i < in_len; i ++) {
        for (j = 0; j < c_len; j ++) {
            d = utils_int32_abs((int32_t)i - (int32_t)c_index[j]);
            min_d = d < min_d ? d : min_d;
        }
        array[i] = min_d;
        min_d = ~0;
    }

finish:
    UTILS_SAFE_FREE(c_index);
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;
    int32_t array[1024] = {0};

    ret = shortest_distance("loveleetcode", 'e', array);
    UTILS_CHECK_RET(ret);

    utils_print_int32_array(array, strlen("loveleetcode"), "hello:");

finish:
    return ret;
}