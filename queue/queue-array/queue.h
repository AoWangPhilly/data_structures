//
// Created by Ao Wang on 9/4/21.
//

#ifndef DATA_STRUCTURES_QUEUE_H
#define DATA_STRUCTURES_QUEUE_H

typedef struct {
    int tail, head;
    int capacity, size;
    int *array;
} Queue;


Queue *create();

void enqueue(Queue *queue, int value);

int dequeue(Queue *queue);

int getSize(Queue *queue);

int isEmpty(Queue *queue);

int front(Queue *queue);

void print(Queue *queue);

void freeQueue(Queue *queue);

#endif //DATA_STRUCTURES_QUEUE_H