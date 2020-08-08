// Copy an array.
//  ... (z0000000)
// Created on 2019-??-??
// Tutor's name (day_hH-lab)

#include <stdio.h>
#include <assert.h>

#define MAX_SIZE 1000

void scan_array(int size, int array[size]);
void show_array(int size, int array[size]);
void copy_array(int size, int from_array[size], int to_array[size]);

// DO NOT CHANGE THIS MAIN FUNCTION
int main(int argc, char *argv[]) {

    // Create the arrays.
    int array1[MAX_SIZE];
    int array2[MAX_SIZE];

    // Get the array size.
    int size;
    printf("Enter array size: ");
    assert(scanf("%d", &size) == 1);
    assert(size > 0);

    // Scan in the values for the array.
    printf("Enter array values: ");
    scan_array(size, array1);

    // Print the values of the first array.
    show_array(size, array1);

    // Copy the values from array1 to array2.
    copy_array(size, array1, array2);

    // Print the copied values.
    show_array(size, array2);

    return 0;
}

// Copy `size` elements from `from_array` into `to_array`.
void copy_array(int size, int from_array[size], int to_array[size]) {
    // Put your code here
    int i = 0;
    while (i < size) {
        to_array[i] = from_array[i];
        i++;
    }
}


// This function reads in values from standard input into an array.
void scan_array(int size, int array[size]) {
    // Put your code here
    int i = 0;
    while (i < size) {
        scanf("%d", &array[i]);
        i++;
    }
}

// This function prints the array in the format
// [1, 2, 3, ...]
void show_array(int size, int array[size]) {
    // Put your code here
    printf("[%d", array[0]);
    int i = 1;
    while (i < size) {
        printf(", %d", array[i]);
        i++;
    }
    printf("]\n");
}
