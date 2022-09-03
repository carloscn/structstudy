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
void linklist_free(LINKLIST_T **node);
void linklist_prink_revert(LINKLIST_T *list);
int32_t linklist_selftest(void);

#endif