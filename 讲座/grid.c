// Lecture demo, September 2019

// Print out a grid of *s using while loops

// Marc Chee (marc.chee@unsw.edu.au)

#include <stdio.h>

int main(void) {
    int exit = 0;
    
    // A loop to run the program multiple times
    while (exit == 0) {
        int size;
        
        // Ask the user how large the grid should be
        printf("How large is the grid?\n");
        scanf("%d", &size);
        
        // exit on a user input of 0
        if (size == 0) {
            exit = 1;
        }
        
        // print the whole grid
        int i = 0;
        while (i < size) {    
            // print one line
            int j = 0;
            while (j < size) {
                printf("*");
                j = j + 1;
            }
            printf("\n");
            
            i = i + 1;
        }       
    }
    return 0;
}
