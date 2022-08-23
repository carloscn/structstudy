#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

static int32_t origin_array[] = {3,3,3,4,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,3,};

static int32_t get_min_1(const int32_t *array, size_t len)
{
    if (NULL == array || len == 0) {
        printf("input parameters error \n");
        return -1;
    }
    size_t i = 0;
    int32_t current_min = origin_array[0];
    for (i = 0; i < len; i ++) {
        if (current_min > origin_array[i]) {
            current_min = origin_array[i];
        }
    }
    return current_min;
}

static int32_t get_min_2(const int32_t *array, size_t len)
{
    size_t i = 0;
    for (i = 1; i < len; i ++) {
        if (array[i] < array[i-1]) {
            return array[i];
        }
    }
    return array[0];
}

int main(void)
{
    size_t pos = 0;
    clock_t start, end;
    int32_t e = 5;
    start = clock();
    e = get_min_1(origin_array, sizeof(origin_array)/sizeof(int32_t));
    printf("\nfound = %d in array\n", e);
    end = clock();
    printf("method 1 time = %fs\n", (double)(end - start) / CLOCKS_PER_SEC);

    start = clock();
    e = get_min_2(origin_array, sizeof(origin_array)/sizeof(int32_t));
    printf("\nfound = %d in array\n", e);
    end = clock();
    printf("method 2 time = %fs\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}