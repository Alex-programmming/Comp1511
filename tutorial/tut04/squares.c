// Author: Finbar Berkon
// Date: October 2019
// A program to store numbers into array then print their squares

#include <stdio.h> 

#define SQUARES_SIZE 15

int main(void) {
    
    int squares[SQUARES_SIZE];
    
    int i = 0;
    while (i < SQUARES_SIZE) {
        squares[i] = i * i;
        i++;
    }
    
    i = 0;
    while (i < SQUARES_SIZE) {
        printf("squares[%d] = %d\n", i, squares[i]);
        i++;
    }

    return 0;
}
