#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "utils.h"

static uint64_t glb_bad_version = 0;

static inline bool is_bad_version(uint64_t val)
{
    return val >= glb_bad_version;
}

static int32_t first_bad_version(const uint64_t *array, size_t n, uint64_t bad_version, uint64_t *result)
{
    int32_t ret = 0;
    uint64_t left = 0;
    uint64_t right = n - 1;
    uint64_t mid = 0;

    UTILS_CHECK_LEN(n);
    UTILS_CHECK_PTR(array);
    UTILS_CHECK_PTR(result);

    glb_bad_version = bad_version;

    while (left <= right) {
        mid = left + (right - left) / 2;
        if (is_bad_version(mid))
            right = mid - 1;
        else
            left = mid + 1;
    }

    *result = left;

finish:
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;
    uint64_t array1[10240] = {0};
    uint64_t result = 0;
    size_t i = 0;

    for (i = 0; i < 10240; i ++) {
        array1[i] = (uint64_t)i;
    }

    ret = first_bad_version(array1, ARRAY_SIZE(array1), 7885, &result);
    UTILS_CHECK_RET(ret);
    LOG("the result is %lld\n", result);

finish:
    return ret;
}