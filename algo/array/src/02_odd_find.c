#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int32_t origin_test_array[12] = {
    1,  4,  6,  28,
	2,  7,  32, 30,
	10, 11, 67, 79
};

static inline void swap_value(int *a, int *b)
{
    *a = (*a) ^ (*b);
    *b = (*b) ^ (*a);
    *a = (*a) ^ (*b);
}

static int reorder_method_1(void)
{
    int k = 0, i = 0, j = 0;
    int test_array[12];

    memcpy(test_array, origin_test_array, sizeof(origin_test_array));
    int *o_array = (int *)malloc(sizeof(test_array) + 1);
    int *e_array = (int *)malloc(sizeof(test_array) + 1);
    if (NULL == o_array || NULL == e_array) {
        printf("malloc failed\n");
        return -1;
    }
    for (i = 0; i < sizeof(test_array)/sizeof(int32_t); i ++) {
        if ((test_array[i] & 1) == 1) {
            o_array[k++] = test_array[i];
        } else {
            e_array[j++] = test_array[i];
        }
    }
    memcpy(test_array, o_array, k * sizeof(int32_t));
    memcpy(test_array + k, e_array, j * sizeof(int32_t));

    printf("\noutput:\n");
    for (i = 0; i < sizeof(test_array)/sizeof(int); i ++) {
        printf("%d, ", test_array[i]);
    }
    free(e_array);
    free(o_array);

    return 0;
}

static int reorder_method_2(void)
{
    uint32_t i = 0, j = 0;
    int test_array[12] = {0};
    uint32_t array_len = sizeof(test_array)/sizeof(int);
    uint32_t ordered = 0;

    memcpy(test_array, origin_test_array, sizeof(origin_test_array));
    // Bubble sort
    for (i = 0; i < array_len; i ++) {
        if (!(test_array[i] & 0x01)) {
            continue;
        }
        for (j = 0; j < i - ordered; j ++) {
            swap_value(&test_array[i-j], &test_array[i-j-1]);
        }
        ordered ++;
        i = ordered;
    }

    printf("\noutput:\n");
    for (i = 0; i < sizeof(test_array)/sizeof(int); i ++) {
        printf("%d, ", test_array[i]);
    }
    return 0;
}

int main(void) {
    int ret;
    clock_t start, end;
    start = clock();
    ret = reorder_method_1();
    end = clock();
    printf("\nmethod 1 time = %f\n", (double)(end - start) / CLOCKS_PER_SEC);

    start = clock();
    ret = reorder_method_2();
    end = clock();
    printf("\nmethod 2 time = %f\n", (double)(end - start) / CLOCKS_PER_SEC);

    return ret;
}