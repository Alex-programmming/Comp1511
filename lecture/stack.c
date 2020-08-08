// Implementation of stack.h
// Marc Chee (cs1511@cse.unsw.edu.au), November 2019

#include "stack.h"

#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

#define MAX_STACK_SIZE 4096

struct stackInternals {
    int stack[MAX_STACK_SIZE];
    int top;
};

// create an empty stack
Stack stackCreate() {
    Stack newStack = malloc(sizeof(struct stackInternals));
    assert(newStack != NULL);
    newStack->top = 0;
    
    return newStack;
}

// Add an element to the top of the stack, move top along
void stackPush(Stack s, int item) {
    if (s->top >= MAX_STACK_SIZE) {
        // array is full, top is outside the array
        printf("Maximum stack size reached, cannot push.\n");
        exit(1);
    } else {
        // array has space to store an item
        s->stack[s->top] = item;
        s->top++;
    }
}

// remove and return the int at the top of the stack
int stackPop(Stack s) {
    if (s->top <= 0) {
        // stack is empty
        printf("Cannot pop from empty stack.\n");
        exit(1);
    } else {
        s->top--;
        return s->stack[s->top];        
    }
}









