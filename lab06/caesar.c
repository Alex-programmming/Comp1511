// Haoheng Duan
// z5248147
// This program  reads characters from its input and writes the characters to 
// its output encrypted with a Caesar cipher. 

#include <stdio.h>

int encrypt(int character, int shift);

int main(void) {
    int shift;
    scanf("%d", &shift);
    shift = shift % 26;
    int character = getchar();
    while (character != EOF) {
        putchar(encrypt(character, shift));
        character = getchar();
    }
    return 0;
}

int encrypt(int character, int shift) {
    int new_char;
    int difference;
    if (character >= 'a' && character <= 'z') {
        if (character + shift > 'z') {
            difference = character + shift - 'z';
            new_char = 'a' + difference - 1;
        } else if (character + shift < 'a') {
            difference = character + shift - 'a';
            new_char = 'z' + difference + 1;
        } else {
            new_char = character + shift;
        }
    } else if (character >= 'A' && character <= 'Z') {
        new_char = character + shift;
        if (character + shift > 'Z') {
            difference = character + shift - 'Z';
            new_char = 'A' + difference - 1;
        } else if (character + shift < 'A') {
            difference = character + shift - 'A';
            new_char = 'Z' + difference + 1;
        } else {
            new_char = character + shift;
        }
    } else {
        return character;
    }
    return new_char;
}
