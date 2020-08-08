// Author: Finbar Berkon
// Date: October 2019
// A program to read input until EOF

#include <stdio.h> 

int main(void) {

    int numbers[10] = {0};
    
    int index = 0;
    int result = scanf("%d", &numbers[index]);

        
    while (result == 1 && index < 10) {
        index++;
        result = scanf("%d", &numbers[index]);
    }
    
    printf("You entered:\n");
    int j = 0;
    while (j < index) {
        printf("%d\n", numbers[j]);
        j++;
    }

    return 0;
}
