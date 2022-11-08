#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

// 1 2 3 3 3 5 6 3 
static int32_t majority_element(const int64_t *array, size_t array_size, int64_t *out)
{
    int32_t ret = 0;
    size_t i = 0, j = 0;
    size_t count = 0, max_count = 0;
    int64_t target = 0;
    
    UTILS_CHECK_PTR(array);
    UTILS_CHECK_PTR(out);
    
    if (0 == array_size)
        goto finish;

    for (i = 0; i < array_size; i ++) {
        target = array[i];
        for (j = i + 1; j < array_size; j ++) {
            if (target == array[j]) {
                max_count = (++count >= max_count) ?    \
                            (*out = target, count) : max_count;
            }
        }
    }

finish:
    return ret;
}

int main(void)
{
    int32_t ret = 0;
    int64_t array1[] = {1,2,2,3,3,3};
    int64_t array2[] = {2,5,2,5,7,2};
    int64_t array3[] = {8,8,9,7,7,8,9,9,9,9,9,9};
    int64_t value = 0;

    ret = majority_element(array1, ARRAY_SIZE(array1), &value);
    UTILS_CHECK_RET(ret);
    LOG("the output value is %zd\n\n", value);

    ret = majority_element(array2, ARRAY_SIZE(array2), &value);
    UTILS_CHECK_RET(ret);
    LOG("the output value is %zd\n\n", value);

    ret = majority_element(array3, ARRAY_SIZE(array3), &value);
    UTILS_CHECK_RET(ret);
    LOG("the output value is %zd\n\n", value);

finish:
    return ret;
}
