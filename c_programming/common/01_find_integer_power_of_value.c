#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "stack.h"
#include "utils.h"

double power(int32_t base, int32_t exp)
{
    int32_t i = 0;
    double inf = base;

    if (exp == 0) {
        return 1.0;
    }
    if (exp > 0) {
        for (i = 0; i < exp; i ++) {
            inf *= base;
        }
        return inf;
    } else {
        for (i = 0; i < -exp; i ++) {
            inf *= base;
        }
        return 1.0/inf;
    }
}

int main(void)
{
    double base = 5;
    double data = 0;
    data = power(base, 10);
    LOG("data is %f\n", data);
    data = power(base, 0);
    LOG("data is %f\n", data);
    data = power(base, -2);
    LOG("data is %f\n", data);
    return 0;
}