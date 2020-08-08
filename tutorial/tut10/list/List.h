// Interface for a list Abstract Data Type (ADT)
// Author: UNSW CSE & Finbar Berkon
// Date: November 2019

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define TRUE 1
#define FALSE 0

struct node {
    int data;
    struct node *next;
};

typedef struct node *Node;

// given two linked lists, add list2 to the end of list1 so that they form a
// single linked list, and return the head of that list
Node list_append(Node list1, Node list2);

// given a linked list, create a copy of the list, and return the head of the 
// new list
// Note: the list should duplicate every node in memory not just provide 
// duplicate pointers to the same list
Node copy(Node head);

// given two linked lists, determine if they are identical, returning TRUE or 
// FALSE accordingly
int identical(struct node *head1, struct node *head2);

// given a linked list, determine whether it is in strictly increasing order, 
// returning TRUE or FALSE accordingly
int ordered(struct node *head);

// given two lists in strictly increasing order, return a new linked list (in 
// strictly increasing order) of the elements in both set1 and set2
Node set_intersection(Node set1, Node set2);

// given two linked lists in strictly increasing order, return a new linked list
// (in strictly increasing order) of the elements in either set1 or set2 - no 
// duplicates (only include them once)
Node set_union(Node set1, Node set2);

//============================================================================//
//=========== Functions to allow us to interact with the list ADT ============//

// creates a struct node with the given data value
// returns a pointer to this node
Node create_node(int data);

// given an array of integer values for data items
// returns the head of a linked list with these values
// in the order as they appear in the array
// size gives the size of the array
Node create_list(char **argv, int size);

// prints out the list given the head of a list
void print_list(Node head);

// frees all the elements in a linked list
void free_list(Node head);

// return the number of items in the linked list
int num_items(Node head);
