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

    for (i = 0; i < 9; ++i) {
        dequeue(q);
    }
    printf("head: %d\ntail: %d\ncap: %d\n", q->head, q->tail, q->capacity);

    for (i = 0; i < 20; ++i) {
        enqueue(q, i);
    }
    printf("\nhead: %d\ntail: %d\ncap: %d\nsize: %d\n", q->head, q->tail, q->capacity, getSize(q));
    print(q);
    freeQueue(q);
}

