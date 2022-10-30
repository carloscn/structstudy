#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "utils.h"
#include "linklist.h"

static int32_t delete_duplicates(LINKLIST_T *list)
{
    int32_t ret = 0;
    LINKLIST_T *free_node = NULL;

    UTILS_CHECK_PTR(list);

    while (list->next != NULL) {
        if (list->val == list->next->val) {
            free_node = list->next;
            list->next = list->next->next;
            linklist_free_node(free_node);
        } else {
            list = list->next;
        }
    }

finish:
    return ret;
}

int main(void)
{
    int32_t ret = 0;
    LINKLIST_T *list1 = NULL, *list2 = NULL;
    const int64_t buffer1[] = {1, 1, 4, 8, 8, 23, 25};
    const int64_t buffer2[] = {1, 4, 4, 4, 4, 4, 4, 4};

    printf("\nthe list 1: \n-----------------------------------\n");
    ret = linklist_append_array(&list1, buffer1, ARRAY_SIZE(buffer1));
    UTILS_CHECK_RET(ret);
    linklist_print(list1);

    ret = delete_duplicates(list1);
    UTILS_CHECK_RET(ret);
    linklist_print(list1);

    printf("\n\n\nthe list 2: \n-----------------------------------\n");
    ret = linklist_append_array(&list2, buffer2, ARRAY_SIZE(buffer2));
    UTILS_CHECK_RET(ret);
    linklist_print(list2);

    ret = delete_duplicates(list2);
    UTILS_CHECK_RET(ret);
    linklist_print(list2);

finish:
    linklist_free(&list1);
    linklist_free(&list2);
    return ret;
}