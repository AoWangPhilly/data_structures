#ifndef STACK_H
#define STACK_H

typedef struct Node Node;

struct Node {
    char *line;
    Node *next;
};

typedef struct {
    Node *top;
    int size;
} Stack;

Stack *create();

void push(Stack *, char *);

char *pop(Stack *);

int isEmpty(Stack *);

#endif //STACK_H