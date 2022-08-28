#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "utils.h"
#include "stack.h"

/* method 1:  */
/* ---------------------------------------------------------------------*/
static int32_t method_1_print_value(int32_t n)
{
    int32_t i = 0;
    size_t count = 1;

    if (n <= 0) {
        return 0;
    }
    for (i = 0; i < n; i++) {
        count *= 10;
    }
    printf("\n");
    for (i = 1; i < count; i ++) {
        printf("%d, ", i);
    }
    printf("\n");
    return 0;
}

/* method 2:  */
/* ---------------------------------------------------------------------*/
static void stack_print_value(STACK_T *sk, int32_t k)
{
    size_t i = 0;
    if (sk->top_index < k || sk->space[0] == (int64_t)'0') {
        return;
    }
    for (i = 0; i < sk->top_index; i ++) {
        printf("%c", (char)sk->space[i]);
    }
    printf(", ");
}
/*
 * k : recuirsion depth.
 * n : limit
 */
static int32_t print_one_position(STACK_T *stack, int32_t k, int32_t n)
{
    if (k > n - 1) {
        return 0;
    }
    char i = 0;
    char j = 0;
    int32_t bk = n;
    for (i = '0'; i <= '9'; i ++) {
        stack_push(stack, (int64_t)i);
        stack_print_value(stack, bk);
        k ++;
        print_one_position(stack, k, n);
        stack_pop(stack, NULL);
        k --;
    }
    return 0;
}

static int32_t method_2_print_value(int32_t n)
{
    int32_t i = 0;
    STACK_T *ps, stack;
    ps = &stack;

    if (n <= 0) {
        return 0;
    }
    stack_malloc(ps, STACK_DEFAULT_SIZE);

    for (i = 1; i <= n; i ++) {
        //printf("print %d posito value : \n", i);
        print_one_position(ps, 0, i);
        //printf("\n");
    }

    stack_free(ps);
    return 0;
}

int main(void)
{
    int32_t ret = 0;
    clock_t start, end;
    start = clock();
    ret = method_1_print_value(0);
    ret = method_1_print_value(1);
    ret = method_1_print_value(2);
    ret = method_1_print_value(3);
    end = clock();
    LOG("method 1 time = %fs\n", (double)(end - start) / CLOCKS_PER_SEC);
    printf("\n");

    start = clock();
    ret = method_2_print_value(0);
    ret = method_2_print_value(1);
    ret = method_2_print_value(2);
    ret = method_2_print_value(3);
    end = clock();
    LOG("method 2 time = %fs\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}
