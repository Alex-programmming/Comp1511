// This program reads 2 integers and prints their absolute multiple.
// Haoheng Duan
// z5248147
// 08/10/2019

#include <stdio.h>

int main(void) {
    int no1;
    int no2;
    int total;
    scanf("%d %d", &no1, &no2);
    total = no1 * no2;
    if (no1 > 0 && no2 > 0) {
        printf("%d\n", total);
    } else if (no1 == 0 || no2 == 0) {
        printf("zero\n");
    } else if (no1 < 0 && no2 < 0) {
        printf("%d\n", total);
    } else {
        printf("%d\n", -total);
    }
    
    return 0;
}
