#ifndef VECTOR_H
#define VECTOR_H

#define VECTOR_INIT_CAPACITY 8

typedef struct vector {
    void **items;
    int capacity;
    int size;
} vector;

void vector_init(vector *vec);
void vector_add(vector *vec, void *data);
void vector_set(vector *vec, int, void *data);
void *vector_get(vector *vec, int index);
void vector_delete(vector *vec, int index);
void vector_free(vector *vec);

#endif /* VECTOR_H */