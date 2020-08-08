l// z5248147
// Haoheng Duan
// This program  reads a line from its input then reads an integer n from its 
// input. It should write the character in position n from the line 

#include <stdio.h>
#define MAX_LINE_LENGTH 256

int main(void) {
    char line[MAX_LINE_LENGTH];
    int input;
    fgets(line, MAX_LINE_LENGTH, stdin);
    scanf("%d", &input);
    printf("The character in position %d is '", input);
    putchar(line[input]);
    printf("'\n");    
    
    
    
    return 0;
}
