#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

typedef void (* free_function)(void *);

typedef struct QueueItem {
    void *data;
    QueueItem *next;
} QueueItem;

typedef struct Queue {
	QueueItem* head;
	int size;
    free_function free_func;
} Queue;


Queue* queue_create(free_function free_func);
void queue_destroy(Queue* queue);
void queue_clear(Queue* queue);

bool queue_is_empty(Queue* queue);

void queue_push(Queue* queue, void* data);
void* queue_pop(Queue* queue);
void* queue_peek(Queue* queue);

#endif /* QUEUE_H */
