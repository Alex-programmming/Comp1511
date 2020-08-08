// Haoheng Duan
// z5248147
// 11/10/2019
// This program reads an integer n from standard input, and prints 
// an nxn pattern of asterisks and dashes in the shape of an "X". 

#include <stdio.h>

int main(void) {
    int i = 0;
    int size;
    printf("Enter size: ");
    scanf("%d", &size);
    while (i < size) {
        int j = 0;
        while (j < size) {
            if (i == j || i + j == size - 1) {
                printf("*");
            } else {
                printf("-");
            }
            j++;
        }
        printf("\n");
        i++;
    }    
    
    
    return 0;
}

