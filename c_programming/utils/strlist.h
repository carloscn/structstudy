#ifndef _STRLIST_H
#define _STRLIST_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define STRLIST_DEFAULT_SIZE 8u

typedef struct strlist_t STRLIST_T;

STRLIST_T* strlist_malloc(void);
int32_t strlist_add(STRLIST_T *strlist, const char *str);
int32_t strlist_add_split_by_char(STRLIST_T *strlist, const char *str, char c);
int32_t strlist_insert_after(STRLIST_T *strlist, const char *str, size_t index);
int32_t strlist_remove_last(STRLIST_T *strlist);
int32_t strlist_remove_at(STRLIST_T *strlist, size_t index);
char* strlist_get_str_at(STRLIST_T *strlist, size_t index);
char *strlist_get_str_at_with_clone(STRLIST_T *strlist, size_t index);
bool strlist_contains(STRLIST_T *strlist, const char *str, size_t *index);
int32_t strlist_append_all_substrs(STRLIST_T *strlist, const char *str);
size_t strlist_get_size(STRLIST_T *strlist);
void strlist_free(STRLIST_T *strlist);
void strlist_infolog(STRLIST_T *strlist);
int32_t strlist_selftest(void);

#endif