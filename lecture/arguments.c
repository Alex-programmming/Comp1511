// A demo of using command line arguments
// This program will start an argument with you
// It will take whatever you say and refuse to agree

// Marc Chee (marc.chee@unsw.edu.au)

#include <stdio.h>

int main(int argc, char *argv[]) {
    int i = 1;
    printf("Well actually %s says there's no such thing as ", argv[0]);
    while (i < argc) {
        fputs(argv[i], stdout);
        printf(" ");
        i++;
    }
    printf("\n");
}
