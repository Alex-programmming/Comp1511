// Print out characters in lower case.
// Created by
//  ... (z0000000)
// Created on 2019-??-??

#include <stdio.h>

int lowercase(int c);

// DO NOT CHANGE THIS MAIN FUNCTION
int main(int argc, char *argv[]) {

    // Scan in the first character.
    int c = getchar();

    // Loop until there are no more characters to scan.
    while (c != EOF) {
        // Print the character, in lowercase.
        putchar(lowercase(c));

        // Get the next character.
        c = getchar();
    }

    return 0;
}

// Returns the specified character `c`, in lowercase.
int lowercase(int c) {
    // Your code goes here!
    // Don't forget to return your result.
    if (c >= 'A' && c <= 'Z') {
        c += ('a' - 'A');
        return c;
    } else {
        return c;
    }

}
