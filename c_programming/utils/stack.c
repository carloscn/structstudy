#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include "utils.h"

int32_t stack_init(STACK_T *stack, size_t size)
{
    if (NULL == stack || 0 == size) {
        LOG("input parameter error\n");
        return -1;
    }

    if (size > STACK_MAX_SIZE) {
        LOG("the size over the MAX_SIZE (%zd), set to %zd\n", STACK_MAX_SIZE, STACK_MAX_SIZE);
        size = STACK_MAX_SIZE;
    }

    stack->space = (int64_t*)malloc(sizeof(int64_t) * size);
    memset(stack->space, 0, sizeof(int64_t) * size);
    if (NULL == stack->space) {
        LOG("stack space malloc failed\n");
        return -1;
    }

    stack->top_index = 0;
    stack->size = size;

    return 0;
}

void stack_deinit(STACK_T *stack)
{
    if (NULL == stack || NULL == stack->space) {
        return;
    }

    stack->top_index = 0;
    free(stack->space);
    stack->space = NULL;
}

STACK_T *stack_malloc(size_t size)
{
    STACK_T *stack = (STACK_T *)malloc(sizeof(STACK_T));
    if (stack_init(stack, size) != 0) {
        return NULL;
    }
    return stack;
}

void stack_free(STACK_T *stack)
{
    if (NULL == stack) {
        return;
    }
    stack_deinit(stack);
    free(stack);
}


int32_t stack_push(STACK_T *stack, int64_t val)
{
    int64_t *p = NULL;

    if (NULL == stack || NULL == stack->space) {
        LOG("input parameter error\n");
        return -1;
    }
    if (stack->top_index >= stack->size) {
        LOG("stack overflow. size == %zu (full)\n", stack->size);
        return -1;
    }
    p = stack->space;
    p[stack->top_index ++] = val;

    return 0;
}

int32_t stack_pop(STACK_T *stack, int64_t *e)
{
    int64_t *p = NULL;

    if (NULL == stack || NULL == stack->space) {
        LOG("input parameter error\n");
        return -1;
    }
    if (stack->top_index == 0) {
        LOG("stack overflow. (empty)\n");
        return -1;
    }
    p = stack->space;
    stack->top_index --;
    if (e != NULL) {
        *e = p[stack->top_index];
    }
    p[stack->top_index] = 0;

    return 0;
}

int32_t stack_peek(STACK_T *stack, int64_t *e)
{
    int64_t *p = NULL;

    if (NULL == stack || NULL == stack->space) {
        LOG("input parameter error\n");
        return -1;
    }
    if (stack->top_index == 0) {
        LOG("stack overflow. (empty)\n");
        return -1;
    }
    p = stack->space;
    if (e != NULL) {
        *e = p[stack->top_index - 1];
    }

    return 0;
}

int32_t stack_clear(STACK_T *stack)
{
    if (NULL == stack || NULL == stack->space) {
        LOG("input parameter error\n");
        return -1;
    }
    memset(stack->space, 0, stack->top_index * sizeof(stack->space[0]));
    stack->top_index = 0;
    return 0;
}

size_t stack_get_size(STACK_T *stack)
{
    if (NULL == stack) {
        LOG("input parameter error\n");
        return -1;
    }
    return stack->size;
}

size_t stack_get_top(STACK_T *stack)
{
    if (NULL == stack) {
        LOG("input parameter error\n");
        return -1;
    }
    return stack->top_index;
}

size_t stack_count(STACK_T *stack)
{
    return stack_get_top(stack);
}

int64_t stack_sum(STACK_T *stack)
{
    size_t i = 0;
    int64_t sum = 0;

    for (i = 0; i < stack->size; i ++) {
        sum += stack->space[i];
    }

    return sum;
}

int32_t stack_dup_array(STACK_T *stack, int64_t **array, size_t *o_len)
{
    int32_t ret = 0;
    int64_t *ptr = NULL;

    UTILS_CHECK_PTR(stack);
    UTILS_CHECK_PTR(array);
    UTILS_CHECK_PTR(o_len);

    ptr = (int64_t *)calloc(sizeof(int64_t), stack->top_index);
    UTILS_CHECK_PTR(ptr);

    memcpy(ptr, stack->space, sizeof(int64_t) * stack->top_index);

    *array = ptr;
    *o_len = stack->top_index;

finish:
    return ret;
}

void stack_print_as_hex(STACK_T *stack)
{
    if (NULL == stack || NULL == stack->space) {
        LOG("input parameter error\n");
        return;
    }
    if (0 == stack->top_index || 0 == stack->size) {
        return;
    }
    int32_t i = stack->top_index - 1;
    printf("top [ ");
    do {
        printf("0x%llx, ", stack->space[i--]);
    } while (i >= 0);
    printf("] bottom.  -- stack len = %zu\n", stack->top_index);
}

void stack_print(STACK_T *stack)
{
    if (NULL == stack || NULL == stack->space) {
        LOG("input parameter error\n");
        return;
    }
    if (0 == stack->top_index || 0 == stack->size) {
        return;
    }
    int32_t i = stack->top_index - 1;
    printf("top [ ");
    do {
        printf("%llu, ", stack->space[i--]);
    } while (i >= 0);
    printf("] bottom.  -- stack len = %zu\n", stack->top_index);
}
void stack_print_as_char(STACK_T *stack)
{
    if (NULL == stack || NULL == stack->space) {
        LOG("input parameter error\n");
        return;
    }
    if (0 == stack->top_index || 0 == stack->size) {
        return;
    }
    int32_t i = stack->top_index - 1;
    printf("top [ ");
    do {
        printf("%c, ", (char)(stack->space)[i--]);
    } while (i >= 0);
    printf("] bottom.  -- stack len = %zu\n", stack->top_index);
}

char* stack_to_str(STACK_T *str_stack)
{
    size_t i = 0;
    char* str = (char*)malloc(str_stack->top_index + 1);
    if (NULL == str) {
        return NULL;
    }
    memset(str, '\0', str_stack->top_index + 1);
    for (i = 0; i < str_stack->top_index; i ++) {
        str[i] = (char)str_stack->space[i];
    }

    return str;
}

int stack_selftest(void)
{
    int32_t ret = 0;
    STACK_T xstack, *stack;
    int64_t e = 0;
    size_t i = 0;

    stack = &xstack;
    ret = stack_init(stack, STACK_DEFAULT_SIZE);
    if (ret != 0) {
        LOG("failed stack malloc\n");
        goto err;
    }
    for (i = 0; i < STACK_DEFAULT_SIZE + 5; i ++) {
        stack_push(stack, (int64_t)i);
    }
    stack_print(stack);
    stack_pop(stack, &e);
    LOG("pop %lld\n", e);
    stack_pop(stack, &e);
    LOG("pop %lld\n", e);
    stack_pop(stack, &e);
    LOG("pop %lld\n", e);
    stack_pop(stack, &e);
    LOG("pop %lld\n", e);
    stack_push(stack, 1000);
    stack_pop(stack, &e);
    LOG("pop %lld\n", e);
    stack_print(stack);

    if (e == 1000 && stack->top_index == 96) {
        LOG("stack self test pass!\n");
        return 0;
    }
err:
    LOG("stack self test failed! \n");
    stack_deinit(stack);
    return 0;
}