#ifndef _STRLIST_H
#define _STRLIST_H

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef struct strlist_t {
    size_t size;
    char **list;
} STRLIST_T;

STRLIST_T* strlist_malloc(void);
int32_t strlist_add(STRLIST_T *strlist, char *str);
int32_t strlist_insert_after(STRLIST_T *strlist, char* str, uint32_t index);
int32_t strlist_remove_last(STRLIST_T *strlist);
int32_t strlist_remove_at(STRLIST_T *strlist, uint32_t index);
char* strlist_get_str_at(STRLIST_T *strlist, uint32_t index);
int32_t strlist_contains(STRLIST_T *strlist, char* str);
int32_t strlist_free(STRLIST_T *strlist);
void strlist_infolog(STRLIST_T *strlist);
int32_t strlist_selftest(void);

#endif