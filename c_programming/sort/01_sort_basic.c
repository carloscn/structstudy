#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

static int32_t origin_array[17] = {1,9,55,6,5,88,8,10,66,0,3,8,7,12,11,22,4};

static inline void swap(int32_t *a, int32_t *b)
{
    if (*a == *b)
        return;
    *a = (*a) ^ (*b);
    *b = (*b) ^ (*a);
    *a = (*a) ^ (*b);
}

static int32_t sort_array_by_bubble(const int32_t *array, int32_t *out, size_t len)
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
                swap(&test_array[i], &test_array[i+1]);
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
static int32_t sort_array_by_selection(const int32_t *array, int32_t *out, size_t len)
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

    // selection
    for (i = 0; i < len; i ++) {
        for (j = i; j < len; j++) {
            if (test_array[i] > test_array[j]) {
                swap(&test_array[i], &test_array[j]);
            }
        }
    }

    printf("\npost: ");
    for (i = 0; i < len; i ++) {
        printf("%d, ", test_array[i]);
    }
    printf("\n");
    return 0;
error:
    return -1;
}

static int32_t sort_array_by_insertion(const int32_t *array, int32_t *out, size_t len)
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

    for (i = 1; i < len; i++) {
        j = i;
        while ((test_array[j-1] > test_array[j]) && (j > 0)) {
            swap(&test_array[j-1], &test_array[j]);
            j--;
        }
    }
    printf("\npost: ");
    for (i = 0; i < len; i ++) {
        printf("%d, ", test_array[i]);
    }
    printf("\n");
    return 0;
error:
    return -1;
}

static int32_t sort_array_by_merge(const int32_t *src, int32_t *dest, size_t start, size_t end)
{
    if (NULL == src || NULL == dest || end > start) {
        printf("parameters error \n");
        goto error;
    }
    if (start + 1 > end) {
        return 0;
    }

    size_t i = 0, j = 0, k = 0, len = end - start, mid = (len >> 1) + start;
    sort_array_by_merge(src, dest, start, mid);
    sort_array_by_merge(src, dest, mid, end);

    i = start;
    j = mid;
    k = 0;


    return 0;
error:
    return -1;
}

static int32_t sort_quick_partion(int32_t *array, int32_t start, int32_t end)
{
    int32_t x_pivot = 0, y_pivot = 0;

    x_pivot = (rand()%(end - start + 1)) + start;
    y_pivot = array[x_pivot];
#ifdef DEBUG
    printf("set x_pivot = %d, y_pivot = %d, start = %d, end = %d\n", x_pivot, y_pivot, start, end);
    size_t j = 0;
#endif
    int32_t small = start - 1;
    int32_t *p2 = array;
    size_t i = 0;
#ifdef DEBUG
    printf("init: ");
    for (j = start; j < end + 1; j ++) {
        printf("%d, ", array[j]);
    }
#endif
    swap(array + x_pivot, array + end);

    for (i = start; i < end; ++i) {
        if (p2[i] < p2[end]) {
            small ++;
            swap(p2 + i, p2 + small);
        }
    }
    small ++;
    swap(p2 + small, p2 + end);
#ifdef DEBUG
    printf("x_pivot renew to (%d, %d)\noutd: ", small, array[small]);
    for (j = start; j < end + 1; j ++) {
        printf("%d, ", array[j]);
    }
    printf("\n\n");
#endif
    return small;
}

static int32_t sort_quick(int32_t *array, int32_t start, int32_t end)
{
    int pivot_pos = 0;
    if (end > start) {
        pivot_pos = sort_quick_partion(array, start, end);
        sort_quick(array, start, pivot_pos - 1);
        sort_quick(array, pivot_pos + 1, end);
    }
    return 0;
}

static int32_t sort_array_by_quick(const int32_t *array, int32_t *out, size_t len)
{
    if (NULL == array || 0 == len || NULL == out) {
        printf("parameters error \n");
        goto error;
    }
    size_t i = 0;
    printf("\npre : ");
    for (i = 0; i < len; i ++) {
        printf("%d, ", array[i]);
    }
    printf("\npost: ");
    memcpy(out, array, sizeof(int32_t) * len);
    sort_quick(out, 0, (int32_t)len - 1);

    for (i = 0; i < len; i ++) {
        printf("%d, ", out[i]);
    }
    printf("\n");

    return 0;
error:
    return -1;
}

int main(void)
{
    size_t pos = 0;
    clock_t start, end;
    int32_t e = 5;
    int32_t array[17];

    /* Bubble sorting: https://www.runoob.com/w3cnote/bubble-sort.html*/
    start = clock();
    e = sort_array_by_bubble(origin_array, array, sizeof(origin_array)/sizeof(int32_t));
    end = clock();
    printf("method 1 time = %fs\n", (double)(end - start) / CLOCKS_PER_SEC);

    /* selection sorting: https://www.runoob.com/w3cnote/selection-sort.html */
    memset(array, 0, sizeof(array));
    start = clock();
    e = sort_array_by_selection(origin_array, array, sizeof(origin_array)/sizeof(int32_t));
    end = clock();
    printf("method 2 time = %fs\n", (double)(end - start) / CLOCKS_PER_SEC);

    /* insertion sorting: https://www.runoob.com/w3cnote/insertion-sort.html */
    memset(array, 0, sizeof(array));
    start = clock();
    e = sort_array_by_insertion(origin_array, array, sizeof(origin_array)/sizeof(int32_t));
    end = clock();
    printf("method 3 time = %fs\n", (double)(end - start) / CLOCKS_PER_SEC);

    /* merge sorting: https://www.runoob.com/w3cnote/merge-sort.html */
    memset(array, 0, sizeof(array));
    start = clock();
    //e = sort_array_by_merge(origin_array, array, sizeof(origin_array)/sizeof(int32_t));
    end = clock();
    printf("method 4 time = %fs\n", (double)(end - start) / CLOCKS_PER_SEC);

    /* merge sorting: https://www.runoob.com/w3cnote/merge-sort.html */
    memset(array, 0, sizeof(array));
    start = clock();
    e = sort_array_by_quick(origin_array, array, sizeof(origin_array)/sizeof(int32_t));
    end = clock();
    printf("method 5 time = %fs\n", (double)(end - start) / CLOCKS_PER_SEC);
    return 0;
}