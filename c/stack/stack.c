//
// Created by Ao Wang on 9/2/21.
//

#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

enum {
    CAPACITY = 64
};

Stack *
create() {
    Stack *stack;

    stack = malloc(sizeof(Stack));
    stack->capacity = CAPACITY;
    stack->top = -1;
    stack->array = malloc(sizeof(int) * CAPACITY);
    return stack;
}

void
push(Stack *stack, int value) {
    if (getSize(stack) >= stack->capacity) {
        resize(&stack);
        printf("Increased capacity to %d elements\n", stack->capacity);
    }
    stack->array[++stack->top] = value;
}

int
pop(Stack *stack) {
    if (isEmpty(stack)) {
        perror("Stack is empty");
        exit(1);
    }
    return stack->array[stack->top--];
}

int
top(Stack *stack) {
    if (isEmpty(stack)) {
        perror("Stack is empty");
        exit(1);
    }
    return stack->array[stack->top];
}

int
isEmpty(Stack *stack) {
    return stack->top == -1;
}

int
getSize(Stack *stack) {
    return stack->top + 1;
}

void
resize(Stack **stack) {
    (*stack)->array = realloc((*stack)->array, (*stack)->capacity *= 2);
}

void
print(Stack *stack) {
    int i;

    printf("<");
    for (i = stack->top; i > 0; --i) {
        printf("%d, ", stack->array[i]);
    }

    if (i >= 0) {
        printf("%d", stack->array[i]);
    }
    printf(">\n");
}

void
freeStack(Stack *stack) {
    free(stack->array);
    stack->array = NULL;
    
    free(stack);
    stack = NULL;
}
