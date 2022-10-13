#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include "utils.h"
#include "linklist.h"
#include "binary_tree.h"

static int32_t binarytree_to_linklist(BIN_TREE_NODE *tree, LINKLIST_T **linklist)
{
    if (NULL == tree) {
        return -1;
    }
    linklist_add_value(linklist, tree->val);
    binarytree_to_linklist(tree->left, linklist);
    binarytree_to_linklist(tree->right,linklist);
    return 0;
}

int main(void)
{
    int32_t ret = 0;
    LINKLIST_T *list = NULL;
    BIN_TREE_NODE *tree = NULL, *p = NULL;
#if 0
    tree = binarytree_malloc();
    if (tree == NULL) {
        ret = -1;
        LOG("tree is null\n");
        return ret;
    }
    tree->val = 1;
    ret = binarytree_insert_value_to_left(tree, 2);
    if (ret != 0 || tree->left == NULL) {
        ret = -1;
        LOG("failed\n");
        return ret;
    }
    p = tree->left;
    ret = binarytree_insert_value_to_left(p, 3);
    if (ret != 0 || p->left == NULL) {
        ret = -1;
        LOG("failed\n");
        return ret;
    }
    ret = binarytree_insert_value_to_right(p, 4);
    if (ret != 0 || p->right == NULL) {
        ret = -1;
        LOG("failed\n");
        return ret;
    }
    p = tree;

    ret = binarytree_insert_value_to_right(p, 5);
    if (ret != 0 || p->right == NULL) {
        ret = -1;
        LOG("failed\n");
        return ret;
    }
    p = p->right;
    ret = binarytree_insert_value_to_right(p, 6);
    if (ret != 0 || p->right == NULL) {
        ret = -1;
        LOG("failed\n");
        return ret;
    }
#endif
    binarytree_insert_by_preorder_by_string(&tree, "1,2,3,#,#,4,#,#,5,#,6,#,#,");
    binarytree_print_by_preorder(tree);
    LOG("call binarytree_tolinklist\n");
    ret = binarytree_to_linklist(tree, &list);
    if (ret != 0) {
        ret = -1;
        LOG("failed\n");
        return ret;
    }
    LOG("print linklist: \n");
    linklist_print(list);
    linklist_free(&list);
    binarytree_free(tree);

    return ret;
}
