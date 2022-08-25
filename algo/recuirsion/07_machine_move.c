#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "stack.h"
#include "utils.h"

static int32_t can_move(int32_t x, int32_t y, int32_t k, int32_t (*visited)[4])
{
    int32_t sum = 0;
    int32_t ret = 0;

    if (x < 0 || y < 0) {
        return 1;
    }

    while(x) {
        sum += x%10;
        x = x/10;
    }
    while(y) {
        sum += y%10;
        y = y/10;
    }
    ret = (sum > k);
    ret |= visited[y][x];

    return ret;
}

static int32_t bt(int32_t x, int32_t y, int32_t k, int32_t (*visited)[4])
{
    int32_t ret = 0;

    // end condition:
    if (can_move(x, y, k, visited) != 0) {
        LOG("can;t move %d, %d\n", x, y);
        return -1;
    }
    LOG("bt %d, %d\n", x, y);
    //*(*(visited + y) + x) = 1;
    visited[y][x] = 1;
    ret = bt(x+1, y, k, visited);
    ret += bt(x-1, y, k, visited);
    ret += bt(x, y+1, k, visited);
    ret += bt(x, y-1, k, visited);

    return ret;
}

static int32_t is_move(int32_t k, int32_t m, int32_t n)
{
    int32_t i = 0, j = 0;

    //gen visited rom
    //int32_t *visited = (int32_t *)malloc(sizeof(int32_t)*m*n);
    int32_t visited[4][4] = {0};
    //memset(visited, 0, sizeof(int32_t) * m * n);
    for (i = 0; i < n; i ++) {
        for (j = 0; j < m; j ++) {
            bt(i, j, k, visited);
        }
    }

    //free(visited);
    return 0;
}

int main(void)
{
    int32_t ret = 0;
    int64_t test_array[] = {2,2,2,4,3,3};
    STACK_T path;

    ret = stack_malloc(&path, STACK_DEFAULT_SIZE);
    if (ret != 0) {
        return -1;
    }
    if (ARRAY_SIZE(test_array) > stack_get_size(&path)) {
        LOG("input array too long.\n");
        return -1;
    }
    //bt(&path, test_array, ARRAY_SIZE(test_array), 0, 8);
    is_move(4, 4, 4);
    stack_free(&path);
    return 0;
}