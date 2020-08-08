// Author: unknown
// Date: ?
// Naive calculation of an average using constants

#include <stdio.h>

#define FIRST_NUMBER     10
#define SECOND_NUMBER    20
#define TOTAL   FIRST_NUMBER + SECOND_NUMBER
#define AVERAGE TOTAL / 2

int main(void) {
    printf("The average of %d and %d is %d\n",
           FIRST_NUMBER, SECOND_NUMBER, AVERAGE);

    return 0;
}
