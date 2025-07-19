#include "queue.h"

#include <stdlib.h>

Queue* queue_create(free_function free_func)
{
    Queue* queue = calloc(1, sizeof(Queue));
    return queue;
}

void queue_destroy(Queue* queue)
{
    if (queue)
    {
        queue_clear(queue);
        free(queue);
    }
}
void queue_clear(Queue* queue)
{
    if (queue)
    {
        QueueItem *current = queue->head;
        while (current)
        {
            QueueItem *next = current->next;
            if (queue->free_func != NULL)
            {
                queue->free_func(current->data);
            }
            // free(current);
        }
    }
}

bool queue_is_empty(Queue* queue)
{
    if (queue != NULL)
    {
        return queue->size == 0;
    }
    else
    {
        return false; // For now, if the queue is NULL, we retrun false.
    }
}

void queue_push(Queue* queue, void* data)
{
    if (queue == NULL)
    {
        return; // TODO: handle error
    }
    
}
void* queue_pop(Queue* queue);
void* queue_peek(Queue* queue);