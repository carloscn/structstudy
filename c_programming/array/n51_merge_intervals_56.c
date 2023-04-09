#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "utils/utils.h"
#include "utils/stack.h"
#include "utils/bufferlist.h"

static int32_t merge_two_element(const BUFFER_T *a_buf,
                                 const BUFFER_T *b_buf,
                                 BUFLIST_T **out)
{
    int32_t ret = 0;
    int64_t a_l = 0, a_r = 0;
    int64_t b_l = 0, b_r = 0;

    UTILS_CHECK_PTR(a_buf);
    UTILS_CHECK_PTR(b_buf);
    UTILS_CHECK_PTR(out);

    if (buffer_get_current_len(a_buf) != 2 ||
        buffer_get_current_len(b_buf) != 2) {
        ret = -1;
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

    *out = buflist_malloc();
    UTILS_CHECK_PTR(*out);

    // a is []
    // b is {}
    // case1 : [ { } ]  -> []
    // case2 : { [ ] }  -> {}
    // case3 : { [ } ]  -> {]
    // case4 : [ { ] }  -> [}
    // case5 : { } [ ]  -> {}, []
    // case6 : [ ] { }  -> [], {}

    if (a_l <= b_l && a_r <= b_r) {
        int64_t buffer[2] = {a_l, a_r};
        ret = buflist_append_array(*out, buffer, 2);
        UTILS_CHECK_RET(ret);
    } else if (a_l >= b_l && a_r >= b_r) {
        int64_t buffer[2] = {b_l, b_r};
        ret = buflist_append_array(*out, buffer, 2);
        UTILS_CHECK_RET(ret);
    } else if (b_r >= a_l) {
        int64_t buffer[2] = {a_l, b_r};
        ret = buflist_append_array(*out, buffer, 2);
        UTILS_CHECK_RET(ret);
    } else if (b_l < a_r) {
        int64_t buffer[2] = {a_l, b_r};
        ret = buflist_append_array(*out, buffer, 2);
        UTILS_CHECK_RET(ret);
    } else if (b_r < a_l) {
        int64_t buffer[2] = {b_l, b_r};
        ret = buflist_append_array(*out, buffer, 2);
        UTILS_CHECK_RET(ret);
        buffer[0] = a_l, buffer[1] = a_r;
        ret = buflist_append_array(*out, buffer, 2);
        UTILS_CHECK_RET(ret);
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

static int32_t merge_intervals(const BUFLIST_T* b_list, BUFLIST_T *out_list)
{
    int32_t ret = 0;
    size_t i = 0;
    size_t len = 0;

    UTILS_CHECK_PTR(b_list);
    UTILS_CHECK_PTR(out_list);
    UTILS_CHECK_LEN(len = buflist_get_size(b_list));

    BUFLIST_T *ret_list = buflist_malloc();
    UTILS_CHECK_PTR(ret_list);

    BUFFER_T *a = NULL;
    BUFFER_T *b = NULL;
    for (i = 0; i < len - 1; i ++) {
        BUFLIST_T *temp_list = NULL;
        b = buflist_get_buffer_at(b_list, i);
        ret = merge_two_element(a, b, &temp_list);
        UTILS_CHECK_RET(ret);

        buffer_free(a);
        if (buflist_get_size(temp_list) == 2) {
            ret = buflist_add(ret_list, buflist_get_buffer_dup_at(temp_list, 0));
            UTILS_CHECK_RET(ret);
            a = buflist_get_buffer_dup_at(temp_list, 1);
        } else {
            a = buflist_get_buffer_dup_at(temp_list, 0);
        }
        buflist_free(temp_list);
    }

    ret = buflist_add(ret_list, a);
    UTILS_CHECK_RET(ret);

finish:
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;
    int64_t array[] = {1,17,5,10,13,15,10,5,16,8};
    size_t res = 0;

    UTILS_CHECK_RET(ret);

    LOG("the result is %zu\n", res);

finish:
    return ret;
}