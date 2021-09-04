//
// Created by Ao Wang on 9/2/21.
//

#ifndef DATA_STRUCTURES_STACK_H
#define DATA_STRUCTURES_STACK_H

typedef struct Stack Stack;

struct Stack {
    int capacity;
    int top;
    int *array;
};

Stack *create();

void push(Stack *stack, int value);

int pop(Stack *stack);

int top(Stack *stack);

int isEmpty(Stack *stack);

int getSize(Stack *stack);

void resize(Stack **stack);

void print(Stack *stack);

void freeStack(Stack *stack);

#endif //DATA_STRUCTURES_STACK_H
