#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "stack.h"
#include "utils.h"


static int64_t stack_sum(STACK_T *stack)
{
    int64_t sum = 0;
    int32_t i = 0;
    for (i = 0; i < stack->top_index; i ++) {
        sum += stack->space[i];
    }
    return sum;
}

static void bt(STACK_T *stack, int64_t *array, int32_t array_len, int32_t sp, int64_t target)
{

    if (stack_sum(stack) == target) {
        stack_print(stack);
        return;
    }

    if (sp >= array_len || stack_count(stack) > target) {
        return;
    }

    int32_t i = 0;
    int64_t val = 0;
    for (i = sp; i < array_len; i ++) {
        stack_push(stack, array[i]);
        bt(stack, array, array_len, i + 1, target);
        stack_pop(stack, &val);
    }
}

int main(void)
{
    int32_t ret = 0;
    int64_t test_array[] = {2,2,2,4,3,3};
    STACK_T path;

    ret = stack_init(&path, STACK_DEFAULT_SIZE);
    if (ret != 0) {
        return -1;
    }
    if (ARRAY_SIZE(test_array) > stack_get_size(&path)) {
        LOG("input array too long.\n");
        return -1;
    }
    bt(&path, test_array, ARRAY_SIZE(test_array), 0, 8);

    stack_deinit(&path);
    return 0;
}