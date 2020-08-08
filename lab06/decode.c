// Haoheng Duan
// z5248147
// 26/10/2019
// This program decrypts text encrypted by substitution.c

#include <stdio.h>
#define CASE_DIFFERENCE ('a' - 'A')

int encrypte(int character, int count['z' + 1]);

int main(void) {
    int count['z' + 1];
    int i = 'a';
    int input = getchar();
    while (i <= 'z' ) {
        count[input] = i;
        i++;
        input = getchar();
    }
    int character = getchar();
    while (character != EOF) {
        putchar(encrypte(character, count));
        character = getchar();
    }
    return 0;
}

int encrypte(int character, int count['z' + 1]) {
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
