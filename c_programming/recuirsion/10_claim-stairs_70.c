#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "utils.h"
#include "stack.h"

#define METHOD_1 1 /* backtracing */
#define METHOD_2 0 /* dynamic */


/*
if inputted n is 5.

0 (k)
|__________________________________
|1                                |2
1                                 2
|________________                 |____________
|1               |2               |1           |2
2                3                3            4
|________        |_______         |______      |
|1       |2      |1      |2       |1     |2    |1
3        4       4       5        4      5     5
|_____   |       |                |
|1   |2  |1      |1               5
4    5   5       5
|
5
*/

/**
 * @brief dfs
 *
 * @param stack: using the stack;
 * @param target: target number;
 * @param count: recording possibilities;
 */
#if METHOD_1
static void dfs(STACK_T *stack, int32_t target, int32_t *count)
{
    int32_t sum = (int32_t)stack_sum(stack);

    if (target < sum) {
        return;
    }

    if (target == sum) {
        *count = *count + 1;
        stack_print(stack);
        return;
    }

    stack_push(stack, 1);       // try number 1.
    dfs(stack, target, count);  // recuirsing.
    stack_pop(stack, NULL);     // backing trace.

    stack_push(stack, 2);       // try number 2.
    dfs(stack, target, count);  // recuirsing.
    stack_pop(stack, NULL);     // backing trace.
}

static int32_t climb_stairs(int32_t n, int32_t *count)
{
    int32_t ret = 0;
    STACK_T *stack = NULL;

    UTILS_CHECK_PTR(count);

    if (n <= 0) {
        LOG("no possible situations.\n");
        *count = n;
        goto finish;
    }

    stack = stack_malloc(STACK_DEFAULT_SIZE);
    UTILS_CHECK_PTR(stack);

    LOG("The following stack content printing represents possible situations: \n");
    dfs(stack, n, count);
    LOG("total : when inputted %d, the %d types output.\n", n, *count);

finish:
    stack_free(stack);
    return ret;
}
#endif

/*
 * f(x) = f(x-1) + f(x-2), {x > 2}
 *        1              , {x = 1, x = 0}
 */
#if METHOD_2
static int32_t climb_stairs(int32_t n, int32_t *count)
{
    int32_t ret = 0;
    int32_t *f = NULL;
    int32_t i = 0;

    UTILS_CHECK_PTR(count);

    if (n <= 0) {
        LOG("no possible situations.\n");
        *count = n;
        goto finish;
    }

    if (1 == n) {
        *count = n;
        goto finish;
    }

    f = (int32_t*)calloc(sizeof(int32_t), n + 1);
    UTILS_CHECK_PTR(f);

    f[0] = f[1] = 1;
    for (i = 2; i <= n; i ++) {
        f[i] = f[i - 1] + f[i - 2];
    }
    *count = f[n];

finish:
    LOG("total : when inputted %d, the %d types output.\n", n, *count);
    if (f != NULL)
        free(f);
    return ret;
}
#endif

int main(void)
{
    int32_t ret = 0;
    int32_t count = 0;

    ret = climb_stairs(5, &count);
    UTILS_CHECK_RET(ret);

finish:

    return ret;
}