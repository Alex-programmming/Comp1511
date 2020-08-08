#include <stdio.h>


int main(void) {
    int i = 0;
    while (i < 6) {
        int j = 0;
        while(j < 5 - i) {
            printf(" ");
            j++;
        }
        int k;
        for(k = 0; k <= i; k++) {
            printf("%c", 'A' + k);
        }
        for(k = 1; k <= i; k++) {
            printf("%c", 'A' + i - k);
        }
        printf("\n");
        i++;
    }
    i = 0;
    while (i < 5) {
        int j = 0;
        while (j <= i) {
            printf(" ");
            j++;
        }
        int k;
        for(k = 0; k <= 4 - i; k++) {
            printf("%c", 'A' + k);
        }
        for(k = 1; k <= 4 - i; k++) {
            printf("%c", 'A' + 4 - i - k);
        }
        printf("\n");
        i++;
    }
    
    return 0;
}
