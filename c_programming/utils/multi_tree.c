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
    size_t child_tree_len = 0;
    MULTI_TREE_NODE_T *node = NULL;
    ret = __get_tree_sub_num(tree, &child_tree_len);
    UTILS_CHECK_RET(ret);

    int64_t tree_addr_val = 0;
    UTILS_CHECK_PTR(tree->son_tree_buffer);
    for (i = 0; i < child_tree_len; i ++) {
        buffer_get_by_index(tree->son_tree_buffer, i, &tree_addr_val);
        node = INT64_TO_MULTI_TREE_ADDR(tree_addr_val);
        multitree_free(node);
    }
    buffer_free(tree->son_tree_buffer);
    free(tree);

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

int32_t multitree_fill_tree(MULTI_TREE_NODE_T **tree, int64_t val)
{
    int32_t ret = 0;
    UTILS_CHECK_PTR(tree);

    if (NULL == *tree) {
        *tree = multitree_malloc(val);
        UTILS_CHECK_PTR(*tree);
    } else {
       ret = multitree_append_child(*tree, val);
       UTILS_CHECK_RET(ret);
    }

finish:
    return ret;
}

static MULTI_TREE_NODE_T* __get_tree_child_by_index(MULTI_TREE_NODE_T *tree, size_t index)
{
    int32_t ret = 0;
    MULTI_TREE_NODE_T *p = NULL;
    UTILS_CHECK_PTR(tree);

    if (index > tree->son_tree_buffer->total_len) {
        LOG("tree index over size error\n");
        goto finish;
    }
    // if index is 0, return root;
    if (0 == index) {
        p = tree;
        goto finish;
    }
    // else index is not 0, return child
    p = INT64_TO_MULTI_TREE_ADDR(tree->son_tree_buffer->data[index-1]);
    LOG("get index = %zd, the p = %p\n", index, p);
finish:
    return p;
}

int32_t multitree_insert_by_preoder_by_queueu(MULTI_TREE_NODE_T **tree, QUEUE_T *queue)
{
    int32_t ret = 0;
    int32_t i = 0;
    int64_t val = 0;
    size_t child_index = 0;
    if (queue_count(queue) == 0) {
        goto finish;
    }
    UTILS_CHECK_PTR(tree);
    MULTI_TREE_NODE_T *p = *tree, *child_node = NULL;
    LOG("CALLED multitree_insert_by_preoder_by_queueu\n");

        queue_pop(queue, &val);
        LOG("val is %lld\n", val);
        if (val == (int64_t)'#' || val == (int64_t)'@') {
            LOG("inser NULL\n");
            p = NULL;
            return 0;
        } else {
            do {
                ret = multitree_fill_tree(tree, val);
                UTILS_CHECK_RET(ret);
                child_node = __get_tree_child_by_index(*tree, child_index);
                LOG("insert value = %lld to %zd\n node", val, child_index);
                ret = multitree_insert_by_preoder_by_queueu(&child_node, queue);
                UTILS_CHECK_RET(ret);
                child_index ++;
                LOG("child index ++\n");
                queue_pop(queue, &val);
                queue_print(queue);
            } while (val != (int64_t)'@');
        }

finish:
    return ret;
}

int32_t binarytree_insert_by_preorder_by_string(MULTI_TREE_NODE_T **tree, const char *str)
{
    int32_t ret = 0;
    QUEUE_T *queue = NULL;
    UTILS_CHECK_PTR(str);
    queue = queue_malloc(QUEUE_DEFUALT_SIZE);
    UTILS_CHECK_PTR(queue);
    ret = queue_str_to_int_queue(queue, str);
    UTILS_CHECK_RET(ret);
    queue_print(queue);
    ret = multitree_insert_by_preoder_by_queueu(tree, queue);
    UTILS_CHECK_RET(ret);
finish:
    queue_free(queue);
    return ret;
}

int32_t multitree_selftest(void)
{
    int32_t ret = 0;
    MULTI_TREE_NODE_T *tree = NULL;
    const char *input_tree = "1,2,1,#,2,#,@,3,5,#,6,#,@,4,3,#,@,@,@,";


    binarytree_insert_by_preorder_by_string(&tree, input_tree);
#if 0
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
#endif
    multitree_free(tree);
    LOG("done\n");
finish:
    return ret;
}
