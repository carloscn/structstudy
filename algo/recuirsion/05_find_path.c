#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include "stack.h"
#include "utils.h"

static int32_t found_len = 0;
static int32_t path[4][2] = {0};
static STACK_T stack;

static bool bt(int64_t (*array)[4], int32_t x, int32_t y, int32_t len, int32_t depth, int64_t *e, int32_t e_len, int32_t find_len)
{
    int32_t i = 0;
    int32_t ret = 0;
    int64_t tmp = 0;

    // end conditions
    // 1. current element not equal
    // 2. over boundary
    if ( (array[y][x] != *(e + find_len)) ||
         (x < 0) || (x > len) || (y < 0) || (y > depth) ) {
        return false;
    }

    // ability return with success.
    if (find_len == e_len - 1) {
        //LOG("found!!!\n");
        //stack_print_as_char(&stack);
        return true;
    }

    //LOG("stack push [%c] \n", (char)array[y][x]);
    stack_push(&stack, array[y][x]);
    array[y][x] = '#';
    // try next node;
    ret = bt(array, x+1, y, len, depth, e, e_len, find_len + 1);
    ret += bt(array, x-1, y, len, depth, e, e_len, find_len + 1);
    ret += bt(array, x, y+1, len, depth, e, e_len, find_len + 1);
    ret += bt(array, x, y-1, len, depth, e, e_len, find_len + 1);
    stack_pop(&stack, &array[y][x]);
    //LOG("stack pop [%c] \n", (char)array[y][x]);
    return ret;
}

static bool is_find_path(int64_t (*array)[4], int64_t *dest, int32_t dest_len)
{
    int32_t array_len = 4;
    int32_t array_depth = 3;

    int32_t i, j;
    for (i = 0; i < array_len; i ++) {
        for (j = 0; j < array_depth; j ++) {
            if (bt(array, i, j, array_len, array_depth, dest, dest_len, 0) == true) {
                return true;
            }
        }
    }
    return false;
}


int main(void)
{
    int32_t ret = 0;
    int64_t test_array[][4] = {{'a','b','t','g'},{'c','f','c','s'},{'j','d','e','h'}};
    int64_t input_array[] = {'b', 'f', 'c', 'e'};

    ret = stack_malloc(&stack, STACK_DEFAULT_SIZE);
    if (ret != 0) {
        goto err;
    }
    if (is_find_path(test_array, input_array, 4)) {
        LOG("found!\n");
    } else {
        LOG("not found!\n");
    }

err:
    stack_free(&stack);
    return 0;
}