// Haoheng Duan
// z5248147
// 04/10/2019
// This program reads 3 integers and prints them from smallest to largest. 

#include <stdio.h>

int main(void) {
    int no1;
    int no2;
    int no3;
    printf("Enter integer: ");
    scanf("%d", &no1);
    printf("Enter integer: ");
    scanf("%d", &no2);
    printf("Enter integer: ");
    scanf("%d", &no3);
    printf("The integers in order are: %d ", (no1 <= no2) * (no1 <= no3) * no1 +
        (no2 < no1) * (no2 < no3)* no2 + (no3 < no1) * (no3 <= no2) * no3);
    printf("%d ", ((no1 <= no2) * (no1 > no3) * no1 + (no2 < no1) * (no2 > no3)*
        no2 + (no3 < no1) * (no3 >= no2) * no3 + (no1 >= no2) * 
        (no1 < no3) * no1 + (no2 > no1) * (no2 < no3)* no2 + (no3 > no1) * 
        (no3 <= no2) * no3 + (no1 < no2) * (no1 == no3) * no1 + (no1 > no2) * 
        (no1 == no3) * no1) + (no3 == no1) * (no2 == no1)* (no2 == no3) * no1);
    printf("%d\n", (no1 >= no2) * (no1 >= no3) * no1 + (no2 > no1) * 
        (no2 > no3)* no2 + (no3 > no1) * (no3 >= no2) * no3);
    return 0;
}
