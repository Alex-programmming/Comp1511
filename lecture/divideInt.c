// A demo for dividing integers and using doubles

// Marc Chee (cs1511@cse.unsw.edu.au), September 2019

#include <stdio.h>

int main(void) {
    int metres = 10;
    int seconds = 15;
    
    int speed = metres/seconds;
    printf("Speed in integers is: %d\n", speed);
    
    double double_speed = metres/(seconds * 1.0);
    printf("Speed in doubles is: %lf\n", double_speed);
    
    return 0;
}
