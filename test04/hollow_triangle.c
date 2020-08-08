// Haoheng Duan
// z5248147
// 15/10/2019
// It reads an integer n from standard input. and prints a pattern of 
// asterisks forming a hollow triangle.

#include <stdio.h>

int main(void) {
    int input;
    printf("Enter size: ");
    scanf("%d", &input);
    int i = 0;
    while (i < input) {
        int j = 0;
        while (j <= i) {
            if (j == 0 || j == i || i == input - 1) {
                printf("*");
            } else {
                printf(" ");
            }
            j++;
        }
        printf("\n");
        i++;;
    }
    
    
    return 0;
}
