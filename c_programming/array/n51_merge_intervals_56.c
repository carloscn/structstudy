#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "utils.h"
#include "stack.h"
#include "bufferlist.h"

static int32_t merge_two_element(BUFFER_T *a_buf,
                                 BUFFER_T *b_buf,
                                 BUFLIST_T **out)
{
    int32_t ret = 0;
    int64_t a_l = 0, a_r = 0;
    int64_t b_l = 0, b_r = 0;

    UTILS_CHECK_PTR(out);

    if (NULL == a_buf && NULL == b_buf) {
        ret = -1;
        goto finish;
    }

    *out = buflist_malloc();
    UTILS_CHECK_PTR(*out);

    if (NULL == a_buf && NULL != b_buf) {
        if (buffer_get_current_len(b_buf) != 2) {
            LOG("the b_buf len is not 2!\n");
            ret = -1;
        } else {
            ret = buflist_add(*out, b_buf);
        }
        goto finish;
    }

    if (NULL != a_buf && NULL == b_buf) {
        if (buffer_get_current_len(a_buf) != 2) {
            ret = -1;
            LOG("the a_buf len is not 2!\n");
        } else {
            ret = buflist_add(*out, a_buf);
        }
        goto finish;
    }

    if (buffer_get_current_len(a_buf) != 2 ||
        buffer_get_current_len(b_buf) != 2) {
        ret = -1;
        LOG("the buf len is not 2 != %zu!\n", buffer_get_current_len(a_buf));
        goto finish;
    }

    ret = buffer_get_by_index(a_buf, 0, &a_l);
    UTILS_CHECK_RET(ret);
    ret = buffer_get_by_index(a_buf, 1, &a_r);
    UTILS_CHECK_RET(ret);
    ret = buffer_get_by_index(b_buf, 0, &b_l);
    UTILS_CHECK_RET(ret);
    ret = buffer_get_by_index(b_buf, 1, &b_r);
    UTILS_CHECK_RET(ret);

    // a is []
    // b is {}
    // case1 : [ { } ]  -> []
    // case2 : { [ ] }  -> {}
    // case3 : { [ } ]  -> {]
    // case4 : [ { ] }  -> [}
    // case5 : { } [ ]  -> {}, []
    // case{6 : [ ] { }  -> [], {}
    // a_l = [
    // a_r = ]
    // b_l = {
    // b_r = }

    // case1 : [ { } ]  -> []
    if (b_l >= a_l && b_r <= a_r) {
        int64_t buffer[2] = {a_l, a_r};
        ret = buflist_append_array(*out, buffer, 2);
        UTILS_CHECK_RET(ret);
    // case2 : { [ ] }  -> {}
    } else if (a_l >= b_l && a_r <= b_r) {
        int64_t buffer[2] = {b_l, b_r};
        ret = buflist_append_array(*out, buffer, 2);
        UTILS_CHECK_RET(ret);
    // case3 : { [ } ]  -> {]
    } else if (a_l <= b_r && a_l >= b_l && b_r <= a_r) {
        int64_t buffer[2] = {b_l, a_r};
        ret = buflist_append_array(*out, buffer, 2);
        UTILS_CHECK_RET(ret);
    // case4 : [ { ] }  -> [}
    } else if (b_l >= a_l && b_l <= a_r && a_r <= b_r) {
        int64_t buffer[2] = {a_l, b_r};
        ret = buflist_append_array(*out, buffer, 2);
        UTILS_CHECK_RET(ret);
    // case5 : { } [ ]  -> {}, []
    } else if (b_r < a_l) {
        int64_t buffer[2] = {b_l, b_r};
        ret = buflist_append_array(*out, buffer, 2);
        UTILS_CHECK_RET(ret);
        buffer[0] = a_l, buffer[1] = a_r;
        ret = buflist_append_array(*out, buffer, 2);
        UTILS_CHECK_RET(ret);
    // case6 : [ ] { }  -> [], {}
    } else if (a_r < b_l) {
        int64_t buffer[2] = {a_l, a_r};
        ret = buflist_append_array(*out, buffer, 2);
        UTILS_CHECK_RET(ret);
        buffer[0] = b_l, buffer[1] = b_r;
        ret = buflist_append_array(*out, buffer, 2);
        UTILS_CHECK_RET(ret);
    }

finish:
    return ret;
}

static int32_t merge_intervals(BUFLIST_T* b_list, BUFLIST_T *out_list)
{
    int32_t ret = 0;
    size_t i = 0;
    size_t len = 0;
    BUFFER_T *a = NULL;
    BUFFER_T *b = NULL;
    BUFLIST_T *ret_list = NULL;

    UTILS_CHECK_PTR(b_list);
    UTILS_CHECK_PTR(out_list);
    UTILS_CHECK_LEN(len = buflist_get_size(b_list));

    for (i = 0; i < len; i ++) {
        BUFLIST_T *temp_list = NULL;
        b = buflist_get_buffer_at(b_list, i);
        UTILS_CHECK_PTR(b);
        ret = merge_two_element(a, b, &temp_list);
        UTILS_CHECK_RET(ret);
        LOG("the i is %zu, and the merged is ", i);
        buflist_infolog(temp_list);

        buffer_free(a), a = NULL;

        if (buflist_get_size(temp_list) == 2) {
            ret = buflist_add(out_list, buflist_get_buffer_at(temp_list, 0));
            UTILS_CHECK_RET(ret);
            a = buflist_get_buffer_dup_at(temp_list, 1);
            UTILS_CHECK_PTR(a);
        } else if (buflist_get_size(temp_list) == 1) {
            a = buflist_get_buffer_dup_at(temp_list, 0);
            UTILS_CHECK_PTR(a);
        } else {
            LOG("error branch!\n");
            while(1);
        }
        buflist_free(temp_list);
    }

    ret = buflist_add(out_list, a);
    UTILS_CHECK_RET(ret);

finish:
    buffer_free(a);
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;
    BUFLIST_T *in = NULL;
    BUFLIST_T *out = NULL;
    int64_t buf[2] = {1, 3};

    in = buflist_malloc();
    UTILS_CHECK_PTR(in);

    ret = buflist_append_array(in, buf, 2);
    UTILS_CHECK_RET(ret);

    buf[0] = 2, buf[1] = 6;
    ret = buflist_append_array(in, buf, 2);
    UTILS_CHECK_RET(ret);

    buf[0] = 8, buf[1] = 10;
    ret = buflist_append_array(in, buf, 2);
    UTILS_CHECK_RET(ret);

    buf[0] = 15, buf[1] = 18;
    ret = buflist_append_array(in, buf, 2);
    UTILS_CHECK_RET(ret);

    buflist_infolog(in);

    out = buflist_malloc();
    UTILS_CHECK_PTR(out);

    ret = merge_intervals(in, out);
    UTILS_CHECK_RET(ret);

    buflist_infolog(out);

finish:
    buflist_free(out);
    buflist_free(in);
    return ret;
}