#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

Queue *
create()
{
    Queue *queue;

    queue = malloc(sizeof(Queue));
    queue->head = queue->tail = NULL;
    queue->size = 0;
}

void
enqueue(Queue *queue, int value)
{
    Node *node;

    node = malloc(sizeof(Node));
    node->value = value;
    node->next = NULL;

    if (isEmpty(queue)) {
        queue->head = queue->tail = node;
    } else {
        queue->tail->next = node;
        queue->tail = node;
    }

    ++queue->size;
}

int 
dequeue(Queue *queue)
{
    Node *tmp;
    int front;

    if (isEmpty(queue)) {
        perror("Queue is empty");
        exit(1);
    }
    
    tmp = queue->head;
    front = tmp->value;

    queue->head = queue->head->next;
    
    free(tmp);
    --queue->size;
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
front(Queue *queue)
{
    return queue->head->value;
}

void
print(Queue * queue)
{
    Node *tmp;
    
    tmp = queue->head;

    printf("<");
    if (tmp) {
        while (tmp->next) {
            printf("%d, ", tmp->value);
            tmp = tmp->next;
        }

        printf("%d", tmp->value);
    }
    printf(">\n");
}

void
freeQueue(Queue *queue)
{
    Node *tmp;
    
    tmp = queue->head;
    while (tmp) {
        queue->head = queue->head->next;
        free(tmp);
        tmp = NULL;

        tmp = queue->head;
    }
    free(queue);
}