// Haoheng Duan
// z5248147
// 04/10/2019
// This program reads a positive integer n and print all the 
// positive integers < n divisible by 3 or 5. 

#include <stdio.h>

int main(void) {
    int input;
    printf("Enter number: ");
    scanf("%d", &input);
    int counter = 1;
    while (counter < input) {
        if (counter % 3 == 0 || counter % 5 == 0) {
            printf("%d\n", counter);
        }
        counter++;
    }

    return 0;
}
