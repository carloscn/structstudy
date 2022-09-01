#include "utils.h"

void utils_swap(int64_t *a, int64_t *b)
{
    *a = (*a) ^ (*b);
    *b = (*b) ^ (*a);
    *a = (*a) ^ (*b);
}

/*
 * return 1: odd number
 * return 0: even number
 */
inline int32_t utils_check_odd_even(int64_t base)
{
    if (base & 0x01) {
        return 1;
    } else {
        return 0;
    }
}
