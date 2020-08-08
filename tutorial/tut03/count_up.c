// Author: Finbar Berkon
// Date: September 2019
// A program to count to 42

#include <stdio.h>

int main(void) {
    
    int loop_end;
    printf("Enter finish: ");
    scanf("%d", &loop_end);
    
    int counter = 1;
    
    while (counter <= loop_end) {
        printf("%d\n", counter);
        
        //counter++;
        //counter += 1;
        counter = counter + 1;
    }
    
    return 0;
}
