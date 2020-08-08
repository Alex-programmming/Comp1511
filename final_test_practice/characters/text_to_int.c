#include <stdio.h>

int main(void) {
    int character = getchar();
    while (character != EOF) {
        printf("%d\n", character);
        character = getchar();
    }
}
