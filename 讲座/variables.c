// Variables demo
// Marc Chee, February 2019

#include <stdio.h>

#define PI 3.14159265359
#define SPEED_OF_LIGHT 299792458.0

int main (void) {
    // Declaring a variable
    int answer;
    // Initialising the variable
    answer = 42;
    // Give the variable a different value
    answer = 7;

    // we can also Declare and Initialise together
	int answerTwo = 88;

    // printing a variable
    int number = 7;
    printf("My number is %d\n", number);
    
    // print two variables
    int first = 5;
    int second = 10;
    printf("First is %d and second is %d\n", first, second);
    
    // print an int and a double
    int diameter = 5;
    double pi = 3.14159;
    printf("Diameter is %d, pi is , %lf\n", diameter, pi);
    
    // reading an integer
    int input;
    printf("Please type in a number: ");
    scanf("%d", &input);
    
    // reading a double
    double inputDouble;
    printf("Please type in a decimal point number: ");
    scanf("%lf", &inputDouble);
    
    // some basic maths
    int x = 5;
    int y = 10;
    int result;
    result = (x + y) * x;
    printf("My maths comes out to: %d\n", result);
}
