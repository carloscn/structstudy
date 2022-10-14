#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "stack.h"
#include "utils.h"

typedef struct queue_t {
    STACK_T *sa;
    STACK_T *sb;
} QUEUE_T;

void queue_free(QUEUE_T *queue)
{
    if (NULL == queue) {
        return;
    }
    if (NULL != queue->sa) {
        free(queue->sa);
        queue->sa = NULL;
    }
    if (NULL != queue->sb) {
        free(queue->sb);
        queue->sb = NULL;
    }
    free(queue);
    queue = NULL;
}

int32_t queue_init(QUEUE_T **queue, size_t sz)
{
    int32_t ret = 0;
    QUEUE_T *new_queue = NULL;
    STACK_T *new_stack = NULL;

    UTILS_CHECK_PTR(queue);

    new_queue = (QUEUE_T *)malloc(sizeof(QUEUE_T));
    UTILS_CHECK_PTR(new_queue);

    new_stack = stack_malloc(sz);
    UTILS_CHECK_PTR(new_stack);
    new_queue->sa = new_stack;

    new_stack = NULL;
    new_stack = stack_malloc(sz);
    UTILS_CHECK_PTR(new_stack);
    new_queue->sb = new_stack;
    *queue = new_queue;

    return ret;
finish:
    queue_free(new_queue);
    return ret;
}

// 1. Push the element to the stack which is not empty.
// 2. If internal stacks of the queue are all empty, then push the input element to the queue->sa.
int32_t queue_push(QUEUE_T *queue, int64_t e)
{
    int32_t ret = 0;
    STACK_T *sa = NULL, *sb = NULL;

    UTILS_CHECK_PTR(queue);
    sa = queue->sa;
    UTILS_CHECK_PTR(sa);
    sb = queue->sb;
    UTILS_CHECK_PTR(sb);

    if (stack_count(sa) != 0) {
        ret = stack_push(sa, e);
    } else if (stack_count(sb) != 0) {
        ret = stack_push(sb, e);
    } else {
        ret = stack_push(sa, e);
    }

finish:
    return ret;
}

// Pop the n-1 elements of the stack which is not empty to the another stack.
// then Pop the left element as the output element.
int32_t queue_pop(QUEUE_T *queue, int64_t *e)
{
    int32_t ret = 0;
    STACK_T *out_s = NULL, *in_s = NULL;
    size_t out_s_sz = 0, in_s_sz = 0;
    size_t i = 0;

    UTILS_CHECK_PTR(queue);
    out_s = queue->sa;
    UTILS_CHECK_PTR(out_s);
    in_s = queue->sb;
    UTILS_CHECK_PTR(in_s);

    out_s_sz = stack_count(out_s);
    in_s_sz = stack_count(in_s);

    if (out_s_sz == 0) {
        utils_swap((int64_t*)&out_s, (int64_t*)&in_s);
        out_s_sz = in_s_sz;
    }

    for (i = 0; i < out_s_sz - 1; i ++) {
        ret = stack_pop(out_s, e);
        UTILS_CHECK_RET(ret);
        ret = stack_push(in_s, *e);
        UTILS_CHECK_RET(ret);
    }

    ret = stack_pop(out_s, e);
    UTILS_CHECK_RET(ret);

    // recover the stack
    int64_t t = 0;
    in_s_sz = stack_count(in_s);
    for (i = 0; i < in_s_sz; i ++) {
        ret = stack_pop(in_s, &t);
        UTILS_CHECK_RET(ret);
        ret = stack_push(out_s, t);
        UTILS_CHECK_RET(ret);
    }

finish:
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;
    int64_t e = 0;
    size_t i = 0;

    QUEUE_T *queue = NULL;

    ret = queue_init(&queue, 100);
    UTILS_CHECK_RET(ret);

    for (i = 0; i < 10; i ++) {
        e = i;
        ret = queue_push(queue, e);
        UTILS_CHECK_RET(ret);
        LOG("queue push e = %lld\n", e);
    }

    for (i = 0; i < 10; i ++) {
        ret = queue_pop(queue, &e);
        UTILS_CHECK_RET(ret);
        LOG("queue pop e = %lld\n", e);
    }
finish:
    free(queue);
    return ret;
}