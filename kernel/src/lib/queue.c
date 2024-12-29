#include "queue.h"

#include <stdio.h>

/* void queue_initializeQueue (Queue* q) { */
/*     q->rear = 0; */
/*     q->front = 0; */
/* } */

bool queue_is_empty (Queue* q) {
    return (q->rear == q->front) && (!q->is_full);
}

bool queue_is_full (Queue* q) {
    return q->is_full;
}

bool queue_enqueue (Queue* q, int value) {
    if (queue_is_full(q)) {
        return false;
    }
    q->items[q->rear] = value;
    q->rear = (q->rear+1) % QUEUE_MAX_SIZE;
    if (q->rear == q->front)
        q->is_full = true;

    return true;
}

int queue_drop (Queue* q) {
    if (queue_is_empty(q)) {
        return 0;
    }
    int ret = queue_peek(q);
    q->front = (q->front+1) % QUEUE_MAX_SIZE;
    q->is_full = false;
    return ret;
}


int queue_peek (Queue* q) {
    if (queue_is_empty(q)) {
        return 0;
    }
    return q->items[q->front];
}

void queue_print (Queue* q) {
    if (queue_is_empty(q)) {
        printf("Queue is empty\n");
        return;
    }

    printf("Current Queue:\n");
    for (int i = q->front; i != q->rear; i=(i+1) % QUEUE_MAX_SIZE) {
        printf("%d: %d\n", i, q->items[i]);
    }
    printf("\n");
}
