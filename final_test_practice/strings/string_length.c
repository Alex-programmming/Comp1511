// How long is a (piece of) string?
// Created by
//  ... (z0000000)
// Created on 2019-??-??

#include <assert.h>
#include <stdio.h>

int string_length(char *string);

int main(int argc, char *argv[]) {

    // Some simple assert-based tests.
    // You probably want to write some more.
    assert(string_length("") == 0);
    assert(string_length("!") == 1);
    assert(string_length("Hello, world!") == 13);
    assert(string_length("17... seventeen.\n") == 17);

    printf("All tests passed.  You are awesome!\n");

    return 0;
}

// Takes a string and finds its length, excluding the null-terminator.
int string_length(char *string) {
    // Your code goes here!
    // Don't forget to return your result.
    int i = 0;
    for(i = 0; string[i] != '\0'; i++);
    
    return i;
}
