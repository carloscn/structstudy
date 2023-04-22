#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "strlist.h"
#include "utils.h"

struct strlist_t {
    size_t capacity;
    size_t size;
    char **list;
};

static int32_t _realloc_strlist(STRLIST_T *strlist, int32_t append_len)
{
    int32_t ret = 0;
    char **p = NULL;
    int32_t current_size = 0;

    UTILS_CHECK_PTR(strlist);
    UTILS_CHECK_LEN(append_len);

    current_size = ((int32_t)strlist->size) + append_len;
    p = (char **)realloc(strlist->list,
                         sizeof(char*) * (size_t)current_size);
    UTILS_CHECK_PTR(p);

    strlist->list = p;
    strlist->capacity = (size_t)current_size;

finish:
    return ret;
}


STRLIST_T* strlist_malloc(void)
{
    STRLIST_T *strlist = NULL;

    strlist = (STRLIST_T *)malloc(sizeof(STRLIST_T));
    if (NULL == strlist) {
        goto finish;
    }

    memset(strlist, 0, sizeof(STRLIST_T));

finish:
    return strlist;
}

int32_t strlist_add(STRLIST_T *strlist, const char *str)
{
    int32_t ret = 0;
    size_t len = 0;
    char *ptr = NULL;

    UTILS_CHECK_PTR(strlist);
    UTILS_CHECK_PTR(str);
    UTILS_CHECK_LEN(len = strlen(str));

    if (strlist->capacity < strlist->size + 1) {
        ret = _realloc_strlist(strlist, STRLIST_DEFAULT_SIZE);
        UTILS_CHECK_RET(ret);
    }

    ptr = (char *)calloc(sizeof(char*), len + 1);
    UTILS_CHECK_PTR(ptr);

    strcpy(ptr, str);

    strlist->list[strlist->size] = ptr;
    strlist->size ++;

finish:
    return ret;
}

int32_t strlist_add_split_by_char(STRLIST_T *strlist, const char *str, char c)
{
    int32_t ret = 0;
    size_t len = 0;
    size_t i = 0;
    char *head = NULL;
    char *dup_str = NULL;

    UTILS_CHECK_PTR(strlist);
    UTILS_CHECK_PTR(str);
    UTILS_CHECK_LEN(len = strlen(str));

    dup_str = strdup(str);
    UTILS_CHECK_PTR(dup_str);

    head = dup_str;

    for (i = 0; i < len; i ++) {
        if (dup_str[i] == c) {
            dup_str[i] = '\0';
            ret = strlist_add(strlist, head);
            UTILS_CHECK_RET(ret);
            dup_str[i] = c;
            head = dup_str + i + 1;
        }
    }

    ret = strlist_add(strlist, dup_str);
    UTILS_CHECK_RET(ret);

finish:
    UTILS_SAFE_FREE(dup_str);
    return ret;
}

int32_t strlist_insert_after(STRLIST_T *strlist, const char *str, size_t index)
{
    int32_t ret = 0;
    int32_t i, len;
    char *ptr = NULL;

    UTILS_CHECK_PTR(strlist);
    UTILS_CHECK_PTR(str);
    UTILS_CHECK_LEN(len = strlen(str));

    if (index >= strlist->size) {
        ret = -1;
        goto finish;
    }

    strlist->size ++;

    if (strlist->capacity < strlist->size + 1) {
        ret = _realloc_strlist(strlist, STRLIST_DEFAULT_SIZE);
        UTILS_CHECK_RET(ret);
    }

    ptr = (char *)calloc(sizeof(char), len + 1);
    UTILS_CHECK_PTR(ptr);

    for (i = strlist->size - 1; i > index + 1; i --) {
        strlist->list[i] = strlist->list[i-1];
    }

    strlist->list[index + 1] = ptr;
    strcpy(strlist->list[index + 1], str);

finish:
    return ret;
}

int32_t strlist_remove_last(STRLIST_T *strlist)
{
    int32_t ret = 0;

    UTILS_CHECK_PTR(strlist);
    UTILS_CHECK_LEN(strlist->size);
    UTILS_CHECK_PTR(strlist->list[strlist->size - 1]);

    free(strlist->list[strlist->size - 1]);
    strlist->size --;

    if (strlist->capacity - strlist->size > STRLIST_DEFAULT_SIZE) {
        ret = _realloc_strlist(strlist, 0 - (int32_t)STRLIST_DEFAULT_SIZE);
        UTILS_CHECK_RET(ret);
    }

finish:
    return ret;
}

