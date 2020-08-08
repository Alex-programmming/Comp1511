
#include <stdio.h>
#include <stdlib.h>

struct node {
    Item data;
    struct node *next;
}

struct queue {
    struct node *head;
    struct node *tail;
}

#include "Queue.h"

Node newNode(Item item);

Queue newQueue() {
    Queue new = malloc(sizeof(struct queue));
    new->head = NULL;
    new->tail = NULL;
    return new;
}

Node newNode(Item item) {
    Node new = malloc(sizeof(struct node));
    new->data = item;
    new->next = NULL;
    return new;
}

void addItem(Queue q, Item data) {
    if (q == NULL) {
        return;
    }
    
    Node new = newNode(item);
    
    if (q->head == NULL) {
        q->head = new;
        q->tail = new;
        return;
    }
    
    Node curr = q->head;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    
    curr->next = new;
    q->tail = new;
}

Node removeItem(Queue q) {
    Node value = q->head;
    q->head = q->head->next;
    return value;
}
