// Haoheng Duan
// z5248147
// 15/10/2019
// This program reads an integer n from standard input, and then scans in
// n integers from standard input, adds them together, then prints the sum.

#include <stdio.h>

int main(void) {
    int inputNumber;
    int input;
    int index = 0;
    int sum = 0;
    printf("How many numbers: ");
    scanf("%d", &inputNumber);
    while (index < inputNumber) {
        scanf("%d", &input);
        sum = sum + input;
        index ++; 
    }
    printf("The sum is: %d\n", sum);
    
    
    return 0;
}
