#include <stdio.h>
#include "Queue.h"

int main(void)
{
    Queue q = newQueue();

    printf("Adding new values to the queue:\n");
    printf("adding: 5\n");
    add(q, 5);
    printf("adding: 3\n");
    add(q, 3);
    printf("adding: 1\n");
    add(q, 1);
    printf("adding: 10\n");
    add(q, 10);
    printf("adding: 4\n");
    add(q, 4);
    printf("adding: 7\n");
    add(q, 7);
    printf("adding: 2\n");
    add(q, 2);

    printf("\nNow get items back off the queue:\n");
    while (!Empty(q)) {
        printf("dequeuing: %d\n", dequeue(s));
    }
}