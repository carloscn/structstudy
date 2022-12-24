#ifndef _UTILS_H
#define _UTILS_H

#ifdef __cplusplus
extern "C" {
#endif /*__cplusplus*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

typedef enum {
    ORDER_BY_ASCEND = 0,
    ORDER_BY_DESCEND
} ORDER_E;

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
#define UTILS_CHECK_TEST_RESULT(ret1, ret2)                                      \
    do {                                                                         \
        if ((ret1) == (ret2)) {                                                  \
            LOG("Test PASS!\n");                                                 \
        } else {                                                                 \
            LOG("Test FAILED!\n");                                               \
        }                                                                        \
    } while(0)
#define UTILS_CHECK_LEN(ret)                                                     \
    do {                                                                         \
        if ((ret) == (0)) {                                                      \
            goto finish;                                                         \
        }                                                                        \
    } while(0)
/* Functions */
void utils_swap(int64_t *a, int64_t *b);
void utils_swap_int32(int32_t *a, int32_t *b);
void utils_swap_char(char *a, char *b);
int32_t utils_check_odd_even(int64_t base);
int utils_check_pass(int e);
void utils_print_int64_array(int64_t *a, size_t size, const char *msg);
void utils_print_int32_array(int32_t *a, size_t size, const char *msg);
void utils_print_size_t_array(size_t *a, size_t size, const char *msg);
void utils_print_uchar_array(unsigned char *a, size_t size, const char *msg);
int utils_compare_array(unsigned char *a, unsigned char *b, size_t size);
void utils_print_array_by_hex(const unsigned char buf[], size_t len, const char *title);
size_t utils_get_num_len(int32_t __x);
int32_t utils_int32_abs(int32_t base);
int64_t utils_int64_abs(int64_t base);
double utils_float_abs(double base);
int32_t utils_int64_convert_str(int64_t value, char **out_str);
void utils_print_32_value_by_binary(uint32_t val);
void utils_print_64_value_by_binary(uint64_t val);
size_t utils_set_array(int64_t *array, size_t sz);
int32_t utils_sort_char_array(char *array, size_t len, ORDER_E order);
#ifdef __cplusplus
}
#endif /*__cplusplus*/

#endif