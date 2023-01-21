#include "utils.h"

#ifdef __cplusplus
extern "C" {
#endif /*__cplusplus*/

void utils_swap(int64_t *a, int64_t *b)
{
    if (a == b)
        return;
    *a = (*a) ^ (*b);
    *b = (*b) ^ (*a);
    *a = (*a) ^ (*b);
}

void utils_swap_char(char *a, char *b)
{
    if (a == b)
        return;
    *a = (*a) ^ (*b);
    *b = (*b) ^ (*a);
    *a = (*a) ^ (*b);
}

void utils_swap_int32(int32_t *a, int32_t *b)
{
    if (a == b)
        return;
    *a = (*a) ^ (*b);
    *b = (*b) ^ (*a);
    *a = (*a) ^ (*b);
}

void utils_swap_int64(int64_t *a, int64_t *b)
{
    if (a == b)
        return;
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

void utils_print_size_t_array(size_t *a, size_t size, const char *msg)
{
    size_t i = 0;
    printf("%s", msg);
    for (i = 0; i < size; i ++) {
        printf("%zu, ", a[i]);
    }
    printf("\n");
}

void utils_print_int32_array(int32_t *a, size_t size, const char *msg)
{
    size_t i = 0;
    printf("%s", msg);
    for (i = 0; i < size; i ++) {
        printf("%d, ", a[i]);
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

size_t utils_set_u8_array(uint8_t *array, size_t sz)
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

int32_t utils_sort_char_array(char *array, size_t len, ORDER_E order)
{
    int32_t ret = 0;
    char *test_array = NULL;
    size_t i = 0, j = 0;

    if (NULL == array || 0 == len) {
        ret = -1;
        LOG("parameters error \n");
        goto error;
    }

    test_array = (char *)calloc(1, len);
    if (NULL == test_array) {
        ret = -1;
        LOG("malloc test_array failed\n");
        goto error;
    }

    memcpy(test_array, array, len);

    LOG("\npre : ");
    for (i = 0; i < len; i ++) {
        printf("%c, ", array[i]);
    }


    // sort from small to large.
    if (ORDER_BY_ASCEND == order) {
        for (j = 0; j < len - 1; j ++) {
            for (i = 0; i < len - j - 1; i ++) {
                if (test_array[i] > test_array[i + 1]) {
                    utils_swap_char(&test_array[i], &test_array[i+1]);
                }
            }
        }
    } else {
        for (j = 0; j < len - 1; j ++) {
            for (i = 0; i < len - j - 1; i ++) {
                if (test_array[i] < test_array[i + 1]) {
                    utils_swap_char(&test_array[i], &test_array[i+1]);
                }
            }
        }
    }

    LOG("\npost: ");
    for (i = 0; i < len; i ++) {
        printf("%c, ", test_array[i]);
    }
    printf("\n");
    memcpy(array, test_array, len);

error:
    if (test_array != NULL)
        free(test_array);
    return ret;
}

int32_t utils_sort_int64_array(int64_t *array, size_t len, ORDER_E order)
{
    int32_t ret = 0;
    int64_t *test_array = NULL;
    size_t i = 0, j = 0;

    if (NULL == array || 0 == len) {
        ret = -1;
        LOG("parameters error \n");
        goto error;
    }

    test_array = (int64_t *)calloc(sizeof(int64_t), len);
    if (NULL == test_array) {
        ret = -1;
        LOG("malloc test_array failed\n");
        goto error;
    }

    memcpy(test_array, array, len * sizeof(int64_t));

    LOG("\npre : ");
    for (i = 0; i < len; i ++) {
        printf("%lld, ", array[i]);
    }

    // sort from small to large.
    if (ORDER_BY_ASCEND == order) {
        for (j = 0; j < len - 1; j ++) {
            for (i = 0; i < len - j - 1; i ++) {
                if (test_array[i] > test_array[i + 1]) {
                    utils_swap_int64(&test_array[i], &test_array[i+1]);
                }
            }
        }
    } else {
        for (j = 0; j < len - 1; j ++) {
            for (i = 0; i < len - j - 1; i ++) {
                if (test_array[i] < test_array[i + 1]) {
                    utils_swap_int64(&test_array[i], &test_array[i+1]);
                }
            }
        }
    }

    LOG("\npost: ");
    for (i = 0; i < len; i ++) {
        printf("%lld, ", test_array[i]);
    }
    printf("\n");
    memcpy(array, test_array, len * sizeof(int64_t));

error:
    if (test_array != NULL)
        free(test_array);
    return ret;
}
// 123456
// 123
bool utils_str_contains(char *input_str, char *sub_str)
{
    size_t in_len, sub_len;
    size_t i = 0;
    char bak_char = 0;
    char *in = NULL;
    char *sub = NULL;
    bool ret = false;

    if (NULL == input_str ||
        NULL == sub_str) {
        goto finish;
    }

    in_len = strlen(input_str);
    sub_len = strlen(sub_str);

    in = strdup(input_str);
    if (NULL == in) {
        ret = false;
        goto finish;
    }

    sub = strdup(sub_str);
    if (NULL == sub) {
        ret = false;
        goto finish;
    }

    if (sub_len > in_len) {
        ret = false;
        goto finish;
    } else if (sub_len == in_len) {
        ret = 0 == strcmp(in, sub);
        goto finish;
    }

    for (i = 0; in_len >= i + sub_len; i ++) {
        bak_char = in[sub_len + i];
        in[sub_len + i] = '\0';
        if (0 == strcmp(in + i, sub)) {
            ret = true;
            goto finish;
        }
        in[sub_len + i] = bak_char;
    }

finish:
    if (in != NULL) {
        free(in);
    }
    if (sub != NULL) {
        free(sub);
    }
    return ret;
}

int32_t utils_int64_to_str(int64_t val, char *str)
{
    int32_t ret = 0;
    size_t i = 0;

    if (NULL == str) {
        ret = -1;
        goto finish;
    }

    for (i = 0; i < sizeof(val) * 8; i ++) {
        *(str + i) = ((val >> i) & 0x01u) + '0';
    }

finish:
    return ret;
}

int32_t utils_size_t_to_str(size_t val, char *str)
{
    int32_t ret = 0;
    size_t i = 0;

    if (NULL == str) {
        ret = -1;
        goto finish;
    }

    for (i = 0; i < sizeof(val) * 8; i ++) {
        *(str + i) = ((val >> i) & 0x01u) + '0';
    }

finish:
    return ret;
}

size_t utils_str_count_char(char *str, char c)
{
    size_t count = 0;
    char *in = str;

    while (*in != '\0') {
        if (*in == c) {
            count ++;
        }
        in ++;
    }

    return count;
}

size_t utils_value_hamming_distance(size_t a, size_t b)
{
    size_t i = 0;
    size_t c = 0;
    char str[sizeof(a) * 8 + 1] = {0};

    c = a ^ b;
    if (utils_size_t_to_str(c, str)) {
        return 0;
    }

    return utils_str_count_char(str, '1');
}

char inline utils_conv_uppercase(char c)
{
    if (c >= 'A' && c <= 'Z') {
        return c;
    } else if (c >= 'a' && c <= 'z') {
        return c - 32;
    } else {
        return 0;
    }
}

char inline utils_conv_lowercase(char c)
{
    if (c >= 'A' && c <= 'Z') {
        return c + 32;
    } else if (c >= 'a' && c <= 'z') {
        return c;
    } else {
        return 0;
    }
}

bool inline utils_is_liter(char c)
{
    if (((c >= 'A') && (c <= 'Z')) || 
        ((c >= 'a') && (c <= 'z'))) {
        return true;
    } else {
        return false;
    }
}

bool inline utils_is_number(char c)
{
    if (((c >= '0') && (c <= '9'))) {
        return true;
    } else {
        return false;
    }
}

#ifdef __cplusplus
}
#endif /*__cplusplus*/