#include <stdio.h>
#include "stack.h"

int
main()
{
    Stack *stack;
    int i;

    stack = create();
    for (i = 0; i < 10; ++i) {
        push(stack, i);
    }

    printf("size: %d\n", getSize(stack));
    printf("top: %d\n", top(stack));
    print(stack);

    pop(stack);
    pop(stack);
    
    printf("size: %d\n", getSize(stack));
    printf("top: %d\n", top(stack));
    print(stack);

    freeStack(stack);
}
