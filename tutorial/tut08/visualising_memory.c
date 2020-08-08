// Author: Finbar Berkon
// Date: November 2019
// Declaring some structs to think about what they look like in memmory

struct overall {
    struct node *start; // Sometimes we call start 'head'
};

struct node {
    int data;
    struct node *next;
};

int main(void) {

    // What will each of theses look like in memory?
    struct overall o1; 
    struct node n1;

    // What about these?
    struct overall *o2 = malloc(sizeof(struct overall));
    struct node *n2 = malloc(sizeof(struct node));

    // What are we doing when we do this?
    o1.start = NULL;

    n1.data = 5;
    n1.next = NULL;

    // What about this?
    o2->start = NULL;

    n2->data = 8;
    n2->next = NULL;
}