#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include "queue.h"
#include "utils.h"

static bool check_queue_dup(QUEUE_T *queue, size_t *dup_len)
{
    int32_t ret = 0;
    size_t i = 0, j = 0;

    for(i = 0; i < queue->current_len - 1; i ++) {
        for(j = i + 1; j < queue->current_len; j ++) {
            if(queue->space[j] == queue->space[i]) {
                *dup_len = i + 1;
                return true;
            }
        }
    }

    return false;
}

static int32_t get_longest_substring_without_repeat(char *str, char **out_str_pos, size_t *out_str_len)
{
    int32_t ret = 0;
    int32_t i = 0;
    size_t str_len = 0;
    char *max_pos = NULL;
    size_t max_len = 0;
    QUEUE_T *queue =  NULL;
    size_t dup_len = 0;
    size_t record_index = 0;

    UTILS_CHECK_PTR(str);
    UTILS_CHECK_PTR(out_str_pos);

    str_len = strlen(str);
    if (!str_len) {
        *out_str_pos = NULL;
        *out_str_len = 0;
        goto finish;
    }

    queue = queue_malloc(str_len);
    UTILS_CHECK_PTR(queue);

    for (i = 0; i < str_len; i ++) {
        ret = queue_push(queue, (int64_t)str[i]);
        UTILS_CHECK_RET(ret);

        if (check_queue_dup(queue, &dup_len)) {
            if (max_len <= queue_count(queue) - 1) {
                max_len = queue_count(queue) - 1;
                max_pos = str + record_index;
            }
            while (dup_len --) {
                ret = queue_pop(queue, NULL);
                UTILS_CHECK_RET(ret);
                record_index ++;
            }
        } else {
            continue;
        }
    }

    *out_str_pos = max_pos;
    *out_str_len = max_len;

finish:
    queue_free(queue);
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;
    int32_t val = 0;
    char *str = NULL;
    bool result = false;
    size_t i = 0;

    char *str1 = "abcabcbb";
    char *str2 = "pwwkew";
    char *str3 = "bbbbbbbb";
    char *out_str1 = NULL;
    size_t out_str_len = 0;

    ret = get_longest_substring_without_repeat(str1, &out_str1, &out_str_len);
    UTILS_CHECK_RET(ret);
    LOG("the result is ");
    for (i = 0; i < out_str_len; i ++) {
        printf("%c", out_str1[i]);
    }
    printf("\n");

    ret = get_longest_substring_without_repeat(str2, &out_str1, &out_str_len);
    UTILS_CHECK_RET(ret);
    LOG("the result is ");
    for (i = 0; i < out_str_len; i ++) {
        printf("%c", out_str1[i]);
    }
    printf("\n");

    ret = get_longest_substring_without_repeat(str3, &out_str1, &out_str_len);
    UTILS_CHECK_RET(ret);
    LOG("the result is ");
    for (i = 0; i < out_str_len; i ++) {
        printf("%c", out_str1[i]);
    }
    printf("\n");

finish:
    return ret;
}