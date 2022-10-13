#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int32_t origin_test_array[] = {-4, 1, 3, 2, 8, 2, 3, 0};

// O(n(n-1))
static int method_1(void)
{
    int k = 0, i = 0, j = 0, s = 0;
    int32_t *test_array = (int32_t *)malloc(sizeof(origin_test_array));
    if (NULL == test_array) {
        printf("malloc error\n");
        return -1;
    }
    memcpy(test_array, origin_test_array, sizeof(origin_test_array));
    size_t array_sz = sizeof(origin_test_array)/sizeof(int);

    for (i = 0; i < array_sz; i ++) {
        for (j = i + 1; j < array_sz - 1; j ++) {
            if (test_array[i] == test_array[j]) {
                printf("\nfound a repeated value: %d\n", test_array[i]);
                goto finish;
            }
        }
    }
finish:
    free(test_array);
    return 0;
}

static inline void swap(int *a, int *b)
{
    *a = (*a) ^ (*b);
    *b = (*b) ^ (*a);
    *a = (*a) ^ (*b);
}

static int method_2(void)
{
    int k = 0, i = 0, j = 0, s = 0;
    int32_t *test_array = (int32_t *)malloc(sizeof(origin_test_array));
    if (NULL == test_array) {
        printf("malloc error\n");
        return -1;
    }
    memcpy(test_array, origin_test_array, sizeof(origin_test_array));
    size_t array_sz = sizeof(origin_test_array)/sizeof(int);

    while (i < array_sz) {
        if (test_array[i] == i) {
            i++;
            continue;
        } else {
            if (test_array[i] == test_array[test_array[i]]) {
                printf("\nfound a repeated value: %d\n", test_array[i]);
                goto finish;
            } else {
                swap(&test_array[i], &test_array[test_array[i]]);
            }
        }
        i++;
    }
finish:
    free(test_array);
    return 0;
}

int main(void) {
    int ret;
    clock_t start, end;
    start = clock();
    ret = method_1();
    end = clock();
    printf("\nmethod 1 time = %f\n", (double)(end - start) / CLOCKS_PER_SEC);

    start = clock();
    ret = method_2();
    end = clock();
    printf("\nmethod 2 time = %f\n", (double)(end - start) / CLOCKS_PER_SEC);

    return ret;
}