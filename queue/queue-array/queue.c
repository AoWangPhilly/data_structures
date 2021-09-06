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
    queue->size = 0;
    queue->array = malloc(sizeof(int) * queue->capacity);

    return queue;
}

void
enqueue(Queue *queue, int value)
{
    int tail;
    if (queue->head == -1) {
        queue->array[++queue->head] = value;
        ++queue->tail;
    } else {
        tail = (queue->tail + 1) % queue->capacity
        if (tail != queue->head) {
            queue->array[tail] = value;
        } else {
            
        }
        
    }
}

int
dequeue(Queue *queue)
{

}

int
isEmpty(Queue *queue)
{
    return queue->size == 0;
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