#include <stdlib.h>
#include <string.h>
#include "stack.h"

Stack *
create()
{
    Stack *s;

    s = malloc(sizeof(Stack));
    s->size = 0;
    s->top = NULL;
    return s;
}

void 
push(Stack *stack, char *line)
{
    Node *node;
    
    node = malloc(sizeof(Node));
    node->line = line;

    if (stack->top == NULL) {
        stack->top = node;
    } else {
        node->next = stack->top;
        stack->top = node;
    }
    ++stack->size;
}

char *
pop(Stack *stack)
{
    Node *tmp;
    char *line;

    tmp = stack->top;
    line = tmp->line;
    stack->top = stack->top->next;

    free(tmp);
    tmp = NULL;

    --stack->size;
    return line;
}

int
isEmpty(Stack *stack)
{
    return stack->size == 0;
}