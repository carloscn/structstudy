#ifndef STACK_H
#define STACK_H

#include <stdint.h>
#include <stdlib.h>

#define STACK_DEFAULT_SIZE (100UL)
#define STACK_MAX_SIZE (200UL)

typedef struct _stack_t {
    int64_t *space;
    size_t top_index;
    size_t size;
} STACK_T;

int32_t stack_malloc(STACK_T *stack, size_t size);
void stack_free(STACK_T *stack);
int32_t stack_push(STACK_T *stack, int64_t val);
int32_t stack_pop(STACK_T *stack, int64_t *e);
int32_t stack_clear(STACK_T *stack);
size_t stack_get_top(STACK_T *stack);
size_t stack_count(STACK_T *stack);
size_t stack_get_size(STACK_T *stack);
void stack_print(STACK_T *stack);
void stack_print_as_char(STACK_T *stack);

int stack_self_test(void);

#endif