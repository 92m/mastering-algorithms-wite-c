#ifndef QUEUE_H
#define QUEUE_H

#include "list.h"

/* Implement queue as linked lists. */
typedef List Queue;

/* Public Interface */
#define queue_init list_init

#define queue_destroy list_destroy

int queue_enqueue(Queue *queue, const void *data);

int queue_dequeue(Queue *queue, void **data);

#define queue_peek(queue) ((queue)->head == NULL ? NULL : (queue)->head)->data)

#define queue_size list_size

#endif /* QUEUE_H */