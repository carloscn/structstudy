#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "bufferlist.h"
#include "stack.h"
#include "utils.h"

static void helper(int64_t *array, BUFLIST_T *reslist, STACK_T *stack, size_t k, int64_t target, size_t n)
{
    if (k > n) {
        return;
    }

    stack_print(stack);

    if (stack_sum(stack) == target) {
        int64_t *array = NULL;
        size_t out_len = 0;
        stack_dup_array(stack, &array, &out_len);
        buflist_append_array(reslist, array, out_len);
        UTILS_PRINT_ARRAY(array, out_len, "found : ");
        UTILS_SAFE_FREE(array);
        return;
    }

    stack_push(stack, array[k]);
    helper(array, reslist, stack, k + 1, target, n);
    stack_pop(stack, NULL);
}

static int32_t comb_sum(const int64_t *array, size_t len, int32_t target)
{
    int32_t ret = 0;
    size_t i = 0, j = 0, n = 0;
    STACK_T *stack = NULL;
    BUFLIST_T *buflist = NULL;
    int64_t dup_array[1024];
    int64_t e = 0;
    int64_t sum = 0;

    UTILS_CHECK_PTR(array);
    UTILS_CHECK_LEN(len);

    for (i = 0; i < len; i ++) {
        sum = 0;
        e = array[i];
        do {
            dup_array[j] = e;
            sum += e;
            j ++;
        } while (sum < target);
    }
    len = j;

    stack = stack_malloc(STACK_DEFAULT_SIZE);
    UTILS_CHECK_PTR(stack);

    ret = utils_sort_int64_array(dup_array, len, ORDER_BY_ASCEND);
    UTILS_CHECK_RET(ret);

    buflist = buflist_malloc();
    UTILS_CHECK_PTR(buflist);

    for (i = 0; i < len; i ++) {
        helper(dup_array, buflist, stack, i, target, len);
    }

    LOG("the result is : \n");
    buflist_infolog(buflist);

finish:
    stack_free(stack);
    buflist_free(buflist);
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;
    int64_t array[] = {2,3,5};

    ret = comb_sum(array, ARRAY_SIZE(array), 8);
    UTILS_CHECK_RET(ret);

finish:
    return ret;
}