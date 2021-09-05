#include <stdlib.h>
#include <stdio.h>
#include "queue.h"


enum {
    CAPACITY = 16
};

Queue*
create()
{
    Queue *queue;

    queue = malloc(sizeof(Queue));

    queue->tail = queue->head = -1;
    queue->capacity = CAPACITY;
    queue->array = malloc(sizeof(int) * queue->capacity);

    return queue;
}

void
enqueue(Queue *queue, int value)
{
    if (queue->head < 0) {
        queue->array[++queue->head] = value;
        ++queue->tail;
    } else if (queue->head != 0 && queue->tail == queue->capacity - 1) {
        queue->tail = 0;
        queue->array[queue->tail] = value;
    } else {
        queue->array[++queue->tail] = value;
    }
}

int
dequeue(Queue *queue)
{
    if (queue->head < queue->tail) {
        return queue->array[queue->head++];
    }

    
}

int
isEmpty(Queue *queue)
{
    return queue->head > queue->tail;
}


void
print(Queue *queue)
{
    Queue *tmp;

    tmp = queue;

    printf("<");
    while(!isEmpty(queue)) {
        printf("%d, ", dequeue(queue));
    }

    printf(">\n");
}