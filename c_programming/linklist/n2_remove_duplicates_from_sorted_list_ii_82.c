#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "utils.h"
#include "linklist.h"

int32_t delete_duplicates(LINKLIST_T* head)
{
    int32_t ret = 0;
    LINKLIST_T *list = head;
    LINKLIST_T *pre = list;

    UTILS_CHECK_PTR(list);

    while (list->next != NULL) {
        if (list->val != list->next->val) {
            pre = list;
            list = list->next;
        } else {
            pre->next = list->next;
            linklist_free_node(list);
            list = pre->next;
        }
    }

finish:
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;
    int64_t buffer[] = {1,2,3,3,4,4,5};
    LINKLIST_T *list = NULL;

    ret = linklist_append_array(&list, buffer, UTILS_ARRAY_SIZE(buffer));
    UTILS_CHECK_RET(ret);

    linklist_print(list);

    ret = delete_duplicates(list);
    UTILS_CHECK_RET(ret);

    linklist_print(list);

finish:
    linklist_free(&list);
    return ret;
}