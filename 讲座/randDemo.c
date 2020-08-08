// A quick demo of random numbers

// Marc Chee (marc.chee@unsw.edu.au)

#include <stdio.h>
#include <stdlib.h>

#define MAX_NUMS 10

int main(int argc, char *argv[]) {
    if (argc > 1) {
        // if we received a command line argument, 
        // use that as our random seed
        srand(strtol(argv[1], NULL, 10));
    }

    int i = 0;
    while (i < MAX_NUMS) {
        printf("%d\n", rand());
        i++;
    }
}
