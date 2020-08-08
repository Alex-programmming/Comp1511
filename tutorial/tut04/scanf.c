// Author: Finbar Berkon
// Date: October 2019
// A program to read input until EOF

#include <stdio.h> 

int main(void) {

    int numbers[10] = {0};
    
    int i = 0;
    int result = scanf("%d", &numbers[i]);

        
    while (result == 1 && i < 10) {
        i++;
        result = scanf("%d", &numbers[i]);
    }
    
    int j = 0;
    while (j < ) {
        
    }

    return 0;
}
