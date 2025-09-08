#include "hashmap.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

hash_map *hash_map_init(size_t size)
{
    hash_map *hash_map = malloc(sizeof(struct hash_map));
    if (!hash_map)
        return NULL;

    hash_map->data = calloc(size, sizeof(pair_list *));
    if (!hash_map->data)
    {
        free(hash_map);
        return NULL;
    }

    hash_map->size = size;
    return hash_map;
}

bool hash_map_insert(hash_map *hash_map, const char *key, char *value,
                     bool *updated)
{
    if (!hash_map || hash_map->size == 0)
        return false;

    *updated = false;
    size_t index = hash(key) % hash_map->size;
    pair_list *current = hash_map->data[index];

    while (current)
    {
        if (strcmp(current->key, key) == 0)
        {
            current->value = value;
            if (updated)
                *updated = true;
            return true;
        }
        current = current->next;
    }

    pair_list *new_pair = malloc(sizeof(pair_list));
    if (!new_pair)
        return false;

    new_pair->key = key;
    new_pair->value = value;
    new_pair->next = hash_map->data[index];
    hash_map->data[index] = new_pair;

    if (updated)
        *updated = false;
    return true;
}

void hash_map_free(hash_map *hash_map)
{
    if (!hash_map)
        return;

    for (size_t i = 0; i < hash_map->size; i++)
    {
        pair_list *current = hash_map->data[i];
        while (current)
        {
            pair_list *next = current->next;
            free(current);
            current = next;
        }
    }

    free(hash_map->data);
    free(hash_map);
}

void hash_map_dump(hash_map *hash_map)
{
    if (!hash_map || hash_map->size == 0)
        return;
    for (size_t i = 0; i < hash_map->size; i++)
    {
        pair_list *current = hash_map->data[i];
        if (current == NULL)
        {
            continue;
        }

        printf("%s: %s", current->key, current->value);
        pair_list *pair = current->next;
        for (; pair != NULL; pair = pair->next)
        {
            printf(", %s: %s", pair->key, pair->value);
        }

        printf("\n");
    }
}

const char *hash_map_get(const hash_map *hash_map, const char *key)
{
    if (!hash_map || hash_map->size == 0)
        return NULL;

    size_t index = hash(key) % hash_map->size;
    pair_list *current = hash_map->data[index];
    while (current)
    {
        if (strcmp(current->key, key) == 0)
            return current->value;
        current = current->next;
    }
    return NULL;
}

bool hash_map_remove(hash_map *hash_map, const char *key)
{
    if (!hash_map || hash_map->size == 0)
        return false;

    size_t index = hash(key) % hash_map->size;
    pair_list *current = hash_map->data[index];
    pair_list *prev = NULL;

    while (current)
    {
        if (strcmp(current->key, key) == 0)
        {
            if (prev)
                prev->next = current->next;
            else
                hash_map->data[index] = current->next;

            free(current);
            return true;
        }
        prev = current;
        current = current->next;
    }
    return false;
}
