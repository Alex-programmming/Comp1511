// Haoheng Duan
// z5248147
// 1/11/2019
// This program reads a string and tests if it is a palindrome.

#include <stdio.h>
#define MAX_LINE_LENGTH 4096

int main(void) {
    char line[MAX_LINE_LENGTH];
    printf("Enter a string: ");
    fgets(line, MAX_LINE_LENGTH, stdin);
    int i = 0;
    while (line[i] != '\0' && i < MAX_LINE_LENGTH) {
        i++;
    }
    i = i - 2;
    int j = 0;
    int counter = 0;
    while (j <= i) {
        if (line[j] == line[i - j]) {
            counter++;
        }
        j++;
    }
    if (counter - 1== i) {
        printf("String is a palindrome\n");
    } else {
        printf("String is not a palindrome\n");
    }
    return 0;
}
