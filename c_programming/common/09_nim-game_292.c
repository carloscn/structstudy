#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

static bool is_win_by_rec(int64_t n, bool *result)
{
    bool ret = 0;
    bool f1 = 0, f2 = 0, f3 = 0, f4 = 0;

    if (result[n] != 0) {
        return result[n] == 1;
    }
    if (n <= 3) {
        result[n] = 1;
        return true;
    }
    f1 = is_win_by_rec(n - 1, result);
    f2 = is_win_by_rec(n - 2, result);
    f3 = is_win_by_rec(n - 3, result);
    ret = !(f1 && f2 && f3);
    result[n] = ret ? true : false;

    return ret;
}

static bool is_win(int64_t n)
{
    return n % 4 != 0;
}


int main(void)
{
    int ret = 0;
    int64_t val = 0;
    bool rom[1000];
    bool res = 0;

    memset(rom, 0, sizeof(bool) * 1000);

    for (val = 0; val < 500; val ++) {
        res = is_win_by_rec(val, rom);
        printf("%lld -> %d\n", val, res);
    }

finish:
    return ret;
}