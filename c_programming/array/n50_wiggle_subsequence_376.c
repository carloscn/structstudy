#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "utils.h"
#include "bufferlist.h"

static int32_t get_wiggle_count(const int64_t *array, size_t len, size_t *result)
{
    int32_t ret = 0;
    size_t i = 0;
    bool is_positive = 0;
    bool except = 0;

    UTILS_CHECK_LEN(len);
    UTILS_CHECK_PTR(array);
    UTILS_CHECK_PTR(result);

    is_positive = array[1] > array[0];
    for (i = 1; i < len - 1; i ++) {
        except = !is_positive;
        is_positive = array[i + 1] > array[i];
        if (is_positive != except) {
            break;
        }
    }

    *result = i + 1;

finish:
    return ret;
}

static int32_t max_wiggle_sub(const int64_t *array, size_t len, size_t *out)
{
    int32_t ret = 0;
    size_t i = 0;
    int64_t *p = NULL;
    size_t p_len = 0;
    BUFLIST_T *buflist = NULL;
    BUFFER_T *buf = NULL;
    size_t c_wig_count = 0;
    size_t max_wig_count = 0;
    size_t max_index = 0;

    UTILS_CHECK_LEN(len);
    UTILS_CHECK_PTR(array);
    UTILS_CHECK_PTR(out);

    buf = buffer_malloc(BUFFER_DEFUALT_SIZE);
    UTILS_CHECK_PTR(buf);

    ret = buffer_append_array(buf, array, len);
    UTILS_CHECK_RET(ret);

    buflist = buflist_malloc();
    UTILS_CHECK_PTR(buflist);

    ret = buflist_append_all_sub_arrays_by_buffer(buflist, buf);
    UTILS_CHECK_RET(ret);

    // buflist_infolog(buflist);

    for (i = buflist_get_size(buflist) - 1; i > 0; i --) {
        ret = buffer_soft_to_array(buflist_get_buffer_at(buflist, i), &p, &p_len);
        UTILS_CHECK_RET(ret);
        ret = get_wiggle_count(p, p_len, &c_wig_count);
        UTILS_CHECK_RET(ret);
        max_wig_count = (c_wig_count > max_wig_count) ?
                        (max_index = i, c_wig_count):
                        (max_wig_count);
    }

    *out = buffer_get_current_len(buflist_get_buffer_at(buflist, max_index));

finish:
    buffer_free(buf);
    buflist_free(buflist);
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;
    int64_t array[] = {1,17,5,10,13,15,10,5,16,8};
    size_t res = 0;

    ret = max_wiggle_sub(array, ARRAY_SIZE(array), &res);
    UTILS_CHECK_RET(ret);

    LOG("the result is %zu\n", res);

finish:
    return ret;
}