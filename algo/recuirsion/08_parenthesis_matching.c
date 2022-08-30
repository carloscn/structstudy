#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include "utils.h"
#include "stack.h"
#include "strlist.h"

static bool check_parenthesis_matching(const char *str)
{
    size_t i = 0;
    size_t count = 0;
    if (NULL == str) {
        LOG("input failed\n");
        return false;
    }
    for (i = 0; i < strlen(str); i ++) {
        if (str[i] == '{') {
            count ++;
        } else if (str[i] == '}') {
            count --;
        } else {
            LOG("input str error \n");
            return false;
        }
        if (count < 0 || count > 3) {
            return false;
        }
    }

    if (count != 0) {
        return false;
    }

    return true;
}

static int32_t stack_str_free(STACK_T *str_list)
{
    size_t i = 0;
    char *p = NULL;
    int64_t val = 0;
    for (i = 0; i < str_list->top_index; i ++) {
        stack_pop(str_list, &val);
        p = (char*)val;
        free(p);
    }
    return 0;
}

static char* stack_to_str(STACK_T *str_stack)
{
    size_t i = 0;
    char* str = (char*)malloc(str_stack->top_index + 1);
    if (NULL == str) {
        return NULL;
    }
    memset(str, '\0', str_stack->top_index + 1);
    for (i = 0; i < str_stack->top_index; i ++) {
        str[i] = (char)str_stack->space[i];
    }

    return str;
}

static int32_t stack_str_print(STACK_T *str_list)
{
    size_t i = 0;
    char *p = NULL;
    int64_t val = 0;
    for (i = 0; i < str_list->top_index; i ++) {
        val = str_list->space[i];
        p = (char*)val;
        printf("%s\n", p);
    }
    return 0;
}

static int32_t method_2_gen_bt(STRLIST_T *str_list, STACK_T *str_stack, int32_t left, int32_t right, int32_t n)
{

    char *str = NULL;
    if (left == 0 && right == 0) {
        stack_print_as_char(str_stack);
        str = stack_to_str(str_stack);
        if (str == NULL) {
            LOG("malloc string error (stack_to_str) \n");
            return -1;
        }
        LOG("convert %s ", str);
        strlist_add(str_list, str);
        return 0;
    }
    int32_t i = 0;
    char c;
    // gen left
    if (left > 0) {
        c = '{';
        stack_push(str_stack, (int64_t) c );
        method_2_gen_bt(str_list, str_stack, left - 1, right, n);
        stack_pop(str_stack, NULL);
    }
    // gen right
    if (left < right) {
        c = '}';
        stack_push(str_stack, (int64_t) c );
        method_2_gen_bt(str_list, str_stack, left, right - 1, n);
        stack_pop(str_stack, NULL);
    }
    return 0;
}


static int32_t method_1_gen_bt(STRLIST_T *str_list, STACK_T *str_stack, int32_t k, int32_t n)
{
    size_t str_element_count = 0;
    char *str = NULL;
    str_element_count = stack_count(str_stack);

    if (str_element_count == 2*n) {
        stack_print_as_char(str_stack);
        str = stack_to_str(str_stack);
        if (str == NULL) {
            LOG("malloc string error (stack_to_str) \n");
            return -1;
        }
        if (!check_parenthesis_matching(str)) {
            free(str);
            return 0;
        }
        LOG("convert %s ", str);
        strlist_add(str_list, str);
        printf(" str count = %zu\n", str_list->size);
        return 0;
    }
    int32_t i = 0;
    char c = '{';
    for (i = 0; i < k; i ++) {
        // gen left
        c = '{';
        stack_push(str_stack, (int64_t) c );
        method_1_gen_bt(str_list, str_stack, k++, n);
        stack_pop(str_stack, NULL);
        k --;

        // gen right
        c = '}';
        stack_push(str_stack, (int64_t) c );
        method_1_gen_bt(str_list, str_stack, k++, n);
        stack_pop(str_stack, NULL);
        k--;
    }
    return 0;
}

static int32_t method_1_gen_parenthesis(int32_t n)
{
    STACK_T sk;
    STRLIST_T *str_list = strlist_malloc();
    stack_malloc(&sk, STACK_DEFAULT_SIZE);
    method_1_gen_bt(str_list, &sk, 1, n);
    strlist_infolog(str_list);
    strlist_free(str_list);
    stack_free(&sk);
    return 0;
}

static int32_t method_2_gen_parenthesis(int32_t n)
{
    STACK_T sk;
    STRLIST_T *str_list = strlist_malloc();
    stack_malloc(&sk, STACK_DEFAULT_SIZE);
    method_2_gen_bt(str_list, &sk, n, n, n);
    strlist_infolog(str_list);
    strlist_free(str_list);
    stack_free(&sk);
    return 0;
}

int32_t main(void)
{
    method_1_gen_parenthesis(3);
    method_2_gen_parenthesis(3);
    return 0;
}