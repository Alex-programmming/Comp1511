// Interface for a list Abstract Data Type (ADT)
// Author: Finbar Berkon
// Date: November 2019

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "List.h"

// creates a struct node with the given data value
// returns a pointer to this node
struct node *create_node(int data) {
    struct node *new = malloc(sizeof(struct node));
    assert(new != NULL);
    new->data = data;
    new->next = NULL;

    return new;
}

// given two linked lists, add list2 to the end of list1 so that they form a
// single linked list, and return the head of that list
Node list_append(Node list1, Node list2) {
    if (list1 == NULL) {
        return list2;
    }
    
    Node curr = list1;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    
    curr->next = list2;
    
    return list1;
}

// given a linked list, create a copy of the list, and return the head of the 
// new list
// Note: the list should duplicate every node in memory not just provide 
// duplicate pointers to the same list
Node copy(Node head) {
    if (head == NULL) {
        return NULL;
    }
    
    // Create a copy of the head node
    Node new_head = create_node(head->data);
    
    // And keep track of the last new node we have created
    Node last_new_node = new_head;
    
    Node curr = head->next;
    while (curr != NULL) {
        // Make a copy of the current node
        last_new_node->next = create_node(curr->data);
        
        // Iterate along on both lists
        last_new_node = last_new_node->next;
        curr = curr->next;
    }
    // If we did this without a new node function, we might need to set 
    // last_new_node to NULL here, but because our create_node() function
    // does this, we don't need to it again.
    
    return new_head;
}

// given two lists, determine if they are identical, returning TRUE or FALSE 
// accordingly
int identical(Node head1, Node head2) {
    // TODO implement this function and change return value
    return FALSE;
}

// given a linked list, determine whether it is in strictly increasing order, 
// returning TRUE or FALSE accordingly
int ordered(Node head) {
    // TODO implement this function and change return value
    return FALSE;
}

// given two lists in strictly increasing order, return a new linked list (in 
// strictly increasing order) of the elements in both set1 and set2
Node set_intersection(Node set1, Node set2) {
    // TODO implement this function and change return value
    return NULL;
}

// given two linked lists in strictly increasing order, return a new linked list
// (in strictly increasing order) of the elements in either set1 or set2 - no 
// duplicates (only include them once)
Node set_union(Node set1, Node set2) {
    // TODO implement this function and change return value
    return NULL;
}
