// Interface for a list Abstract Data Type (ADT)
// Author: Finbar Berkon
// Date: November 2019

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "List.h"

//============================================================================//
//==== Functions for us to implement to add functionality to our list ADT ====//

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

//============================================================================//
//=========== Functions to allow us to interact with the list ADT ============//

// creates a struct node with the given data value
// returns a pointer to this node
struct node *create_node(int data) {
    struct node *new = malloc(sizeof(struct node));
    assert(new != NULL);
    new->data = data;
    new->next = NULL;

    return new;
}

// reads command line arguments into 
// returns the head of a linked list with these values
// in the order as they appear in the array
// size gives the size of the array
struct node *create_list(char **argv, int size) {
    // So that we skip the name of the program which is always the first argument
    int i = 1;

    if (size <= 0) {
        // empty linked list (or invalid size)
        return NULL;
    }

    struct node *head = NULL;   // head of the linked list
    struct node *tmp = NULL;    // temporary item we're working with
    struct node *curr = NULL;   // current node we're looking at in the linked list

    while (i < size) {
        tmp = create_node(atoi(argv[i]));

        // link this node onto our list
        if (head == NULL) {
            // this is the first node in the list
            head = tmp;
            curr = head;
        } else {
            // this is not the first node in the list
            // add it to the end, i.e. after curr
            curr->next = tmp;

            // reset curr to point at the new last node
            curr = tmp;
        }
        i = i + 1;
    }

    return head;
}

// prints out the list given the head of a list
void print_list(struct node *head) {
    struct node *curr;
    curr = head;

    while (curr != NULL) {
        printf("[ %d ]-->", curr->data);
        curr = curr->next;
    }
    printf("X\n");
}

// frees all the elements in a linked list
void free_list(struct node *head) {
    if (head == NULL) {
        return;
    }
    free_list(head->next);
    free(head);
}

// return the number of items in the linked list
int num_items(struct node *head) {
    struct node *curr = head;
    int count = 0;

    while (curr != NULL) {
        count = count + 1;
        curr = curr->next;
    }

    return count;
}
