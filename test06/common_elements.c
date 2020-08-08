// z5248147
// Haoheng Duan
// copy all of the values in source1 which are also found in source2 into 
// destination
// return the number of elements copied into destination

int common_elements(int length, int source1[length], int source2[length], 
int destination[length]) {
    // PUT YOUR CODE HERE (you must change the next line!)
    int i = 0;
    int counter = 0;
    int num = 0;
    while (i < length) {
        int j = 0;
        int index = 0;
        while (j < length) {
            if (source1[i] == source2[j]) {
                index++;          
            }
            j++;
        }
        if (index >= 1) {
            counter++;
            destination[num] = source1[i];
            num++;
        }
        i++;
    }
    
    
    return counter;
}

// You may optionally add a main function to test your common_elements function.
// It will not be marked.
// Only your common_elements function will be marked.
