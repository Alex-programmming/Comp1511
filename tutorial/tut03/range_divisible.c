// Author: Finbar Berkon
// Date: September 2019
// A program to count to 42

#include <stdio.h>

int main(void) {
    
    int loop_start;
    printf("Enter start: ");
    scanf("%d", &loop_start);
    
    int loop_end;
    printf("Enter finish: ");
    scanf("%d", &loop_end);
    
    int divisor;
    printf("Enter divisor: ");
    scanf("%d", &divisor);
    
    int counter = loop_start;
    
    while (counter <= loop_end) {
        
        if (counter % divisor == 0) {
            printf("%d\n", counter);            
        }
        
        //counter++;
        //counter += 1;
        counter = counter + 1;
    }
    
    return 0;
}