int32_t strlist_remove_at(STRLIST_T *strlist, size_t index)
{
    int32_t ret = 0;
    size_t i;

    UTILS_CHECK_PTR(strlist);

    if (index >= strlist->size) {
        ret = -1;
        goto finish;
    }

    UTILS_CHECK_PTR(strlist->list[index]);
    free(strlist->list[index]);

    for (i = index; i < strlist->size - 1; i ++) {
        strlist->list[i] = strlist->list[i + 1];
    }

    strlist->size --;

    if (strlist->capacity - strlist->size > STRLIST_DEFAULT_SIZE) {
        ret = _realloc_strlist(strlist, 0 - (int32_t)STRLIST_DEFAULT_SIZE);
        UTILS_CHECK_RET(ret);
    }

finish:
    return ret;
}

char* strlist_get_str_at(STRLIST_T *strlist, size_t index)
{
    if (strlist == NULL || index >= strlist->size) {
        return NULL;
    }

    return strlist->list[index];
}

char *strlist_get_str_at_with_clone(STRLIST_T *strlist, size_t index)
{
    return strdup(strlist_get_str_at(strlist, index));
}

bool strlist_contains(STRLIST_T *strlist, const char *str, size_t *index)
{
    size_t i;

    for (i = 0; i < strlist->size; i++) {
        if (0 == (strcmp(strlist->list[i], str))) {
            if (index != NULL) {
                *index = i;
            }
            return true;
        }
    }

    return false;
}

int32_t strlist_append_all_substrs(STRLIST_T *strlist, const char *str)
{
    int32_t ret = 0;
    size_t i = 0;
    size_t j = 0;
    size_t len = 0;
    size_t count = 0;
    char *p = NULL;

    UTILS_CHECK_PTR(strlist);
    UTILS_CHECK_PTR(str);
    UTILS_CHECK_LEN(len = strlen(str));

    for (i = 1; i < len; i ++) {
        for (j = 0; j < len - i + 1; j ++) {
            p = (char *)calloc(sizeof(char), i + 1);
            UTILS_CHECK_PTR(p);
            memcpy(p, str + j, i);
            ret = strlist_add(strlist, p);
            UTILS_CHECK_RET(ret);
            count ++;
            p = NULL;
        }
    }

finish:
    return ret;
}

size_t strlist_get_size(STRLIST_T *strlist)
{
    if (NULL == strlist) {
        return 0;
    }

    return strlist->size;
}

void strlist_free(STRLIST_T *strlist)
{
    size_t i = 0;

    if (NULL == strlist) {
        return;
    }

    for (i = 0; i < strlist->size; i ++) {
        free(strlist->list[i]);
    }

    free(strlist->list);
    free(strlist);
}

void strlist_infolog(STRLIST_T *strlist)
{
    size_t i;
    printf("\n>>>\n");
    printf("strlist info:\n");
    printf("strlist size: %zu\n", strlist->size);
    for (i = 0; i < strlist->size; i ++) {
        printf("%zu : %s\n", i , strlist->list[i]);
    }
}

int32_t strlist_selftest(void)
{
    printf("hello c_strlist!");

    STRLIST_T *strlist = strlist_malloc();

    strlist_infolog(strlist);

    strlist_add(strlist,(char*)"aaaa");
    strlist_infolog(strlist);

    strlist_add(strlist,(char*)"bbbb");
    strlist_infolog(strlist);

    strlist_add(strlist,(char*)"字符串列表测试");
    strlist_infolog(strlist);

    strlist_insert_after(strlist, (char*)"ccccc", 1);
    strlist_infolog(strlist);

    printf("\nis strlist contians \"123\"?  %d\n",
           strlist_contains(strlist,(const char*)"123", NULL));

    printf("\nis strlist contians \"字符串列表测试\" ? %d\n",
           strlist_contains(strlist,(const char*)"字符串列表测试", NULL));

    strlist_remove_last(strlist);
    strlist_infolog(strlist);

    printf("\nis strlist contians \"字符串列表测试\" ? %d\n",
           strlist_contains(strlist,(const char*)"字符串列表测试", NULL));

    strlist_remove_at(strlist,1);
    strlist_infolog(strlist);


    strlist_free(strlist);

    return 0;
}