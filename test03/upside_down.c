// Haoheng Duan
// z5248147
// 08/10/2019
// This program reads 3 numbers and indicate whether they are strictly 
// increasing (called "up"), strictly decreasing (called "down"), 
// or neither ("neither").

#include <stdio.h>

int main(void) {
    double no1;
    double no2;
    double no3;
    printf("Please enter three numbers: ");
    scanf("%lf %lf %lf", &no1, &no2, &no3);
    
    if (no3 > no2 && no2 > no1) {
        printf("up\n");
    } else if (no3 < no2 && no2 < no1) {
        printf("down\n");
    } else {
        printf("neither\n");
    }
    
    return 0;
}
