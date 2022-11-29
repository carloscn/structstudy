#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "utils.h"
#include "queue.h"

// 1 1 0 5 0 5 8 9
static int32_t remove_zeros(int64_t *array, size_t len)
{
    int32_t ret = 0;
    size_t i = 0;
    QUEUE_T *queue = NULL;

    UTILS_CHECK_LEN(len);
    UTILS_CHECK_PTR(array);

    queue = queue_malloc(len);
    UTILS_CHECK_PTR(queue);

    for (i = 0; i < len; i ++) {
        if (0 != array[i]) {
            ret = queue_push(queue, array[i]);
            UTILS_CHECK_RET(ret);
        }
    }

    memset(array, 0, len * sizeof(int64_t));
    memcpy(array, queue->space, len * sizeof(int64_t));

finish:
    queue_free(queue);
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;
    uint64_t array1[] = {0,1,0,3,12};

    ret = remove_zeros(array1, ARRAY_SIZE(array1));
    UTILS_CHECK_RET(ret);
    utils_print_int64_array(array1, ARRAY_SIZE(array1), "output : ");

finish:
    return ret;
}