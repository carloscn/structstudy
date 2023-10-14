#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>
#include <assert.h>
#include "utils.h"

static int32_t decode_message(const char *key, char *message)
{
    int32_t ret = 0;
    char *table = NULL;
    size_t key_len, mes_len;

    UTILS_CHECK_PTR(key);
    UTILS_CHECK_PTR(message);
    UTILS_CHECK_LEN(key_len = strlen(key));
    UTILS_CHECK_LEN(mes_len = strlen(message));

    table = (char *)calloc(key_len + 1, sizeof(char));
    UTILS_CHECK_PTR(table);

    for (size_t count = 0, i = 0; i < key_len; i ++) {
        if (key[i] == ' ') {
            table[i] = ' ';
            continue;
        }
        for (size_t j = 0; j < i; j ++) {
            if (key[i] == key[j]) {
                table[i] = '@';
                break;
            }
        }
        table[i] = table[i] == '@' ?
                   table[i] :
                   'a' + count ++;
    }

    for (size_t i = 0; i < mes_len; i ++) {
        char e = message[i];
        if (message[i] == ' ') {
            continue;
        }
        for (size_t j = 0; j < key_len; j ++) {
            if (key[j] == e) {
                message[i] = table[j];
                break;
            }
        }
    }

finish:
    UTILS_SAFE_FREE(table);
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;
    char str[1024] = {0};

    strcpy(str, "vkbs bs t suepuv");
    ret = decode_message("the quick brown fox jumps over the lazy dog", str);
    assert(ret == 0), assert(strcmp(str, "this is a secret") == 0);

    strcpy(str, "zwx hnfx lqantp mnoeius ycgk vcnjrdb");
    ret = decode_message("eljuxhpwnyrdgtqkviszcfmabo", str);
    assert(ret == 0), assert(strcmp(str, "the five boxing wizards jump quickly") == 0);

    LOG("All tests pass!");

finish:
    return ret;
}
