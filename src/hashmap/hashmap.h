#ifndef HASHMAP_H
#define HASHMAP_H

#include <stdbool.h>
#include <stddef.h>

typedef struct pair_list {
  const char *key;
  char *value;
  struct pair_list *next;
} pair_list;

typedef struct hash_map {
  pair_list **data;
  size_t size;
} hash_map;

size_t hash(const char *str);
hash_map *hash_map_init(size_t size);
bool hash_map_insert(hash_map *hash_map, const char *key, char *value,
                     bool *updated);
void hash_map_free(hash_map *hash_map);
void hash_map_dump(hash_map *hash_map);
const char *hash_map_get(const hash_map *hash_map, const char *key);
bool hash_map_remove(hash_map *hash_map, const char *key);

#endif /* HASHMAP_H */