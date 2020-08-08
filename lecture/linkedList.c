// A demo of a basic linked list

// Marc Chee (marc.chee@unsw.edu.au), July 2019

#include <stdlib.h>
#include <stdio.h>

struct node {
    int data;
    struct node *next;
};

struct node *createNode(int data, struct node *next);
void printData(struct node* n);

int main (void) {
    // head will always point to the first element of our list
    struct node *head = createNode(1, NULL);
    head = createNode(2, head);
    head = createNode(3, head);
    head = createNode(4, head);
    head = createNode(5, head);
    
    printData(head);
    
    return 0;
}

// Create a node using the data and next pointer provided
// Return a pointer to this node
struct node *createNode(int data, struct node *next) {
    struct node *n;
    n = malloc(sizeof(struct node));
    if (n == NULL) {
        // malloc returns NULL if there isn't enough memory
        // terminate the program
        printf("Cannot allocate node. Program will exit.\n");
        exit(1);
    }
    n->data = data;
    n->next = next;
    return n;
}

// Loop through a list of nodes, printing out their data
void printData(struct node* n) {
    while (n != NULL) {
        printf("%d\n", n->data);
        n = n->next;
    }
}

