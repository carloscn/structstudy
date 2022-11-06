#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "hash_map.h"
#include "utils.h"

static int32_t hashnode_init(HASH_NODE_T *node, const char *key, int64_t val)
{
    int32_t ret = 0;
    char *t_key = NULL;

    UTILS_CHECK_PTR(node);
    if (NULL != key) {
        t_key = (char *)malloc(strlen(key) + 1);
        UTILS_CHECK_PTR(t_key);
        strcpy(t_key, key);
    }
    node->key = t_key;
    node->next = NULL;
    node->value = val;

finish:
    return ret;
}

HASH_MAP_T* hashmap_malloc(size_t sz)
{
    int32_t ret = 0;
    HASH_MAP_T *mp = NULL;
    size_t i = 0;

    mp = (HASH_MAP_T *)malloc(sizeof(HASH_MAP_T));
    if (NULL == mp) {
        LOG("hash map table create failed on malloc\n");
        return NULL;
    }

    mp->table = (HASH_NODE_T *)malloc(sizeof(HASH_NODE_T) * sz);
    if (NULL == mp->table) {
        LOG("hash map node create failed on malloc\n");
        free(mp);
        return NULL;
    }

    mp->capacity = sz;
    for (i = 0; i < sz; i ++) {
        ret = hashnode_init(&mp->table[i], NULL, 0);
        if (0 != ret) {
            LOG("hash mp init failed\n");
            free(mp);
            free(mp->table);
        }
    }

    return mp;
}

void hashmap_free(HASH_MAP_T *mp)
{
    HASH_NODE_T *head = NULL, *tail = NULL;
    HASH_NODE_T *temp = NULL;
    size_t i = 0;

    if (NULL == mp)
        return;
    for (i = 0; i < mp->capacity; i ++) {
        head = &mp->table[i];
        tail = head->next;
        while (tail) {
            temp = tail;
            tail = tail->next;
            free(temp->key);
            free(temp);
            temp = NULL;
        }
    }
    free(mp->table);
    mp->table = NULL;
    free(mp);
    mp = NULL;
}

static size_t hash(const char *str, size_t table_size)
{
    size_t hash_value = 0;

    while (*str != '\0') {
        hash_value += (hash_value << 5) + *str++;
    }

    return hash_value % table_size;
}

int32_t hashmap_push(HASH_MAP_T *mp, const char *key, int64_t value)
{
    int32_t ret = 0;
    HASH_NODE_T *head = NULL, *tail = NULL, *prev = NULL;

    UTILS_CHECK_PTR(mp);
    UTILS_CHECK_PTR(key);

    head = &mp->table[hash(key, mp->capacity)];
    tail = head->next;
    prev = head;

    while (tail) {
        if (strcmp(key, tail->key) == 0) {
            tail->value = value;
            goto finish;
        }
        tail = tail->next;
        prev = prev->next;
    }

    head = NULL;
    head = (HASH_NODE_T *)malloc(sizeof(HASH_NODE_T));
    UTILS_CHECK_PTR(head);

    ret = hashnode_init(head, key, value);
    if (0 != ret) {
        LOG("hashnode_init failed\n");
        free(head);
        goto finish;
    }
    prev->next = head;

finish:
    return ret;
}

/*
 * Returns the value to which the specified key is mapped,
 * or -1 if this map contains no mapping for the key.
 */
int32_t hashmap_get(HASH_MAP_T *mp, const char *key, int64_t *out_val)
{
    int32_t ret = 0;
    HASH_NODE_T *head = NULL, *tail = NULL;

    UTILS_CHECK_PTR(mp);
    UTILS_CHECK_PTR(key);
    UTILS_CHECK_PTR(out_val);

    head = &mp->table[hash(key, mp->capacity)];
    tail = head->next;

    while (tail) {
        if (strcmp(key, tail->key) == 0) {
            *out_val = tail->value;
            goto finish;
        }
        tail = tail->next;
    }
    ret = -1;

finish:
    return ret;
}

/*
 * Removes the mapping of the specified value key
 * if this map contains a mapping for the key.
 */
int32_t hashmap_delete(HASH_MAP_T *mp, const char *key, int64_t *out_val)
{
    int32_t ret = 0;
    HASH_NODE_T *head = NULL, *tail = NULL, *prev = NULL;

    UTILS_CHECK_PTR(mp);
    UTILS_CHECK_PTR(key);
    UTILS_CHECK_PTR(out_val);

    head = &mp->table[hash(key, mp->capacity)];
    tail = head->next;
    prev = head;

    while (tail) {
        if (strcmp(key, tail->key) == 0) {
            prev->next = tail->next;
            *out_val = tail->value;
            free(tail);
            tail = NULL;
            goto finish;
        }
        tail = tail->next;
        prev = prev->next;
    }
    ret = -1;

finish:
    return ret;
}

int32_t hashmap_selftest()
{
    int32_t ret = 0;
    int64_t val = 0;

    HASH_MAP_T *hash_map = NULL;
    hash_map = hashmap_malloc(HASH_MAP_DEFAULT_SIZE);
    UTILS_CHECK_PTR(hash_map);

    ret = hashmap_push(hash_map, "my_a", 1);
    UTILS_CHECK_RET(ret);

    ret = hashmap_push(hash_map, "my_b", 2);
    UTILS_CHECK_RET(ret);

    ret = hashmap_push(hash_map, "my_c", 3);
    UTILS_CHECK_RET(ret);

    ret = hashmap_get(hash_map, "my_a", &val);
    if (ret == -1) {
        LOG("not found key mapping value\n");
    } else if (ret == 0) {
        LOG("get the value is %lld\n", val);
    } else {
        LOG("failed get\n");
    }

    ret = hashmap_delete(hash_map, "my_a", &val);
    if (ret == -1) {
        LOG("not found key mapping value\n");
    } else if (ret == 0) {
        LOG("delete the value is %lld\n", val);
    } else {
        LOG("failed get\n");
    }

    ret = hashmap_get(hash_map, "my_a", &val);
    if (ret == -1) {
        LOG("not found key mapping value\n");
    } else if (ret == 0) {
        LOG("get the value is %lld\n", val);
    } else {
        LOG("failed get\n");
    }

    ret = hashmap_push(hash_map, "my_a", val);
    UTILS_CHECK_RET(ret);
    LOG("push my_a value to 1\n");

    ret = hashmap_get(hash_map, "my_a", &val);
    if (ret == -1) {
        LOG("not found key mapping value\n");
    } else if (ret == 0) {
        LOG("get the value is %lld\n", val);
    } else {
        LOG("failed get\n");
    }

finish:
    hashmap_free(hash_map);
    return ret;
}