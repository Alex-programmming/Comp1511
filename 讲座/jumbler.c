// Jumbler . . . a functions and pointers demo
// This program will read numbers from the command line
// It will swap some of these numbers in an array
// It will then print out the jumbled numbers

#include <stdio.h>
#include <stdlib.h>

#define MAX_NUMS 100

void read_args(int argc, char *argv[], int arg_ints[MAX_NUMS]);
void print_nums(int arg_ints[MAX_NUMS], int num_count);
void swap_nums(int *a, int *b);
void jumble(int arg_ints[MAX_NUMS], int num_count);

int main(int argc, char *argv[]) {
    int arg_ints[MAX_NUMS];
    read_args(argc, argv, arg_ints);
    jumble(arg_ints, argc - 1);    
    print_nums(arg_ints, argc - 1);
}

// read command line arguments and convert to numbers
// write them to an array
void read_args(int argc, char *argv[], int arg_ints[MAX_NUMS]) {
    int i = 1;
    while (i < argc) {
        arg_ints[i - 1] = strtol(argv[i], NULL, 10);
        i++;  
    }
}

// print out the first num_count elements of an integer array
void print_nums(int arg_ints[MAX_NUMS], int num_count) {
    int i = 0;
    while (i < num_count) {
        printf("%d ", arg_ints[i]);
        i++;
    }
    printf("\n");
}

// Swap any two integers
void swap_nums(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Jumble calls swap_nums multiple times to "mess up"
// a list
void jumble(int arg_ints[MAX_NUMS], int num_count) {
    int i = 0;
    while (i < num_count) {
        int j = i * 2;
        if (j < num_count) {
            swap_nums(&arg_ints[i], &arg_ints[j]);
        }
        i++;
    }
}





