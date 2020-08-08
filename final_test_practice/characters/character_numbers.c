#include <stdio.h>

int main(void) {
    int i = 32;
    while (i <= 126) {
        printf(" %d", i);
        printf(" 0x%x", i);
        printf(" %c\n", i);
        i++;
    }  
}
