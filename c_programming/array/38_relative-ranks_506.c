#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "utils.h"

static const char *first_str = "Gold Medal";
static const char *sec_str = "Silver Medal";
static const char *third_str = "Bronze Medal";

static int32_t relative_rank(int32_t *array, size_t len)
{
    int32_t ret = 0;
    size_t i = 0, j = 0;
    int32_t max = 0;
    int32_t *index = NULL;
    char *strlist[100] = { NULL };
    char temp[3] = {0};

    UTILS_CHECK_PTR(array);
    UTILS_CHECK_LEN(len);

    index = (int32_t *)malloc(sizeof(int32_t) * len);
    UTILS_CHECK_PTR(index);

    for (i = 0; i < len; i ++) {
        index[i] = i;
    }

    for (j = 0; j < len - 1; j ++) {
        for (i = 0; i < len - j - 1; i ++) {
            if (array[i] < array[i + 1]) {
                utils_swap_int32(&array[i], &array[i + 1]);
                utils_swap_int32(&index[i], &index[i + 1]);
            }
        }
    }
    utils_print_int32_array(index, len, "the reorder index : ");

    for (i = 0; i < len; i ++) {
        if (index[i] == 0) {
            strlist[i] = strdup(first_str);
        } else if (index[i] == 1) {
            strlist[i] = strdup(sec_str);
        } else if (index[i] == 2) {
            strlist[i] = strdup(third_str);
        } else {
            sprintf(temp, "%d", index[i] + 1);
            strlist[i] = strdup(temp);
        }
    }
    LOG("output : \n");
    for (i = 0; i < len; i ++) {
        printf("%s, ", strlist[i]);
        free(strlist[i]);
    }
    printf("\n");

finish:
    if (index != NULL)
        free(index);
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;
    int32_t array_1[] = {10,3,8,9,4};
    size_t sz = 0;

    ret = relative_rank(array_1, ARRAY_SIZE(array_1));
    UTILS_CHECK_RET(ret);

finish:
    return ret;
}