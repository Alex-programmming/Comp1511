// COMP1511 Week 5 Lab: Array Maximum
//
// This program was written by HAoheng Duan (z5248147)
// on 18/10/2019
//
// This program calculates the maximum value in an array of integers.
//

#include <stdio.h>

// Returns the maximum value from an array of `size` integers.
int array_maximum(int size, int array[size]);


// This is a simple main function that you can use to test your array_maximum
// function.
// It will not be marked - only your array_maximum function will be marked.
//
// Note: the autotest does not call this main function!
// It calls your array_maximum function directly.
// Any changes that you make to this function will not affect the autotests.

#define MAX_SIZE 100

int main(void) {
    int size1 = 7;
    int array1[MAX_SIZE] = {3, 14, 15, 9, 2, 6, 5};

    int result1 = array_maximum(size1, array1);
    printf("The largest value from array1 is: %d\n", result1);

    int size2 = 10;
    int array2[MAX_SIZE] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};

    int result2 = array_maximum(size2, array2);
    printf("The largest value from array2 is: %d\n", result2);

    // Note: you can add more tests here (but they won't be marked).

    return 0;
}

int array_maximum(int size, int array[size]) {

    int max = array[0];
    int i = 0;
    while (i < size) {
        if (array[i] > max) {
            max = array[i];
        }
        i++;
    }

    return max;
}

