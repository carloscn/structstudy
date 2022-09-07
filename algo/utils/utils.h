#ifndef _UTILS_H
#define _UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/* MACRO define */
#define ARRAY_SIZE(_a_) ((size_t)(sizeof(_a_)/sizeof((_a_)[0])))
#define MAX(_a_, _b_) (((_a_)>(_b_))?(_a_):(_b_))
#define MIN(_a_, _b_) (((_a_)<(_b_))?(_a_):(_b_))

#define LOG printf("%s:%d on func:(%s) -- ",__FILE__,__LINE__,__FUNCTION__);printf
#define LOG_LINE() printf("\n------------------------------------------------------------------")
#define LOG_LINE_WITH_TR() printf("\n------------------------------------------------------------------\n");
#define LOG_LINE_WITH_DOUBLE_TR() printf("\n------------------------------------------------------------------\n\n");
#define LOG_ERR LOG
#define UTILS_CHECK_RET(err)                                                     \
    do {                                                                         \
        if (ret != 0) {                                                          \
            LOG_ERR("Operation failed: err= 0x%x\n", err);                       \
            ret  = -1;                                                           \
            goto finish;                                                         \
        }                                                                        \
    } while(0)
#define UTILS_CHECK_BOOL(err)                                                    \
    do {                                                                         \
        if (ret_b != true) {                                                     \
            LOG_ERR("Operation failed: err= 0x%x\n", err);                       \
            ret_b  = false;                                                      \
            goto finish;                                                         \
        }                                                                        \
    } while(0)
#define UTILS_CHECK_PTR(p)                                                       \
    do {                                                                         \
        if (NULL == (p)) {                                                       \
            LOG_ERR("pointer is NULL\n");                                        \
            ret  = -1;                                                           \
            goto finish;                                                         \
        }                                                                        \
    } while(0)

/* Functions */
void utils_swap(int64_t *a, int64_t *b);
inline int32_t utils_check_odd_even(int64_t base);
int utils_check_pass(int e);
void utils_print_int64_array(int64_t *a, size_t size, const char *msg);
void utils_print_uchar_array(unsigned char *a, size_t size, const char *msg);
int utils_compare_array(unsigned char *a, unsigned char *b, size_t size);
void utils_print_array_by_hex(const unsigned char buf[], size_t len, const char *title);

#endif