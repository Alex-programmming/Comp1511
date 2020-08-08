// Haoheng Duan
// z5248147
// 15/10/2019
// This program reads 3 integers and prints the middle integer.

#include <stdio.h>

int main(void) {
    int input1;
    int input2;
    int input3;
    printf("Enter integer: ");
    scanf("%d", &input1);
    printf("Enter integer: ");
    scanf("%d", &input2);
    printf("Enter integer: ");
    scanf("%d", &input3);
    int middle;
    if (input1 >= input2 && input1 <= input3) {
        middle = input1;
    } else if (input2 >= input1 && input2 <= input3) {
        middle = input2;
    } else if (input3 >= input2 && input3 <= input1) {
        middle = input3;
    } else if (input1 <= input2 && input1 >= input3) {
        middle = input1;
    } else if (input2 <= input1 && input2 >= input3) {
        middle = input2;
    } else {
        middle = input3;
    }
    printf("Middle: %d\n", middle);
    
    return 0;    
}
