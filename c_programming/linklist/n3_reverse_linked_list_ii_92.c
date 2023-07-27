#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "utils.h"
#include "linklist.h"

int32_t reverse_between(LINKLIST_T *in_list, size_t left, size_t right)
{
    int32_t ret = 0;

    UTILS_CHECK_PTR(in_list);

    if (left > right || left == 0) {
        ret = -1;
        goto finish;
    }

    if (left == right) {
        goto finish;
    }

    size_t ln = left - 1;
    size_t rn = right - 1;
    LINKLIST_T *L = in_list, *R = in_list, *PR = NULL;

    // Find left header
    while (ln --) {
        L = L->next;
    }

    // Find right header
    while (rn --) {
        PR = R;
        R = R->next;
    }

    rn = right - left - 1;

    while (rn --) {
        ret = linklist_swap_value(L, R);
        UTILS_CHECK_RET(ret);

        L = L->next;
        R = PR;
        PR = in_list;
        while (PR->next != R) {
            PR = PR->next;
        }
    }

finish:
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;
    int64_t buffer[] = {1,2,3,4,5};
    LINKLIST_T *list = NULL;

    ret = linklist_append_array(&list, buffer, UTILS_ARRAY_SIZE(buffer));
    UTILS_CHECK_RET(ret);

    linklist_print(list);

    ret = reverse_between(list, 2, 4);
    UTILS_CHECK_RET(ret);

    linklist_print(list);

finish:
    linklist_free(&list);
    return ret;
}