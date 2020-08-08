// Copy a String
// Created by
//  ... (z0000000)
// Created on 2019-??-??

#include <stdio.h>

#define BUFFER_LENGTH 64

void string_copy(char *destination, char *source, int destination_size);

int main(int argc, char *argv[]) {
    // Declare a buffer.  In this case, we're declaring and using a
    // 64-byte buffer, but this could be any length you like, and in
    // our tests you will be required to handle arrays of any length.
    char buffer[BUFFER_LENGTH] = {0};

    // Copy a string into the buffer ...
    string_copy(buffer, "Seventeen bytes.\n", BUFFER_LENGTH);

    // ... and print it out.  The `%s` format code prints a string.
    printf("<%s>\n", buffer);

    return 0;
}

// Takes a string in `source`, and copies it to `destination`, which
// is `destSize` elements in size; only copies up to `destSize` bytes.
// Ensures the `destination` array is null-terminated.
void string_copy(char *destination, char *source, int destination_size) {
    // Put your code here
    int i = 0;
    while (source[i] != '\0' && i < destination_size - 1) {
        destination[i] = source[i];
        i++;
    }
    destination[i] = '\0';
}
