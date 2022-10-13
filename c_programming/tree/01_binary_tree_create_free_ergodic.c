#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "utils.h"

#define STACK_ENABLE
#define QUEUE_ENABLE

#define STACK_SIZE  (100UL)
#define QUEUE_SIZE  (100UL)

#ifdef STACK_ENABLE
static int64_t __stack_space[STACK_SIZE] = {0};
static size_t __stack_top_index = 0;

static int64_t stack_push(int64_t e)
{
    if (__stack_top_index >= STACK_SIZE) {
        printf("stack overflow. (full)\n");
        return -1;
    }
    __stack_space[__stack_top_index ++] = e;
    return 0;
}

static int64_t stack_pop(int64_t *e)
{
    if (__stack_top_index <= 0) {
        printf("stack overflow. (empty)\n");
        return -1;
    }
    if (e != NULL) {
        *e = __stack_space[__stack_top_index];
    }
    __stack_space[__stack_top_index --] = 0;

    return 0;
}

static void stack_size_print(void)
{
    printf("stack size : %zu / %zu\n", __stack_top_index, STACK_SIZE);
}

static void stack_print(void)
{
    int32_t i = __stack_top_index - 1;
    printf("top [ ");
    do {
        printf("%lld, ", __stack_space[i--]);
    } while (i >= 0);
    printf("] bottom. \n -- stack len = %zu\n", __stack_top_index);
}
#endif /* STACK_ENABLE */

#ifdef QUEUE_ENABLE
static int64_t __queue_space[QUEUE_SIZE] = {0};
static size_t __queue_len = 0;
static int64_t *__queue_head = __queue_space;
static int64_t *__queue_tail = __queue_space;

static int64_t queue_push(int64_t e)
{
    if (__queue_len >= QUEUE_SIZE) {
        printf("queue overflow (full)\n");
        return -1;
    }
    *(__queue_tail++) = e;
    __queue_len ++;

    return 0;
}

static int64_t queue_pop(int64_t *e)
{
    if (__queue_len <= 0) {
        printf("queue overflow (empty)\n");
        return -1;
    }
    if (e != NULL) {
        *e = *__queue_head;
    }
    size_t i = 0;
    __queue_len --;
    for (i = 0; i < __queue_len; i ++) {
        __queue_head[i] = __queue_head[i+1];
    }
    *(__queue_tail --) = 0;
    return 0;
}

static void queue_size_print(void)
{
    printf("queue size : %zd\n", __queue_len);
}

static void queue_print(void)
{
    size_t i = 0;
    printf("head [ ");
    do {
        printf("%lld, ", __queue_space[i++]);
    } while (i < __queue_len);
    printf("] tail. \n -- queue len = %zu\n", __queue_len);
}

static size_t queue_size(void)
{
    return __queue_len;
}

#endif /* QUEUE_ENABLE */

typedef struct bin_tree_node_t {
    int32_t val;
    struct bin_tree_node_t *left;
    struct bin_tree_node_t *right;
} BIN_TREE_NODE;

static BIN_TREE_NODE* bin_tree_create(void)
{
    BIN_TREE_NODE *p = NULL;
    p = (BIN_TREE_NODE *)malloc(sizeof(BIN_TREE_NODE));
    if (p == NULL) {
        printf("malloc a tree memory failed\n");
        return NULL;
    }
    return p;
}

static int32_t bin_tree_insert_by_preorder(BIN_TREE_NODE **tree)
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
            LOG("inserted null\n");
        } else {
            *tree = bin_tree_create();
            if (*tree == NULL) {
                printf("malloc a tree memory failed\n");
                return -1;
            }
            (*tree)->left = (*tree)->right = NULL;
            (*tree)->val = ch - '0';
            LOG("inserted value %lld\n", (*tree)->val);
            LOG("insert left :\n");
            bin_tree_insert_by_preorder(&((*tree)->left));
            LOG("insert right :\n");
            bin_tree_insert_by_preorder(&((*tree)->right));
        }
    }
    return 0;
}
#define CONVERT_TREE_NODE_TO_ADDR(tree) ((int64_t)(tree))
#define CONVERT_ADDR_TO_TREE_NODE(tree) ((BIN_TREE_NODE *)(tree))

static void bin_tree_print_by_layers(BIN_TREE_NODE *tree)
{
    int64_t val = 0;
    BIN_TREE_NODE *p = tree;
    if (NULL == p) {
        return;
    }
    queue_push(CONVERT_TREE_NODE_TO_ADDR(p));

    while(queue_size() > 0) {
        queue_pop(&val);
        p = CONVERT_ADDR_TO_TREE_NODE(val);
        if (p->left != NULL) {
            queue_push(CONVERT_TREE_NODE_TO_ADDR(p->left));
        }
        if (p->right != NULL) {
            queue_push(CONVERT_TREE_NODE_TO_ADDR(p->right));
        }
        printf("%d, ", p->val);
    }
}

static void bin_tree_print_by_preorder(BIN_TREE_NODE *tree)
{
    if (NULL == tree) {
        return;
    }
    printf("%d, ", tree->val);
    bin_tree_print_by_preorder(tree->left);
    bin_tree_print_by_preorder(tree->right);
}

static void bin_tree_print_by_rootorder(BIN_TREE_NODE *tree)
{
    if (NULL == tree) {
        return;
    }
    bin_tree_print_by_rootorder(tree->left);
    printf("%d, ", tree->val);
    bin_tree_print_by_rootorder(tree->right);
}

static void bin_tree_print_by_postorder(BIN_TREE_NODE *tree)
{
    if (NULL == tree) {
        return;
    }
    bin_tree_print_by_postorder(tree->left);
    bin_tree_print_by_postorder(tree->right);
    printf("%d, ", tree->val);
}

static void bin_tree_free(BIN_TREE_NODE *tree)
{

    if (NULL == tree) {
        printf("tree is null, return\n");
        return;
    }
    BIN_TREE_NODE *next_left = tree->left, *next_right = tree->right;

    tree->val = 0;
    free(tree);

    if (next_left != NULL) {
        bin_tree_free(next_left);
    }
    if (next_right != NULL) {
        bin_tree_free(next_right);
    }
}

int32_t p_n(int32_t n)
{
    if (n == 1 || n == 2) {
        return 1;
    } else if (n >= 3 ){
        return p_n(n - 1) + p_n(n - 2);
    } else {
        return -1;
    }
}

int main(void) {

    size_t i = 0;
    int32_t pop_val;
    int32_t ret = 0;
    /*
    // 124#7###35##68###
    */
    BIN_TREE_NODE *tree = NULL;
    printf("input binary tree using the pre-order (# is NULL):");
    ret = bin_tree_insert_by_preorder(&tree);
    if (ret != 0) {
        printf("set bin tree failed\n");
        return -1;
    }
    printf("\nprint tree by layers: ");
    bin_tree_print_by_layers(tree);
    printf("\nprint tree by pre-order: ");
    bin_tree_print_by_preorder(tree);
    printf("\nprint tree by root-order: ");
    bin_tree_print_by_rootorder(tree);
    printf("\nprint tree by post-order: ");
    bin_tree_print_by_postorder(tree);
    printf("\n");
    bin_tree_free(tree);

    return 0;
}