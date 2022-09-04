#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include "utils.h"
#include "stack.h"
#include "binary_tree.h"

static int32_t find_paths(BIN_TREE_NODE *tree, STACK_T *one_path_stack)
{
    if (NULL == tree) {
        stack_print(one_path_stack);
        return 0;
    }
    int64_t val;
    stack_push(one_path_stack, tree->val);
    find_paths(tree->left, one_path_stack);
    find_paths(tree->right, one_path_stack);
    stack_pop(one_path_stack, &val);
    return 0;
}

static int32_t print_all_tree_paths(BIN_TREE_NODE *tree)
{
    int32_t ret = 0;
    STACK_T *stack = NULL;

    if (NULL == tree) {
        LOG("tree is NULL\n");
        return -1;
    }
    stack = stack_malloc(STACK_DEFAULT_SIZE);
    if (NULL == stack) return -1;

    ret = find_paths(tree, stack);

    return ret;
}


int32_t main(void)
{
    int32_t ret = 0;
    BIN_TREE_NODE *tree = NULL, *p = NULL;
    ret = binarytree_insert_by_preorder_by_string(&tree, "1,2,3,#,#,4,#,#,5,#,6,#,#,");
    if (ret != 0)   return ret;

    binarytree_print_by_layers(tree);
    printf("\n");
    binarytree_print_by_preorder(tree);
    printf("\n");
    binarytree_print_by_rootorder(tree);
    printf("\n");

    ret = print_all_tree_paths(tree);

    return ret;

}