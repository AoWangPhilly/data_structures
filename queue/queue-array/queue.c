#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

enum {
    CAPACITY = 8
};

Queue *
create()
{
    Queue *q;

    q = malloc(sizeof(Queue));
    q->head = q->size = 0;
    q->tail = -1;
    q->capacity = CAPACITY;
    q->array = malloc(CAPACITY * sizeof(int));
    return q;
}

void
enqueue(Queue * queue, int value)
{
    if (isFull(queue)) {
        resize(queue);
    }
    queue->tail = (queue->tail + 1) % queue->capacity;
    queue->array[queue->tail] = value;
    ++queue->size;
}

int
dequeue(Queue *queue)
{   
    int front;
    if (isEmpty(queue)) {
        perror("Queue is empty");
        exit(1);
    }

    front = queue->array[queue->head];
    --queue->size;
    if (queue->size == 0) {
        queue->head = 0;
        queue->tail = -1;
    } else {
        queue->head = (queue->head + 1) % queue->capacity;
    }
    
    return front;
}


int
getSize(Queue *queue)
{
    return queue->size;
}

int
isEmpty(Queue *queue)
{
    return getSize(queue) == 0;
}

int
isFull(Queue *queue)
{
    return getSize(queue) == queue->capacity;
}

int
front(Queue *queue)
{
    if (isEmpty(queue)) {
        perror("Queue is empty");
        exit(1);
    }
    return queue->array[queue->head];
}

void
print(Queue *queue)
{
    int head = queue->head;
    printf("<");
    if (!isEmpty(queue)) {
        while (head != queue->tail) {
            // printf("head: %d\n", head);
            printf("%d, ", queue->array[head]);
            head = (head + 1) % queue->capacity;
        }
        printf("%d", queue->array[head]);
    }
    printf(">\n");
}

void
resize(Queue *queue)
{
    int *tmp;
    int i;

    tmp = malloc(2 * queue->capacity * sizeof(int));

    for (i = 0; !isEmpty(queue); ++i) {
        tmp[i] = dequeue(queue);
    }

    free(queue->array);
    queue->capacity *= 2;
    queue->array = tmp;
    queue->head = 0;
    queue->tail = i - 1;
    queue->size = i;
}

void
freeQueue(Queue *queue)
{
    free(queue->array);
    queue->array = NULL;

    free(queue);
    queue = NULL;
}

