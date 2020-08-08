// Linked list stack implementation and visualisation by Finbar Berkon
// October 2018

#include "Item.h"

typedef struct _stack *Stack;

Stack newStack(void);
void push(Stack s, Item data);
Item pop(Stack s);
int StackEmpty(Stack s);