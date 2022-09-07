#ifndef _MULTI_TREE_H
#define _MULTI_TREE_H

#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include "buffer.h"

typedef struct multi_tree_node_t MULTI_TREE_NODE_T;

#define MULTI_TREE_ADDR_TO_INT64(addr) ((int64_t)(addr))
#define INT64_TO_MULTI_TREE_ADDR(val) ((MULTI_TREE_NODE_T*)(val))

struct multi_tree_node_t {
    int64_t val;
    BUFFER_T *son_tree_buffer;
};

int32_t multitree_selftest(void);

#endif /* _MULTI_TREE_H */