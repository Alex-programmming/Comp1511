#include <stdio.h>

int main(void) {
    int character = getchar();
    while (character != EOF) {
        putchar(character);
        character = getchar();
    }
}
