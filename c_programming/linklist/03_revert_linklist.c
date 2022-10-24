#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "utils.h"
#include "linklist.h"

int main(void)
{
    int32_t ret = 0;
    LINKLIST_T *list = NULL;
    const int64_t buffer[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};

    ret = linklist_append_array(&list, buffer, ARRAY_SIZE(buffer));
    UTILS_CHECK_RET(ret);
    linklist_print(list);

    ret = linklist_revert(&list);
    UTILS_CHECK_RET(ret);
    linklist_print(list);

finish:
    linklist_free(&list);
    return ret;
}