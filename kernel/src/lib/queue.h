#ifndef QUEUE_H_
#define QUEUE_H_

#define QUEUE_MAX_SIZE 256

#include <lib.h>

typedef struct {
    int items[QUEUE_MAX_SIZE];
    int front;
    int rear;
    bool is_full;
} Queue;


bool queue_is_empty(Queue* q);

bool queue_is_full(Queue* q);

bool queue_enqueue(Queue* q, int value);

int queue_drop(Queue* q);

int queue_peek(Queue* q);

void queue_print(Queue* q);

#endif // QUEUE_H_
