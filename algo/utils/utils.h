#ifndef _UTILS_H
#define _UTILS_H

#include <stdlib.h>
#include <stdint.h>

/* MACRO define */
#define ARRAY_SIZE(_a_) ((size_t)(sizeof(_a_)/sizeof((_a_)[0])))
#define MAX(_a_, _b_) (((_a_)>(_b_))?(_a_):(_b_))
#define MIN(_a_, _b_) (((_a_)<(_b_))?(_a_):(_b_))

#define LOG printf("%s:%s:%d--",__FILE__, __FUNCTION__, __LINE__);printf
#define LOG_LINE() printf("\n------------------------------------------------------------------")
#define LOG_LINE_WITH_TR() printf("\n------------------------------------------------------------------\n");
#define LOG_LINE_WITH_DOUBLE_TR() printf("\n------------------------------------------------------------------\n\n");

/* Functions */
void utils_swap(int64_t *a, int64_t *b);
inline int32_t utils_check_odd_even(int64_t base);

#endif