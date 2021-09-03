//
// Created by Ao Wang on 9/2/21.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "stack.h"

int
main() {
    Stack *stack;
    int i;

    srand(time(0));
    stack = create();

    for (i = 0; i < 10; ++i) {
        push(stack, rand());
    }
    printf("size: %d\n", getSize(stack));
    printf("capacity: %d\n", stack->capacity);
    print(stack);
    printf("top: %d\n\n", top(stack));

    for (i = 0; i < 10; ++i) {
        pop(stack);
    }
    printf("size: %d\n", getSize(stack));
    printf("capacity: %d\n", stack->capacity);
    print(stack);
}
