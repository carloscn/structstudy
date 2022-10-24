#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "utils.h"
#include "linklist.h"

static int32_t merge_two_lists(LINKLIST_T* list1, LINKLIST_T* list2, LINKLIST_T** list_out)
{
    int32_t ret = 0;
    LINKLIST_T **op_node = NULL;

    UTILS_CHECK_PTR(list1);
    UTILS_CHECK_PTR(list2);

    while (((list1 != NULL) || (list2 != NULL))) {
        // check conditions
        if ((NULL == list1) && (NULL != list2)) {
            op_node = &list2;
        } else if ((NULL != list1) && (NULL == list2)) {
            op_node = &list1;
        } else if ((NULL != list1) && (NULL != list2)) {
            op_node = (list1->val <= list2->val) ? &list1 : &list2;
        } else {
            break;
        }

        // add value to new linklist
        ret = linklist_add_value(list_out, (*op_node)->val);
        UTILS_CHECK_RET(ret);
        (*op_node) = (*op_node)->next;
    };

finish:
    return ret;
}

int main(void)
{
    int32_t ret = 0;
    LINKLIST_T *list1 = NULL, *list2 = NULL, *list_out = NULL;
    const int64_t buffer1[] = {1, 2, 4, 8, 22, 23, 25};
    const int64_t buffer2[] = {1, 3, 4, 6, 9, 10, 12, 29};

    ret = linklist_append_array(&list1, buffer1, ARRAY_SIZE(buffer1));
    UTILS_CHECK_RET(ret);
    linklist_print(list1);

    ret = linklist_append_array(&list2, buffer2, ARRAY_SIZE(buffer2));
    UTILS_CHECK_RET(ret);
    linklist_print(list2);

    ret = merge_two_lists(list1, list2, &list_out);
    UTILS_CHECK_RET(ret);
    linklist_print(list_out);

finish:
    linklist_free(&list1);
    linklist_free(&list2);
    linklist_free(&list_out);
    return ret;
}