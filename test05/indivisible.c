// Haoheng Duan
// z5248147
// This program reads integers > 1 from standard input 
// until it reaches end-of-input.
// It should then print the integers read which are not exactly divisible 
// by any other of the integers read.

#include <stdio.h>

int main(void) {
    int input[1000];
    
    int i = 0;
    while (scanf("%d", &input[i]) == 1 && i < 1000) {
        i++;
    }
    i--;
    int state;
    state = i;
    printf("Indivisible numbers: ");
    i = 0;
    while (i <= state) {
        int j = 0;
        int check = 0;
        while(j <= state) {
            if (input[i] % input[j] == 0) {
                check = check + 1;
            }
            j++;
        }
        if (check == 1) {
            printf("%d ", input[i]);
        }
        i++;
    }
    printf("\n");
    return 0;
}
