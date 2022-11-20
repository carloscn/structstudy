#include "utils.h"

#ifdef __cplusplus
extern "C" {
#endif /*__cplusplus*/

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

inline int64_t utils_int64_abs(int64_t base)
{
    base = base * (((base >> 63) << 1) + 1);
    return base;
}

inline int32_t utils_int32_abs(int32_t base)
{
    base = base * (((base >> 31) << 1) + 1);
    return base;
}

inline double utils_float_abs(double base)
{
    if (base >= 0)
        return base;
    return -base;
}

void utils_print_array_by_hex(const unsigned char buf[], size_t len, const char *title)
{
    printf("%s", title);
    for (size_t i = 0; i < len; i++) {
        if (i % 16 == 0)
            printf("\n");
        printf("0x%02X,", buf[i]);
    }
    printf("\r\n");
}

void utils_print_64_value_by_binary(uint64_t val)
{
    size_t i = 0;

    printf("utils_print_64_value_by_binary: (%llu) -> (0x%llX) -> ", val, val);
    for (i = 0; i < 64; i ++) {
        if (((val >> (63 - i)) & 0x1) == 1) {
            printf("1");
        } else {
            printf("0");
        }
    }
    printf("\n");
}

void utils_print_32_value_by_binary(uint32_t val)
{
    size_t i = 0;

    printf("utils_print_64_value_by_binary: (%u) -> (0x%X) -> ", val, val);
    for (i = 0; i < 32; i ++) {
        if (((val >> (31 - i)) & 0x1) == 1) {
            printf("1");
        } else {
            printf("0");
        }
    }
    printf("(B)\n");
}

int utils_compare_array(unsigned char *a, unsigned char *b, size_t size)
{
    size_t i = 0;
    for (i = 0; i < size; i ++) {
        if (a[i] != b[i]) {
            return -1;
        }
    }
    return 0;
}

void utils_print_uchar_array(unsigned char *a, size_t size, const char *msg)
{
    size_t i = 0;
    printf("%s", msg);
    for (i = 0; i < size; i ++) {
        printf("0x%2x,", a[i]);
    }
    printf("\n");
}

void utils_print_int64_array(int64_t *a, size_t size, const char *msg)
{
    size_t i = 0;
    printf("%s", msg);
    for (i = 0; i < size; i ++) {
        printf("%lld, ", a[i]);
    }
    printf("\n");
}

int utils_check_pass(int e)
{
    if (!e) {
        LOG("Result Passed!\n");
    }else{
        LOG("Result Failed!\n");
    }
    return e;
}

inline size_t utils_get_num_len(int32_t __x)
{
    size_t __c = 0;

    while(__x) {
        __x = __x / 10;
         __c ++;
    }
    return __c;
}

int32_t utils_int64_convert_str(int64_t value, char **out_str)
{
    int32_t ret = 0;
    char *str = NULL;

    str = (char*)malloc(17);

    if (NULL == str) {
        *out_str = NULL;
        return -1;
    }
    memset(str, '\0', 17);
    ret = sprintf(str, "%llx", value);
    if (ret < 0) {
        return ret;
    }
    *out_str = str;
    ret = 0;

    return ret;
}

size_t utils_set_array(int64_t *array, size_t sz)
{
    size_t i = 0, j = 0, k = 0;
    size_t count = 0;
    int64_t e = 0;
    size_t ori_len = sz;

    if (NULL == array || 0 == ori_len) {
        return 0;
    }

    for (i = 0; i < ori_len; i ++) {
        e = array[i];
        for (j = i + 1; j < ori_len; j ++) {
            if (e == array[j]) {
                count ++;
                ori_len --;
                for (k = j, j--; k < ori_len; k ++) {
                    array[k] = array[k + 1];
                }
            }
        }
    }

    return sz - count;
}

#ifdef __cplusplus
}
#endif /*__cplusplus*/