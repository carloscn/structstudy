#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "buffer.h"
#include "utils.h"

BUFFER_T* buffer_malloc(size_t sz)
{
    BUFFER_T* buffer = (BUFFER_T*)malloc(sizeof(BUFFER_T));
    if (NULL == buffer) {
        LOG("buffer malloc is NULL\n");
        return buffer;
    }

    buffer->data = (int64_t *)malloc(sizeof(int64_t) * sz);
    memset(buffer->data, 0, sizeof(int64_t) * sz);
    buffer->total_len = sz;
    buffer->current_len = 0;
    
    return buffer;
}

void buffer_free(BUFFER_T *buffer)
{
    if (NULL == buffer) {
        return;
    }
    if (NULL != buffer->data) {
        free(buffer->data);
        buffer->current_len = 0;
        buffer->total_len = 0;
    }
    free(buffer);
}

int32_t buffer_get_current_len(BUFFER_T *buffer)
{
    return buffer->current_len;
}

int32_t buffer_get_total_len(BUFFER_T *buffer)
{
    return buffer->total_len;
}

bool buffer_is_empty(BUFFER_T *buffer)
{
    return (buffer->current_len)?true:false;
}

static inline bool ___buffer_check_index(BUFFER_T *buffer, size_t index)
{
    return ( (index < 0) || (index > buffer->current_len) ) ? false : true;
}

static int32_t ___buffer_resize(BUFFER_T *buffer, size_t resize)
{
    int32_t ret = 0;

    if (0 == resize || NULL == buffer) {
        return 0;
    }
    if (resize > BUFFER_MAX_SZIE) {
        LOG("over the max len %zd\n", BUFFER_MAX_SZIE);
        return -1;
    }
    int64_t *buf = (int64_t *)malloc(sizeof(int64_t) * buffer->current_len);
    if (NULL == buf) {
        ret = -1;
        LOG("remalloc failed\n");
        goto finish;
    }
    memcpy(buf, buffer->data, sizeof(int64_t) * buffer->current_len);
    buffer->data = (int64_t *)realloc(buffer->data, sizeof(int64_t) * resize);
    if (NULL == buffer->data) {
        ret = -1;
        LOG("reamalloc failed\n");
        goto finish;
    }
    memcpy(buffer->data, buf, sizeof(int64_t) * buffer->current_len);
    buffer->total_len = resize;

finish:
    if (buf != NULL)
        free(buf);
    return ret;
}

int32_t buffer_push_by_index(BUFFER_T *buffer, size_t index, int64_t e)
{
    int32_t ret = 0;
    size_t i = 0;

    if (NULL == buffer) {
        ret = -1;
        LOG("buffer is NULL\n");
        goto finish;
    }
    if (___buffer_check_index(buffer, index) == false) {
        ret = -1;
        goto finish;
    }

    if (buffer->current_len == buffer->total_len){
        ret = ___buffer_resize(buffer, buffer->total_len + BUFFER_DEFUALT_SIZE);
        if (ret != 0) {
            LOG("buffer resize failed\n");
            ret = -1;
            goto finish;
        }
    }
    for (i = buffer->current_len - 1; i >= index; i --) {
        buffer->data[i + 1] = buffer->data[i];
    }
    buffer->data[index] = e;
    buffer->current_len ++;
finish:
    return ret;
}

int32_t buffer_push_tail(BUFFER_T *buffer, int64_t e)
{
    return buffer_push_by_index(buffer, buffer->current_len, e);
}

int32_t buffer_push_head(BUFFER_T *buffer, int64_t e)
{
    return buffer_push_by_index(buffer, 0, e);
}

int32_t buffer_get_by_index(BUFFER_T *buffer, size_t index, int64_t *e)
{
    int32_t ret = 0;

    if (NULL == buffer || NULL == e) {
        ret = -1;
        LOG("buffer is NULL\n");
        goto finish;
    }
    if (___buffer_check_index(buffer, index) == false) {
        ret = -1;
        LOG("index is error \n");
        goto finish;
    }
    *e = buffer->data[index];

finish:
    return ret;
}

int32_t buffer_set_by_index(BUFFER_T *buffer, size_t index, int64_t e)
{
    int32_t ret = 0;

    if (NULL == buffer) {
        ret = -1;
        LOG("buffer is NULL\n");
        goto finish;
    }
    if (___buffer_check_index(buffer, index) == false) {
        ret = -1;
        LOG("index is error \n");
        goto finish;
    }
    buffer->data[index] = e;
    
finish:
    return ret;
}

