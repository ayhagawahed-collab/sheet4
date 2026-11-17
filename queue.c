#include "queue.h"

/* Circular queue */
void CreateQueue(Queue *q) {
    q->front = 0;
    q->rear  = -1;
    q->size  = 0;
}

int QueueEmpty(const Queue *q) {
    return q->size == 0;
}

int QueueFull(const Queue *q) {
    return q->size == MAX_SIZE;
}

int QueueSize(const Queue *q) {
    return q->size;
}

int Enqueue(element_type e, Queue *q) {
    if (QueueFull(q)) return 0;
    q->rear = (q->rear + 1) % MAX_SIZE;
    q->items[q->rear] = e;
    q->size++;
    return 1;
}

int Dequeue(element_type *e, Queue *q) {
    if (QueueEmpty(q)) return 0;
    *e = q->items[q->front];
    q->front = (q->front + 1) % MAX_SIZE;
    q->size--;
    return 1;
}
