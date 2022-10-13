#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include "utils.h"
#include "queue.h"
#include "stack.h"
#include "binary_tree.h"

static void insert_to_buffer_by_order(int64_t *array, size_t index, int64_t e)
{
    if (0 == index) {
        array[index] = e;
        return;
    }
    do {
        if (array[index - 1] > e) {
            array[index] = array[index - 1];
            array[index - 1] = e;
        } else {
            array[index] = e;
            break;
        }
        index --;
    } while( index > 0);
}

static int64_t method_1(BIN_TREE_NODE *tree, int64_t k)
{
    if (NULL == tree) {
        return -1;
    }
    int64_t val = 0;
    int64_t buffer[QUEUE_DEFUALT_SIZE] = {0};
    size_t index = 0;
    BIN_TREE_NODE *tree_p = NULL;
    QUEUE_T *queue = queue_malloc(QUEUE_DEFUALT_SIZE);

    if (NULL == queue) return -1;
    queue_push(queue, CONVERT_TREE_NODE_TO_ADDR(tree));
    while(queue_count(queue) != 0) {
        queue_pop(queue, &val);
        tree_p = CONVERT_ADDR_TO_TREE_NODE(val);
        if (tree_p->left != NULL) {
            queue_push(queue, CONVERT_TREE_NODE_TO_ADDR(tree_p->left));
        }
        if (tree_p->right != NULL) {
            queue_push(queue, CONVERT_TREE_NODE_TO_ADDR(tree_p->right));
        }
        insert_to_buffer_by_order(buffer, index++, tree_p->val);
    }
    queue_free(queue);
    return buffer[k-1];
}

static bool end_flag = 0;

static void bt(BIN_TREE_NODE *tree, STACK_T *stack, int64_t n)
{
    if (stack_count(stack) == n) {
        stack_print(stack);
        end_flag = 1;
        return;
    }
    if (NULL == tree) {
        return;
    }

    bt(tree->left, stack, n);
    if (end_flag != 1)
        stack_push(stack, tree->val);
    LOG("found value %lld\n", tree->val);
    bt(tree->right, stack, n);

}

static int64_t method_2(BIN_TREE_NODE *tree, int64_t k)
{
    if (NULL == tree) {
        return -1;
    }
    STACK_T *stack = stack_malloc(STACK_DEFAULT_SIZE);
    if (NULL == stack) return -1;
    bt(tree, stack, k);
    stack_pop(stack, &k);
    stack_free(stack);
    return k;
}

int32_t main(void)
{
    int32_t ret = 0;
    int64_t k = 3;
    int64_t result = 0;
    BIN_TREE_NODE *tree = NULL;
    clock_t start, end;
    binarytree_insert_by_preorder_by_string(&tree, "5,3,2,1,#,#,#,4,#,#,6,#,#,");
    binarytree_print_by_preorder(tree);
    printf("\n");
    binarytree_print_by_rootorder(tree);
    printf("\n");
    binarytree_print_by_postorder(tree);
    printf("\n");
    binarytree_print_by_layers(tree);
    LOG("call the method 1 |V\n");
    start = clock();
    result = method_1(tree, k);
    end = clock();
    LOG("method 1 result is %lld\n", result);
    LOG("method 1 time = %fs\n", (double)(end - start) / CLOCKS_PER_SEC);

    LOG("call the method 2 |V\n");
    start = clock();
    result = method_2(tree, k);
    end = clock();
    LOG("method 2 result is %lld\n", result);
    LOG("method 2 time = %fs\n", (double)(end - start) / CLOCKS_PER_SEC);
    binarytree_free(tree);
    return ret;
}
