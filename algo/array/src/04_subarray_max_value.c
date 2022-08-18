#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int32_t origin_test_array[] = {1, -2, 3, 10, -4, 7, 2, -5};

// O(n^3)
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
    int sub_sum = 0, last_max_sub_sum = 0, last_max_sum = 0;
    for (k = 1; k <= array_sz; k++) {
        last_max_sub_sum = 0;
        for (i = 0; i <= array_sz - k; i++) {
            sub_sum = 0;
            for (j = 0; j < k; j++) {
                s++;
                sub_sum += test_array[i + j];
            }
            if (sub_sum > last_max_sub_sum) {
                last_max_sub_sum = sub_sum;
                //printf("found a %d elements sub array max value : %d\n", k, sub_sum);
            }
        }
        if (last_max_sub_sum > last_max_sum) {
            last_max_sum = last_max_sub_sum;
        }
        //printf("---------> the %d elements sub array max value : %d\n", k, last_max_sub_sum);
    }
    printf("\nthe sub array max value : %d calcu times %d\n", last_max_sum, s);

    free(test_array);
    return 0;
}
// O(n)
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
    int sub_sum = 0, last_max_sub_sum = 0, last_max_sum = 0;
    for (i = 0; i < array_sz; ++i) {
        if (sub_sum > 0) {
            sub_sum += test_array[i];
            s++;
        } else {
            sub_sum = test_array[i];
        }
        if (sub_sum > last_max_sum) {
            last_max_sum = sub_sum;
        }
    }
    printf("\nthe sub array max value : %d, calcu times %d\n", last_max_sum, s);

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