#include <stdio.h>
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

    for(i = 0; i < 10; ++i) {
        printf("%d, ", dequeue(q));
    }
    printf("\n");

}
