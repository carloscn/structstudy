#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>
#include <stack.h>
#include "utils.h"

static int32_t number_of_pairs(int32_t *nums, size_t nums_size, int32_t *out, size_t *o_len)
{
    int32_t ret = 0;
    STACK_T *stack = NULL;

    UTILS_CHECK_LEN(nums_size);
    UTILS_CHECK_PTR(nums);
    UTILS_CHECK_PTR(out);
    UTILS_CHECK_PTR(o_len);

    stack = stack_malloc(STACK_DEFAULT_SIZE);
    UTILS_CHECK_PTR(stack);

    ret = utils_sort_int32_array(nums, nums_size, ORDER_BY_ASCEND);
    UTILS_CHECK_RET(ret);

    for (size_t i = 0; i < nums_size; i ++) {
        if (stack_get_top(stack) == 0) {
            ret = stack_push(stack, nums[i]);
            UTILS_CHECK_RET(ret);
            continue;
        }
        int64_t e = 0;
        ret = stack_peek(stack, &e);
        UTILS_CHECK_RET(ret);

        ret = ((int32_t)e == nums[i]) ?
              stack_pop(stack, NULL):
              stack_push(stack, nums[i]);
        UTILS_CHECK_RET(ret);
    }

    *o_len = 0;
    size_t deleted_pair_len = (nums_size - stack_get_top(stack)) / 2;
    *(out) = (int32_t) deleted_pair_len, (*o_len) ++;
    *(out + 1) = (int32_t) stack_get_top(stack), (*o_len) ++;

finish:
    stack_free(stack);
    return ret;
}


int32_t main(void)
{
    int32_t ret = 0;
    int32_t array1[] = {1,3,2,1,3,2,2};
    int32_t out[32] = {0};
    size_t o_len;

    ret = number_of_pairs(array1, ARRAY_SIZE(array1), out, &o_len);
    assert(ret == 0);
    utils_print_int32_array(out, o_len, "the out is ");

    int32_t array2[] = {1,1};
    ret = number_of_pairs(array2, ARRAY_SIZE(array2), out, &o_len);
    assert(ret == 0);
    utils_print_int32_array(out, o_len, "the out is ");

    int32_t array3[] = {0};
    ret = number_of_pairs(array3, ARRAY_SIZE(array3), out, &o_len);
    assert(ret == 0);
    utils_print_int32_array(out, o_len, "the out is ");

    LOG("All tests have passed!\n");

finish:
    return ret;
}