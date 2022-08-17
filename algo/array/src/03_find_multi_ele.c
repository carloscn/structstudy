#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int32_t origin_test_array[] = {1, 2, 3, 3, 6, 9, 3, 3, 3, 9};

static int method_1(void)
{
    int k = 0, i = 0, j = 0;
    int32_t *test_array = (int32_t *)malloc(sizeof(origin_test_array));
    if (NULL == test_array) {
        printf("malloc error\n");
        return -1;
    }
    memcpy(test_array, origin_test_array, sizeof(origin_test_array));

    int major = test_array[0], count = 0;
    for (i = 1; i < sizeof(origin_test_array)/sizeof(int32_t); i ++) {
        if (test_array[i] == major) {
            count ++;
        } else {
            if (count > 0) {
                count --;
            } else if (count == 0) {
                major = test_array[i];
            }
        }
    }
    if (count > 0) {
        printf("the value is : %d\n", major);
    } else {
        printf("no value. \n");
    }
    return 0;
}

int main(void) {
    int ret;
    clock_t start, end;
    start = clock();
    ret = method_1();
    end = clock();
    printf("\nmethod 1 time = %f\n", (double)(end - start) / CLOCKS_PER_SEC);

    return ret;
}