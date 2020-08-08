// This program reads characters from its input and writes the characters
// to its output encrypted with a Substitution cipher. 
// Haoheng Duan
// z5248147
// 26/10/2019

#include <stdio.h>
#define CASE_DIFFERENCE ('a' - 'A')

int encrypte(int character, int count['z' + 1], int i);

int main(void) {
    int count['z' + 1];
    int i = 'a';
    count[i] = getchar();
    i++;
    while (i <= 'z' ) {
        count[i] = getchar();
        i++;
    }
    getchar();
    int character = getchar();
    while (character != EOF) {
        putchar(encrypte(character, count, i));
        character = getchar();
    }
    return 0;
}

int encrypte(int character, int count['z' + 1], int i) {
    int new_char;
    if (character >= 'a' && character <= 'z') {
        new_char = count[character];
    } else if (character >= 'A' && character <= 'Z') {
        new_char = count[character + CASE_DIFFERENCE] - CASE_DIFFERENCE;
    } else {
        return character;
    }
    return new_char;
}
