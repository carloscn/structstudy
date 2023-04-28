#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "utils.h"
#include "linklist.h"

int32_t get_decimal_value(LINKLIST_T* list, int32_t *out)
{
    int32_t ret = 0;
    int32_t val = 0;

    UTILS_CHECK_PTR(list);
    UTILS_CHECK_PTR(out);

    do {
        val = (val << 1) + list->val;
        list = list->next;
    } while (list != NULL);

    *out = val;

finish:
    return ret;
}

int main(void)
{
    int32_t ret = 0;
    LINKLIST_T *list1 = NULL, *list2 = NULL, *t_list = NULL;
    const int64_t buffer1[] = {1,0,1};
    const int64_t buffer2[] = {1,0,0,1,0,0,1,1,1,0,0,0,0,0,0};
    int32_t val = 0;

    printf("\nthe list 1: \n-----------------------------------\n");
    ret = linklist_append_array(&list1, buffer1, ARRAY_SIZE(buffer1));
    UTILS_CHECK_RET(ret);
    linklist_print(list1);

    printf("\n\n\nthe list 2: \n-----------------------------------\n");
    ret = linklist_append_array(&list2, buffer2, ARRAY_SIZE(buffer2));
    UTILS_CHECK_RET(ret);
    linklist_print(list2);

    ret = get_decimal_value(list1, &val);
    UTILS_CHECK_RET(ret);
    LOG("the value is %d\n", val);
    linklist_print(list1);

    ret = get_decimal_value(list2, &val);
    UTILS_CHECK_RET(ret);
    LOG("the value is %d\n", val);


finish:
    linklist_free(&list1);
    linklist_free(&list2);
    return ret;
}