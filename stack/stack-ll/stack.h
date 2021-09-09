#ifndef DATA_STRUCTURES_STACK_H
#define DATA_STRUCTURES_STACK_H

typedef struct Node Node;

struct Node {
    int value;
    Node *next;
};

typedef struct {
    Node *top;
    int size;
} Stack;

Stack *create();

void push(Stack *stack, int value);

int pop(Stack *stack);

int top(Stack *stack);

int isEmpty(Stack *stack);

int getSize(Stack *stack);

void print(Stack *stack);

void freeStack(Stack *stack);

#endif //DATA_STRUCTURES_STACK_H
