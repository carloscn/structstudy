#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define QUEUE_ENABLE

#define STACK_SIZE  (100UL)

static int64_t __stack_space[STACK_SIZE] = {0};
static size_t __stack_top_index = 0;

static int64_t stack_push(int64_t e)
{
    if (__stack_top_index >= STACK_SIZE) {
        printf("stack overflow. (full)\n");
        return -1;
    }
    __stack_space[__stack_top_index ++] = e;
    return 0;
}

static int64_t stack_pop(int64_t *e)
{
    if (__stack_top_index <= 0) {
        printf("stack overflow. (empty)\n");
        return -1;
    }
    if (e != NULL) {
        *e = __stack_space[__stack_top_index];
    }
    __stack_space[__stack_top_index --] = 0;

    return 0;
}

static void stack_size_print(void)
{
    printf("stack size : %zu / %zu\n", __stack_top_index, STACK_SIZE);
}

static size_t stack_size(void)
{
    return __stack_top_index;
}

static void stack_print(void)
{
    int32_t i = __stack_top_index - 1;
    printf("top [ ");
    do {
        printf("%lld, ", __stack_space[i--]);
    } while (i >= 0);
    printf("] bottom. \n -- stack len = %zu\n", __stack_top_index);
}

int main(void)
{
    size_t i = 0;
    int64_t val = 0;
    for (i = 0; i < 100; i ++) {
        stack_push((int64_t)i);
    }
    stack_print();
    printf("stack size : %zd\n", stack_size());
    stack_pop(&val);
    printf("popped data %lld\n", val);
    stack_print();
}