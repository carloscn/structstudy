#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "buffer.h"
#include "utils.h"

struct buffer_t {
    int64_t *data;
    size_t current_len;
    size_t total_len;
};

BUFFER_T* buffer_malloc(size_t sz)
{
    BUFFER_T* buffer = (BUFFER_T*)malloc(sizeof(BUFFER_T));
    if (NULL == buffer) {
        LOG("buffer malloc is NULL\n");
        return buffer;
    }

    if (sz != 0) {
        buffer->data = (int64_t *)malloc(sizeof(int64_t) * sz);
        if (NULL == buffer->data) {
            goto err;
        }
        memset(buffer->data, 0, sizeof(int64_t) * sz);
    } else {
        buffer->data = NULL;
    }
    buffer->total_len = sz;
    buffer->current_len = 0;

    return buffer;
err:
    free(buffer);
    return NULL;
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

size_t buffer_get_current_len(BUFFER_T *buffer)
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
    int64_t i = 0;

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
    //memcpy(buffer->data + index + 1 , buffer->data + index, buffer->current_len - index);
    for (i = (int64_t)buffer->current_len - 1; i >= (int64_t)index; i --) {
        *(buffer->data + i + 1) = *(buffer->data + i);
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

bool buffer_is_equal(BUFFER_T *a, BUFFER_T *b)
{
    if (NULL == a ||
        NULL == b ||
        a->current_len != b->current_len) {
        return false;
    }

    return memcmp(a->data, b->data, a->current_len * sizeof(int64_t)) == 0;
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

bool buffer_find(BUFFER_T *buffer, size_t *index, int64_t e)
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
    bool ret_b = false;
    size_t index = 0;
    ret_b = buffer_find(buffer, &index, e);
    if (!ret_b) {
        LOG("find e=%lld failed\n", e);
        return -1;
    }
    ret = buffer_pop_by_index(buffer, index, NULL);
    if (ret != 0) {
        LOG("find e= %lld failed\n", e);
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
    printf(" [ ");
    for (i = 0; i < buffer->current_len; i ++) {
        printf("%lld, ", buffer->data[i]);
    }
    printf("]\n");
}

int32_t buffer_copy(BUFFER_T *dest, BUFFER_T *src)
{
    int32_t ret = 0;
    size_t i = 0;

    UTILS_CHECK_PTR(dest);
    UTILS_CHECK_PTR(src);

    if (dest->total_len < src->current_len) {
        return -1;
    }

    ret = buffer_clear(dest);
    UTILS_CHECK_RET(ret);

    memcpy(dest->data, src->data, src->current_len * sizeof(int64_t));
    dest->current_len = src->current_len;

finish:
    return ret;
}

int32_t buffer_clear(BUFFER_T *buffer)
{
    int32_t ret = 0;

    UTILS_CHECK_PTR(buffer);

    memset(buffer->data, 0, buffer->total_len);
    buffer->current_len = 0;

finish:
    return ret;
}

int32_t buffer_dup(BUFFER_T *buffer, BUFFER_T **out)
{
    int32_t ret = 0;

    UTILS_CHECK_PTR(buffer);
    UTILS_CHECK_PTR(out);

    *out = buffer_malloc(buffer_get_current_len(buffer) + 1);
    UTILS_CHECK_PTR(*out);

    ret = buffer_copy(*out, buffer);
    UTILS_CHECK_RET(ret);

finish:
    return ret;
}

int32_t buffer_dup_array(BUFFER_T* buffer, int64_t **array, size_t *o_len)
{
    int32_t ret = 0;
    int64_t *buf_array = NULL;

    UTILS_CHECK_PTR(buffer);
    UTILS_CHECK_PTR(array);

    buf_array = (int64_t*)calloc(sizeof(int64_t), buffer->current_len);
    UTILS_CHECK_PTR(buf_array);

    memcpy(buf_array, buffer->data, buffer->current_len * sizeof(int64_t));

    if (o_len != NULL)
        *o_len = buffer->current_len;
    *array = buf_array;

finish:
    return ret;
}

int32_t buffer_soft_to_array(BUFFER_T *buffer, int64_t **array, size_t *o_len)
{
    int32_t ret = 0;

    UTILS_CHECK_PTR(buffer);
    UTILS_CHECK_PTR(array);
    UTILS_CHECK_PTR(o_len);

    *o_len = buffer->current_len;
    *array = buffer->data;

finish:
    return ret;
}

int64_t* buffer_soft_to_array_2(BUFFER_T *buffer)
{
    int32_t ret = 0;
    int64_t *ret_p = NULL;

    UTILS_CHECK_PTR(buffer);

    ret = buffer_soft_to_array(buffer, &ret_p, NULL);
    if (ret != 0) {
        ret_p = NULL;
    }

finish:
    return ret_p;
}

int32_t buffer_append_array(BUFFER_T *buffer, const int64_t *array, size_t len)
{
    int32_t ret = 0;
    int64_t *ptr = NULL;

    UTILS_CHECK_PTR(buffer);
    UTILS_CHECK_PTR(array);
    UTILS_CHECK_LEN(len);

    if (buffer->total_len - buffer->current_len < len) {
        ptr = (int64_t*)realloc(buffer->data, (buffer->total_len + len + BUFFER_DEFUALT_SIZE) * sizeof(int64_t));
        UTILS_CHECK_PTR(ptr);
        buffer->data = ptr;
        buffer->total_len = buffer->total_len + len + BUFFER_DEFUALT_SIZE;
    }

    memcpy(buffer->data + buffer->current_len, array, len * sizeof(int64_t));
    buffer->current_len += len;

finish:
    return ret;
}

int64_t buffer_sum(BUFFER_T *buffer)
{
    int32_t ret = 0;
    size_t i = 0;
    int64_t sum_out = 0;

    for (i = 0; i < buffer->current_len; i ++) {
        sum_out += buffer->data[i];
    }

    return sum_out;
}

int32_t buffer_selftest(void)
{
    int32_t ret = 0;
    size_t i = 0;

    BUFFER_T *buffer = NULL;
    buffer= buffer_malloc(20);
    if (NULL == buffer) return -1;

    for (i = 0; i < 10 ; i ++) {
        ret = buffer_push_by_index(buffer, i, (int64_t)0xffff);
        if (ret != 0) {
            LOG("test failed, buffer_push_by_index failed\n");
            return ret;
        }
    }
    buffer_print(buffer);
    ret = buffer_push_by_index(buffer, 5, 10);
    if (ret != 0) return ret;
    buffer_print(buffer);
    ret = buffer_remove_element(buffer, 10);
    if (ret != 0) return ret;
    buffer_print(buffer);

    for (i = 0; i < 20; i ++) {
        ret = buffer_push_head(buffer, (int64_t)i);
        if (ret != 0) {
            LOG("test failed, buffer_push_by_index failed\n");
            return ret;
        }
    }
    for (i = 0; i < 20; i ++) {
        ret = buffer_push_tail(buffer, (int64_t)i);
        if (ret != 0) {
            return ret;
        }
    }
    buffer_print(buffer);
    buffer_free(buffer);

    return ret;
}