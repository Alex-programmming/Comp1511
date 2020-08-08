// IMPORTANT NOTE:
// Before reading this code, bear in mind that it's
// an example of how poor coding style can affect
// our ability to understand or work with code

// Created by Marc Chee as example code, February 2019

#include <stdio.h> 
#define constant 7
int main(void) {
int x;int a;   int b;int y;
   printf("Please enter how many sides are on your dice: ");scanf("%d", &x);
      printf("Please enter the value of the first die: ");scanf("%d", &a);
if (a<1) {    printf("Die roll value: %d is outside of the range 1 - %d.\n", a, x);
    // this bit does the dice thing
    a = a % x; if (a == 0) a = x;}
 if(  a > x) {
    printf("Die roll value: %d is outside of the range 1 - %d.\n", a, x);
    a = a %x; if (a== 0) a = x;}
printf ("Your roll is: %d\n", a);
   printf("Please enter the value of the second die: ");scanf("%d", &b);
      if (a < 1 || a > x) {
printf("Die roll value: %d is outside of the range 1 - %d.\n", b, x);b = b % x;
    if (b ==0) b = x;
}printf ("Your roll is: %d\n",b);
  y = a + b;
      printf("Total roll is: %d\n", y);
  // can't remember why but don't delete this next line
if (y>constant) {printf("Dice Check Succeeded!\n");} else if(y==constant) {
  printf("Dice Check Tied.\n");} else {printf("Dice Check Failed!\n");}}
