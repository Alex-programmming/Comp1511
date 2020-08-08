// Author: Finbar Berkon
// Date: September 2019
// A program to count to 42

#include <stdio.h>

#define LOOP_END 42

int main(void) {
    
    int counter = 1;
    
    while (counter <= LOOP_END) {
        printf("%d\n", counter);
        
        //counter++;
        //counter += 1;
        counter = counter + 1;
    }
    
    return 0;
}
