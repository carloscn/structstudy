#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"
#include "utils.h"

BIN_TREE_NODE* binarytree_malloc(void)
{
    BIN_TREE_NODE *p = NULL;
    p = (BIN_TREE_NODE *)malloc(sizeof(BIN_TREE_NODE));
    if (p == NULL) {
        LOG("malloc a tree memory failed\n");
        return NULL;
    }
    return p;
}

void binarytree_free(BIN_TREE_NODE *tree)
{
    if (NULL == tree) {
        printf("tree is null, return\n");
        return;
    }
    BIN_TREE_NODE *next_left = tree->left, *next_right = tree->right;

    tree->val = 0;
    free(tree);

    if (next_left != NULL) {
        binarytree_free(next_left);
    }
    if (next_right != NULL) {
        binarytree_free(next_right);
    }
}

void binarytree_print_by_layers(BIN_TREE_NODE *tree)
{
    int64_t val = 0;
    BIN_TREE_NODE *p = tree;
    if (NULL == p) {
        return;
    }
    QUEUE_T *queue = queue_malloc(QUEUE_DEFUALT_SIZE);
    if (NULL == queue) {
        LOG("queue malloc failed\n");
        return;
    }
    queue_push(queue, CONVERT_TREE_NODE_TO_ADDR(p));
    while(queue_count(queue) > 0) {
        queue_pop(queue, &val);
        p = CONVERT_ADDR_TO_TREE_NODE(val);
        if (p->left != NULL) {
            queue_push(queue, CONVERT_TREE_NODE_TO_ADDR(p->left));
        }
        if (p->right != NULL) {
            queue_push(queue, CONVERT_TREE_NODE_TO_ADDR(p->right));
        }
        printf("%lld, ", p->val);
    }
    queue_free(queue);
}

void binarytree_print_by_preorder(BIN_TREE_NODE *tree)
{
    if (NULL == tree) {
        return;
    }
    printf("%lld, ", tree->val);
    binarytree_print_by_preorder(tree->left);
    binarytree_print_by_preorder(tree->right);
}

void binarytree_print_by_rootorder(BIN_TREE_NODE *tree)
{
    if (NULL == tree) {
        return;
    }
    binarytree_print_by_rootorder(tree->left);
    printf("%lld, ", tree->val);
    binarytree_print_by_rootorder(tree->right);
}

void binarytree_print_by_postorder(BIN_TREE_NODE *tree)
{
    if (NULL == tree) {
        return;
    }
    binarytree_print_by_postorder(tree->left);
    binarytree_print_by_postorder(tree->right);
    printf("%lld, ", tree->val);
}

int32_t binarytree_insert_by_preorder(BIN_TREE_NODE **tree)
{
    int32_t ret = 0;
    char ch = '\0';
    if (tree == NULL) {
        printf("input error on tree\n");
        return -1;
    }
    if (*tree == NULL) {
        scanf("%c", &ch);
        if (ch == '#') {
            *tree = NULL;
        } else {
            *tree = binarytree_malloc();
            if (*tree == NULL) {
                printf("malloc a tree memory failed\n");
                return -1;
            }
            (*tree)->left = (*tree)->right = NULL;
            (*tree)->val = (int64_t)ch - '0';
            binarytree_insert_by_preorder(&((*tree)->left));
            binarytree_insert_by_preorder(&((*tree)->right));
        }
    }
    return 0;
}

int32_t binarytree_selftest(void)
{
    size_t i = 0;
    int32_t pop_val;
    int32_t ret = 0;
    /*
    // 124#7###35##68###
    */
    BIN_TREE_NODE *tree = NULL;
    printf("input binary tree using the pre-order (# is NULL):");
    ret = binarytree_insert_by_preorder(&tree);
    if (ret != 0) {
        printf("set bin tree failed\n");
        return -1;
    }
    printf("\nprint tree by layers: ");
    binarytree_print_by_layers(tree);
    printf("\nprint tree by pre-order: ");
    binarytree_print_by_preorder(tree);
    printf("\nprint tree by root-order: ");
    binarytree_print_by_rootorder(tree);
    printf("\nprint tree by post-order: ");
    binarytree_print_by_postorder(tree);
    printf("\n");
    binarytree_free(tree);
}
