#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "utils.h"

static int32_t sum3(int64_t *array,
                    size_t sz,
                    int64_t **out_index_array,
                    size_t *depth)
{
    int32_t ret = 0;
    size_t i = 0, j = 0, k = 0;
    size_t dep = 0;
    int64_t *buf = NULL;

    UTILS_CHECK_LEN(sz);
    UTILS_CHECK_PTR(array);
    UTILS_CHECK_PTR(depth);
    UTILS_CHECK_PTR(out_index_array);

    if (sz < 3) {
        ret = -1;
        LOG("input array length error \n");
        goto finish;
    }

    for (i = 0; i < sz; i ++) {
        for (j = i + 1; j < sz; j ++) {
            for (k = j + 1; k < sz; k ++) {
                if ((array[i] + array[j] + array[k] == 0) &&
                    (i != j) && (j != k)) {
                    buf = NULL, buf = (int64_t*)malloc(sizeof(int64_t) * 3);
                    UTILS_CHECK_PTR(buf);
                    buf[0] = array[i], buf[1] = array[j], buf[2] = array[k];
                    out_index_array[dep ++] = buf;
                }
            }
        }
    }
    *depth = dep;

finish:
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;
    int64_t array1[] = {-1,0,1,2,-1,-4,0,0,0,0,9,20,20,2,9,-1,0,0,0,0,0,0,0,99,3,2,1,15,16,17,18,19,20,21,22,23,24,0,0,0,0};
    int64_t value = 0;
    int64_t *buf_list[50];
    int64_t *buf = NULL;
    size_t depth = 0;
    size_t i = 0, j = 0;

    ret = sum3(array1, ARRAY_SIZE(array1), buf_list, &depth);
    UTILS_CHECK_RET(ret);

    printf("\n");
    for (i = 0; i < depth; i ++) {
        buf = buf_list[i];
        for (j = 0; j < 3; j ++) {
            printf("%lld,", buf[j]);
        }
        printf("\n");
    }
    printf("\n");

    for (i = 0; i < depth; i ++) {
        if (buf_list[i] != NULL)
            free(buf_list[i]);
    }
finish:
    return ret;
}