// Using a list Abstract Data Type (ADT)
// Author: Finbar Berkon
// Date: November 2019

#include "List.h"

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        printf("useage: %s <iteger list items>\n", argv[0]);
        return 1;
    }

    // Convert our command line arguments into a linked list of ints
    Node head = create_list(argv, argc);
    Node new = copy(head);
    
    Node joined = list_append(head, new);

    print_list(joined);
}