#ifndef _STACK_H
#define _STACK_H

#include <stdint.h>
#include <stdlib.h>

#define STACK_DEFAULT_SIZE (100UL)
#define STACK_MAX_SIZE (200UL)

typedef struct _stack_t {
    int64_t *space;
    size_t top_index;
    size_t size;
} STACK_T;

STACK_T *stack_malloc(size_t size);
void stack_free(STACK_T *stack);
int32_t stack_init(STACK_T *stack, size_t size);
void stack_deinit(STACK_T *stack);
int32_t stack_push(STACK_T *stack, int64_t val);
int32_t stack_pop(STACK_T *stack, int64_t *e);
int32_t stack_peek(STACK_T *stack, int64_t *e);
int32_t stack_clear(STACK_T *stack);
size_t stack_get_top(STACK_T *stack);
size_t stack_count(STACK_T *stack);
size_t stack_get_size(STACK_T *stack);
void stack_print(STACK_T *stack);
void stack_print_as_char(STACK_T *stack);
void stack_print_as_hex(STACK_T *stack);
char* stack_to_str(STACK_T *str_stack);
int64_t stack_sum(STACK_T *stack);
int32_t stack_dup_array(STACK_T* stack, int64_t **array, size_t *o_len);
int stack_selftest(void);

#endif