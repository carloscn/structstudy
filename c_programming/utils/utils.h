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
#define UTILS_ARRAY_SIZE(__a) ARRAY_SIZE(__a)
#define UTILS_MAX(__a, __b) MAX(__a, __b)
#define UTILS_MIN(__a, __b) MIN(__a, __b)
#define UTILS_ASCII_TO_INT(__x) (((__x) - '0'))
#define UTILS_INT_TO_ASCII(__x) (((__x) + '0'))

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
#define UTILS_CHECK_CONDITION(err_condition, ret_code, format, ...)            \
    do {                                                                       \
        if ((err_condition)) {                                                 \
            printf("%s line:%d. Error number is 0x%x \n", __func__, __LINE__,  \
                ret);                                                          \
            printf(format, ##__VA_ARGS__);                                     \
            ret = ret_code;                                                    \
            goto finish;                                                       \
        }                                                                      \
    } while (0)
#define UTILS_SAFE_FREE(_p)                                                     \
    do {                                                                        \
        if ((_p) != NULL) {                                                     \
            free((_p));                                                         \
            (_p) = NULL;                                                        \
        }                                                                       \
    } while(0)
/* Functions */
void utils_swap(int64_t *a, int64_t *b);
void utils_swap_int32(int32_t *a, int32_t *b);
void utils_swap_char(char *a, char *b);
void utils_swap_size_t(size_t *a, size_t *b);
void utils_swap_int64(int64_t *a, int64_t *b);
void utils_swap_null(void *a, void *b);
#define UTILS_SWAP(_v, _b)                          \
        _Generic((_v),                              \
            int64_t*:   utils_swap_int64,           \
            int32_t*:   utils_swap_int32,           \
            char*:      utils_swap_char,            \
            size_t*:    utils_swap_size_t,          \
            default:    utils_swap_null)(_v, _b)

int32_t utils_check_odd_even(int64_t base);
int utils_check_pass(int e);
void utils_print_int64_array(int64_t *a, size_t size, const char *msg);
void utils_print_int32_array(int32_t *a, size_t size, const char *msg);
void utils_print_size_t_array(size_t *a, size_t size, const char *msg);
void utils_print_uchar_array(unsigned char *a, size_t size, const char *msg);
void utils_print_char_array(char *a, size_t size, const char *msg);
#define UTILS_PRINT_ARRAY(_v, _b, _c)                      \
        _Generic((_v),                                     \
            int64_t*:   utils_print_int64_array,           \
            int32_t*:   utils_print_int32_array,           \
            unsigned char*:  utils_print_uchar_array,      \
            size_t*:    utils_print_size_t_array,          \
            default:    utils_print_size_t_array)(_v, _b, _c)

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
size_t utils_set_u8_array(uint8_t *array, size_t sz);
size_t utils_str_set(char *str);
int32_t utils_sort_char_array(char *array, size_t len, ORDER_E order);
int32_t utils_sort_int64_array(int64_t *array, size_t len, ORDER_E order);
int32_t utils_sort_int32_array(int32_t *array, size_t len, ORDER_E order);
bool utils_str_contains(char *input_str, char *sub_str);
size_t utils_value_hamming_distance(size_t a, size_t b);
size_t utils_str_count_char(char *str, char c);
int32_t utils_size_t_to_str(size_t val, char *str);
int32_t utils_int64_to_str(int64_t val, char *str);
bool utils_is_liter(char c);
bool utils_is_number(char c);
char utils_conv_lowercase(char c);
char utils_conv_uppercase(char c);
int32_t utils_str_reverse(char *s);
bool utils_is_lowercase(char c);
bool utils_is_capital(char c);
int32_t utils_str_reserve_region(char* s, size_t start, size_t end);
int32_t utils_str_to_uppercase(char *str);
int32_t utils_str_to_lowercase(char *str);
int32_t utils_str_filter_letter(char *str);
bool utils_str_contains_char(char *input_str, char e);
void utils_print_sub_array_int64(const int64_t *array, size_t len);
void utils_print_two_dim_array_int32_t(int32_t *array, size_t len, size_t depth, size_t len_cap);
void utils_print_two_dim_array_int64_t(int64_t *array, size_t len, size_t depth, size_t len_cap);
int32_t utils_convert_char_to_nibble(uint8_t inchar, uint8_t *num);
int32_t utils_convert_str_to_be(const char *str, uint8_t *buf, size_t len);
void utils_print_bio_array(uint8_t *buffer, size_t len, char* msg);
double utils_sqrt(double x);
#ifdef __cplusplus
}
#endif /*__cplusplus*/

#endif