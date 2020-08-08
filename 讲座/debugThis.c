// This program is intended for debugging
// It doesn't compile first go, it needs a bit of attention

// This is code intended to loop
// Each time it loops, it will draw a square of asterisks
// that is sized based on the user input


#include <stdio.h>

int main (void) {
    int gridSize;
    int x = 0; // x coordinate of the grid
    int y = 0; // y coordinate of the grid
    int exit = 0;
    
    while (exit = 0) {
        // Let the user choose the grid size
        printf("Please enter the size of grid you would like me to make.\n");
        printf("If you would like to exit, please type 0.\n");
        scanf("%d", &gridSize);
        
        // if my user gives me 0, exit the loop
        if(gridSize == 0) {
            exit = 1;
        }
        
        // loop through the rows of the grid
        while (y < gridSize) {
            // For each row, loop through the columns
            while (x <= gridSize) {
                printf("*");
                x = x + 1;
            }
        }
            printf("\n"); // end the row, and start the next on a new line
            x = 0; // reset x to zero so that it can print another line
            x = y + 1;
        }
        
        // reset all variables for the next run through
        gridSize = 0;
        x = 0;
        y = 0;
    }
    
    printf("Thank you for using grid drawer. Have a nice day!\n");
    
    return 0;
} 
