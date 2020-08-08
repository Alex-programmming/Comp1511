// Author: Finbar Berkon
// Date: October 2019
// A program to sum the digits in a line of input

#include <stdio.h>

int main(void) {
    int ch;
    int sum = 0;
    int num_digits = 0;
    
    ch = getchar();
    while (ch != EOF) {
        if (ch >= '0' && ch <= '9') {
            sum += ch - '0';
            num_digits++;
            
        }
        ch = getchar();
    }
    
    printf("Input contained %d digits which summed to %d\n", num_digits, sum);
    
    return 0;
}
