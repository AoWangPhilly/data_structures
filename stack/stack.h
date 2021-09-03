//
// Created by Ao Wang on 9/2/21.
//

#ifndef DATA_STRUCTURES_STACK_H
#define DATA_STRUCTURES_STACK_H

typedef struct stack stack;

struct stack {
    int capacity;
    int top;
    int *array;
};

stack *create();

void push(stack *stack, int value);

int pop(stack *stack);

int top(stack *stack);

int isEmpty(stack *stack);

int getSize(stack *stack);

#endif //DATA_STRUCTURES_STACK_H
