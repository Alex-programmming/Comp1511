// A program that shows us all possible
// totals of two dice.

// It will also show us the percentage
// chance of rolling a certain total
// using these two dice

// Marc Chee (cs1511@cse.unsw.edu.au), October 2019

#include <stdio.h>

int main(void) {
    int dieOneSize;
    int dieTwoSize;
    int targetValue;
    
    // Set up dice sizes and target based on user input
    printf("Please enter the size of the first die: ");
    scanf("%d", &dieOneSize);
    printf("Please enter the size of the second die: ");
    scanf("%d", &dieTwoSize);
    printf("Please enter the target value: ");
    scanf("%d", &targetValue);
    
    // Loop through all possible totals of the dice
    int numRolls = 0;
    int numSuccesses = 0;
    
    int dieOneCounter = 1;
    while (dieOneCounter <= dieOneSize) {
        int dieTwoCounter = 1;
        while (dieTwoCounter <= dieTwoSize) {
            numRolls++;
            int total = dieOneCounter + dieTwoCounter;
            if (total == targetValue) {
                numSuccesses++;
                printf(
                    "Die One: %d, Die Two: %d, Total: %d\n", 
                    dieOneCounter, dieTwoCounter, total
                );
            }
            
            dieTwoCounter++;
        }
        dieOneCounter++;
    }
    
    // Print out the percentage chance of rolling the target value
    printf(
        "Rolled %d times, matched %d %d times. Chance of success %lf.\n",
        numRolls,
        targetValue,
        numSuccesses,
        (numSuccesses / (numRolls * 1.0)) * 100
    );
    
    return 0;
}
