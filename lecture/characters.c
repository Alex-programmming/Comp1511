// A demo of the use of characters
// Marc Chee, March 2019

#include <stdio.h>

#define MAX_LINE_LENGTH 80

int main (void) {
    // we're using an int to represent a single character
    int character;
    
    // using single quotes to assign an ASCII value
    character = 'a';
    // This int representing a character can be used as either
    // a character or a number
    printf("The letter %c has the ASCII value %d.\n", character, character);
    
    // using getchar() to read a single character from input
    int inputChar;
    printf("Please enter a character: ");
    inputChar = getchar();
    printf("The input %c has the ASCII value %d.\n", inputChar, inputChar);
    
    // using putchar() to write a single character to output
    putchar(inputChar);

    // This code has multiple examples that use EOF to end the input
    // Only part of the code will work at a time
    
    // reading multiple characters in a loop
//    int readChar;
//    readChar = getchar();
//    while (readChar != EOF) {
//        printf("I read character: %c, with ASCII code: %d.\n", readChar, readChar);
//        readChar = getchar();
//    }
        
    // a string is an array of characters
    char word1[] = {'h','e','l','l','o'};
    // but we also have a convenient shorthand that feels more like words
    char word2[] = "hello";
    printf("%s I just printed a string!\n", word2);
    
    // reading and writing lines of text
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, stdin) != NULL) {        
        fputs(line, stdout);
    }
    
    return 0;
}
