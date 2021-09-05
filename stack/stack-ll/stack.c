#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

Stack *
create()
{
    Stack *stack;

    stack = malloc(sizeof(Stack));
    stack->size = 0;
    stack->top = NULL;
    return stack;
}

void
push(Stack *stack, int value)
{
    Node *node;

    node = malloc(sizeof(Node));
    node->value = value;
    node->next = NULL;

    if (isEmpty(stack)) {
        stack->top = node;
    } else {
        node->next = stack->top;
        stack->top = node;
    }
    ++stack->size;
}

int
pop(Stack *stack)
{   
    int value;
    Node *tmp;

    if (isEmpty(stack)) {
        perror("Stack is empty");
        exit(1);
    }

    tmp = stack->top;
    value = tmp->value;
    stack->top = stack->top->next;

    free(tmp);
    tmp = NULL;

    --stack->size;
    return value;
}

int
top(Stack *stack)
{
    return stack->top->value;
}

int
isEmpty(Stack *stack)
{
    return stack->size == 0;
}

int
getSize(Stack *stack)
{
    return stack->size;
}

void
print(Stack *stack)
{
    Node *tmp;

    tmp = stack->top;
    
    printf("<");
    if (tmp) {
        for (;tmp->next; tmp = tmp->next) {
            printf("%d, ", tmp->value);
        }
        printf("%d", tmp->value);
    }

    printf(">\n");
}

void
freeStack(Stack *stack)
{   
    Node *tmp;

    while(stack->top) {
        tmp = stack->top;
        stack->top = stack->top->next;

        free(tmp);
    }

    free(stack);
}
