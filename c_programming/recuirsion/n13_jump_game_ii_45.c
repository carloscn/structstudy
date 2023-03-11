#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "utils.h"
#include "stack.h"

static int32_t helper(STACK_T *stack, const int64_t *array, size_t k, size_t m, size_t n, size_t *min_len)
{
    int32_t ret = 0;
    size_t i = 0;

    UTILS_CHECK_PTR(stack);
    UTILS_CHECK_PTR(array);
    UTILS_CHECK_LEN(n);

    stack_print(stack);

    if (m == n - 1) {
        *min_len = *min_len > stack_get_top(stack) ?
                   stack_get_top(stack):
                   *min_len;
        return ret;
    }

    if (k == n - 1) {
        return ret;
    }

    for (i = 0; i < array[m]; i ++) {
        ret = stack_push(stack, array[i + m]);
        UTILS_CHECK_RET(ret);

        ret = helper(stack, array, k + 1, i + m + 1, n, min_len);
        UTILS_CHECK_RET(ret);

        ret = stack_pop(stack, NULL);
        UTILS_CHECK_RET(ret);
    }

finish:
    return ret;
}

static int32_t jump_game(const int64_t *array, size_t len, size_t *out)
{
    int32_t ret = 0;
    STACK_T *stack = NULL;

    UTILS_CHECK_LEN(len);
    UTILS_CHECK_PTR(array);
    UTILS_CHECK_PTR(out);

    stack = stack_malloc(STACK_DEFAULT_SIZE);
    UTILS_CHECK_PTR(stack);

    *out = ~0;
    ret = helper(stack, array, 0, 0, len, out);
    UTILS_CHECK_RET(ret);

finish:
    stack_free(stack);
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;
    int64_t array[] = {2,3,1,1,4};
    size_t out = 0;

    ret = jump_game(array, ARRAY_SIZE(array), &out);
    UTILS_CHECK_RET(ret);

    LOG("the out is %zu\n", out);

finish:
    return ret;
}