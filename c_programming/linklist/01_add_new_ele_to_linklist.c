#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct list_node_t {
    int32_t val;
    struct list_node_t *next;
} LIST_NODE;


static int add_value(LIST_NODE **list, int32_t val) {

    LIST_NODE *list_new = (LIST_NODE*)malloc(sizeof(LIST_NODE));
    LIST_NODE *p = NULL;
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

static int remove_value(LIST_NODE **list, int32_t val)
{

    if (list == NULL && *list == NULL) {
        printf("check paramters\n");
        return -1;
    }

    LIST_NODE *p = *list;
    LIST_NODE *d = NULL;

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

void free_node(LIST_NODE **node)
{
    if (*node == NULL || node == NULL) {
        return;
    }
    LIST_NODE *p = *node, *next_p = NULL;
    do {
        next_p = p->next;
        free(p);
        p = next_p;
    } while (p != NULL);

}

static int print_linklist(LIST_NODE *list)
{
    if (list == NULL) {
        printf("check paramters\n");
        return -1;
    }
    LIST_NODE *p = list;
    printf("\n");
    do {
        printf("%d,", p->val);
        p = p->next;
    } while (p != NULL);
    printf("\n");

    return 0;
}

static int print_revert_linklist(LIST_NODE *list)
{
    if (list == NULL) {
        printf("check paramters\n");
        return -1;
    }
    LIST_NODE *p = list;
    if (p != NULL) {
        if (p->next != NULL) {
            print_revert_linklist(p->next);
        }
        printf("%d,", p->val);
    }

    return 0;
}

int main(void)
{
    LIST_NODE *test_node = NULL;
    LIST_NODE *p = NULL;
    add_value(&test_node, 1);
    add_value(&test_node, 2);
    add_value(&test_node, 3);
    add_value(&test_node, 4);
    add_value(&test_node, 5);
    add_value(&test_node, 5);
    add_value(&test_node, 5);
    add_value(&test_node, 5);
    add_value(&test_node, 5);

    remove_value(&test_node, 2);
    print_linklist(test_node);
    print_revert_linklist(test_node);

    free_node(&test_node);
    return 0;
}