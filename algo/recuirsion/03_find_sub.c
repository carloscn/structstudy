#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "stack.h"
#include "utils.h"
// 1 2 3 4

static STACK_T path;
static int32_t count = 0;
static void backingtrace_comb(int64_t *array, int32_t n, int32_t k, int32_t sp)
{
    int32_t x = 0;
    int64_t e = 0;

    if (NULL == array) {
        LOG("input parameter error\n");
        return;
    }

    // end condition
    if (stack_count(&path) == k) {
        stack_print(&path);
        count ++;
        return;
    }

    for (x = sp; x < n; x++) {
        stack_push(&path, array[x]);
        backingtrace_comb(array, n, k, sp + 1);
        stack_pop(&path, &e);
        sp ++;
    }

}

static void backtracing_sub(int64_t *array, int32_t n, int32_t k, int32_t sp)
{
    int32_t x = 0, s = 1;
    int64_t e = 0;

    if (NULL == array) {
        LOG("input parameter error\n");
        return;
    }

    if (stack_count(&path) == k) {
        stack_print(&path);
        count ++;
        return;
    }

    for (x = sp; x < n; x ++) {
        stack_push(&path, array[x]);
        backtracing_sub(array, n, k, sp + 1);
        stack_pop(&path, &e);
        sp ++;
    }
}

static int32_t find_sub(int64_t *array, int32_t n, int32_t k, int32_t sp)
{
    size_t s = 0;

    for (s = 1; s < n + 1; s++) {
        backtracing_sub(array, n, s, sp);
    }
    printf("find %d sub array\n", count);
    return 0;
}

int main(void)
{
    int32_t ret = 0;
    int64_t test_array[] = {1,2,3,4,5,6,7,8};
    int32_t step_len = 3;

    count = 0;
    ret = stack_malloc(&path, STACK_DEFAULT_SIZE);
    if (ret != 0) {
        return -1;
    }
    if (ARRAY_SIZE(test_array) > stack_get_size(&path)) {
        LOG("input array too long.\n");
        return -1;
    }

    ret = find_sub(test_array, ARRAY_SIZE(test_array), 1, 0);
    if (ret != 0) {
        LOG("find failed\n");
    }
    stack_free(&path);
    return 0;
}