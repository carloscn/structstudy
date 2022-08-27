#ifndef UTILS_H
#define UTILS_H

#include <stdlib.h>
#include <stdint.h>

#define LOG printf("%s:%s:%d--",__FILE__, __FUNCTION__, __LINE__);printf
#define ARRAY_SIZE(_a_) ((size_t)(sizeof(_a_)/sizeof((_a_)[0])))

inline void utils_swap(int64_t *a, int64_t *b);
inline int32_t utils_check_odd_even(int64_t base);

#endif