// Haoheng Duan
// z5248147
// 18/10/2019

#include <stdio.h>

int main(void) {
    int size;
    printf("Enter vector length: ");
    scanf("%d", &size);
    int vector[size];
    printf("Enter vector : ");
    int i = 0;
    while (i < size) {
        scanf("%d", &vector[i]);
        i++;
    }
    int array[size];
    printf("Enter permutation: ");
    int j = 0;
    while (j < size) {
        scanf("%d", &array[j]);
        if (array[j] < 0 || array[j] >= size) {
            printf("Invalid permutation\n");
            return 0;
        }
        j++; 
    }
    j = 0;
    while (j < size) {
        printf("%d", vector[array[j]]);
        j++; 
    }
    
    printf("\n");
    
    
    return 0;
}
