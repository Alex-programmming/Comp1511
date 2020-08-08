// A program to store player scores in a game

// It will show use of arrays and looping

// Capabilities:
// Store scores
// Show winner/loser
// Show total of all scores

#include <stdio.h>

#define NUM_PLAYERS 4

int main(void) {
    int scores[NUM_PLAYERS] = {0};
    
    // Explicitly assigning scores to 4 players
    //scores[0] = 11;
    //scores[1] = 27;
    //scores[2] = 76;
    //scores[3] = 55;
    
    // Read in all the players' scores
    int i = 0;
    while (i < NUM_PLAYERS) {
        printf("Please enter Player %d's score: ", i);
        scanf("%d", &scores[i]);
        i++;
    }
    
    // Print all the player's scores
    i = 0;
    while (i < NUM_PLAYERS) {
        printf("Player %d has a score of %d\n", i, scores[i]);
        i++;
    }
    
    // Find the current highest scoring player and their score
    i = 0;
    int winningPlayer = 0;
    int highestScore = scores[0];
    int totalScore = 0;
    while (i < NUM_PLAYERS) {
        printf("Checking player %d\n", i);
        if (scores[i] > highestScore) {
            printf(
                "Player %d's score, %d is higher than %d\n",
                i, scores[i], highestScore
            );
            winningPlayer = i;
            highestScore = scores[i];
        }
        totalScore += scores[i];
        i++;
    }
    printf(
        "The winner is Player %d with a score of %d\n", 
        winningPlayer, highestScore
    );
    printf("The total of all players' scores is %d\n", totalScore);
    
    return 0;
}




