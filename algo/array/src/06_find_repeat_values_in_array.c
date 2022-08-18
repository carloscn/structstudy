#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>



// O(n(n-1))
static int method_1(const int32_t test_array[], size_t array_sz)
{
    // check parameters
    if (0 == array_sz) {
        printf("error: input len is 0\n");
        return 0;
    }
    if (NULL == test_array) {
        printf("error: input parameter NULL\n");
        return -1;
    }

    // find values
    int k = 0, i = 0, j = 0, s = 0;
    for (i = 0; i < array_sz; i ++) {
        for (j = i + 1; j < array_sz - 1; j ++) {
            if (test_array[i] == test_array[j]) {
                printf("\nfound a repeated value: %d\n", test_array[i]);
            }
        }
    }

    return 0;
}

static inline void swap(int *a, int *b)
{
    *a = (*a) ^ (*b);
    *b = (*b) ^ (*a);
    *a = (*a) ^ (*b);
}

static int method_2(const int32_t test_array[], size_t array_sz)
{
    if (0 == array_sz) {
        printf("error: input len is 0\n");
        return 0;
    }
    if (NULL == test_array) {
        printf("error: input parameter NULL\n");
        return -1;
    }

    // dichotomy
    size_t k = 0, i = 0, j = 0, s = 0;
    size_t start = 1, end = array_sz - 1, mid = 0;
    size_t repeat_count = 0;
    while (end >= start) {
        mid = ((end - start) >> 1) + start;   // +start: may be the right sub array.
        repeat_count = 0;
        for (j = 0; j < array_sz; j ++) {
            if (test_array[j] <= mid ) {
                repeat_count ++;
            }
        }

        /* return condition: */
        if (end == start) {
            if (repeat_count > 1) {
                printf("\nfound a repeated value\n");
                return start;
            } else {
                break;
            }
        }

        /* loop condition: */
        if (repeat_count >= mid) {  // on the left sub array
            start = start;
            end = mid;
        } else {                    // on the right sub array
            start = mid + 1;
            end = end;
        }
    }

    return 0;
}

int main(void) {
    int ret;
    clock_t start, end;
    int32_t origin_test_array[] = {-4, 1, 3, 3, 8, 2, 3, 0};
    size_t array_sz = sizeof(origin_test_array)/sizeof(int);

    start = clock();
    ret = method_1(origin_test_array, array_sz);
    end = clock();
    printf("\nmethod 1 time = %f\n", (double)(end - start) / CLOCKS_PER_SEC);

    start = clock();
    ret = method_2(origin_test_array, array_sz);
    end = clock();
    printf("\nmethod 2 time = %f\n", (double)(end - start) / CLOCKS_PER_SEC);

    return ret;
}