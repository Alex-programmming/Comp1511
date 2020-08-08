/* A Dice checking app
Marc Chee September 2019

This will take dice roll numbers from a user
and add them together.

It will then check if the roll total is higher
or lower than a secret target number

This version exits if there is any invalid input

*/

#include <stdio.h>

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1
#define SECRET_VALUE 7

int main(void) {
    int dieOne;
    int dieTwo;
    int diceSize = 6;
    
    // Ask the user for the size of the dice
    printf("How many sides are on the dice?\n");
    scanf("%d", &diceSize);
    
    // Get user input for dice rolls
    printf("Please type in the result of the first die:\n");
    scanf("%d", &dieOne);
    if (1 <= dieOne && dieOne <= diceSize) {
        // this is valid for 1-dice size
        
        // Note: This if statement isn't necessary, but
        // it was part of the example shown in the lecture
        // If you want to see an interesting alternative
        // look at how the second die is handled below
    } else {        
        printf("%d was invalid for the range 1-%d.\n", dieOne, diceSize);
        return EXIT_FAILURE;
    }
    
    printf("Please type in the result of the second die:\n");
    scanf("%d", &dieTwo);
    if (dieTwo < 1 || dieTwo > diceSize) {
        printf("%d was invalid for the range 1-%d.\n", dieTwo, diceSize);
        return EXIT_FAILURE;
    }
    
    printf("You rolled %d and %d\n", dieOne, dieTwo);
    
    // create total and check against the secret number
    int total = dieOne + dieTwo;
    
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
    
    return EXIT_SUCCESS;
}








