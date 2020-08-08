//Author Haoheng Duan
//z5248147
//27/09/2019
#include <stdio.h>
int main(void) {
    int number;
    scanf("%d", &number);
    if (number < 0) {
        printf("Don't be so negative!\n");
    } else if (number == 0) {
        printf("You have entered zero.\n");
    } else {
        printf("You have entered a positive number.\n");
    }
    return 0;
}



