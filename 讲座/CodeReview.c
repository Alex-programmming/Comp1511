// Some Code for Review
// Marc Chee, September 2019

#include <stdio.h>

int main(void) 
{
    // Read in the number.
    printf("Please enter an integer: ");
    int num;
    scanf("%d", &num);

    printf("You entered ");
    if (num <= 0) 
    {
        printf("a number less than one.");
    } 
    if (num == 1) 
    {
        printf("one.");
    } 
    if (num == 2) 
    {
        printf("two.");
    } 
    if (num == 3) 
    {
        printf("three.");
    } 
    if (num == 4) 
    {
        printf("four.");
    } 
    if (num == 5) 
    {
        printf("five.");
    } 
    else 
    {
        printf("a number greater than five.");
    }
    printf("\n");
    
    return 0;
}
