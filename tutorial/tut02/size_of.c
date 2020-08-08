// Author: Finbar Berkon (finbar.berkon@unsw.edu.au)
// Date: June 2019
// A program that will print out the sizes of various data types

#include <stdio.h>

#define BITS_IN_BYTE 8

int main(void) {

	// %lu is used to print an 'unsigned long' which is similar to
	// an integer in C, except without the signed bit (ie, it cannot
	// be negative) that is also double the length of an int. This 
	// is just the type of the value returned from sizeof and has
	// nothing to do with the actual size of the value we're looking at.
	printf("sizeof(char) = %lu byte = %lu bits\n",
			sizeof(char), sizeof(char) * BITS_IN_BYTE);
	printf("sizeof(int) = %lu bytes = %lu bits\n",
			sizeof(int), sizeof(int) * BITS_IN_BYTE);
	printf("sizeof(double) = %lu bytes = %lu bits\n",
			sizeof(double), sizeof(double) * BITS_IN_BYTE);

	return 0;
}
