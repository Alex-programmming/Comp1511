// Implementation of queue.h

#include <stdlib.h>
#include <assert.h>

#include "queue.h"

// queueInternals holds the queue itself
struct queueInternals {
    struct queueNode *head;
    struct queueNode *tail;
};

// linked list node for storing queue items
struct queueNode {
    int data;
    struct queueNode *next;
};

// Declarations of Helper Functions
static struct queueNode *createNode(int item);

Queue queueCreate() {
    Queue newQueue = malloc(sizeof(struct queueInternals));
    assert(newQueue != NULL);
    newQueue->head = NULL;
    newQueue->tail = NULL;
    return newQueue;
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
}

// return the int from the head of the list
// remove head node from list
int queueRemove(Queue q) {
    int result = q->head->data;
    
    struct queueNode *remNode = q->head;
    q->head = q->head->next;
    free(remNode);
    
    return result;
}

// Helper function that creates a node
static struct queueNode *createNode(int item) {
    struct queueNode *newNode = malloc(sizeof(struct queueNode));
    newNode->data = item;
    newNode->next = NULL;
    return newNode;
}




