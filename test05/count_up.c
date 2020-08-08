// Haoheng Duan
// z5248147
// This program reads 2 positive integers and prints the integers 
// between them, one per line.

#include <stdio.h>

int main(void) {
    int input1;
    int input2; 
    printf("Enter lower: ");
    scanf("%d", &input1);
    printf("Enter upper: ");
    scanf("%d", &input2);
    int i = input1 + 1;
    while (i < input2 && i > input1) {
        printf("%d\n", i);
        i++;
    }
    
    return 0;
}
