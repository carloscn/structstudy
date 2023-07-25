#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "utils.h"
#include "buffer.h"
#include "bufferlist.h"

int32_t subsets_with_dup(int32_t *array, size_t len)
{
    int32_t ret = 0;

    if (array == NULL || 0 == len) {
        ret = -1;
        goto finish;
    }

    BUFLIST_T *buffer_list = NULL;
    BUFFER_T *buffer = NULL;

    buffer_list = buflist_malloc();
    UTILS_CHECK_PTR(buffer_list);

    buffer = buffer_malloc(BUFFER_DEFUALT_SIZE);
    UTILS_CHECK_PTR(buffer);

    // collect subset
    int32_t num = 0, i = 0, j = 0, k = 0, n = 0;

    num = 1 << len;
    for(i = 0; i < num; i ++) {
        j = i;
        k = 0;
        n = 0;

        while (j) {
            if (j & 1) {
                buffer_push_tail(buffer, array[k]);
            }
            j >>= 1;
            k ++;
        }
        ret = buflist_add(buffer_list, buffer);
        UTILS_CHECK_RET(ret);
        buffer_clear(buffer);
    }

    // set the bufferlist
    ret = buflist_set(buffer_list);
    UTILS_CHECK_RET(ret);

    // print buffer list
    buflist_infolog(buffer_list);

finish:
    buffer_free(buffer);
    buflist_free(buffer_list);
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;
    int32_t array1[] = {1, 2, 2};
    int32_t array2[] = {0};

    ret = subsets_with_dup(array1, ARRAY_SIZE(array1));
    UTILS_CHECK_RET(ret);

    ret = subsets_with_dup(array2, ARRAY_SIZE(array2));
    UTILS_CHECK_RET(ret);

finish:
    return ret;
}