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

void linklist_prink_revert(LINKLIST_T *list)
{
    if (list == NULL) {
        printf("check paramters\n");
        return;
    }
    LINKLIST_T *p = list;
    if (p != NULL) {
        if (p->next != NULL) {
            linklist_prink_revert(p->next);
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
    linklist_prink_revert(test_node);
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