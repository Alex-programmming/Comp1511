// z5248147
// Haoheng Duan
// This program reads lines and prints them unless it 
// has seen exactly the same line previously.

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(void) {
    char line[256] = {0};
    int num1 = 0;
    char array[256][256] = {{1}};
    while (fgets(line, 256, stdin) != NULL) {
        bool flag = false;        
        int i = 0;
        while (i < 256 && flag == false) {
            if (strcmp(array[i], line) == 0) {
                flag = true;
            }
            i++;
        }
        strcpy(array[num1], line);
        if (flag == false) {  
            printf("%s", line);
        }
        num1++;
    }
    return 0;
}
