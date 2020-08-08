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
            if(posR == row && posC = col) {
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

