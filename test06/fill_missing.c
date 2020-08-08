// z5248147
// Haoheng Duan
// This program reads integers from standard input until it reaches 
// end-of-input. It should then print the missing integers.

#include <stdio.h>



int main(void) {
    int array[10000];
    int i = 0;
    while (i < 10000 && scanf("%d", &array[i]) == 1) {
        i++;
    }
    i--;
    int temp = i;
    int max = array[i];
    while (i >= 0) {
        if (array[i] > max) {
            max = array[i];
        }
        i--;        
    }
    int j = 1;
    while (j <= max) {
        i = temp;
        int counter = 0;
        while (i >= 0) {
            if (j == array[i]) {
                counter++;
            }
            i--;
        }
        if (counter == 0) {
            printf("%d ", j);
        }
        j++;
    }
    printf("\n");
    return 0;
}
