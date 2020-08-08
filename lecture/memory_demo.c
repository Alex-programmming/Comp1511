// Simple demonstration of memory allocation

// Marc Chee (marc.chee@unsw.edu.au), July 2019

int *mallocNumber()

int main(void) {
    // Use an allocated variable via its pointer then free it
    int *iPointer = mallocNumber();
    
    *iPointer += 25;

    free(iPointer);
    return 0;
}

// Allocate memory for a number and return a pointer to it
int *mallocNumber() {
    int *intPointer = malloc(sizeof(int));
    *intPointer = 10;
    return intPointer;
}

