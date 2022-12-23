#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include "utils.h"

static char str_rom[100] = {0};

static char dec_2_hex(int32_t e)
{
    if (e < 10) {
        return e + '0';
    } else if (e >= 10 || e < 16) {
        return e + 'a' - 10;
    } else {
        return '0';
    }
}

static char* to_hex(int32_t e)
{
    size_t i = 0, j = 0;
    uint32_t m = e;

    if (m == 0) {
        str_rom[0] = '0';
        str_rom[1] = '\0';
        return str_rom;
    }

    while (m) {
        str_rom[i ++] = dec_2_hex(m & 15);
        m /= 16;
    }

    for (j = 0; j < i / 2; j ++) {
        utils_swap_char(str_rom + j, str_rom + i - j - 1);
    }

    str_rom[i] = '\0';

    return str_rom;
}

int32_t main(void)
{
    int32_t ret = 0;
    char *result = NULL;

    result = to_hex(0);
    printf("the result is %s\n", result);

finish:
    return ret;
}
