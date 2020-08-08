// A demo of structs using the most awesome fighting team

// Marc Chee (marc.chee@unsw.edu.au)

#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 50

struct ninja {
    char name[MAX_LENGTH];
    char phrase[MAX_LENGTH];
    int power;
    int health;
};

int main(void) {
    struct ninja leo;
    strcpy(leo.name, "Leonardo");
    strcpy(leo.phrase, "Leonardo Leads");
    leo.power = 8;
    leo.health = 8;

    printf("%s's phrase is: %s.\n", leo.name, leo.phrase);
}

