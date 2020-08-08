#include <stdio.h>
#include "Stack.h"

int main(void)
{
    // Malloc our Stack called 's' and set initialise its values (here, to NULL)
    Stack s = newStack();

    printf("Pushing values onto the stack:\n");
    printf("pushing: 5\n");
    push(s, 5);
    printf("pushing: 3\n");
    push(s, 3);
    printf("pushing: 1\n");
    push(s, 1);
    printf("pushing: 10\n");
    push(s, 10); // notice this is the step explained below
    printf("pushing: 4\n");
    push(s, 4);
    printf("pushing: 7\n");
    push(s, 7);
    printf("pushing: 2\n");
    push(s, 2);

    printf("\nNow popping items back off the stack:\n");
    while (!StackEmpty(s)) {
        printf("popping: %d\n", pop(s));
    }
}