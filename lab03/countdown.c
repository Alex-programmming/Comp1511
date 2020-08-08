// Haoheng Duan
// z5248147
// 04/10/2019
// This program uses a loop to print a countdown from 10 to 0

#include <stdio.h>

int main(void) {
    //initialise counter to 10
    int counter = 10;
    // loop until not >= 0
    while (counter >= 0) {
        // print counter
        printf("%d\n", counter);
        // increment counter
        counter = counter - 1;
    }

    return 0;
}
