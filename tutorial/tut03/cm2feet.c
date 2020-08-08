// Author: Finbar Berkon
// Date: June 2019
// A program to convert cm to feet

#include <stdio.h>

#define CM_IN_INCH 2.54
#define INCH_IN_FOOT 12

int main(void) {
    
    int height_cm = 0;
    
    printf("Enter your height in centimetres: ");
    scanf("%d", &height_cm);
    
    // Is there a better variable type we could use here?
    int height_ft = (height_cm / INCH_IN_CM) / FOOT_IN_INCH;
    
    printf("Your height in feet is %d\n", height_ft);
    
    return 0;
}
