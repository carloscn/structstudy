#ifndef _BINARY_TREE_H
#define _BINARY_TREE_H

#include <stdint.h>
#include <stdlib.h>
#include "queue.h"

typedef struct bin_tree_node_t {
    int64_t val;
    struct bin_tree_node_t *left;
    struct bin_tree_node_t *right;
} BIN_TREE_NODE;

#define CONVERT_TREE_NODE_TO_ADDR(tree) ((int64_t)(tree))
#define CONVERT_ADDR_TO_TREE_NODE(tree) ((BIN_TREE_NODE *)(tree))

BIN_TREE_NODE* binarytree_malloc(void);
void binarytree_free(BIN_TREE_NODE *tree);
void binarytree_print_by_layers(BIN_TREE_NODE *tree);
void binarytree_print_by_preorder(BIN_TREE_NODE *tree);
void binarytree_print_by_rootorder(BIN_TREE_NODE *tree);
void binarytree_print_by_postorder(BIN_TREE_NODE *tree);
int32_t binarytree_insert_by_preorder(BIN_TREE_NODE **tree);
int32_t binarytree_insert_value_to_left(BIN_TREE_NODE *tree, int64_t val);
int32_t binarytree_insert_value_to_right(BIN_TREE_NODE *tree, int64_t val);
int32_t binarytree_selftest(void);

#endif /* _BINARY_TREE_H */
