#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "linklist.h"
#include "utils.h"

LINKLIST_T* linklist_create_node(int64_t val)
{
    LINKLIST_T *p = NULL;
    p = (LINKLIST_T *)malloc(sizeof(LINKLIST_T));
    if (p != NULL) {
        p->val = val;
    }
    return p;
}

void linklist_free_node(LINKLIST_T *p)
{
    if (p != NULL)
        free(p);
}

int32_t linklist_add_value(LINKLIST_T **list, int64_t val)
{
    LINKLIST_T *list_new = (LINKLIST_T*)malloc(sizeof(LINKLIST_T));
    LINKLIST_T *p = NULL;
    if (NULL == list_new) {
        printf("failed create new node\n");
        return -1;
    }
    list_new->next = NULL;
    list_new->val = val;
    // judge first node;
    if (*list == NULL) {
        *list = list_new;
    // judge node that includes the sub nodes.
    } else {
        p = *list;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = list_new;
    }
    return 0;
}


int32_t linklist_add_node(LINKLIST_T *list, LINKLIST_T *node)
{
    if (NULL == node || NULL == list) {
        printf("add failed, node is NULL\n");
        return -1;
    }
    LINKLIST_T *p = list;
    do {
        p = p->next;
    } while(p->next != NULL);
    p->next = node;

    return 0;
}

#define O_1 1
#define O_N 0

#if O_1

int32_t linklist_remove_node(LINKLIST_T *list, LINKLIST_T *node)
{
    if (NULL == node || NULL == list) {
        printf("delete failed, node is NULL\n");
        return -1;
    }

    LINKLIST_T *p = list;
    /* Change node value. */
    LINKLIST_T *p1, *p2;
    p1 = node;
    p2 = node->next;
    p1->val = p2->val;
    p1->next = p2->next;
    node = p2;
    linklist_free_node(p2);

    return 0;
}
#endif /* O_1 */

#if O_N
int32_t linklist_remove_node(LINKLIST_T *list, LINKLIST_T *node)
{
    if (NULL == node || NULL == list) {
        printf("delete failed, node is NULL\n");
        return -1;
    }

    LINKLIST_T *p = list;

    if (p == node) {
        goto deal;
    }
    while (p->next != node && p->next->next != NULL) {
        p = p->next;
    };

    if (NULL == p) {
        printf("not found the inputted node\n");
        return -1;
    }
deal:
    p->next = node->next;
    linklist_free_node(node);

    return 0;
}
#endif /* O_N */

int32_t linklist_remove_value(LINKLIST_T **list, int64_t val)
{
    if (list == NULL && *list == NULL) {
        printf("check paramters\n");
        return -1;
    }

    LINKLIST_T *p = *list;
    LINKLIST_T *d = NULL;

    if (p->val == val) {
        d = p;
        p = d->next;
        d->val = 0;
        free(d);
    } else {
        do {
            if (p->next->val != val) {
                p = p->next;
            } else {
                d = p->next;
                if (d->next == NULL) {
                    p->next = NULL;
                } else {
                    p->next = d->next;
                }
                d->next = NULL;
                free(d);
                break;
            }
        } while(p != NULL);
    }
    return 0;
}

int32_t linklist_append_array(LINKLIST_T **node, const int64_t *buffer, size_t len)
{
    int32_t ret = 0;
    size_t i = 0;

    if (0 == len) {
        goto finish;
    }
    UTILS_CHECK_PTR(node);
    UTILS_CHECK_PTR(buffer);

    for (i = 0; i < len; i ++) {
        ret = linklist_add_value(node, buffer[i]);
        UTILS_CHECK_RET(ret);
    }

finish:
    return ret;
}

inline int32_t linklist_copy_node(LINKLIST_T *node_dest, LINKLIST_T *node_src)
{
    int32_t ret = 0;

    UTILS_CHECK_PTR(node_dest);
    UTILS_CHECK_PTR(node_src);

    memcpy(node_dest, node_src, sizeof(LINKLIST_T));

finish:
    return ret;
}

inline int32_t linklist_dup_node(LINKLIST_T **node_dest, LINKLIST_T *node_src)
{
    int32_t ret = 0;
    LINKLIST_T *list = NULL;

    UTILS_CHECK_PTR(node_dest);

    list = linklist_create_node(0);
    UTILS_CHECK_PTR(list);

    ret = linklist_copy_node(list, node_src);
    if (ret != 0) {
        LOG("linklist_copy_node failed\n");
        linklist_free_node(list);
        goto finish;
    }

    *node_dest = list;
finish:
    return ret;
}

int32_t linklist_get_len(LINKLIST_T *list, size_t *o_len)
{
    int32_t ret = 0;
    size_t len = 0;
    LINKLIST_T *node = list;

    UTILS_CHECK_PTR(list);
    UTILS_CHECK_PTR(o_len);

    do {
        node = node->next;
        len ++;
    } while(node != NULL);

    *o_len = len;
finish:
    return ret;
}

void linklist_free(LINKLIST_T **node)
{
    if (*node == NULL || node == NULL) {
        return;
    }
    LINKLIST_T *p = *node, *next_p = NULL;
    do {
        next_p = p->next;
        linklist_free_node(p);
        p = next_p;
    } while (p != NULL);
}

int32_t linklist_revert(LINKLIST_T **list)
{
    int32_t ret = 0;
    LINKLIST_T *back_node = NULL, *pre_node = NULL, *cur_node = NULL;

    UTILS_CHECK_PTR(list);

    cur_node = *list;
    back_node = linklist_create_node(0);
    UTILS_CHECK_PTR(back_node);

    do {
        ret = linklist_copy_node(back_node, cur_node);
        UTILS_CHECK_RET(ret);
        cur_node->next = pre_node;
        pre_node = cur_node;
        cur_node = back_node->next;
    } while (cur_node != NULL);

    *list = pre_node;

finish:
    if (back_node != NULL)
        free(back_node);
    return ret;
}

void linklist_print(LINKLIST_T *list)
{
    if (list == NULL) {
        printf("check paramters\n");
        return;
    }
    LINKLIST_T *p = list;
    printf("\n");
    do {
        printf("%lld -> ", p->val);
        p = p->next;
    } while (p != NULL);
    printf("NULL\n");
}

void linklist_print_revert(LINKLIST_T *list)
{
    if (list == NULL) {
        printf("check paramters\n");
        return;
    }
    LINKLIST_T *p = list;
    if (p != NULL) {
        if (p->next != NULL) {
            linklist_print_revert(p->next);
        }
        printf("%lld -> ", p->val);
    }
}

int32_t linklist_selftest(void)
{
    LINKLIST_T *test_node = NULL;
    LINKLIST_T *to_be_add_node = NULL;

    /* test for adding and removing value. */
    linklist_add_value(&test_node, 1);
    linklist_add_value(&test_node, 2);
    linklist_add_value(&test_node, 3);
    linklist_add_value(&test_node, 4);
    linklist_add_value(&test_node, 5);
    linklist_remove_value(&test_node, 2);
    linklist_print(test_node);
    linklist_print_revert(test_node);
    printf("\n");

    /* test for adding and removing node. */
    to_be_add_node = linklist_create_node(33333);
    if (NULL == to_be_add_node) {
        printf("node create failed\n");
        goto err;
    }
    linklist_add_node(test_node, to_be_add_node);
    linklist_print(test_node);
    linklist_add_value(&test_node, 999);
    linklist_print(test_node);
    linklist_remove_node(test_node, to_be_add_node);
    linklist_print(test_node);

err:
    linklist_free(&test_node);
    return 0;
}