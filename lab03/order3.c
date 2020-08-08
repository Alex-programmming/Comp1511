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
    printf("The integers in order are: ");
    
    if (no1 <= no2 && no1 <= no3) {
        printf("%d ", no1);
        if (no2 <= no3) {
            printf("%d ", no2);
            printf("%d \n", no3);
        } else if (no3 <= no2) {
            printf("%d ", no3);
            printf("%d \n", no2);
        }
    } else if (no2 <= no1 && no2 <= no3) {
        printf("%d ", no2);
        if (no1 <= no3) {
            printf("%d ", no1);
            printf("%d \n", no3);
        } else if (no3 <= no1) {
            printf("%d ", no3);
            printf("%d \n", no1);
        }
    } else {
        printf("%d ", no3);
        if (no2 <= no1) {
            printf("%d ", no2);
            printf("%d \n", no1);
        } else if (no1 <= no2) {
            printf("%d ", no1);
            printf("%d \n", no2);
        }
    }

    return 0;
}
