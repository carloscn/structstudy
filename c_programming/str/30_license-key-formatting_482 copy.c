#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../utils/utils.h"

static int32_t format_key(char *key_str, size_t *key_str_len, size_t k)
{
    int32_t ret = 0;
    size_t str_len = 0;
    int32_t i = 0, j = 0;
    size_t count = 0;
    char *key_dup = NULL;
    
    UTILS_CHECK_PTR(key_str);
    UTILS_CHECK_PTR(key_str_len);
    UTILS_CHECK_LEN(k);
    UTILS_CHECK_LEN(str_len = strlen(key_str));
    
    key_dup = strdup(key_str);
    UTILS_CHECK_PTR(key_dup);

    memset(key_dup, '0', str_len);

    for (i = str_len - 1, j = str_len - 1; i >= 0; i --) {
        if (utils_is_liter(key_str[i]) || utils_is_number(key_str[i])) {
            if (utils_is_liter(key_str[i])) {
                key_dup[j] = utils_conv_uppercase(key_str[i]);
            } else {
                key_dup[j] = key_str[i];
            }
            count ++;
            j --;
            if (count == k && i > 1) {
                count = 0;
                key_dup[j] = '-';
                j --;
            }
            LOG("key_str: %s\n", key_str);
            LOG("key_dup: %s , i = %d, j = %d\n", key_dup, i, j);
        }
    }

    strcpy(key_str, key_dup + j + 1);

finish:
    if (key_dup != NULL)
        free(key_dup);
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;
    char str1[100];
    size_t out = 0;

    sprintf(str1, "%s", "2-5g-3-J");
    ret = format_key(str1, &out, 2);
    UTILS_CHECK_RET(ret);

    LOG("the %s out is %d\n", str1, out);

finish:
    return ret;
}
