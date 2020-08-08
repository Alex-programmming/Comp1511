// Haoheng Duan
// z5248147
// 25/10/2019
// This programreads characters from its input and writes the same characters to
// its output with lower case letters converted to upper case and upper case 
// letters converted to lower case. 


#include <stdio.h> 
#define CASE_DIFFERENCE ('a' - 'A') 

int swap_case(int character);

int main(void) {
    int character = getchar();
    while (character != EOF) {
        putchar(swap_case(character));
        character = getchar();
    }
    
    
    
    return 0;
}

int swap_case(int character) {
    int new_character;
    if (character >= 'a' && character <= 'z') {
        new_character = character - CASE_DIFFERENCE;
    } else if (character >= 'A' && character <= 'Z') {
        new_character = character + CASE_DIFFERENCE;
    } else {
        return character;
    }
    return new_character;

}
