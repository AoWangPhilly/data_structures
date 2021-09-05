#include <stdio.h>
#include "queue.h"

int
main()
{
    Queue *queue;
    int i;

    queue = create();


    for(i = 0; i < 10; ++i) {
        enqueue(queue, i);
    }

    dequeue(queue);
    print(queue);
    dequeue(queue);
    // for(i = 0; i < 10; ++i) {
    //     printf("%d\n", dequeue(queue));
    // }

    // printf("head: %d, tail: %d\n", queue->head, queue->tail);
}
