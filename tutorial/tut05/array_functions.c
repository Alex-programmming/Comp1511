// z5254701 | Ben Briant
// October 2019
// This program will use functions to print and scan into an array.

#include <stdio.h>
#define MAX_SIZE 5

void print_array(int n, int array[n]);
int scanf_array(int n, int array[n]);

int main(void) {
    int numbers[MAX_SIZE] = {0};
    int array_size = scanf_array(MAX_SIZE, numbers);
    print_array(array_size, numbers);
}

void initialise_array(int n, int array[n]) {
    int i = 0;
    while (i < n) {
        array[i] = 0;
    }
}

int scanf_array(int n, int array[n]) {
    int items_read = 0;
    
    int result = scanf("%d", &array[items_read]);
    items_read++;
    
    while (items_read < n && result == 1) {
        result = scanf("%d", &array[items_read]);
        items_read++;
    }
    items_read--;
    return items_read;
}

void print_array(int n, int array[n]) {
    int i = 0;
    while (i < n) {
        printf("%d ", array[i]);
        
        i++;
    }
    printf("\n");
}



