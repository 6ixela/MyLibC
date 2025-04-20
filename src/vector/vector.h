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

/**
 * Initializes a vector with a custom free function.
 *
 * @param vec Pointer to the vector to initialize.
 * @param free_function Free function to use for the vector's elements.
 */
void vector_init(vector *vec, free_function free_function);

/**
 * Adds an element to the end of the vector.
 *
 * @param vec Pointer to the vector.
 * @param data Pointer to the data to add.
 */
void vector_add(vector *vec, void *data);

/**
 * Replaces the element at a specific index in the vector.
 *
 * @param vec Pointer to the vector.
 * @param index Index of the element to replace.
 * @param data Pointer to the new data.
 */
void vector_set(vector *vec, int index, void *data);

/**
 * Retrieves the element at a specific index in the vector.
 *
 * @param vec Pointer to the vector.
 * @param index Index of the element to retrieve.
 * @return Pointer to the element's data.
 */
void *vector_get(vector *vec, int index);

/**
 * Deletes the element at a specific index in the vector.
 *
 * @param vec Pointer to the vector.
 * @param index Index of the element to delete.
 */
void vector_delete(vector *vec, int index);

/**
 * Removes and returns the last element of the vector.
 *
 * @param vec Pointer to the vector.
 * @return Pointer to the data of the removed element.
 */
void *vector_pop(vector *vec);

/**
 * Frees the memory allocated for the vector and its elements.
 *
 * @param vec Pointer to the vector to free.
 */
void vector_free(vector *vec);


#endif /* VECTOR_H */