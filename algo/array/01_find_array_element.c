#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

int num[3][4] = {
    1,  4,  6,  28,
	2,  7,  32, 30,
	10, 11, 67, 79
};

int main(void)
{
    char c[3] = { 0 };
    int number = 0;
    clock_t start, end;

    // 1. get number from user
    printf("input your wanting to find :");
    scanf("%s", c);
    number = atoi(c);
    printf("\nrecv: %d\n", number);

    int i = 0, j = 0;
    // 2. method 1: i, j
    start = clock();
    for (i = 0; i < 4; i ++) {
        for (j = 0; j < 3; j ++) {
            if (number == num[j][i]) {
                printf("the %d is inclued in the array, index: (%d, %d)\n", number, j + 1, i + 1);
                break;
            }
        }
    }
    end = clock();
    printf("method 1 time = %f\n", (double)(end - start) / CLOCKS_PER_SEC);

    // 3. methed 2: transform the i,j to i.
    int *p = (int *)num;
    start = clock();
    for (i = 0; i < 12; i ++) {
        if (number == *(p + i)) {
            printf("the %d is inclued in the array, index: (%d, %d)\n", number, i/4 + 1, i%4 + 1);
            break;
        }
    }
    end = clock();
    printf("method 2 time = %f\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}