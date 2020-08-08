// Main file for Queue Abstract Data Type demo
// Marc Chee, July 2019

#include <stdio.h>
#include "queue.h"

int main(void) {
    printf("Creating the Queue for Ice Cream.\n");
    Queue iceQueue = queueCreate();
    int id = 1;
    printf("Person %d joins the queue!\n", id);
    queueAdd(iceQueue, id);
    id = 2;
    printf("Person %d joins the queue!\n", id);
    queueAdd(iceQueue, id);
    id = 3;
    printf("Person %d joins the queue!\n", id);
    queueAdd(iceQueue, id);
    
    printf("Person %d just got their ice cream!\n", queueRemove(iceQueue));
    printf("Person %d just got their ice cream!\n", queueRemove(iceQueue));
    printf("Person %d just got their ice cream!\n", queueRemove(iceQueue));
    return 0;
}
