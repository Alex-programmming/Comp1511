// Convert a character to uppercase.
// Created by ... (z0000000)
// Created on 2019-??-??

#include <stdio.h>

int uppercase(int c);

// DO NOT CHANGE THIS MAIN FUNCTION
int main(int argc, char *argv[]) {

    // Get the character
    int c = getchar();

    // Loop until end of characters
    while (c != EOF) {
        // print the character in uppercase
        putchar(uppercase (c));

        // get the next character
        c = getchar();
    }

    return 0;
}
// END OF MAIN FUNCTION

int uppercase(int c) {
    // PUT YOUR CODE HERE
    if (c >= 'a' && c <= 'z') {
        c -= ('a' - 'A');
        return c;
    } else {
        return c;
    }
    return 0; // change to your return value
}
