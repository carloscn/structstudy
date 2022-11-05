#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "utils.h"
#include "linklist.h"

//                ______
//                |    |
//                V    |
//      1 -> 2 -> 3 -> 4 ( -> NULL )
static int32_t check_cycle_linklist(LINKLIST_T *list, size_t *out_pos)
{
    int32_t ret = 0;
    size_t pos = 0;
    LINKLIST_T *quick_node = list;
    LINKLIST_T *slow_node = list;

    UTILS_CHECK_PTR(list);
    UTILS_CHECK_PTR(out_pos);

    while (++pos) {
        if ((NULL == slow_node->next) ||
            (NULL == quick_node->next) ||
            (NULL == quick_node->next->next)) {
            *out_pos = 0xffffUL;
            break;
        }
        slow_node = slow_node->next;
        quick_node = quick_node->next->next;
        if (slow_node == quick_node) {
            *out_pos = pos;
            break;
        }
    };

finish:
    return ret;
}

int main(void)
{
    int32_t ret = 0;
    LINKLIST_T *list1 = NULL, *list2 = NULL, *t_list = NULL;
    const int64_t buffer1[] = {1, 1, 4, 8, 8, 23, 25};
    const int64_t buffer2[] = {1, 2, 3, 4, 5, 6, 9, 10};
    size_t pos = 0;

    printf("\nthe list 1: \n-----------------------------------\n");
    ret = linklist_append_array(&list1, buffer1, ARRAY_SIZE(buffer1));
    UTILS_CHECK_RET(ret);
    linklist_print(list1);

    ret = check_cycle_linklist(list1, &pos);
    UTILS_CHECK_RET(ret);
    LOG("the pos is %zu\n", pos);

    printf("\n\n\nthe list 2: \n-----------------------------------\n");
    ret = linklist_append_array(&list2, buffer2, ARRAY_SIZE(buffer2));
    UTILS_CHECK_RET(ret);
    linklist_print(list2);

    // create cycle linkedlist;
    t_list = list2;
    while (t_list->next != NULL) {
        t_list = t_list->next;
    }
    t_list->next = list2->next->next;

    ret = check_cycle_linklist(list2, &pos);
    UTILS_CHECK_RET(ret);
    LOG("the pos is %zu\n", pos);

finish:
    linklist_free(&list1);
    t_list->next = NULL;
    linklist_free(&list2);
    return ret;
}