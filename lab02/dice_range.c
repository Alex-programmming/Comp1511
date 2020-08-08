//Author Haoheng Duan
//z5248147
//27/09/2019
#include <stdio.h>
int main(void) {
    int numa;
    int numb;
    double average;
    int numc;
    printf("Enter the number of sides on your dice: ");
    scanf("%d", &numa);
    printf("Enter the number of dice being rolled: ");
    scanf("%d", &numb);
    numc = numa * numb;
    average = (numb + numc) / 2.0;
    if (numa > 0 && numb > 0) {
        printf("Your dice range is %d to %d.\n", numb, numc);
        printf("The average value is %.6lf\n", average);
    } else {
        printf("These dice will not produce a range.\n");
        } 
    return 0;
}
