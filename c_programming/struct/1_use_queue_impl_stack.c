#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "queue.h"
#include "utils.h"

typedef struct stack_t {
    QUEUE_T *qa;
    QUEUE_T *qb;
} STACK_T;

int32_t stack_init(STACK_T **stack, size_t sz)
{
    int32_t ret = 0;
    QUEUE_T *new_queue = NULL;
    STACK_T *new_stack = NULL;

    UTILS_CHECK_PTR(stack);

    new_stack = (STACK_T *)malloc(sizeof(STACK_T));
    UTILS_CHECK_PTR(new_stack);

    new_queue = queue_malloc(sz);
    UTILS_CHECK_PTR(new_queue);
    new_stack->qa = new_queue;
    new_queue = NULL;
    new_queue = queue_malloc(sz);
    UTILS_CHECK_PTR(new_queue);
    new_stack->qb = new_queue;
    *stack = new_stack;

    return ret;
finish:
    if (new_stack != NULL)
        free(new_stack);
    return ret;
}

void stack_free(STACK_T *stack)
{
    if (NULL == stack) {
        return;
    }
    if (NULL != stack->qa) {
        free(stack->qa);
        stack->qa = NULL;
    }
    if (NULL != stack->qb) {
        free(stack->qb);
        stack->qb = NULL;
    }
    free(stack);
    stack = NULL;
}

// 1. Push the element to the queue which is not empty.
// 2. If internal queues of the stack are all empty, then push the input element to the stack->qa.
int32_t stack_push(STACK_T *stack, int64_t e)
{
    int32_t ret = 0;
    QUEUE_T *qa = NULL, *qb = NULL;

    UTILS_CHECK_PTR(stack);
    qa = stack->qa;
    UTILS_CHECK_PTR(qa);
    qb = stack->qb;
    UTILS_CHECK_PTR(qb);

    if (queue_count(qa) != 0) {
        ret = queue_push(qa, e);
    } else if (queue_count(qb) != 0) {
        ret = queue_push(qb, e);
    } else {
        ret = queue_push(qa, e);
    }

finish:
    return ret;
}

// Pop the n-1 elements of the queue which is not empty to the another queue.
// then Pop the left element as the output element.
int32_t stack_pop(STACK_T *stack, int64_t *e)
{
    int32_t ret = 0;
    QUEUE_T *out_q = NULL, *in_q = NULL;
    size_t out_q_sz = 0, in_q_sz = 0;
    size_t i = 0;

    UTILS_CHECK_PTR(stack);
    out_q = stack->qa;
    UTILS_CHECK_PTR(out_q);
    in_q = stack->qb;
    UTILS_CHECK_PTR(in_q);

    out_q_sz = queue_count(out_q);
    in_q_sz = queue_count(in_q);

    if (out_q_sz == 0) {
        utils_swap((int64_t*)&out_q, (int64_t*)&in_q);
        out_q_sz = in_q_sz;
    }

    for (i = 0; i < out_q_sz - 1; i ++) {
        ret = queue_pop(out_q, e);
        UTILS_CHECK_RET(ret);
        ret = queue_push(in_q, *e);
        UTILS_CHECK_RET(ret);
    }

    ret = queue_pop(out_q, e);

finish:
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;
    int64_t e = 0;
    size_t i = 0;

    STACK_T *stack = NULL;

    ret = stack_init(&stack, 100);
    UTILS_CHECK_RET(ret);

    for (i = 0; i < 10; i ++) {
        e = i;
        ret = stack_push(stack, e);
        UTILS_CHECK_RET(ret);
        LOG("stack push e = %lld\n", e);
    }

    for (i = 0; i < 10; i ++) {
        ret = stack_pop(stack, &e);
        UTILS_CHECK_RET(ret);
        LOG("stack pop e = %lld\n", e);
    }
finish:
    return ret;
}