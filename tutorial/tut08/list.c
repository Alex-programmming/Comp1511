// Author: Finbar Berkon
// Date: November 2019
// Create linked lists

#include <stdio.h>
#include <stdlib.h>

struct overall {
    struct node *start;
};

struct node {
    int data;
    struct node *next;
};

struct node *new_node(int data);
void insert_at_end(struct overall *o, int data);

int main(void) {
    /* Make a new 'struct overall' pointer called 'list' which we will use to 
     * keep track of the start and end of our linked list */
    struct overall *o = malloc(sizeof(struct overall));

    /* Ensure malloc succeeded and exit the program otherwise. Here, we'll print
     * out an error message, then exit our program with an exit status of 1 */
    if (o == NULL) {
        printf("Error: malloc failed\n");
        return 1;
    }

    /* Initialise all of the values inside the struct as soon as we know it was
     * successfully created */
    o->start = NULL;

    /* Add some values to our linked list */
    insert_at_end(o, 5);
    insert_at_end(o, 8);
    insert_at_end(o, 2);
    
    return 0;
}

/* Create a new node with the specified data value and return a pointer to that
 * new node */
struct node *new_node(int data) {
    struct node *new;
    new = malloc(sizeof(struct node));
    new->data = data;
    new->next = NULL;
    return new;    
}

void insert_at_end(struct overall *o, int data) {
    struct node *new = new_node(data);
    
    struct node *curr = o->start;
    
    // We have an empty list)
    if (curr == NULL) {
        o->start = new;
    } else {
        while (curr->next != NULL) {
            curr = curr->next;
        }
        
        curr->next = new;
    }
    // Are there any edge cases we should be aware of?
}
