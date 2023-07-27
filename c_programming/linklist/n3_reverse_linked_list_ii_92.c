#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "utils.h"
#include "linklist.h"

int32_t reverse_between(LINKLIST_T *in_list, LINKLIST_T **out_list, size_t left, size_t right)
{
    int32_t ret = 0;

    UTILS_CHECK_PTR(in_list);
    UTILS_CHECK_PTR(out_list);

    if (left > right || left == 0) {
        ret = -1;
        goto finish;
    }

    if (left == right) {
        ret = linklist_copy_node(in_list, *out_list);
        goto finish;
    }

    size_t ln = left - 1;
    size_t rn = right - 1;
    LINKLIST_T *L = in_list, *R = in_list, *PL = NULL, *PR = NULL;

    // Find left header
    while (ln --) {
        PL = L;
        L = L->next;
    }

    // Find right header
    while (rn --) {
        PR = R;
        R = R->next;
    }

    LINKLIST_T *t_node;
    while (R != L) {
        // change L and R position
        PL->next = R;
        PR->next = L;
        ret = linklist_dup_node(&t_node, R->next);
        UTILS_CHECK_RET(ret);
        t_node = R->next;
        R = L->next;
        L->next = t_node;
        linklist_free_node(t_node);

        // change L and R position
        PL = L;
        L = L->next;

        R = PR;
        while (PR->next != R) {
            R = R->next;
        }
    }

finish:
    linklist_free_node(t_node);
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