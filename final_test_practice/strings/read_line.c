// Read a line of input.
// Created by
//  ... (z0000000)
// Created on 2019-??-??

#include <stdio.h>

#define BUFFER_LENGTH 16

void read_line(int buffer_len, char *buffer);

int main(int argc, char *argv[]) {
    // Declare a buffer.  In this case, we're declaring and using a
    // 64-byte buffer, but this could be any length you like, and in
    // our tests you will be required to handle arrays of any length.
    char buffer[BUFFER_LENGTH] = {0};

    // Read in a line...
    read_line(BUFFER_LENGTH, buffer);

    // ... and print it out.  The `%s` format code prints a string.
    printf("<%s>\n", buffer);

    return 0;
}

// Reads a line of input into `buffer`, excluding the newline;
// then ensures that `buffer` is a null-terminated string.
void read_line(int buffer_len, char *buffer) {

    // PUT YOUR CODE HERE
    int i = 0;
    int ch = getchar();
    while (i < buffer_len - 1 && ch != '\n' && ch != EOF) {
        buffer[i] = ch;
        i++;
        ch = getchar();
    }
    buffer[i] = '\0';
}
