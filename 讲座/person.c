// First look at multi-file projects
// This code is an adaptation of a live stream on pointers and structs

// Marc Chee (marc.chee@unsw.edu.au), July 2019

// Implementation of the person that is declared in person.h

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "person.h"


struct person {
    char name[MAX_NAME_LENGTH];
    char powers[MAX_NUM_POWERS][MAX_POWER_LENGTH];
    int num_powers;
};

Person create_person(char name[MAX_NAME_LENGTH]) {
    Person hero = malloc(sizeof (struct person));
    strcpy(hero->name, name);
    hero->num_powers = 0;
    return hero;
}

void free_person(Person hero) {
    free(hero);
}

void give_power(char power[MAX_POWER_LENGTH], struct person *hero) {
    if (hero->num_powers < MAX_NUM_POWERS) {
        strcpy(hero->powers[hero->num_powers], power);
        hero->num_powers++;
    }
}

void display_person(struct person *hero) {
    printf("Name: %s\n", hero->name);
    printf("Powers:\n");
    int i = 0;
    while(i < hero->num_powers) {
        fputs(hero->powers[i], stdout);
        putchar('\n');
        i++;
    }
    printf("----------\n");
}

