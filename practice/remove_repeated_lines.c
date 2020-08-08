// z5248147
// Haoheng Duan
// This program reads lines and prints them unless it 
// has seen exactly the same line previously.

#include <stdio.h>
#include <string.h>

int main(void) {
    char input[256];
    int num1 = 0;
    char array[256][256] = {{7}};
    char line[256] = {5};
    while (fgets(input, 256, stdin) != NULL) {
        int len = strlen(input) - 1;
        if (input[len] == '\n') {
        len--;
        }
        int b = 0;
        while (b <= len) {
            line[b] = input[b];
            b++;
        }
        int i = 0;
        int counter = 0;
        while (i < 256) {
            int j = 0;
            while (j < 256) {
                if (array[i][j] == line[j]) {
                    counter++;
                }
                j++;
            }
            if (counter != len + 1) {
                counter = 0;
                i++;
            } else {
                i = 257;
            }
        }
        int a = 0;
        while (a <= len) {
            array[num1][a] = input[a];
            a++;
        }
        if (counter == 0) {
            int k = 0;
            while(k <= len) {
                printf("%c", input[k]);
                k++;
            } 
        } else {
        }
        printf("\n");
        num1++;
    }
    return 0;
}
