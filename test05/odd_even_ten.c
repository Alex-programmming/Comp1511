// Haoheng Duan
// z5248147
// This program reads 10 integers from standard input, prints the odd 
// numbers on one line, then prints the even numbers on one line.

#include <stdio.h>

int main(void) {
    int input[10];
    int i = 0;
    while (i < 10) {
        scanf("%d", &input[i]);
        i++;
    }
    printf("Odd numbers were: ");
    i = 0;
    while (i < 10) {
        if (input[i] % 2 != 0) {
            printf("%d ", input[i]);
        }
        i++;
    }
    printf("\nEven numbers were: ");
    i = 0;
    while (i < 10) {
        if (input[i] % 2 == 0) {
            printf("%d ", input[i]);
        }
        i++;
    }
    printf("\n");
    
    return 0;
}
