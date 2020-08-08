// Perform the ROT13 algorithm on a string
// Completed by
//  ... (z0000000)
// Completed on 2019-??-??

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 256

// Add your own #defines here

void rotate_thirteen(char *string);
char rotate_one(char c);
void rotate_thirteen(char *string);
int strings_equal(char *string1, char *string2);

// Add your own function prototypes here

int main(int argc, char *argv[]) {
    // Example tests
    char test_a[MAX_LENGTH] = "Hello, world!";
    rotate_thirteen(test_a);
    assert(strings_equal("Uryyb, jbeyq!", test_a));

    char test_b[MAX_LENGTH] = "abcdefghijklmnopqrstuvwxyz";
    rotate_thirteen(test_b);
    assert(strings_equal("nopqrstuvwxyzabcdefghijklm", test_b));

    char test_c[MAX_LENGTH] = "The quick brown fox jumped over the lazy dog.";
    rotate_thirteen(test_c);
    assert(strings_equal("Gur dhvpx oebja sbk whzcrq bire gur ynml qbt.", test_c));

    // Add your own tests here

    printf("All tests passed. You are awesome!\n");

    return 0;
}

void rotate_thirteen(char *string) {
    // YOUR CODE HERE
    // See: https://en.wikipedia.org/wiki/ROT13
    int i;
    for (i = 0; string[i] != '\0'; i++);
    int length = i;
    i = 0;
    while (i < length) {
        int j = 0;
        while (j < 13) {
            string[i] = rotate_one(string[i]);
            j++;
        }
        i++;
    }
}

char rotate_one(char c) {
    // Your code goes here!
    // Don't forget to return your result.
    if (c >= 'a' && c <= 'z') {
        if (c + 1 > 'z') {
            return 'a';
        } else {
            return (c + 1);
        }
    } else if (c >= 'A' && c <= 'Z') {
        if (c + 1 > 'Z') {
            return 'A';
        } else {
            return (c + 1);
        }
    } else {
        return c;
    }
    

}

int strings_equal(char *string1, char *string2) {
    // Your code goes here!
    // Don't forget to return your result.
    int i = 0;
    int value = 0;
    for (i = 0; string1[i] != '\0'; i++);
    int length1 = i;
    for (i = 0; string2[i] != '\0'; i++);
    int length2 = i;
        i = 0;
    while (string1[i] != '\0' && string2[i] != '\0') {
        if (string1[i] == string2[i]) {
            i++;
        } else {
            value = 1;
            break;
        }
    }
    if (value == 0 && length1 == length2) {
        return 1;
    } else {
        return 0;
    }
    
}
