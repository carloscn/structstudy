#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "utils.h"
#include "stack.h"
#include "bufferlist.h"

//  candidates = [10,1,2,7,6,1,5], target = 8,
static int32_t helper(int64_t *array, size_t len, STACK_T *stack, BUFLIST_T *reslist, size_t k, int64_t target)
{
    int32_t ret = 0;
    int64_t *result_array = NULL;
    size_t result_o_len = 0;
    size_t i = 0;

    UTILS_CHECK_PTR(array);
    UTILS_CHECK_PTR(stack);
    UTILS_CHECK_PTR(reslist);

    stack_print(stack);

    if (k > len - 1) {
        goto finish;
    }

    if (stack_sum(stack) == target) {
        ret = stack_dup_array(stack, &result_array, &result_o_len);
        UTILS_CHECK_RET(ret);
        ret = buflist_append_array(reslist, result_array, result_o_len);
        UTILS_CHECK_RET(ret);
        UTILS_SAFE_FREE(result_array);
        goto finish;
    }

    for (i = k; i < len; i ++) {
        ret = stack_push(stack, array[i]);
        UTILS_CHECK_RET(ret);

        ret = helper(array, len, stack, reslist, i + 1, target);
        UTILS_CHECK_RET(ret);

        ret = stack_pop(stack, NULL);
        UTILS_CHECK_RET(ret);
    }

finish:
    return ret;
}

static int32_t comb_sum(const int64_t *array, size_t len, int64_t target, BUFLIST_T *reslist)
{
    int32_t ret = 0;
    int64_t *dup_array = NULL;
    size_t i = 0;
    STACK_T *stack = NULL;

    UTILS_CHECK_PTR(array);
    UTILS_CHECK_PTR(reslist);
    UTILS_CHECK_LEN(len);

    dup_array = (int64_t *)calloc(sizeof(int64_t), len);
    UTILS_CHECK_PTR(dup_array);

    memcpy(dup_array, array, sizeof(int64_t) * len);

    ret = utils_sort_int64_array(array, len, ORDER_BY_ASCEND);
    UTILS_CHECK_RET(ret);

    stack = stack_malloc(STACK_DEFAULT_SIZE);
    UTILS_CHECK_PTR(stack);

    ret = helper(array, len, stack, reslist, 0, target);
    UTILS_CHECK_RET(ret);


finish:
    stack_free(stack);
    UTILS_SAFE_FREE(dup_array);
    return ret;
}


int32_t main(void)
{
    int32_t ret = 0;
    int64_t can[] = {10,1,2,7,6,1,5};
    int64_t target = 8;
    BUFLIST_T *result_list = NULL;

    result_list = buflist_malloc();
    UTILS_CHECK_PTR(result_list);

    ret = comb_sum(can, ARRAY_SIZE(can), target, result_list);
    UTILS_CHECK_RET(ret);

    ret = buflist_set(result_list);
    UTILS_CHECK_RET(ret);

    buflist_infolog(result_list);

finish:
    buflist_free(result_list);
    return ret;
}