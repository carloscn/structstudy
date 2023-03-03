#ifndef _BUFFERLIST_H
#define _BUFFERLIST_H

#include <stdint.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include "buffer.h"

#define BUFLIST_DEFAULT_SIZE 32u

typedef struct bufferlist_t BUFLIST_T;

BUFLIST_T* buflist_malloc(void);
int32_t buflist_add(BUFLIST_T *buflist, BUFFER_T *buf);
int32_t buflist_insert_after(BUFLIST_T *buflist, BUFFER_T *buf, size_t index);
int32_t buflist_remove_last(BUFLIST_T *buflist);
int32_t buflist_remove_at(BUFLIST_T *buflist, size_t index);
BUFFER_T* buflist_get_buffer_at(BUFLIST_T *buflist, size_t index) __unsafe_indexable;
bool buflist_contains(BUFLIST_T *buflist, BUFFER_T* buf, size_t *index) __unsafe_indexable;
size_t buflist_get_size(BUFLIST_T *buflist) __unsafe_indexable;
int32_t buflist_append_all_buflist(BUFLIST_T *buflist, BUFLIST_T *buflist_app);
int32_t buflist_append_array(BUFLIST_T *buflist, int64_t *array, size_t len);
BUFLIST_T* buflist_dup(BUFLIST_T *buflist);
void buflist_free(BUFLIST_T *buflist);
void buflist_infolog(BUFLIST_T *buflist);
int32_t buflist_selftest(void);

#endif
