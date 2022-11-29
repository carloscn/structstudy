#ifndef _QUEUE_H
#define _QUEUE_H

#include <stdint.h>
#include <stdlib.h>

#define QUEUE_DEFUALT_SIZE (1024UL)

typedef struct queue_t {
    int64_t *space;
    int64_t *head;
    int64_t *tail;
    size_t current_len;
    size_t total_len;
} QUEUE_T;

int32_t queue_init(QUEUE_T *queue, size_t size);
void queue_deinit(QUEUE_T *queue);
QUEUE_T *queue_malloc(size_t size);
void queue_free(QUEUE_T *queue);
int32_t queue_push(QUEUE_T *queue, int64_t e);
int64_t queue_pop(QUEUE_T *queue, int64_t *e);
void queue_print(QUEUE_T *queue);
size_t queue_limit_len(QUEUE_T *queue);
size_t queue_count(QUEUE_T *queue);
int32_t queue_str_to_queue(QUEUE_T *queue, const char *str);
int32_t queue_queue_to_str(QUEUE_T* queue, char *out);
int32_t queue_str_to_int_queue(QUEUE_T *queue, const char *str);
void queue_print_as_char(QUEUE_T *queue);
int32_t queue_selftest(void);
int32_t queue_push_array(QUEUE_T *queue, int64_t *array, size_t sz);
int32_t queue_pop_array(QUEUE_T *queue, int64_t *array, size_t *sz);
#endif /* QUEUE_H */