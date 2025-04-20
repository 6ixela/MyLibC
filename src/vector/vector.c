#include "vector.h"

#include <stdlib.h>

void vector_init(vector *vec, free_function free_function)
{
    vec->capacity = VECTOR_INIT_CAPACITY;
    vec->size = 0;
    vec->items = malloc(sizeof(void *) * vec->capacity);
    vec->free_function = free_function;
}

static void vector_resize(vector *vec, int capacity)
{
    void **items = realloc(vec->items, sizeof(void *) * capacity);
    if (items != NULL)
    {
        vec->items = items;
        vec->capacity = capacity;
    }
}

void vector_add(vector *vec, void *data)
{
    if (vec->capacity == vec->size)
    {
        vector_resize(vec, vec->capacity * 2);
    }
    vec->items[vec->size++] = data;
}

void vector_set(vector *vec, int index, void *data)
{
    if (index >= 0 && index < vec->size)
    {
        vec->items[index] = data;
    }
}

void *vector_get(vector *vec, int index)
{
    if (index >= 0 && index < vec->size)
    {
        return vec->items[index];
    }
    return NULL;
}

void vector_delete(vector *vec, int index)
{
    if (index < 0 || index >= vec->size)
    {
        return;
    }
    vec->items[index] = NULL;
    for (int i = index; i < vec->size - 1; i++)
    {
        vec->items[i] = vec->items[i + 1];
    }
    
    vec->size--;
    if (vec->size > 0 && vec->size == vec->capacity / 4)
    {
        vector_resize(vec, vec->capacity / 2);
    }
}

void *vector_pop(vector *vec)
{
    int index = vec->size - 1;
    void *data = vector_get(vec, index);
    vector_delete(vec, index);
    return data;
}

void vector_free(vector *vec)
{
    if (vec->items != NULL)
    {
        if (vec->free_function != NULL)
        {
            for (int i = 0; i < vec->size; i++)
            {
                vec->free_function(vec->items[i]);
            }
        }
        free(vec->items);
        vec->items = NULL;
    }
    vec->capacity = 0;
    vec->size = 0;
}