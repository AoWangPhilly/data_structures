#include <stdio.h>
#include <stdlib.h>
#include "queue.h"


int
main()
{
    Queue *q;
    int i;

    q = create();
    for (i = 0; i < 10; ++i) {
        enqueue(q, i);
    }
    
    print(q);
    freeQueue(q);
}

