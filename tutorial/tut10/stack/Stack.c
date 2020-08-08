// Linked list stack implementation and visualisation by Finbar Berkon
// October 2018

#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

// This is a regular linked list like you've seen before
typedef struct _node {
    // this is where you put your data. I am using 'Item', but it can be anything
    Item data;
    struct _node *next;
} node; // This makes 'node' mean 'struct _node' (ie you can malloc sizeof(node)

// This makes 'Node' mean 'node *' (ie it is a pointed and you shouldn't malloc
// sizeof(Node) because it will only allocate space for a pointer
typedef node *Node;

// It is a little funny to declare a struct to hold just one value, but you
// will see why we do this down at the bottom of this file (where I explain it)
typedef struct _stack {
    Node top;
} stack; // these typedefs do the same as above

// Read the explanation above the function implementations below
void push(Stack s, Item data);
Item pop(Stack s);

Stack newStack(void) {
    Stack s = malloc(sizeof(stack));
    s->top = NULL;
    return s;
}

// Given a stack and some data (here its an int, but it can be anything), make
// a new node with that data and add it to the top of the list
void push(Stack s, Item data)
{
    /*
    Let the initial stack be:
       top
     ___|___        _______        _______ 
    |   1   |____\ |   3   |____\ |   5   |____\ NULL
    |_______|    / |_______|    / |_______|    / 
    and the value to be pushed is 10
    */
    Node tmp;
    tmp = malloc(sizeof(node));
    tmp -> data = data;
    /*
     The above lines will make a new node like this:
     _______ 
    |   10  |
    |_______|
    */
    tmp -> next = s->top;
    /*
    The above line will put the node at the start of the list like this:
                      top
     _______        ___|___        _______       _______
    |   10  |____\ |   1   |____\ |   3   |____\| 5     |____\ NULL
    |_______|    / |_______|    / |_______|    /|_______|    /
    */
    s->top = tmp;
    /*
    The above line will update the top of the list like this:
       top               
     ___|___        _______        _______       _______
    |   10  |____\ |   1   |____\ |   3   |____\| 5     |____\ NULL
    |_______|    / |_______|    / |_______|    /|_______|    /
    */
}

// 'pop' an item off the stack, freeing the node it was in, updating the top of
// the stack and returning the value
Item pop(Stack s) {
    // variables to store our temp node so we can free it and the data from the
    // freed node
    Node tmp;
    Item data;

    /*
    Imagine the stack currently looks like this:
       top               
     ___|___        _______        _______       _______
    |   10  |____\ |   1   |____\ |   3   |____\| 5     |____\ NULL
    |_______|    / |_______|    / |_______|    /|_______|    /
    */

    // save the data from the node we're about to pop off so we can return it
    data = s->top->data;

    tmp = s->top;

    /*
    Now tmp and top point to the same thing (so we don't loose the node!)
    
     tmp top               
     _|___|_        _______        _______       _______
    |   10  |____\ |   1   |____\ |   3   |____\| 5     |____\ NULL
    |_______|    / |_______|    / |_______|    /|_______|    /
    */

    s->top = s->top->next;

    /*
    Now we move top over to the next node
    
       tmp            top   
     ___|___        ___|___        _______       _______
    |   10  |____\ |   1   |____\ |   3   |____\| 5     |____\ NULL
    |_______|    / |_______|    / |_______|    /|_______|    /
    */


    free(tmp);
    /*
    after freeing, the top in our Stack s (s->top) looks like this
    
       top   
     ___|___        _______       _______
    |   1   |____\ |   3   |____\| 5     |____\ NULL
    |_______|    / |_______|    /|_______|    /
    
    Note that we can actually change what is inside Stack s AND return data from
    the function because the pointer to the Stack we called 'p' never changes
    so we can still access what is in s->top outside this function but we have
    changed what 'top' inside the Struct s points to.
    */

    return data;
}

int StackEmpty(Stack s) {
    return (s->top == NULL);
}