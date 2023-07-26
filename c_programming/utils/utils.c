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

void utils_swap_size_t(size_t *a, size_t *b)
{
    if (a == b)
        return;
    *a = (*a) ^ (*b);
    *b = (*b) ^ (*a);
    *a = (*a) ^ (*b);
}

void utils_swap_null(void *a, void *b)
{
    (void)a;
    (void)b;
    LOG("unsupport type!\n");
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

#define DUMP_WIDTH 16
static void bio_dump(const char *s, int len)
{
    char buf[160+1] = {0};
    char tmp[20] = {0};
    unsigned char ch;
    int32_t i, j, rows;

#ifdef TRUNCATE
    int32_t trunc = 0;
    for(; (len > 0) && ((s[len-1] == ' ') || (s[len-1] == '\0')); len--)
        trunc++;
#endif

    rows = (len / DUMP_WIDTH);
    if ((rows * DUMP_WIDTH) < len)
        rows ++;
    for (i = 0; i < rows; i ++) {
        /* start with empty string */
        buf[0] = '\0';
        sprintf(tmp, "%04x - ", i * DUMP_WIDTH);
        strcpy(buf, tmp);
        for (j = 0; j < DUMP_WIDTH; j ++) {
            if (((i * DUMP_WIDTH) + j) >= len) {
                strcat(buf,"   ");
            } else {
                ch = ((unsigned char)*(s + i * DUMP_WIDTH + j)) & 0xff;
                sprintf(tmp, "%02x%c" , ch, j == 7 ? '-':' ');
                strcat(buf, tmp);
            }
        }
        strcat(buf, "  ");
        for(j = 0;j < DUMP_WIDTH;j ++) {
            if (((i * DUMP_WIDTH) + j) >= len)
                break;
            ch = ((unsigned char)*(s + i * DUMP_WIDTH + j)) & 0xff;
            sprintf(tmp, "%c", ((ch >= ' ')&&(ch <= '~')) ? ch : '.');
            strcat(buf, tmp);
        }
        strcat(buf, "\n");
        printf("%s", buf);
    }
#ifdef TRUNCATE
    if (trunc > 0) {
        sprintf(buf,"%04x - <SPACES/NULS>\n",len+trunc);
        printf("%s", buf);
    }
#endif
}

void utils_print_bio_array(uint8_t *buffer, size_t len, char* msg)
{
    printf("\n");
    printf("%s: the len is %zu\n", msg, len);
    bio_dump((const char *)buffer, len);
    printf("\n");
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

void utils_print_char_array(char *a, size_t size, const char *msg)
{
    size_t i = 0;
    printf("%s", msg);
    for (i = 0; i < size; i ++) {
        printf("%c,", a[i]);
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
        printf("%4d, ", a[i]);
    }
    printf("\n");
}

void utils_print_int64_array(int64_t *a, size_t size, const char *msg)
{
    size_t i = 0;
    printf("%s", msg);
    for (i = 0; i < size; i ++) {
        printf("%4lld, ", a[i]);
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

size_t utils_str_set(char *str)
{
    size_t i = 0, j = 0, k = 0;
    size_t count = 0;
    char e = 0;
    size_t ori_len = 0;

    if (NULL == str || 0 == ori_len) {
        return 0;
    }

    ori_len = strlen(str);

    for (i = 0; i < ori_len; i ++) {
        e = str[i];
        for (j = i + 1; j < ori_len; j ++) {
            if (e == str[j]) {
                count ++;
                ori_len --;
                for (k = j, j--; k < ori_len; k ++) {
                    str[k] = str[k + 1];
                }
            }
        }
    }

    str[ori_len - count] = '\0';

    return ori_len - count;
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

    // LOG("\npre : ");
    // for (i = 0; i < len; i ++) {
    //     printf("%c, ", array[i]);
    // }

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

    // LOG("\npost: ");
    // for (i = 0; i < len; i ++) {
    //     printf("%c, ", test_array[i]);
    // }
    // printf("\n");
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

int32_t utils_sort_int32_array(int32_t *array, size_t len, ORDER_E order)
{
    int32_t ret = 0;
    int32_t *test_array = NULL;
    size_t i = 0, j = 0;

    if (NULL == array || 0 == len) {
        ret = -1;
        LOG("parameters error \n");
        goto error;
    }

    test_array = (int32_t *)calloc(sizeof(int32_t), len);
    if (NULL == test_array) {
        ret = -1;
        LOG("malloc test_array failed\n");
        goto error;
    }

    memcpy(test_array, array, len * sizeof(int32_t));

    LOG("\npre : ");
    for (i = 0; i < len; i ++) {
        printf("%d, ", array[i]);
    }

    // sort from small to large.
    if (ORDER_BY_ASCEND == order) {
        for (j = 0; j < len - 1; j ++) {
            for (i = 0; i < len - j - 1; i ++) {
                if (test_array[i] > test_array[i + 1]) {
                    utils_swap_int32(&test_array[i], &test_array[i+1]);
                }
            }
        }
    } else {
        for (j = 0; j < len - 1; j ++) {
            for (i = 0; i < len - j - 1; i ++) {
                if (test_array[i] < test_array[i + 1]) {
                    utils_swap_int32(&test_array[i], &test_array[i+1]);
                }
            }
        }
    }

    LOG("\npost: ");
    for (i = 0; i < len; i ++) {
        printf("%d, ", test_array[i]);
    }
    printf("\n");
    memcpy(array, test_array, len * sizeof(int32_t));

error:
    if (test_array != NULL)
        free(test_array);
    return ret;
}
// 123456
// 123

bool utils_str_contains_char(char *input_str, char e)
{
    if (NULL == input_str) {
        return false;
    }

    size_t len = strlen(input_str);
    size_t i = 0;

    for (i = 0; i < len; i ++) {
        if (input_str[i] == e) {
            return true;
        }
    }

    return false;
}


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

int32_t utils_str_filter_letter(char *str)
{
    if (NULL == str) {
        return -1;
    }

    size_t i = 0, j = 0;
    size_t len = strlen(str);

    for (i = 0; i < len; i ++) {
        if ((str[i] >= 'a' && str[i] <= 'z') ||
            (str[i] >= 'A' && str[i] <= 'Z')) {
           str[j] = str[i];
           j ++;
        }
    }
    str[j] = '\0';

    return 0;
}

int32_t utils_str_to_lowercase(char *str)
{
    if (NULL == str) {
        return -1;
    }

    size_t i = 0;
    size_t len = strlen(str);

    for (i = 0; i < len; i ++) {
        if ((str[i] >= 'A' && str[i] <= 'Z')) {
            str[i] = str[i] - ('A' - 'a');
        } else {
            str[i] = str[i];
        }
    }

    return 0;
}

int32_t utils_str_to_uppercase(char *str)
{
    if (NULL == str) {
        return -1;
    }

    size_t i = 0;
    size_t len = strlen(str);

    for (i = 0; i < len; i ++) {
        if ((str[i] >= 'a' && str[i] <= 'z')) {
            str[i] = str[i] + ('A' - 'a');
        } else {
            str[i] = str[i];
        }
    }

    return 0;
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
        return c;
    }
}

char inline utils_conv_lowercase(char c)
{
    if (c >= 'A' && c <= 'Z') {
        return c + 32;
    } else if (c >= 'a' && c <= 'z') {
        return c;
    } else {
        return c;
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

bool inline utils_is_capital(char c)
{
    if ((c >= 'A') && (c <= 'Z')) {
        return true;
    }
    return false;
}

bool inline utils_is_lowercase(char c)
{
    if ((c >= 'a') && (c <= 'z')) {
        return true;
    }
    return false;
}

int32_t utils_str_reverse(char *s)
{
    int32_t ret = 0;
    size_t len = 0;
    size_t i = 0;

    if (s == NULL || (len = strlen(s)) == 0) {
        ret = -1;
        goto finish;
    }

    for (i = 0; i < len / 2; i ++) {
        utils_swap_char(&(s[i]), &(s[len - i - 1]));
    }

finish:
    return ret;
}

int32_t utils_str_reserve_region(char* s, size_t start, size_t end)
{
    int32_t ret = 0;
    size_t count = 1;
    size_t j = 0;
    size_t len = 0;

    if (start == end) {
        goto finish;
    }

    if (s == NULL || (start > end) || (len = strlen(s)) == 0) {
        ret = -1;
        goto finish;
    }

    if (end - start == 1) {
       utils_swap_char(s + start, s + end);
       goto finish;
    }

    for (j = start; j < (end - start) / 2; j ++) {
        utils_swap_char(s + j, s + end - count);
        count ++;
    }

finish:
    return ret;
}

void* utils_memmove(void *dest, const void *src, size_t n)
{
    uint8_t *from = (uint8_t *) src;
    uint8_t *to = (uint8_t *) dest;

    if (from == to || 0 == n) {
        return dest;
    }

    if (to > from && to - from < (int)n) {
        /* to overlaps with from */
        /*  <from......>         */
        /*         <to........>  */
        /* copy in reverse, to avoid overwriting from */
        int32_t i;
        for (i = n - 1; i >= 0; i --) {
            to[i] = from[i];
        }

        goto finish;
    }

    if (from > to && from - to < (int)n) {
        /* to overlaps with from */
        /*        <from......>   */
        /*  <to........>         */
        /* copy forwards, to avoid overwriting from */
        size_t i;
        for (i = 0; i < n; i ++) {
            to[i] = from[i];
        }

        goto finish;
    }

    memcpy(dest, src, n);
finish:
    return dest;
}

void utils_print_sub_array_int64(const int64_t *array, size_t len)
{
    size_t num = 0;
    size_t i = 0;
    size_t j = 0;
    size_t k = 0;
    size_t n = 0;
    int64_t *temp_buffer = NULL;

    temp_buffer = (int64_t *)calloc(sizeof(int64_t), len);
    if (temp_buffer == NULL) {
        return;
    }

    num = 1 << len;
    for(i = 0; i < num; i ++) {
        j = i;
        k = 0;
        n = 0;
        while (j) {
            if (j & 1) {
                temp_buffer[n] = array[k];
                n ++;
            }
            j >>= 1;
            k ++;
        }
        utils_print_int64_array(temp_buffer, n, "sub: ");
    }

    UTILS_SAFE_FREE(temp_buffer);
}

void utils_print_two_dim_array_int32_t(int32_t *array, size_t len, size_t depth, size_t len_cap)
{
    size_t i = 0;

    if (0 == len || 0 == depth || 0 == len_cap || NULL == array) {
        return;
    }

    for (i = 0; i < depth; i ++) {
        utils_print_int32_array((array + len_cap * i), len, "");
    }
}

void utils_print_two_dim_array_int64_t(int64_t *array, size_t len, size_t depth, size_t len_cap)
{
    size_t i = 0;

    if (0 == len || 0 == depth || 0 == len_cap || NULL == array) {
        return;
    }

    for (i = 0; i < depth; i ++) {
        utils_print_int64_array((array + len_cap * i), len, "");
    }
}

int32_t utils_convert_char_to_nibble(uint8_t inchar, uint8_t *num)
{
    int32_t ret = 0;

    UTILS_CHECK_PTR(num);

    /* Convert the char to nibble */
    if ((inchar >= (uint8_t)'0') && (inchar <= (uint8_t)'9')) {
        *num = inchar - (uint8_t)'0';
    } else if ((inchar >= (uint8_t)'a') && (inchar <= (uint8_t)'f')) {
        *num = inchar - (uint8_t)'a' + 10U;
    } else if ((inchar >= (uint8_t)'A') && (inchar <= (uint8_t)'F')) {
        *num = inchar - (uint8_t)'A' + 10U;
    } else {
        ret = -1;
    }

finish:
    return ret;
}

int32_t utils_convert_str_to_be(const char *str, uint8_t *buf, size_t len)
{
    int32_t ret = -1;
    size_t c_len = 0;
    uint8_t lower_nibble, upper_nibble;

    UTILS_CHECK_PTR(str);
    UTILS_CHECK_PTR(buf);

    /* Len has to be multiple of 2 */
    if ((0 == len) || (len % 2 == 1)) {
        goto finish;
    }

    c_len = 0;
    while (c_len < len) {
        if (utils_convert_char_to_nibble(str[c_len], &upper_nibble) == 0) {
            if (utils_convert_char_to_nibble(str[c_len + 1], &lower_nibble) == 0) {
                buf[c_len / 2] = (upper_nibble << 4) | lower_nibble;
            } else {
                goto finish;
            }
        } else {
            goto finish;
        }
        c_len += 2;
    }
    ret = 0;

finish:
    return ret;
}

#ifdef __cplusplus
}
#endif /*__cplusplus*/