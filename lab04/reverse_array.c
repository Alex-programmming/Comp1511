// Haoheng Duan
// z5248147
// 11/10/2019
// This program reads integers line by line, and when it reaches
// the end of input, prints those integers in reverse order, line by line. 

#include <stdio.h>

int main(void) {
    int array[100] = {0};
    int i = 0;
    printf("Enter numbers forwards:\n");
    while (scanf("%d", &array[i]) == 1 && i < 100) {
        i++;
    }
    printf("Reversed:\n");
    i--;
    while (i >= 0) {
        printf("%d\n", array[i]);
        i--;
    }
    
    
    return 0;
}
