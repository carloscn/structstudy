#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"
#include "bufferlist.h"
struct bufferlist_t {
    size_t capacity;
    size_t size;
    BUFFER_T **list;
};

static int32_t _realloc_buflist(BUFLIST_T *buflist, int32_t append_len)
{
    int32_t ret = 0;
    BUFFER_T **p = NULL;
    int32_t current_size = 0;

    UTILS_CHECK_PTR(buflist);
    UTILS_CHECK_LEN(append_len);

    current_size = ((int32_t) buflist->size) + append_len;
    p = (BUFFER_T **)realloc(buflist->list,
                             sizeof(BUFFER_T*) * (size_t)current_size);
    UTILS_CHECK_PTR(p);

    buflist->list = p;
    buflist->capacity = (size_t)current_size;

finish:
    return ret;
}

BUFLIST_T* buflist_malloc(void)
{
    BUFLIST_T *buflist = NULL;

    buflist = (BUFLIST_T*)malloc(sizeof(BUFLIST_T));
    if (NULL == buflist) {
        goto finish;
    }
    buflist->capacity = 0;
    memset(buflist, 0, sizeof(BUFLIST_T));

finish:
    return buflist;
}

void buflist_free(BUFLIST_T *buflist)
{
    size_t i = 0;

    if (NULL == buflist) {
        return;
    }

    for (i = 0; i < buflist->size; i ++) {
        buffer_free(buflist->list[i]);
    }

    buflist->size = 0;

    free(buflist->list);
    free(buflist);
}

int32_t buflist_add(BUFLIST_T *buflist, BUFFER_T *buf)
{
    int32_t ret = 0;
    size_t sz = 0;
    BUFFER_T **p = NULL;

    UTILS_CHECK_PTR(buflist);
    UTILS_CHECK_PTR(buf);

    sz = buflist->size + 1;

    if (sz > buflist->capacity) {
        ret = _realloc_buflist(buflist, BUFFER_DEFUALT_SIZE);
        UTILS_CHECK_RET(ret);
    }

    p = buflist->list;
    p[buflist->size] = buffer_malloc(buffer_get_current_len(buf));
    UTILS_CHECK_PTR(p[buflist->size]);

    ret = buffer_copy(*(p + buflist->size), buf);
    UTILS_CHECK_RET(ret);

    buflist->size = sz;

finish:
    p = NULL;
    return ret;
}

int32_t buflist_insert_after(BUFLIST_T *buflist, BUFFER_T *buf, size_t index)
{
    int32_t ret = 0;
    size_t sz = 0;
    BUFFER_T **p = NULL;
    size_t i = 0;

    UTILS_CHECK_PTR(buflist);
    UTILS_CHECK_PTR(buf);

    sz = buflist->size + 1;

    if (sz > buflist->capacity) {
        ret = _realloc_buflist(buflist, BUFFER_DEFUALT_SIZE);
        UTILS_CHECK_RET(ret);
    }

    p = buflist->list;
    for(i = buflist->size; i > index + 1; i --){
        p[i] = p[i - 1];
    }

    p[index + 1] = buffer_malloc(buffer_get_current_len(buf));
    UTILS_CHECK_PTR(p[index + 1]);

    ret = buffer_copy(*(p + index + 1), buf);
    UTILS_CHECK_RET(ret);

    buflist->size = sz;

finish:
    p = NULL;
    return ret;
}

int32_t buflist_remove_last(BUFLIST_T *buflist)
{
    int32_t ret = 0;

    UTILS_CHECK_PTR(buflist);

    buflist->size --;

    buffer_free(buflist->list[buflist->size]);

    if (buflist->capacity - buflist->size > BUFFER_DEFUALT_SIZE) {
        ret = _realloc_buflist(buflist, 0 - (int32_t)BUFFER_DEFUALT_SIZE);
        UTILS_CHECK_RET(ret);
    }

finish:
    return ret;
}

