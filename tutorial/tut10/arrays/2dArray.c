#include <stdio.h>

#define SIZE 4

void remove_less_than(int array[SIZE][SIZE], int value);
void print_array(int array[SIZE][SIZE]);

int main(void) {
    int array[SIZE][SIZE];
    array[0][0] = 5;
    array[0][1] = 7;
    array[0][2] = 3;
    array[0][3] = 2;
    array[1][0] = 6;
    array[1][1] = 8;
    array[1][2] = 3;
    array[1][3] = 6;
    array[2][0] = 7;
    array[2][1] = 4;
    array[2][2] = 8;
    array[2][3] = 2;
    array[3][0] = 3;
    array[3][1] = 4;
    array[3][2] = 8;
    array[3][3] = 6;

    printf("Our original array:\n");
    print_array(array);

    int size_to_remove = 6;
    printf("\nRemoving numbers less than %d...\n", size_to_remove);
    remove_less_than(array, size_to_remove);

    printf("\nOur new array:\n");
    print_array(array);
}

// For any number less than 'value', make it an 0 instead
void remove_less_than(int array[SIZE][SIZE], int value) {
    int i = 0;
    while (i < SIZE) {
        int j = 0;
        while (j < SIZE) {
            
            // Apart from this if statement, the rest of this code is a generic
            // 2 dimensional while loop. This if statement then checks each 
            // element of the array
            if (array[i][j] < value) {
                array[i][j] = 0;
            }

            j++;
        }
        i++;
    }
}









































void print_array(int array[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
}