#include "utils.h"

inline void utils_swap(int64_t *a, int64_t *b)
{
    *a = (*a) ^ (*b);
    *b = (*b) ^ (*a);
    *a = (*a) ^ (*b);
}