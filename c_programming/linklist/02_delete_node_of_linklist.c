#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "utils.h"
#include "linklist.h"

int main(void)
{
    int32_t ret = 0;
    clock_t start, end;
    linklist_selftest();
    end = clock();
    LOG_LINE_WITH_TR();
    LOG("method 1 time = %fs", (double)(end - start) / CLOCKS_PER_SEC);
    LOG_LINE_WITH_DOUBLE_TR();

    return 0;
}