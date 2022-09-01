#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include "utils.h"
#include "strlist.h"
#include "stack.h"

static void print_array(int64_t *array, size_t len)
{
    size_t i = 0;
    for (i = 0; i < len; i ++) {
        printf("%llu, ", array[i]);
    }
    printf("\n");
}

static bool is_compare_by_dictinary_order(int32_t a, int32_t b, bool last_equal)
{
    if (a == b) {
        return true;
    }

    char a_str[20], b_str[20];
    //LOG("a = %d b = %d\n", a, b);
    memset(a_str, '\0', 20);
    memset(b_str, '\0', 20);
    sprintf(a_str, "%d", a);
    sprintf(b_str, "%d", b);
    LOG("a_str = %s b_str = %s\n", a_str, b_str);

    if (strlen(a_str) == 1 && strlen(b_str) != 1 && last_equal == true) {
        return true;
    }

    if (strlen(a_str) != 1 && strlen(b_str) == 1 && last_equal == true) {
        return false;
    }

    size_t i = 0;
    char a_h, b_h;
    a_h = a_str[0];
    b_h = b_str[0];

    if (a_h == b_h) {
        if (strlen(a_str) == 1) {
            return true;
        }
        if (strlen(b_str) == 1) {
            return false;
        }
        memcpy(a_str, a_str + 1, strlen(a_str));
        memcpy(b_str, b_str + 1, strlen(b_str));
        return is_compare_by_dictinary_order(atoi(a_str), atoi(b_str), true);
    } else if (a_h < b_h) {
        return true;
    }
    return false;
}


static int method_1(int32_t test_array[], size_t array_sz)
{
    // check parameters
    if (0 == array_sz) {
        LOG("error: input len is 0\n");
        return 0;
    }
    if (NULL == test_array) {
        LOG("error: input parameter NULL\n");
        return -1;
    }

    size_t i = 0, j = 0;
    int64_t *array = (int64_t *)malloc(array_sz * sizeof(int64_t));
    if (array == NULL) {
        return -1;
    }
    for (i = 0; i < array_sz; i ++) {
        array[i] = test_array[i];
        printf("%llu, ", array[i]);
    }
    printf("\n");
    for (i = 0; i < array_sz - 1; i ++) {
        for (j = 0; j < array_sz - i - 1; j ++) {
            //LOG("compare %d, %d\n", array[j], array[j+1]);
            if (is_compare_by_dictinary_order(array[j], array[j+1], false) == false) {
                utils_swap(&array[j], &array[j+1]);
                LOG("change position to : \n");
                print_array(array, (size_t)array_sz);
            }
        }
    }
    print_array(array, array_sz);

    free(array);
    return 0;
}



static void bt(STRLIST_T *result_list, STACK_T *stack, int32_t k, int32_t n, int32_t v)
{
    char *str_result;
    if (k > n) {
        str_result = stack_to_str(stack);
        strlist_add(result_list, str_result);
        strlist_infolog(str_result);
        return;
    }

    int32_t i = 0;
    for (i = 0; i < 9; i ++) {
        stack_push(stack, (int64_t) (i + '0'));
        bt(result_list, stack, k + 1, n, v);
        stack_pop(stack, NULL);
    }
}


int main(void) {
    int ret;
    clock_t start, end;
    int32_t origin_test_array[] = {1, 9, 10, 3, 33, 2, 27, 99};
    size_t array_sz = sizeof(origin_test_array)/sizeof(int);
    STRLIST_T *str = strlist_malloc();

    ret = is_compare_by_dictinary_order(100, 1, false);
    if (ret == true) {
        LOG("no need to change position\n");
    } else {
        LOG("need to change position\n");
    }


    start = clock();
    ret = method_1(origin_test_array, array_sz);
    end = clock();
    LOG("\nmethod 1 time = %f\n", (double)(end - start) / CLOCKS_PER_SEC);

    start = clock();
    ret = bt();
    end = clock();
    LOG("\nmethod 2 time = %f\n", (double)(end - start) / CLOCKS_PER_SEC);

    return ret;
}