//z5248147
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// Do not edit this struct. You may use it exactly as
// it is but you cannot make changes to it

// A node in a linked list
struct node {
    int data;
    struct node *next;
};

// ADD ANY FUNCTION DECLARATIONS YOU WISH TO USE HERE

// Remove any nodes in a list that are higher 
// than the node directly after them.
// Return the head of the list.
// The returned list must have no disorder in it!
struct node *remove_disorder(struct node *head) {
    // WRITE YOUR CODE HERE (you may need to change the line below)   
    bool flag = false;
    while (flag == false) {
        struct node *curr = head;
        struct node *prev = NULL;
        struct node *remove = head;
        if (curr == NULL) {
            return NULL;
        }
        while (curr->next != NULL) {
            if (curr->data > curr->next->data) {
                if (prev == NULL) {
                    head = head->next;
                    remove = curr;
                    free(remove);
                } else {
                    remove = curr;
                    prev->next = curr->next;
                  //curr->next = curr->next->next;
                    curr = curr->next;
                    free(remove);
                }
            } else {
                prev = curr;
                curr = curr->next;
            }
        }
        struct node *curr02 = head;
        int counter = 0;
        while (curr02 != NULL && curr02->next != NULL) {
            if (curr02->data > curr02->next->data) {
                counter++;
            }
            curr02 = curr02->next;
        }
        if (counter > 0) {
            flag = false;
        } else {
            flag = true;
        }
    }
    return head;
}

// These helper functions are for the main below and will
// have no effect on your remove_disorder. They do not
// need to be modified.
struct node *make_list(int a, int b, int c);
void printList(struct node *head);

// This is a main function which could be used
// to test your remove_disorder function.
// It will not be marked.
// Only your remove_disorder function will be marked.
//
// It's recommended to change the int values in this
// main to test whether your remove_disorder is working.
int main(void) {
    // test an ordered list
    struct node *ordered = make_list(1, 2, 3);
    ordered = remove_disorder(ordered);
    printList(ordered);
    
    // test removing one element out of order
    ordered = make_list(1, 3, 2);
    ordered = remove_disorder(ordered);
    printList(ordered);
    
    // test a completely disordered list
    ordered = make_list(3, 2, 1);
    ordered = remove_disorder(ordered);
    printList(ordered);

    // test with the first removal causing more disorder
    ordered = make_list(2, 3, 1);
    ordered = remove_disorder(ordered);
    printList(ordered);
        
    return 0;
}

// A simple function to make a linked list with 3 elements
// This function is purely for the main above
// You will be tested with lists that are more and less
// than 3 elements long
struct node *make_list(int a, int b, int c) {
    struct node *head = malloc(sizeof (struct node));
    struct node *n = head;
    n->data = a;
    n->next = malloc(sizeof (struct node));
    n = n->next;
    n->data = b;
    n->next = malloc(sizeof (struct node));
    n = n->next;
    n->data = c;
    n->next = NULL;
    
    return head;
}

void printList(struct node *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}
// ADD ANY FUNCTION DEFINITIONS YOU WISH TO USE HERE


