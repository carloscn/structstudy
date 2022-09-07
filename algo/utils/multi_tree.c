#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "multi_tree.h"
#include "utils.h"

static int32_t __get_tree_sub_num(MULTI_TREE_NODE_T *tree, size_t *len)
{
    int32_t ret = 0;

    UTILS_CHECK_PTR(tree);
    UTILS_CHECK_PTR(len);
    UTILS_CHECK_PTR(tree->son_tree_buffer);

    *len = buffer_get_current_len(tree->son_tree_buffer);

finish:
    return ret;
}

MULTI_TREE_NODE_T* multitree_malloc(int64_t val)
{
    MULTI_TREE_NODE_T *p = NULL;
    p = (MULTI_TREE_NODE_T *)malloc(sizeof(MULTI_TREE_NODE_T));
    if (NULL == p) {
        LOG("malloc a multi tree memory failed\n");
        return NULL;
    }
    p->val = val;
    p->son_tree_buffer = buffer_malloc(0);
    return p;
}

void multitree_free(MULTI_TREE_NODE_T *tree)
{
    int32_t ret = 0;
    size_t i = 0;
    UTILS_CHECK_PTR(tree);
    UTILS_CHECK_PTR(tree->son_tree_buffer);
    int64_t tree_addr_val = 0;
    size_t child_tree_len = 0;
    MULTI_TREE_NODE_T *node = NULL;
    ret = __get_tree_sub_num(tree, &child_tree_len);
    UTILS_CHECK_RET(ret);

    for (i = 0; i < child_tree_len; i ++) {
        buffer_get_by_index(tree->son_tree_buffer, i, &tree_addr_val);
        node = INT64_TO_MULTI_TREE_ADDR(tree_addr_val);
        multitree_free(node);
    }
    LOG("free node %p\n", node);
    free(node);
    LOG("free buffer %p\n", tree->son_tree_buffer);
    buffer_free(tree->son_tree_buffer);
finish:
    return;
}

int32_t multitree_append_child(MULTI_TREE_NODE_T *tree, int64_t child_val)
{
    int32_t ret = 0;
    UTILS_CHECK_PTR(tree);

    MULTI_TREE_NODE_T *child_node = NULL;
    child_node = multitree_malloc(child_val);
    UTILS_CHECK_PTR(child_node);
    UTILS_CHECK_PTR(tree->son_tree_buffer);

    buffer_push_tail(tree->son_tree_buffer, MULTI_TREE_ADDR_TO_INT64(child_node));

finish:
    return ret;
}

int32_t multitree_selftest(void)
{
    int32_t ret = 0;
    MULTI_TREE_NODE_T *tree = NULL;

    tree = multitree_malloc(45);
    UTILS_CHECK_PTR(tree);

    LOG("\n");
    ret = multitree_append_child(tree, 1);
    UTILS_CHECK_RET(ret);
    LOG("\n");
    ret = multitree_append_child(tree, 2);
    UTILS_CHECK_RET(ret);

    LOG("\n");
    ret = multitree_append_child(tree, 8);
    UTILS_CHECK_RET(ret);

    LOG("\n");

    multitree_free(tree);
    LOG("done\n");
finish:
    return ret;
}