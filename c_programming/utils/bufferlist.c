#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"
#include "bufferlist.h"

BUFLIST_T* buflist_malloc(void)
{
    BUFLIST_T *buflist = NULL;

    buflist = (BUFLIST_T*)malloc(sizeof(BUFLIST_T));
    if (NULL == buflist) {
        goto finish;
    }
    memset(buflist, 0, sizeof(BUFLIST_T));

finish:
    return buflist;
}

int32_t buflist_add(BUFLIST_T *buflist, BUFFER_T *buf)
{
    int32_t ret = 0;
    size_t sz = 0;
    BUFFER_T **p = NULL;

    UTILS_CHECK_PTR(buflist);
    UTILS_CHECK_PTR(buf);

    sz = buflist->size + 1;

    p = (BUFFER_T **)realloc(buflist->list, sz * sizeof(BUFFER_T*));
    UTILS_CHECK_PTR(p);

    p[buflist->size] = buffer_malloc(buffer_get_current_len(buf));
    UTILS_CHECK_PTR(p[buflist->size]);

    ret = buffer_copy(*(p + buflist->size), buf);
    UTILS_CHECK_RET(ret);

    buflist->list = p;
    buflist->size = sz;

finish:
    p = NULL;
    return ret;
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
    free(buflist);
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

    p = (BUFFER_T **)realloc(buflist->list, sz * sizeof(BUFFER_T*));
    UTILS_CHECK_PTR(p);

    for(i = buflist->size; i > index + 1; i --){
        p[i] = p[i - 1];
    }

    p[index + 1] = buffer_malloc(buffer_get_current_len(buf));
    UTILS_CHECK_PTR(p[index + 1]);

    ret = buffer_copy(*(p + index + 1), buf);
    UTILS_CHECK_RET(ret);

    buflist->list = p;
    buflist->size = sz;

finish:
    p = NULL;
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
    BUFLIST_T *buflist = NULL;
    BUFFER_T *buffer1 = NULL;
    BUFFER_T *buffer2 = NULL;
    BUFFER_T *buffer3 = NULL;
    BUFFER_T *buffer4 = NULL;
    BUFFER_T *buffer5 = NULL;

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

    buflist_infolog(buflist);
finish:
    buflist_free(buflist);
    return 0;
}