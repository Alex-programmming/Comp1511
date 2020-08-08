// A heavily modified version of paint.c for Assignment 1

// This is starter code for the Tourist Program

// This program was written by Marc Chee (marc.chee@unsw.edu.au)
// in June 2019
//

#include <stdio.h>

// The dimensions of the map
#define N_ROWS 10
#define N_COLS 10

// Helper Function: Print out the canvas.
void printMap(int map[N_ROWS][N_COLS], int posR, int posC);


int main(void) {
    int map[N_ROWS][N_COLS] = {0};
    
    // tourist position coordinates
    int posR = N_ROWS/2;
    int posC = N_COLS/2;
    
    int exit = 0;
    while (exit == 0) {
        printMap(map, posR, posC);
        // check if we've been here before
        if (map[posR][posC] == 1) {
            printf("We've been here before! How Boring!\n");
            exit = 1;
        } else {
            // set visited
            map[posR][posC] = 1;
            
            // movement
            printf("Please enter a movement direction (2,4,6 or 8): ");
            int dir = -1;
            scanf("%d", &dir);
            if (dir == 2) {
                // down
                posR++;
            } else if (dir == 4) {
                // left
                posC--;
            } else if (dir == 6) {
                // right
                posC++;
            } else if (dir == 8) {
                // up
                posR--;
            } else if(dir == 0) {
                printf("Exiting tourist program.\n");
                exit = 1;
            } else {
                printf("Invalid input, please try again.\n");
            }
            
            // Keeping the tourist on the map
            if (posC < 0) {
                // left
                posC = 0;
            } else if (posC >= N_COLS) {
                // right
                posC = N_COLS - 1;
            } else if (posR < 0) {
                // top
                posR = 0;
            } else if (posR >= N_ROWS) {
                // bottom
                posR = N_ROWS - 1;
            }
        }
    }
    return 0;
}


// Prints the map, by printing the integer value stored in
// each element of the 2-dimensional map array.
// Prints a T instead at the position posR, posC
void printMap(int map[N_ROWS][N_COLS], int posR, int posC) {
    int row = 0;
    while (row < N_ROWS) {
        int col = 0;
        while (col < N_COLS) {
            if(posR == row && posC == col) {
                printf("T ");
            } else {
                printf("%d ", map[row][col]);
            }            
            col++;
        }
        row++;
        printf("\n");
    }
}
