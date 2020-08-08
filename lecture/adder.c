// A Command Line Arguments demo
// Showing the ability to read command line arguments
// as numbers and using them

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int total = 0;
    
    int i = 1;
    while (i < argc) {
        total += strtol(argv[i], NULL, 10);
        i++;
    }    
    printf("Total is %d.\n", total);
}
