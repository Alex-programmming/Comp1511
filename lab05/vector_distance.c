// Haoheng Duan
// z5248147
// 18/10/2019


#include <stdio.h>
#include <math.h>

int main(void) {
    int size;
    printf("Enter vector length: ");
    scanf("%d", &size);
    int vector1[size];
    printf("Enter vector 1: ");
    int i = 0;
    while (i < size) {
        scanf("%d", &vector1[i]);
        i++;
    }
    int vector2[size];
    printf("Enter vector 2: ");
    int j = 0;
    while (j < size) {
        scanf("%d", &vector2[j]);
        j++;
    }
    printf("Euclidean distance =  ");
    int sum = 0;
    int num = 0;
    while (num < size) {
        sum = sum + (vector2[num] - vector1[num]) * (vector2[num] - vector1[num]);
        num++;
    }
    double outcome = sqrt(sum);
    printf("%.6lf\n", outcome);
    return 0;  
}
