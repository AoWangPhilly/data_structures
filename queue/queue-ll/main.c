#include <stdio.h>
#include "queue.h"

int
main()
{
    Queue *q;
    int i;

    q = create();

    for (i = 0; i < 3; ++i) {
        enqueue(q, i);
    }

    print(q);
    freeQueue(q);

}
