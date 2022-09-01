#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"
#include "utils.h"

int32_t queue_init(QUEUE_T *queue, size_t size)
{
    if (NULL == queue || 0 == size) {
        LOG("input queue is NULL\n");
        return -1;
    }

    queue->space = (int64_t *)malloc(sizeof(QUEUE_T) * size);
    if (NULL == queue->space) {
        LOG("malloc queue space failed\n");
        return -1;
    }
    queue->head = queue->space;
    queue->tail = queue->space;
    queue->total_len = size;
    queue->current_len = 0;

    return 0;
}

void queue_deinit(QUEUE_T *queue)
{
    if (NULL == queue || NULL == queue->space) {
        return;
    }
    free(queue->space);
}

QUEUE_T *queue_malloc(size_t size)
{
    QUEUE_T *queue = (QUEUE_T *)malloc(sizeof(QUEUE_T));
    if (queue_init(queue, size) != 0) {
        return NULL;
    }

    return queue;
}

void queue_free(QUEUE_T *queue)
{
    if (NULL == queue) {
        return;
    }
    queue_deinit(queue);
    free(queue);
}

int32_t queue_push(QUEUE_T *queue, int64_t e)
{
    if (queue->current_len >= queue->total_len) {
        printf("queue overflow (full)\n");
        return -1;
    }
    *(queue->tail++) = e;
    queue->current_len ++;

    return 0;
}

int64_t queue_pop(QUEUE_T *queue, int64_t *e)
{
    if (queue->current_len <= 0) {
        printf("queue overflow (empty)\n");
        return -1;
    }
    if (e != NULL) {
        *e = *(queue->head);
    }
    size_t i = 0;
    queue->current_len --;
    for (i = 0; i < queue->current_len; i ++) {
        queue->head[i] = queue->head[i+1];
    }
    *(queue->tail --) = 0;

    return 0;
}

void queue_print(QUEUE_T *queue)
{
    size_t i = 0;
    printf("head [ ");
    do {
        printf("%lld, ", queue->space[i++]);
    } while (i < queue->current_len);
    printf("] tail. \n -- queue len = %zu\n", queue->current_len);
}

size_t queue_count(QUEUE_T *queue)
{
    return queue->current_len;
}

size_t queue_limit_len(QUEUE_T *queue)
{
    return queue->total_len;
}

int32_t queue_selftest(void)
{
    size_t i = 0;
    int64_t val = 0;

    QUEUE_T *queue = queue_malloc(QUEUE_DEFUALT_SIZE);
    if (NULL == queue) {
        LOG("queue malloc failed\n");
        return -1;
    }
    for (i = 0; i < 100; i ++) {
        queue_push(queue, (int64_t)i);
    }
    queue_print(queue);
    printf("queue current size : %zd\n", queue_count(queue));
    queue_pop(queue, &val);
    printf("popped data %lld\n", val);
    queue_print(queue);
    queue_free(queue);
    return 0;
}