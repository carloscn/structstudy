#ifndef _LINKLIST_H
#define _LINKLIST_H

#include <stdint.h>
#include <stdlib.h>

typedef struct list_node_t {
    int64_t val;
    struct list_node_t *next;
} LINKLIST_T;

LINKLIST_T* linklist_create_node(int64_t val);
void linklist_free_node(LINKLIST_T *p);
int32_t linklist_add_node(LINKLIST_T *list, LINKLIST_T* node);
int32_t linklist_remove_node(LINKLIST_T *list, LINKLIST_T *node);
int32_t linklist_add_value(LINKLIST_T **list, int64_t val);
int32_t linklist_remove_value(LINKLIST_T **list, int64_t val);
int32_t linklist_append_array(LINKLIST_T **node, const int64_t *buffer, size_t len);
int32_t linklist_copy_node(LINKLIST_T *node_dest, LINKLIST_T *node_src);
int32_t linklist_dup_node(LINKLIST_T **node_dest, LINKLIST_T *node_src);
int32_t linklist_get_len(LINKLIST_T *list, size_t *o_len);
int32_t linklist_revert(LINKLIST_T **list);
int32_t linklist_swap_value(LINKLIST_T *n0, LINKLIST_T *n1);
void linklist_free(LINKLIST_T **node);
void linklist_print(LINKLIST_T *list);
void linklist_print_revert(LINKLIST_T *list);
int32_t linklist_selftest(void);

#endif