bool buffer_is_contain(BUFFER_T *buffer, int64_t e)
{
    bool ret = true;
    size_t i = 0;

    if (NULL == buffer) {
        ret = false;
        LOG("buffer is NULL\n");
        goto finish;
    }

    for (i = 0; i < buffer->current_len; i ++ ) {
        if ( buffer->data[i] == e ) {
            ret = true;
            break;
        }
    }
    
finish:
    return ret;
}

int32_t buffer_find(BUFFER_T *buffer, size_t *index, int64_t e)
{
    bool ret = true;
    size_t i = 0;

    if (NULL == buffer || NULL == index) {
        ret = false;
        LOG("buffer is NULL\n");
        goto finish;
    }
    for (i = 0; i < buffer->current_len; i ++) {
        if ( buffer->data[i] == e ) {
            *index = i;
            break;
        }
    }

finish:
    return ret;
}

int32_t buffer_pop_by_index(BUFFER_T *buffer, size_t index, int64_t *e)
{
    int32_t ret = 0;
    size_t i = 0;

    if (NULL == buffer) {
        ret = -1;
        LOG("buffer is NULL\n");
        goto finish;
    }
    if (___buffer_check_index(buffer, index) == false) {
        ret = -1;
        LOG("index is error \n");
        goto finish;
    }
    if (e != NULL)
        *e = buffer->data[index];
    for (i = index + 1; i < buffer->current_len; i ++) {
        buffer->data[i - 1] = buffer->data[i];
    }
    buffer->current_len --;
    buffer->data[buffer->current_len] = 0;

    if ((buffer->current_len <= buffer->total_len/4) &&
        (buffer->total_len/2 != 0)) {
        ___buffer_resize(buffer, buffer->total_len/2);
    }

finish:
    return ret;
}

int32_t buffer_pop_tail(BUFFER_T *buffer, int64_t *e)
{
    return buffer_pop_by_index(buffer, buffer->current_len - 1, e);
}

int32_t buffer_pop_head(BUFFER_T *buffer, int64_t *e)
{
    return buffer_pop_by_index(buffer, 0, e);
}

int32_t buffer_remove_element(BUFFER_T *buffer, int64_t e)
{
    int32_t ret = 0;
    size_t index = 0;
    ret = buffer_find(buffer, &index, e);
    if (ret != 0) {
        LOG("find e=%lld failed\d", e);
        return -1;
    }
    ret = buffer_pop_by_index(buffer, index, NULL);
    if (ret != 0) {
        LOG("find e= %lld failed\d", e);
        return -1;
    }
    return ret;
}

int32_t buffer_get_tail(BUFFER_T *buffer, int64_t *e)
{
    return buffer_get_by_index(buffer, buffer->current_len - 1, e);
}

int32_t buffer_get_head(BUFFER_T *buffer, int64_t *e)
{
    return buffer_get_by_index(buffer, 0, e);
}

void buffer_print(BUFFER_T *buffer)
{
    size_t i = 0;
    if (NULL == buffer || 0 == buffer->current_len) {
        return;
    }
    printf("print buffer: \n[ ");
    for (i = 0; i < buffer->current_len; i ++) {
        printf("%lld, ", buffer->data[i]);
    }
    printf(" ]\n");
}

int32_t buffer_selftest(void)
{
    int32_t ret = 0;
    size_t i = 0;

    BUFFER_T *buffer = buffer_malloc(BUFFER_DEFUALT_SIZE);
    if (NULL != buffer) return -1;

    for (i = 0; i < 10 ; i ++) {
        ret = buffer_push_by_index(buffer, i, (int64_t)i);
        if (ret != 0) {
            LOG("test failed, buffer_push_by_index failed\n");
            return ret;
        }
    }
    buffer_print(buffer);

    ret = buffer_push_by_index(buffer, 5, 10);
    if (ret != 0) return ret;

    ret = buffer_remove_element(buffer, 5);
    if (ret != 0) return ret;
    buffer_print(buffer);

    for (i = 0; i < 500; i ++) {
        ret = buffer_push_by_index(buffer, i, (int64_t)i);
        if (ret != 0) {
            LOG("test failed, buffer_push_by_index failed\n");
            return ret;
        }
    }
    buffer_print(buffer);
    buffer_free(buffer);

    return ret;
}