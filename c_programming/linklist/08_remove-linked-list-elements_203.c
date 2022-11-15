#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "utils.h"
#include "linklist.h"

static int32_t remove_list_elements(LINKLIST_T *p_list, int64_t val)
{
    int32_t ret = 0;
    LINKLIST_T *write_node = p_list;
    LINKLIST_T *free_node = NULL;

    UTILS_CHECK_PTR(p_list);

    while (p_list != NULL) {
        if (p_list->val != val) {
            write_node->val = p_list->val;
            free_node = write_node;
            write_node = write_node->next;
        }
        p_list = p_list->next;
    }
    linklist_free(&(free_node->next));
    free_node->next = NULL;

finish:
    return ret;
}


int main(void)
{
    int32_t ret = 0;
    LINKLIST_T *list1 = NULL, *list2 = NULL, *t_list = NULL;
    const int64_t buffer1[] = {1, 1, 4, 1, 9, 1, 25, 26, 8, 1};
    const int64_t buffer2[] = {1, 2, 3, 4, 5, 6, 9, 10};
    int64_t val = 0;

    printf("\nthe list 1: \n-----------------------------------\n");
    ret = linklist_append_array(&list1, buffer1, ARRAY_SIZE(buffer1));
    UTILS_CHECK_RET(ret);
    linklist_print(list1);

    printf("\n\n\nthe list 2: \n-----------------------------------\n");
    ret = linklist_append_array(&list2, buffer2, ARRAY_SIZE(buffer2));
    UTILS_CHECK_RET(ret);
    linklist_print(list2);

    ret = remove_list_elements(list1, 1);
    UTILS_CHECK_RET(ret);
    LOG("the removed value is %d\n", 1);
    linklist_print(list1);

    ret = remove_list_elements(list2, 2);
    UTILS_CHECK_RET(ret);
    LOG("the removed value is %d\n", 2);
    linklist_print(list2);


finish:
    linklist_free(&list1);
    linklist_free(&list2);
    return ret;
}