#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include "utils.h"
#include "stack.h"
#include "strlist.h"

/*
 * k：depth of recuirsion
 * n: number of subsets
 * start_pos: start pos of subset
 * m: element numbers of a subset.
*/
static void bt(STRLIST_T *out_list,
                STACK_T* stack,
                const char* str,
                int32_t k,
                int32_t n,
                int32_t start_pos,
                int32_t m)
{
    int32_t i = 0;
    size_t str_len = strlen(str);
    // end condition
    if (k == n + 1) {
        if (stack_count(stack) == n)
            stack_print(stack);
        return;
    }
    // recuirsion
    // i 切割元素的次数
    for (i = 1; i < str_len - k - 1; i ++) {
        //LOG("i = %d\n", i);
        start_pos += i;
        if (str_len - start_pos - 1 < n + 1 - k) {
            return;
        }
        stack_push(stack, (int64_t)start_pos);
        bt(out_list, stack, str, k + 1, n, start_pos, i);
        stack_pop(stack, NULL);
        start_pos -= i;
    }
}


static int32_t recover_ip_address(const char* origin_str, STRLIST_T *out_ip_str_list)
{
    if (NULL == origin_str || NULL == out_ip_str_list) {
        LOG("input str error \n");
        return -1;
    }
    STACK_T stack;
    size_t origin_str_len = strlen(origin_str);

    stack_init(&stack, STACK_DEFAULT_SIZE);
    bt(out_ip_str_list, &stack, origin_str, 1, 3, 0, 0);

    stack_deinit(&stack);
    return 0;
}


int main(void)
{
    int32_t ret = 0;
    const char *origin_str = "10203040";
    STRLIST_T *str_list = strlist_malloc();
    if (str_list == NULL) {
        LOG("error strlist malloc\n");
        return -1;
    }

    ret = recover_ip_address(origin_str, str_list);
    if (ret != 0) {
        LOG("recover ip failed\n");
        return ret;
    }
    strlist_infolog(str_list);

    return ret;
}