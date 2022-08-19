#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// O(n(n-1))
static int method_1(const int32_t *test_array,
                    size_t len,
                    size_t width,
                    int32_t e)
{
    // check parameters
    if (0 == len && 0 == width) {
        printf("error: input len is 0\n");
        return 0;
    }
    if (NULL == test_array) {
        printf("error: input parameter NULL\n");
        return -1;
    }
    // find values
    size_t k = 0, i = 0, j = 0, s = 0;
    size_t array_sz = len * width;

    for (i = 0; i < array_sz; i ++) {
        if (e == test_array[i]) {
            printf("vvvvvvvv found e = %d in array\n", e);
            goto finish;
        }
    }
    printf("xxxxxxxx the e = %d not in array\n", e);

finish:
    return 0;
}

static int method_2(const int32_t (*test_array)[4],
                    size_t len,
                    size_t depth,
                    int32_t e)
{
    // check parameters
    if (0 == len && 0 == depth) {
        printf("error: input len is 0\n");
        return 0;
    }
    if (NULL == test_array) {
        printf("error: input parameter NULL\n");
        return -1;
    }

    size_t k = 0, i = 0, j = 0, s = 0;
    int x = 0, y = len - 1;
    int32_t value = 0;

    do {
        value = test_array[x][y];
#ifdef DEBUG
        printf("check value %d \n", value);
#endif
        if (value == e) {
            printf("vvvvvvvv found e = %d in array\n", e);
            goto finish;
        } else if (e > value) {
            x ++;
#ifdef DEBUG
            printf("the value %d is < e=%d, move down, x = %d\n", value, e, x);
#endif
        } else {
            y --;
#ifdef DEBUG
            printf("the value %d is > e=%d, move left, y = %d\n", value, e, y);
#endif
        }
    } while ((x <= depth) && (y >= 0));
    printf("xxxxxxxx the e = %d not in array\n", e);
finish:
    return 0;
}

int main(void) {
    int ret;
    clock_t start, end;
    int32_t origin_test_array[4][4] = {
            {1,  2,  3,  4},
            {3,  6,  8,  9},
            {8,  10, 11, 15},
            {9,  12, 13, 19},
            };
    size_t array_sz = sizeof(origin_test_array)/sizeof(int);
    size_t array_len = sizeof(origin_test_array[0])/sizeof(origin_test_array[0][0]);
    size_t array_width = sizeof(origin_test_array)/sizeof(origin_test_array[0]);
    int32_t e = 0;

    start = clock();
    for (e = 0; e < 20; e ++) {
        ret = method_1(&origin_test_array[0][0], array_len, array_width, e);
    }
    end = clock();
    printf("\nmethod 1 time = %f\n\n\n", (double)(end - start) / CLOCKS_PER_SEC);

    start = clock();
    for (e = 0; e < 20; e ++) {
        ret = method_2(origin_test_array, array_len, array_width, e);
    }
    end = clock();
    printf("\n\nmethod 2 time = %f\n\n\n", (double)(end - start) / CLOCKS_PER_SEC);
    return ret;
}