/* A Dice checking app
Marc Chee September 2019

This will take dice roll numbers from a user
and add them together.

It will then check if the roll total is higher
or lower than a secret target number

*/

#include <stdio.h>

#define SECRET_VALUE 7

int main(void) {
    int dieOne;
    int dieTwo;
    int total;
    
    // Get user input for dice rolls
    printf("Please type in the result of the first die:\n");
    scanf("%d", &dieOne);
    printf("Please type in the result of the second die:\n");
    scanf("%d", &dieTwo);
    
    printf("You rolled %d and %d\n", dieOne, dieTwo);
    
    // create total and check against the secret number
    total = dieOne + dieTwo;
    
    printf("The total is %d\n", total);
        
    if (total > SECRET_VALUE) {
        // total is higher than SECRET_VALUE
        printf("You succeeded!\n");
    } else if (total == SECRET_VALUE) {
        // total is tied with SECRET_VALUE
        printf("An exact tie!\n");
    } else {
        // total is lower than SECRET_VALUE
        printf("You failed!\n");
    }
    
    return 0;
}








