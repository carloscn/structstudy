#ifndef _BUFFER_H
#define _BUFFER_H

#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

#define BUFFER_DEFUALT_SIZE (64UL)
#define BUFFER_MAX_SZIE (100000000UL)

typedef struct buffer_t BUFFER_T;

BUFFER_T* buffer_malloc(size_t sz);
void buffer_free(BUFFER_T *buffer);
size_t buffer_get_current_len(BUFFER_T *buffer);
bool buffer_is_empty(BUFFER_T *buffer);
int32_t buffer_push_by_index(BUFFER_T *buffer, size_t index, int64_t e);
int32_t buffer_push_head(BUFFER_T *buffer, int64_t e);
int32_t buffer_push_tail(BUFFER_T *buffer, int64_t e);
int32_t buffer_get_by_index(BUFFER_T *buffer, size_t index, int64_t *e);
int32_t buffer_set_by_index(BUFFER_T *buffer, size_t index, int64_t e);
bool buffer_is_contain(BUFFER_T *buffer, int64_t e);
bool buffer_find(BUFFER_T *buffer, size_t *index, int64_t e);
int64_t buffer_sum(BUFFER_T *buffer);
int32_t buffer_pop_by_index(BUFFER_T *buffer, size_t index, int64_t *e);
int32_t buffer_pop_tail(BUFFER_T *buffer, int64_t *e);
int32_t buffer_pop_head(BUFFER_T *buffer, int64_t *e);
int32_t buffer_remove(BUFFER_T *buffer, size_t index, int64_t *removed_e);
int32_t buffer_remove_element(BUFFER_T *buffer, int64_t e);
int32_t buffer_clear(BUFFER_T *buffer);
int32_t buffer_get_tail(BUFFER_T *buffer, int64_t *e);
int32_t buffer_get_head(BUFFER_T *buffer, int64_t *e);
int32_t buffer_copy(BUFFER_T *dest, BUFFER_T *src);
int32_t buffer_dup_array(BUFFER_T* buffer, int64_t **array, size_t *o_len);
int32_t buffer_dup(BUFFER_T *buffer, BUFFER_T **out);
int32_t buffer_append_array(BUFFER_T *buffer, const int64_t *array, size_t len);
int32_t buffer_soft_to_array(BUFFER_T *buffer, int64_t **array, size_t *o_len);
int64_t* buffer_soft_to_array_2(BUFFER_T *buffer);
int32_t buffer_get_min_value(BUFFER_T *buffer, size_t *min_index, int64_t *min_e);
int32_t buffer_get_max_value(BUFFER_T *buffer, size_t *max_index, int64_t *max_e);
bool buffer_is_equal(BUFFER_T *a, BUFFER_T *b);
void buffer_print(BUFFER_T *buffer);
int32_t buffer_selftest(void);
#endif /* _BUFFER_H */