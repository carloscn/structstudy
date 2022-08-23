#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

static int32_t origin_array[17] = {1,9,55,6,5,1,8,10,12,0,3,8,7,66,11,22,4};

static int32_t sort_array(const int32_t *array, int32_t *out, size_t len)
{
    if (NULL == array || 0 == len || NULL == out) {
        printf("parameters error \n");
        goto error;
    }
    int32_t *test_array = out;
    size_t i = 0, j = 0;

    memcpy(test_array, array, len * sizeof(int32_t));
    printf("\npre : ");
    for (i = 0; i < len; i ++) {
        printf("%d, ", array[i]);
    }
    printf("\npost: ");

    // sort from small to large.
    for (j = 0; j < len - 1; j ++) {
        for (i = 0; i < len - j - 1; i ++) {
            if (test_array[i] > test_array[i + 1]) {
                test_array[i] = test_array[i] ^ test_array[i+1];
                test_array[i+1] = test_array[i+1] ^ test_array[i];
                test_array[i] = test_array[i] ^ test_array[i+1];
            }
        }
    }
    for (i = 0; i < len; i ++) {
        printf("%d, ", test_array[i]);
    }
    printf("\n");
    return 0;

error:
    return -1;
}

static size_t search_by_sequential(const int32_t *array, size_t len, int32_t e)
{
    if (NULL == array || 0 == len) {
        printf("parameters error \n");
        goto error;
    }
    size_t i = 0;
    for (i = 0; i < len; i ++) {
        if (array[i] == e) {
            return i;
        }
    }
error:
    return (size_t)-1;
}

static size_t search_by_binary_iteration(const int32_t *array, size_t len, int32_t e)
{
    if (NULL == array || 0 == len) {
        printf("parameters error \n");
        goto error;
    }

    size_t i = 0, j = 0;
    size_t left = 0, right = len, mid = 0;
    int32_t *test_array = (int32_t *)malloc(sizeof(int32_t) * len);
    if (NULL == test_array) {
        printf("malloc failed\n");
        goto error;
    }
    if (0 != sort_array(array, test_array, len)) {
        printf("sort array failed\n");
        goto error;
    }
    do {
        mid = (right - left) / 2;
        if (test_array[mid] == e) {
            return mid;
        } else if (test_array[mid] < e) {
            right = mid + 1;
        } else {
            left = mid - 1;
        }
    } while (left <= right);

error:
    if (test_array != NULL)
        free(test_array);
    return (size_t)-1;
}

static size_t search_by_insert(const int32_t *array, size_t len, int32_t e)
{
    if (NULL == array || 0 == len) {
        printf("parameters error \n");
        goto error;
    }

    size_t i = 0, j = 0;
    size_t left = 0, right = len, mid = 0;
    int32_t *test_array = (int32_t *)malloc(sizeof(int32_t) * len);
    if (NULL == test_array) {
        printf("malloc failed\n");
        goto error;
    }
    if (0 != sort_array(array, test_array, len)) {
        printf("sort array failed\n");
        goto error;
    }
    do {
        mid = left + (right -1 - left) * (e - test_array[left]) / (test_array[right-1] - test_array[left]);;
        if (test_array[mid] == e) {
            return mid;
        } else if (test_array[mid] < e) {
            right = mid + 1;
        } else {
            left = mid - 1;
        }
    } while (left <= right);

error:
    if (test_array != NULL)
        free(test_array);
    return (size_t)-1;
}

int main(void)
{
    size_t pos = 0;
    clock_t start, end;
    int32_t e = 5;
    int32_t array[17];
    start = clock();
    pos = search_by_sequential(origin_array, sizeof(origin_array)/sizeof(int32_t), e);
    printf("\nfound = %d in array pos = %zd\n", e, pos);
    end = clock();
    printf("method 1 time = %fs\n", (double)(end - start) / CLOCKS_PER_SEC);

    start = clock();
    pos = search_by_binary_iteration(origin_array, sizeof(origin_array)/sizeof(int32_t), e);
    printf("\nfound = %d in array pos = %zd\n", e, pos);
    end = clock();
    printf("method 2 time = %fs\n", (double)(end - start) / CLOCKS_PER_SEC);

    start = clock();
    pos = search_by_insert(origin_array, sizeof(origin_array)/sizeof(int32_t), e);
    printf("\nfound = %d in array pos = %zd\n", e, pos);
    end = clock();
    printf("method 3 time = %fs\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}