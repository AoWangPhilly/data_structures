#include <stdio.h>
#include "stack.h"

int
main()
{
    Stack *s;
    int i;

    s = create();
    for (i = 0; i < 4; ++i) {
        push(s, i);
    }

    pop(s);
    pop(s);
    pop(s);
    pop(s);
    print(s); 
    freeStack(s);
}
