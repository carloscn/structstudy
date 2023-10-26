#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>
#include "utils.h"
#include "buffer.h"

static int32_t distinct_averages(int64_t *nums, size_t nums_size)
{
    int32_t ret = 0;
    float *rom = NULL;
    BUFFER_T *buffer = NULL;

    UTILS_CHECK_PTR(nums);
    UTILS_CHECK_LEN(nums_size);

    size_t rom_index = 0;
    rom = (float *)calloc(nums_size, sizeof(float));
    UTILS_CHECK_PTR(rom);

    buffer = buffer_malloc(nums_size);
    UTILS_CHECK_PTR(buffer);

    ret = buffer_append_array(buffer, nums, nums_size);
    UTILS_CHECK_RET(ret);
    do {
        size_t max_index, min_index;
        int64_t max_value, min_value;
        ret = buffer_get_max_value(buffer, &max_index, &max_value) || \
              buffer_remove(buffer, max_index, NULL);
        UTILS_CHECK_RET(ret);
        ret = buffer_get_min_value(buffer, &min_index, &min_value) || \
              buffer_remove(buffer, min_index, NULL);
        UTILS_CHECK_RET(ret);
        rom[rom_index ++] = ((float)max_value + (float)min_value) / 2.0f;
    } while (buffer_get_current_len(buffer) != 0);

finish:
    UTILS_SAFE_FREE(rom);
    buffer_free(buffer);
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;
    int64_t array1[] = {4,1,4,0,3,5};
    int64_t array2[] = {1,2,4,7,10};

    ret = distinct_averages(array1, ARRAY_SIZE(array1));
    assert(ret == 0);

    ret = distinct_averages(array2, ARRAY_SIZE(array2));
    assert(ret == 0);

    LOG("All tests have passed!\n");

finish:
    return ret;
}