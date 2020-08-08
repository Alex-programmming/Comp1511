// Haoheng Duang
// z5248147
// 04/10/2019
// This program reads 3 integers and prints them from smallest to largest. 

#include <stdio.h>

int main(void) {
    int no1;
    int no2;
    int no3;
    int no4;
    int no5;
    int no6;
    printf("Enter integer: ");
    scanf("%d", &no1);
    printf("Enter integer: ");
    scanf("%d", &no2);
    printf("Enter integer: ");
    scanf("%d", &no3);
    no4 = (no1 <= no2) * (no1 <= no3) * no1 + (no2 < no1) * (no2 < no3)* no2 
        + (no3 < no1) * (no3 <= no2) * no3;
    no5 = ((no1 <= no2) * (no1 > no3) * no1 + (no2 < no1) * (no2 > no3)* no2 + 
        (no3 < no1) * (no3 >= no2) * no3 + (no1 >= no2) * (no1 < no3) * no1 + 
        (no2 > no1) * (no2 < no3)* no2 + (no3 > no1) * (no3 <= no2) * no3 + 
        (no1 < no2) * (no1 == no3) * no1 + (no1 > no2) * (no1 == no3) * no1) + 
        (no3 == no1) * (no2 == no1)* (no2 == no3) * no1;
    no6 = (no1 >= no2) * (no1 >= no3) * no1 + (no2 > no1) * (no2 > no3)* no2 + 
        (no3 > no1) * (no3 >= no2) * no3;
    printf("The integers in order are: %d %d %d\n",no4,no5,no6);
    return 0;
}