int32_t buflist_remove_at(BUFLIST_T *buflist, size_t index)
{
    int32_t ret = 0;
    size_t i = 0;

    UTILS_CHECK_PTR(buflist);
    buffer_free(buflist->list[index]);

    buflist->size --;

    for (i = index; i < buflist->size; i ++) {
        buflist->list[i] = buflist->list[i + 1];
    }

    if (buflist->capacity - buflist->size > BUFFER_DEFUALT_SIZE) {
        ret = _realloc_buflist(buflist, 0 - (int32_t)BUFFER_DEFUALT_SIZE);
        UTILS_CHECK_RET(ret);
    }

finish:
    return ret;
}

BUFFER_T* buflist_get_buffer_at(BUFLIST_T *buflist, size_t index)
__unsafe_indexable
{
    if ((NULL == buflist) ||
        (index > buflist->size - 1)) {
        return NULL;
    }

    return buflist->list[index];
}

bool buflist_contains(BUFLIST_T *buflist, BUFFER_T* buf, size_t *index)
__unsafe_indexable
{
    size_t i = 0;
    int32_t ret = 0;
    int64_t *array_a = NULL;
    int64_t *array_b = NULL;
    size_t sz_a = 0;
    size_t sz_b = 0;

    if (NULL == buflist ||
        NULL == buf ||
        0 == buflist->size) {
        return false;
    }

    ret = buffer_dup_array(buf, &array_a, &sz_a);
    UTILS_CHECK_RET(ret);

    for (i = 0; i < buflist->size; i ++) {
        ret = buffer_dup_array(buflist->list[i], &array_b, &sz_b);
        UTILS_CHECK_RET(ret);
        if (sz_b != sz_a) {
            UTILS_SAFE_FREE(array_b);
            continue;
        }

        if (0 == memcmp(array_a, array_b, sz_a * sizeof(int64_t))) {
            if (index != NULL) {
                *index = i;
            }
            goto finish;
        }
    }

    ret = !ret;

finish:
    UTILS_SAFE_FREE(array_a);
    UTILS_SAFE_FREE(array_b);
    return ret == 0;
}

size_t buflist_get_size(BUFLIST_T *buflist)
__unsafe_indexable
{
    if (NULL == buflist) {
        return 0;
    }

    return buflist->size;
}

BUFLIST_T* buflist_dup(BUFLIST_T *buflist)
{
    int32_t ret = 0;
    BUFLIST_T *ptr = NULL;
    size_t i = 0;
    size_t j = 0;

    if (NULL == buflist) {
        return NULL;
    }

    ptr = buflist_malloc();
    if (NULL == ptr) {
        return ptr;
    }

    for (i = 0; i < buflist->size; i ++) {
        ret = buflist_add(ptr, buflist->list[i]);
        UTILS_CHECK_RET(ret);
    }

    if (buflist->capacity != ptr->capacity) {
        ret = _realloc_buflist(ptr, (int32_t)buflist->capacity - (int32_t)ptr->capacity);
        UTILS_CHECK_RET(ret);
    }

finish:
    if (ret != 0) {
        buflist_free(ptr);
    }
    return ptr;
}

int32_t buflist_append_all_buflist(BUFLIST_T *buflist, BUFLIST_T *buflist_app)
{
    int32_t ret = 0;
    size_t i = 0;
    BUFLIST_T *dup = NULL;

    UTILS_CHECK_PTR(buflist);
    UTILS_CHECK_PTR(buflist_app);
    UTILS_CHECK_LEN(buflist_app->size);

    dup = buflist_dup(buflist_app);
    UTILS_CHECK_PTR(dup);

    for (i = 0; i < dup->size; i ++) {
        ret = buflist_add(buflist, dup->list[i]);
        UTILS_CHECK_RET(ret);
    }

finish:
    buflist_free(dup);
    return ret;
}

int32_t buflist_append_array(BUFLIST_T *buflist, int64_t *array, size_t len)
{
    int32_t ret = 0;
    BUFFER_T *buffer = NULL;

    UTILS_CHECK_PTR(buflist);
    UTILS_CHECK_PTR(array);
    UTILS_CHECK_LEN(len);

    buffer = buffer_malloc(BUFFER_DEFUALT_SIZE);
    UTILS_CHECK_PTR(buffer);

    ret = buffer_append_array(buffer, array, len);
    UTILS_CHECK_RET(ret);

    ret = buflist_add(buflist, buffer);
    UTILS_CHECK_RET(ret);

finish:
    buffer_free(buffer);
    return ret;
}

