// z5248147
// Haoheng Duan
// This program reads lines and writes them out with the
// characters of each line in reverse order.

#include <stdio.h>
#include <string.h>

int main(void) {
    char line[256];
    while (fgets(line, 256, stdin) != NULL) {
        int len = strlen(line) - 1;
        if (line[len] == '\n') {
            len--;
        }
        int i = len;
        while (i >= 0) {
            printf("%c", line[i]);
            i--;
        }
        printf("\n");
    }
    return 0;
}
