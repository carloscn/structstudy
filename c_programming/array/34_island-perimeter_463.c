#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "utils.h"

static int64_t metrix[4][4] = {
    {1,1,0,0},
    {1,1,1,0},
    {0,1,0,0},
    {1,1,0,0}
};

static size_t get_count(int64_t metrix[4][4], size_t x_index, size_t y_index, size_t width, size_t length)
{
    size_t count = 0;

    LOG("for j,i = (%zu, %zu):\n", x_index, y_index);

    // checking up
    if ((y_index == 0) ||
        (metrix[y_index - 1][x_index] == 0)) {
        LOG("up ++\n");
        count ++;
    }

    // checking down
    if ((y_index == length - 1) ||
        (metrix[y_index + 1][x_index] == 0)) {
        LOG("down ++\n");
        count ++;
    }

    // checking left
    if ((x_index == 0) ||
        (metrix[y_index][x_index - 1] == 0)) {
        LOG("left ++\n");
        count ++;
    }

    // checking right
    if ((x_index == width - 1) ||
        (metrix[y_index][x_index + 1] == 0)) {
        LOG("right ++\n");
        count ++;
    }

    LOG("\n");
    return count;
}

static int32_t island_perimeter(int64_t metrix[4][4], size_t width, size_t length, size_t *out)
{
    int32_t ret = 0;
    size_t i = 0, j = 0;
    size_t t_count = 0, s_count = 0;

    UTILS_CHECK_PTR(metrix);
    UTILS_CHECK_LEN(width);
    UTILS_CHECK_LEN(length);

    for (i = 0; i < width; i ++) {
        for (j = 0; j < length; j ++) {
            if (metrix[j][i]) {
                t_count = get_count(metrix, i, j, width, length);
                s_count += t_count;
            }
        }
    }

    *out = s_count;

finish:
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;
    size_t result = 0;

    ret = island_perimeter(metrix, 4, 4, &result);
    UTILS_CHECK_RET(ret);
    LOG("the result is %zu\n", result);

finish:
    return ret;
}