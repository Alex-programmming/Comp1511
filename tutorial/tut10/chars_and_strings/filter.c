// process characters 1 by 1 when we DON'T KNOW how many
// we will be given

#include <stdio.h>

#define TRUE 1
#define FALSE 0

int isAlpha(int ch);

int main(void) {
    
    printf("Please enter some text to be stripped of punctuation:\n");

    // initialise your ch character (like: int i = 0;)
    int ch = getchar();
    // Make sure the loop ends (like: while (i < SIZE))
    while (ch != EOF) {

        // Do something to each element
        if (isAlpha(ch) == TRUE) {
            putchar(ch);
        }

        // increment your condition variable (like: i++;)
        ch = getchar();
    }

    return 0;
}

int isAlpha(int ch) {
    if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) {
        return TRUE;
    } else {
        return FALSE;
    }

    // fun fact: you can return the result of this if statement directly, like so:
    // return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z');
    //        ^ this whole expression will evaluate to true or false (that's how the if
    //          statement works in the first place) and return that result
}
