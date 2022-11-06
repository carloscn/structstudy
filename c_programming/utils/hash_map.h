#ifndef _HASH_MAP
#define _HASH_MAP

#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

#define HASH_MAP_DEFAULT_SIZE (1024U)

typedef struct hash_node_t {
    char *key;
    int64_t value;
    struct hash_node_t *next;
} HASH_NODE_T;

typedef struct hash_map_t {
    struct hash_node_t *table;
    size_t capacity;
} HASH_MAP_T;

HASH_MAP_T* hashmap_malloc(size_t sz);
void hashmap_free(HASH_MAP_T *mp);
int32_t hashmap_push(HASH_MAP_T *mp, const char *key, int64_t value);
int32_t hashmap_get(HASH_MAP_T *mp, const char *key, int64_t *out_val, bool *state);
int32_t hashmap_delete(HASH_MAP_T *mp, const char *key, int64_t *out_val, bool *state);
int32_t hashmap_selftest();

#endif /* _HASH_MAP */