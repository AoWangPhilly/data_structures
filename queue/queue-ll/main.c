#include <stdio.h>
#include "queue.h"

int
main()
{
    Queue *q;
    int i;

    q = create();

    for (i = 0; i < 5; ++i) {
        enqueue(q, i);
    }
    printf("size: %d\n", getSize(q));
    printf("empty?: %s\n", isEmpty(q) ? "yes" : "no");
    printf("front: %d\n", front(q));
    print(q);
    freeQueue(q);

}
