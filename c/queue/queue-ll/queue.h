#ifndef DATA_STRUCTURES_QUEUE_H
#define DATA_STRUCTURES_QUEUE_H

typedef struct Node Node;

struct Node {
    int value;
    Node *next;
};

typedef struct {
    Node *head, *tail;
    int size;
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
