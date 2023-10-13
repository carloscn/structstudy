#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>
#include "utils.h"

static int32_t check_x_matrix(int32_t *grid, size_t grid_len, size_t grid_size, bool *res)
{
    int32_t ret = 0;

    UTILS_CHECK_PTR(grid);
    UTILS_CHECK_PTR(res);
    UTILS_CHECK_LEN(grid_len);
    UTILS_CHECK_LEN(grid_size);

    *res = false;
    for (size_t i = 0; i < grid_size; i ++) {
        int32_t *grid_line = grid + i * grid_len;
        for (size_t j = 0; j < grid_len; j ++) {
            if ((i == j) || (i + j == grid_size - 1)) {
                if (grid_line[j] == 0) {
                    goto finish;
                }
            } else if (grid_line[j] > 0) {
                goto finish;
            }
        }
    }

    *res = true;

finish:
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;
    bool result = false;
    int32_t in1[] = {
                        2,0,0,1,
                        0,3,1,0,
                        0,5,2,0,
                        4,0,0,2
    };

    ret = check_x_matrix(in1, 4, 4, &result);
    assert(ret == 0), assert(result == true);

    int32_t in2[] = {
                        5,7,0,
                        0,3,1,
                        0,5,0,
    };

    ret = check_x_matrix(in2, 3, 3, &result);
    assert(ret == 0), assert(result == false);

    LOG("All tests have passed!\n");

finish:
    return ret;
}