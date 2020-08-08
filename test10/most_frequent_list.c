#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node {
    struct node *next;
    int          data;
};

int most_frequent(struct node *head);
struct node *strings_to_list(int len, char *strings[]);

// DO NOT CHANGE THIS MAIN FUNCTION

int main(int argc, char *argv[]) {
    // create linked list from command line arguments
    struct node *head = strings_to_list(argc - 1, &argv[1]);

    int result = most_frequent(head);
    printf("%d\n", result);

    return 0;
}


// return the value which occurs most frequently in a linked list
// if several values are equally most frequent
// the value that occurs earliest in the list is returned
int most_frequent(struct node *head) {

    // PUT YOUR CODE HERE (change the next line!)
    int frequent = 0;
    int max = 0;
    struct node *curr = head;
    while (curr != NULL) {
        int counter = 0;
        struct node *curr2 = head;
        while (curr2 != NULL) {
            if (curr2->data == curr->data) {
                counter++;
            }
            curr2 = curr2->next;
        }
        if (counter > max) {
            max = counter;
            frequent = curr->data;
        }
        curr = curr->next;
    }
    return frequent;

}


// DO NOT CHANGE THIS FUNCTION

// create linked list from array of strings
struct node *strings_to_list(int len, char *strings[]) {
    struct node *head = NULL;
    for (int i = len - 1; i >= 0; i = i - 1) {
        struct node *n = malloc(sizeof (struct node));
        assert(n != NULL);
        n->next = head;
        n->data = atoi(strings[i]);
        head = n;
    }
    return head;
}
