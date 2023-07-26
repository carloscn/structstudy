#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include "utils.h"
#include "buffer.h"

#define N2A_MAP(_num) ((char)((_num) + 'A' - 1))
#define A2N_MAP(_char) ((int32_t)((_char) - 'A' + 1))

int32_t num_decode(char *s)
{
    int32_t ret = 0;
    size_t len = 0;

    UTILS_CHECK_PTR(s);
    UTILS_CHECK_LEN(len = strlen(s));

    BUFFER_T *buffer = NULL;

    buffer = buffer_malloc(BUFFER_DEFUALT_SIZE);
    UTILS_CHECK_PTR(buffer);


finish:
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;

    LOG("the number is %c, %d\n", 'A', A2N_MAP('A'));
    LOG("the number is %c, %d\n", 'B', A2N_MAP('B'));
    LOG("the number is %c, %d\n", 'K', A2N_MAP('K'));
    LOG("the number is %c, %d\n", 'Z', A2N_MAP('Z'));
    LOG("the alpha is %d, %c\n", 1, N2A_MAP(1));
    LOG("the alpha is %d, %c\n", 13, N2A_MAP(2));
    LOG("the alpha is %d, %c\n", 20, N2A_MAP(20));
    LOG("the alpha is %d, %c\n", 26, N2A_MAP(26));

finish:
    return ret;
}