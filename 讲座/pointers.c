// Some examples of using pointers
// Marc Chee, July 2019

#include <stdio.h>

// note that even though these two functions have
// the same name, they're actually different
// because they have different input parameters
void incrementInt(int n);
void incrementPointer(int *n);

int main(void) {
    int i = 100;
    // create a pointer called ip that points at
    // an integer in the location of i
    int *ip = &i;
    printf("%p is the address of i, which has the value %d\n", ip, *ip);
    
    incrementInt(i);
    printf("i, %d, hasn't changed.\n", i);
    incrementPointer(ip);
    printf("i, %d, has now changed.\n", i);
    
    int numbers[10];
    
    // showing that arrays are actually pointers
    // to chunks of memory
    printf("%p\n", &numbers[0]);
    printf("%p\n", numbers);

}

// this function will have no effect!
void incrementInt(int n) { 
    n = n + 1; 
}
// this function will affect whatever n is pointing at
void incrementPointer(int *n) { 
    *n = *n + 1; 
}

