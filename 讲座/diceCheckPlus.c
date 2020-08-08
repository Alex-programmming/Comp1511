/* A Dice checking app
Marc Chee September 2019

This will take dice roll numbers from a user
and add them together.

It will then check if the roll total is higher
or lower than a secret target number

This version uses a constant for dice size
and corrects any invalid input while reporting
the invalid number.

*/

#include <stdio.h>

#define EXIT_SUCCESS 0
#define SECRET_VALUE 7
#define DICE_SIZE 6

int main(void) {
    int dieOne;
    int dieTwo;
    
    // Get user input for dice rolls
    printf("Please type in the result of the first die:\n");
    scanf("%d", &dieOne);
    if (1 <= dieOne && dieOne <= DICE_SIZE) {
        // this is valid for 1-dice size
        
        // Note: This if statement isn't necessary, but
        // it was part of the example show in the lecture
        // If you want to see an interesting alternative
        // look at how the second die is handled below
    } else {        
        printf("%d was invalid, ", dieOne);
        
        // Use mod to give a value inside the range 1-dice size
        dieOne = dieOne % DICE_SIZE;
        if (dieOne == 0) {
            dieOne = DICE_SIZE;
        }
        printf("and has been corrected to %d.\n", dieOne);
    }
    
    printf("Please type in the result of the second die:\n");
    scanf("%d", &dieTwo);
    if (dieTwo < 1 || dieTwo > diceSize) {
        // Correct and report an invalid dice roll       
        printf("%d was invalid, ", dieTwo);
        
        // Use mod to give a value inside the range 1-dice size
        dieTwo = dieTwo % diceSize;
        if (dieTwo == 0) {
            dieTwo = diceSize;
        }
        printf("and has been corrected to %d.\n", dieTwo);
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








