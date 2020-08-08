// z5248147
// Haoheng Duan
// This program reads lines and prints them unless it 
// has seen exactly the same line previously.

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(void) {
    char line[256] = {5};
    int num1 = 0;
    char array[256][256] = {{7}};
    bool flag = false;
    while (fgets(line, 256, stdin) != NULL) {
        int len = strlen(line) - 1;
        if (line[len] == '\n') {
            len--;
        }
        int i = 0;
        int counter = 0;
        while (i < 256) {
            int j = 0;
            while (j < strlen(line)) {
                if (strcmp(&array[i][j], &line[j]) == 0) {
                    counter++;
                }
                j++;
            }
            if (counter != len + 2) {
                flag = true;
                counter = 0;
                i++;
            } else {
                flag = false;
                
                i = 257;
            }
        }
        strcpy(array[num1], line);
        if (flag == true) {
            int num2 = 0;
            while (num2 <= len + 1) {
                printf("%c", line[num2]);
                num2++;
            } 
        } else if (flag == false) {
        }
        num1++;
    }
    return 0;
}