void buflist_infolog(BUFLIST_T *buflist)
{
    size_t i;
    printf("\n>>>\n");
    printf("buffer list info:\n");
    printf("buffer list size: %zu\n", buflist->size);
    for(i = 0; i < buflist->size; i ++){
        printf("%zu :", i);
        buffer_print(buflist->list[i]);
    }
    printf("\n");
}

int32_t buflist_selftest(void)
{
    int32_t ret = 0;
    size_t i = 0;
    bool result = 0;

    BUFLIST_T *buflist = NULL;
    BUFFER_T *buffer1 = NULL;
    BUFFER_T *buffer2 = NULL;
    BUFFER_T *buffer3 = NULL;
    BUFFER_T *buffer4 = NULL;
    BUFFER_T *buffer5 = NULL;
    int64_t array[] = {777, 888, 999, 1000};

    buffer1 = buffer_malloc(BUFFER_DEFUALT_SIZE);
    UTILS_CHECK_PTR(buffer1);

    for (i = 0; i < 20; i ++) {
        ret = buffer_push_tail(buffer1, i);
        UTILS_CHECK_RET(ret);
    }

    buffer2 = buffer_malloc(BUFFER_DEFUALT_SIZE);
    UTILS_CHECK_PTR(buffer2);

    for (i = 0; i < 15; i ++) {
        ret = buffer_push_tail(buffer2, i*2);
        UTILS_CHECK_RET(ret);
    }

    buffer3 = buffer_malloc(BUFFER_DEFUALT_SIZE);
    UTILS_CHECK_PTR(buffer3);

    for (i = 0; i < 10; i ++) {
        ret = buffer_push_tail(buffer3, i*3);
        UTILS_CHECK_RET(ret);
    }

    buffer4 = buffer_malloc(BUFFER_DEFUALT_SIZE);
    UTILS_CHECK_PTR(buffer4);

    for (i = 0; i < 8; i ++) {
        ret = buffer_push_tail(buffer4, i*4);
        UTILS_CHECK_RET(ret);
    }

    buffer5 = buffer_malloc(BUFFER_DEFUALT_SIZE);
    UTILS_CHECK_PTR(buffer5);

    for (i = 0; i < 9; i ++) {
        ret = buffer_push_tail(buffer5, i*5);
        UTILS_CHECK_RET(ret);
    }

    buflist = buflist_malloc();
    UTILS_CHECK_PTR(buflist);

    ret = buflist_add(buflist, buffer1);
    UTILS_CHECK_RET(ret);

    ret = buflist_add(buflist, buffer2);
    UTILS_CHECK_RET(ret);

    ret = buflist_add(buflist, buffer3);
    UTILS_CHECK_RET(ret);

    ret = buflist_add(buflist, buffer4);
    UTILS_CHECK_RET(ret);

    ret = buflist_insert_after(buflist, buffer5, 2);
    UTILS_CHECK_RET(ret);

    ret = buflist_remove_last(buflist);
    UTILS_CHECK_RET(ret);

    ret = buflist_add(buflist, buffer4);
    UTILS_CHECK_RET(ret);

    buflist_infolog(buflist);

    ret = buflist_remove_at(buflist, 1);
    UTILS_CHECK_RET(ret);

    buflist_infolog(buflist);

    result = buflist_contains(buflist, buffer2, NULL);
    LOG("the result is %d\n", result);

    ret = buflist_append_array(buflist, array, ARRAY_SIZE(array));
    UTILS_CHECK_RET(ret);

    buflist_infolog(buflist);

    ret = buflist_append_all_buflist(buflist, buflist);
    UTILS_CHECK_RET(ret);

    buflist_infolog(buflist);
finish:
    buflist_free(buflist);
    return 0;
}