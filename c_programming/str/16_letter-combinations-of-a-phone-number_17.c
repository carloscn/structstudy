#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "utils.h"
#include "strlist.h"
#include "stack.h"

#define C_OF(__u) ((size_t)((__u) - '0'))

static char* table[] = {
    "",         // 0
    "",         // 1
    "abc",      // 2
    "def",      // 3
    "ghi",      // 4
    "jkl",      // 5
    "mno",      // 6
    "pqrs",     // 7
    "tuv",      // 8
    "wxyz"      // 9
};

static void bt(STRLIST_T *str_list, char *in_buffer, STACK_T *stack, size_t current_depth, size_t current_len, size_t dest_depth)
{
    size_t i = 0;
    size_t dest_len = 0;

    if (current_depth >= dest_depth) {
        if (stack_count(stack) == dest_depth) {
            char *buffer = (char*)calloc(1, dest_depth + 1);
            for (i = 0; i < dest_depth; i ++) {
                buffer[i] = (char)stack->space[i];
            }
            strlist_add(str_list, buffer);
            free(buffer);
        }
        return;
    }

    dest_len = strlen(table[C_OF(in_buffer[current_depth])]);
    for (i = 0; i < dest_len; i ++) {
        stack_push(stack, (int64_t) *(table[C_OF(in_buffer[current_depth])] + i));
        bt(str_list, in_buffer, stack, current_depth + 1, i, dest_depth);
        stack_pop(stack, NULL);
    }
}

static int32_t print_letter_comb(char *number)
{
    int32_t ret = 0;
    size_t str_len = 0;
    STRLIST_T *list = NULL;
    STACK_T *stack = NULL;

    UTILS_CHECK_PTR(number);
    str_len = strlen(number);
    UTILS_CHECK_LEN(str_len);

    list = strlist_malloc();
    UTILS_CHECK_PTR(list);

    stack = stack_malloc(str_len);
    UTILS_CHECK_PTR(stack);

    bt(list, number, stack, 0, 0, str_len);

    strlist_infolog(list);

finish:
    stack_free(stack);
    strlist_free(list);
    return ret;
}


int32_t main(void)
{
    int32_t ret = 0;
    char s[100];

    sprintf(s,"%s", "237");
    ret = print_letter_comb(s);
    UTILS_CHECK_RET(ret);
    LOG_LINE_WITH_DOUBLE_TR();

finish:
    return ret;
}
