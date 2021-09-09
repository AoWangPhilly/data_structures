//
// Created by Ao Wang on 9/2/21.
//

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int
main() {
    Stack *stack;
    int i;

    stack = create();

    for (i = 0; i < 10; ++i) {
        push(stack, i);
    }
    printf("size: %d\n", getSize(stack));
    printf("capacity: %d\n", stack->capacity);
    printf("top: %d\n", top(stack));
    print(stack);

    freeStack(stack);
}
