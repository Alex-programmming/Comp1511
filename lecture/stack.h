// Abstract Data Type Stack demo
// Marc Chee, April 2019

// This file describes the interface to a stack of ints
// It must be included in other code files to be of use

// ======================================================
// The type "stack" refers to a stack_internals pointer.
// In other files, programs can use stack, but they will
// not get direct access to the stack's internal workings
// nor will they know exactly what they are
typedef struct stackInternals *Stack;

// ======================================================
// These functions are the only way external code can
// manipulate a stack.

// functions to create and destroy stacks
Stack stackCreate();
void stackFree(Stack s);

// Add and remove items from stacks
// Removing the item returns the item for use
void stackPush(Stack s, int item);
int stackPop(Stack s);

// Check on the size of the stack
int stackSize(Stack s);
