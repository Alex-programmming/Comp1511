// A Simple program showing the use of functions

#include <stdio.h>

// A function declaration. This is above the main so that the compiler knows
// it exists and can use it later
void add (int a, int b);

// We still always need a main function. This is what runs when the program
// is run
int main (void) {
    int number = 4;
    int otherNumber = 8;
    //int total = add(number, otherNumber);
    //printf("Total is: %d", total);
    return 0;
}

// our add function declaration. This is the actual code that runs when the
// function is called
void add (int a, int b) {
    int total = 0;
    total += a;
    total += b;
    printf("The total is: %d\n", total);
    return;
}







