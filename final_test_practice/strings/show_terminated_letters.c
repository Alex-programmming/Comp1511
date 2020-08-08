// Displaying arrays as text
// Created by
//  ... (z0000000)
// Created on 2019-??-??

#include <stdio.h>

#define ENOUGH_SPACE 100

// Print out each character in a NUL-terminated array of characters.
void show_terminated_letters(char *letters);

int main(int argc, char *argv[]) {

    char letters_a[14] = {0};
    letters_a[0] = 72;
    letters_a[1] = 101;
    letters_a[2] = 108;
    letters_a[3] = 108;
    letters_a[4] = 111;
    letters_a[5] = 44;
    letters_a[6] = 32;
    letters_a[7] = 119;
    letters_a[8] = 111;
    letters_a[9] = 114;
    letters_a[10] = 108;
    letters_a[11] = 100;
    letters_a[12] = 33;
    letters_a[13] = 0;
    show_terminated_letters(letters_a);

    putchar('\n');

    char letters_b[14] = {
        84,  101, 115, 116, 32,
        109, 101, 115, 115, 97,
        103, 101, 46, 0
    };
    show_terminated_letters(letters_b);

    putchar('\n');

    char letters_c[12] = {
        's', 'a', 'm', 'p', 'l', 'e',
        ' ', 't', 'e', 'x', 't', '\0'
    };
    show_terminated_letters(letters_c);

    putchar('\n');

    char letters_d[ENOUGH_SPACE] = "a string";
    show_terminated_letters(letters_d);

    putchar('\n');

    return 0;
}

void show_terminated_letters(char *letters) {
    // Your code here
    int i = 0;
    while (letters[i] != '\0') {
        putchar(letters[i]);
        i++;
    }
}
