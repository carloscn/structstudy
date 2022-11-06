#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include "hash_map.h"
#include "utils.h"
#include "linklist.h"

//
//           5 -> 7
//                |
//                V
//      1 -> 2 -> 3 -> 4 -> 5 -> NULL
static int32_t find_intersection_in_loop(LINKLIST_T *list1, LINKLIST_T *list2, int64_t *out_val)
{
    int32_t ret = 0;
    LINKLIST_T *list1_current_node = list1;
    LINKLIST_T *list2_current_node = list2;

    UTILS_CHECK_PTR(list1);
    UTILS_CHECK_PTR(list2);
    UTILS_CHECK_PTR(out_val);

    while (list1_current_node->next != NULL) {
        while (list2_current_node->next != NULL) {
            if (list1_current_node == list2_current_node) {
                *out_val = list1_current_node->val;
                goto finish;
            }
            list2_current_node = list2_current_node->next;
        }
        list2_current_node = list2->next;
        list1_current_node = list1_current_node->next;
    }

    LOG("no intersection point.\n");
    *out_val = 0xFFFF;

finish:
    return ret;
}

static int32_t find_intersection_in_double_pointer(LINKLIST_T *list1, LINKLIST_T *list2, int64_t *out_val)
{
    int32_t ret = 0;
    size_t count = 0;
    LINKLIST_T *list1_current_node = list1;
    LINKLIST_T *list2_current_node = list2;

    UTILS_CHECK_PTR(list1);
    UTILS_CHECK_PTR(list2);
    UTILS_CHECK_PTR(out_val);

    while ((list1_current_node != list2_current_node)) {
        list1_current_node = (NULL != list1_current_node) ? (list1_current_node->next) : (list2);
        list2_current_node = (NULL != list2_current_node) ? (list2_current_node->next) : (list1);

        // anti no intersection linked lists
        if ((NULL == list1_current_node) ||
            (NULL == list2_current_node)) {
            count ++;
            if (count > 2) {
                LOG("no intersection point.\n");
                *out_val = 0xFFFF;
                goto finish;
            }
        }
    }

    *out_val = list1_current_node->val;

finish:
    return ret;
}

static int32_t find_intersection_in_hash_map(LINKLIST_T *list1, LINKLIST_T *list2, int64_t *out_val)
{
    int32_t ret = 0;
    size_t count = 0;
    LINKLIST_T *current_node = list1;
    HASH_MAP_T *hash_map = NULL;
    char *hash_key = NULL;
    int64_t val = 0;

    UTILS_CHECK_PTR(list1);
    UTILS_CHECK_PTR(list2);
    UTILS_CHECK_PTR(out_val);

    hash_map = hashmap_malloc(1000);
    UTILS_CHECK_PTR(hash_map);

    while (NULL != current_node) {
        ret = utils_int64_convert_str((int64_t)current_node, &hash_key);
        UTILS_CHECK_RET(ret);

        ret = hashmap_push(hash_map, hash_key, current_node->val);
        UTILS_CHECK_RET(ret);

        current_node = current_node->next;

        free(hash_key);
        hash_key = NULL;
    }

    current_node = list2;
    while (NULL != current_node) {
        ret = utils_int64_convert_str((int64_t)current_node, &hash_key);
        UTILS_CHECK_RET(ret);

        ret = hashmap_get(hash_map, hash_key, &val);
        if (0 == ret) {
            *out_val = val;
            goto finish;
        }

        current_node = current_node->next;

        free(hash_key);
        hash_key = NULL;
    }
    ret = 0;
    LOG("no intersection point.\n");
    *out_val = 0xFFFF;

finish:
    if (NULL != hash_key) {
        free(hash_key);
    }
    hashmap_free(hash_map);
    return ret;
}

int main(void)
{
    int32_t ret = 0;
    LINKLIST_T *list1 = NULL, *list2 = NULL, *t_list = NULL;
    const int64_t buffer1[] = {1, 1, 4, 8, 9, 23, 25};
    const int64_t buffer2[] = {1, 2, 3, 4, 5, 6, 9, 10};
    int64_t val = 0;

    printf("\nthe list 1: \n-----------------------------------\n");
    ret = linklist_append_array(&list1, buffer1, ARRAY_SIZE(buffer1));
    UTILS_CHECK_RET(ret);
    linklist_print(list1);

    printf("\n\n\nthe list 2: \n-----------------------------------\n");
    ret = linklist_append_array(&list2, buffer2, ARRAY_SIZE(buffer2));
    UTILS_CHECK_RET(ret);
    linklist_print(list2);

    ret = find_intersection_in_loop(list1, list2, &val);
    UTILS_CHECK_RET(ret);
    LOG("loop method: the common value is %lld\n", val);

    ret = find_intersection_in_double_pointer(list1, list2, &val);
    UTILS_CHECK_RET(ret);
    LOG("double pointer method: the common value is %lld\n", val);

    ret = find_intersection_in_hash_map(list1, list2, &val);
    UTILS_CHECK_RET(ret);
    LOG("hash map method: the common value is %lld\n", val);

    // create intersection linkedlist;
    t_list = list2;
    while (t_list->next != NULL) {
        t_list = t_list->next;
    }
    t_list->next = list1->next->next->next;

    ret = find_intersection_in_loop(list1, list2, &val);
    UTILS_CHECK_RET(ret);
    LOG("the common value is %lld\n", val);

    ret = find_intersection_in_double_pointer(list1, list2, &val);
    UTILS_CHECK_RET(ret);
    LOG("double pointer method: the common value is %lld\n", val);

    ret = find_intersection_in_hash_map(list1, list2, &val);
    UTILS_CHECK_RET(ret);
    LOG("hash map method: the common value is %lld\n", val);

finish:
    linklist_free(&list1);
    t_list->next = NULL;
    linklist_free(&list2);
    return ret;
}