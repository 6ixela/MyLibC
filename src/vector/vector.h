#ifndef VECTOR_H
#define VECTOR_H

#define VECTOR_INIT_CAPACITY 8

typedef void (*free_function)(void *ptr);

typedef struct vector {
    void **items;
    int capacity;
    int size;
    free_function free_function;
} vector;

void vector_init(vector *vec, free_function free_function);
void vector_add(vector *vec, void *data);
void vector_set(vector *vec, int, void *data);
void *vector_get(vector *vec, int index);
void vector_delete(vector *vec, int index);
void *vector_pop(vector *vec);
void vector_free(vector *vec);

#endif /* VECTOR_H */