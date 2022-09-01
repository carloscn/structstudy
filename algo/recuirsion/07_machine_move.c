#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include "stack.h"
#include "utils.h"

static bool can_move(int32_t x, int32_t y, int32_t k)
{
    int32_t sum = 0;

    if (x < 0 || y < 0) {
        return false;
    }
    while(x) {
        sum += x%10;
        x = x/10;
    }
    while(y) {
        sum += y%10;
        y = y/10;
    }
    if(sum >= k) {
        return false;
    }

    return true;
}

static int32_t bt(int32_t x, int32_t y, int32_t k, bool *visited, int32_t n, int32_t m)
{
    int32_t count = 0;

    // end condition:
    if (can_move(x, y, k) == false) {
        //LOG("can't move %d, %d, sum_value k = %d\n", x, y, k);
        return 0;
    }
    // exclued visited
    if (*(visited + y * m + x) == true) {
        //LOG("can't move %d, %d, visited node\n", x, y);
        return 0;
    }
    //LOG("bt %d, %d\n", x, y);
    *(visited + y * m + x) = 1;
    count = bt(x+1, y, k, visited, n, m) + 1;
    count += bt(x-1, y, k, visited, n, m);
    count += bt(x, y+1, k, visited, n, m);
    count += bt(x, y-1, k, visited, n, m);

    return count;
}

static bool is_move(int32_t k, int32_t n, int32_t m)
{
    int32_t i = 0, j = 0;
    int32_t count = 0;
    //gen visited rom
    bool *visited = (bool *)malloc(sizeof(bool)*m*n);
    memset(visited, false, sizeof(bool)*m*n);
    for (i = 0; i < n; i ++) {
        for (j = 0; j < m; j ++) {
            count = bt(i, j, k, visited, n, m);
            if (count != 0) {
                LOG("starting with (%d, %d) , move %d types position!\n", i, j, count);
            }
            memset(visited, false, sizeof(bool)*m*n);
        }
    }

    free(visited);
    return 0;
}

int main(void)
{
    int32_t ret = 0;
    int64_t test_array[] = {2,2,2,4,3,3};
    STACK_T path;

    ret = stack_init(&path, STACK_DEFAULT_SIZE);
    if (ret != 0) {
        return -1;
    }
    if (ARRAY_SIZE(test_array) > stack_get_size(&path)) {
        LOG("input array too long.\n");
        return -1;
    }
    //bt(&path, test_array, ARRAY_SIZE(test_array), 0, 8);
    is_move(3, 4, 4);
    stack_deinit(&path);

    return 0;
}
