// Scan in an array.
// Created by
//  ... (z0000000)
// Created on 2019-??-??

#include <stdio.h>
#include <assert.h>

#define MAX_SIZE 1000

void scan_array(int size, int array[size]);
void show_array(int size, int array[size]);

// DO NOT CHANGE THIS MAIN FUNCTION
int main(int argc, char *argv[]) {
    // Create the array.
    int array[MAX_SIZE];

    // Get the array size.
    int size;
    printf("Enter array size: ");
    assert(scanf("%d", &size) == 1);
    assert(size > 0);

    // Scan in values for the array.
    printf("Enter array values: ");
    scan_array(size, array);

    // Print the values.
    show_array(size, array);

    return 0;
}

// This function reads in values from standard input into an array.
void scan_array(int size, int array[size]) {
    // PUT YOUR CODE HERE
    int i = 0;
    while (i < size) {
        scanf("%d", &array[i]);
        i++;
    }
}

// This function prints the array in the format
// [1, 2, 3, ...]
void show_array(int size, int array[size]) {
    // PUT YOUR CODE HERE
    printf("[%d", array[0]);
    int i = 1;
    while (i < size) {
        printf(", %d", array[i]);
        i++;
    }
    printf("]\n");
}
