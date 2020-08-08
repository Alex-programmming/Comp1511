// Implementation of queue.h
// Marc Chee (cs1511@cse.unsw.edu.au), November 2019

#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

#include "queue.h"

// queueInternals holds the queue itself
struct queueInternals {
    struct queueNode *head;
    struct queueNode *tail;
    int size;
};

// linked list node for storing queue items
struct queueNode {
    int data;
    struct queueNode *next;
};

// Declarations of Helper Functions
static struct queueNode *createNode(int item);

// Create a new empty queue
Queue queueCreate() {
    Queue newQueue = malloc(sizeof(struct queueInternals));
    assert(newQueue != NULL);
    newQueue->head = NULL;
    newQueue->tail = NULL;
    newQueue->size = 0;
    return newQueue;
}

// Free all elements of the linked list
void queueFree(Queue q) {
    struct queueNode *curr = q->head;
    // free every node in the list
    while (curr != NULL) {
        struct queueNode *remNode = curr;
        curr = curr->next;
        free(remNode);
    }
    // free the queueInternals that was managing the list
    free(q);
}

// add item at the tail of the linked list
void queueAdd(Queue q, int item) {
    struct queueNode *newNode = createNode(item);
    if (q->tail == NULL) {
        // list is empty
        q->head = newNode;
        q->tail = newNode;
    } else {
        // list is not empty
        q->tail->next = newNode;
        q->tail = newNode;
    }
    q->size++;
}

// return the int from the head of the list
// remove head node from list
int queueRemove(Queue q) {
    if(q->head == NULL) {
        printf("Attempting to remove an item from an empty queue.\n");
        printf("Program will exit now.\n");
        exit(1);
    }
    int result = q->head->data;
    
    struct queueNode *remNode = q->head;
    q->head = q->head->next;
    free(remNode);
    
    q->size--;
    
    return result;
}

// return the value stored in q->size
int queueSize(Queue q) {
    return q->size;
}

// Helper function that creates a node
static struct queueNode *createNode(int item) {
    struct queueNode *newNode = malloc(sizeof(struct queueNode));
    newNode->data = item;
    newNode->next = NULL;
    return newNode;
}




