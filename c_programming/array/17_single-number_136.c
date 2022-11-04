#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

static int32_t single_number(int64_t *array, size_t array_len, int64_t *value)
{   
    int32_t ret = 0;
    size_t i = 0, j = 0;
    int64_t target = 0;
    int64_t count = 0;

    UTILS_CHECK_PTR(array);
    UTILS_CHECK_PTR(value);
    
    if (0 == array_len) {
        goto finish;
    }

    for (i = 0; i < array_len; i ++) {
        count = 0;
        target = array[i];
        for (j = 0; j < array_len; j ++) {
            if (target == array[j] && i != j) {
                count ++;
                break;
            }
        }
        if (0 == count) {
            *value = target;
            break;
        }
    }

finish:
    return ret;
}


int main(void)
{
    int32_t ret = 0;
    int64_t array1[] = {1,2,2,3,3};
    int64_t array2[] = {2,5,2,5,7};
    int64_t array3[] = {8,8,9,7,7};
    int64_t value = 0;

    ret = single_number(array1, ARRAY_SIZE(array1), &value);
    UTILS_CHECK_RET(ret);
    LOG("the output value is %zd\n\n", value);

    ret = single_number(array2, ARRAY_SIZE(array2), &value);
    UTILS_CHECK_RET(ret);
    LOG("the output value is %zd\n\n", value);

    ret = single_number(array3, ARRAY_SIZE(array3), &value);
    UTILS_CHECK_RET(ret);
    LOG("the output value is %zd\n\n", value);

finish:
    return ret;
}
