// Haoheng Duan
// z5248147
// 11/10/2019
// This program reads a positive integer n from standard input and prints all
// the factors of n, their sum and indicates whether n is a perfect number. 

#include <stdio.h>

int main(void) {
    int num;
    int i = 1;
    int sum = 0;
    printf("Enter number: ");
    scanf("%d", &num);
    printf("The factors of %d are:\n", num);
    while (i <= num) {
        if (num % i == 0) {
            printf("%d\n", i);
            sum = sum + i;
        }
        i++;
    }
    printf("Sum of factors = %d\n", sum);
    if (sum - num == num) {
        printf("%d is a perfect number\n", num);
    } else {
        printf("%d is not a perfect number\n", num);
    }
    return 0;
}
