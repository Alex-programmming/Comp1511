// Haoheng Duan
// z5248147
// 25/10/2019
// This program reads characters from its input and writes 
// the same characters to its output, except it does not 
// write lower case vowels ('a', 'e','i', 'o', 'u'). 

#include <stdio.h>

int is_vowel(int character);

int main(void) {
    int character = getchar();
    while (character != EOF) {
        if (is_vowel(character) == 0) {
            putchar(character);
        }
        character = getchar();
    }
    
    return 0;
}

int is_vowel(int character) {
    if (character == 'a' || character == 'e' || character == 'i' 
    || character == 'o' || character == 'u') {
        return 1;
    } else {
        return 0;
    }

}
