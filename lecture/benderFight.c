// A simulation of a battle between Element Benders 
// A team of four will face a single powerful enemy

// This demo shows use of structs

// Marc Chee (cs1511@cse.unsw.edu.au)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 100
#define TEAM_SIZE 4

// struct for characters
struct bender {
    char name[MAX_LENGTH];
    char element[MAX_LENGTH];
    int power;
    int health;
};

void setup_team(struct bender companions[TEAM_SIZE]);
void attack(struct bender *attacker, struct bender *defender);
int still_alive(struct bender team[TEAM_SIZE], struct bender *solo);
void declare_element(struct bender *b);

int main(int argc, char *argv[]) {
    if (argc > 1) {
        srand(strtol(argv[1], NULL, 10));
    }

    struct bender companions[TEAM_SIZE];
    setup_team(companions);
    struct bender zuko;
    strcpy(zuko.name, "Prince Zuko");
    strcpy(zuko.element, "Fire");
    zuko.power = 12;
    zuko.health = 20;
    
    // Fight between the two teams
    int team_count = 0;
    struct bender *companion = &companions[team_count];
    struct bender *enemy = &zuko;
    declare_element(companion);
    declare_element(enemy);
    
    while (still_alive(companions, enemy)) {
        if (companion->health <= 0) {
            // companion knocked out, replace with
            // the next companion
            team_count++;
            companion = &companions[team_count];
            declare_element(companion);
        } else {
            attack(enemy, companion);
            attack(companion, enemy);
        }
    }
    
    return 0;
}

// Enter all the details for the team of Benders
void setup_team(struct bender companions[TEAM_SIZE]) {
    strcpy(companions[0].name, "Aang");
    strcpy(companions[0].element, "Air");
    companions[0].power = 10;
    companions[0].health = 5;
    strcpy(companions[1].name, "Katara");
    strcpy(companions[1].element, "Water");
    companions[1].power = 7;
    companions[1].health = 7;
    strcpy(companions[2].name, "Sokka");
    strcpy(companions[2].element, "None");
    companions[2].power = 2;
    companions[2].health = 10;
    strcpy(companions[3].name, "Toph");
    strcpy(companions[3].element, "Earth");
    companions[3].power = 8;
    companions[3].health = 8;
}

// attacker hits defender
// defender->health will lower by attacker->power
void attack(struct bender *attacker, struct bender *defender) {
    int damage = (rand() % attacker->power) + 1;
    
    printf(
        "%s attacks %s for %d damage.\n",
        attacker->name,
        defender->name,
        damage
    );
    
    defender->health -= damage;
    if (defender->health <= 0) {
        printf("%s has been knocked out.\n", defender->name);
    }
}

// returns 1 if both teams are still alive 
// (has any member with health > 0)
// returns 0 otherwise
int still_alive(struct bender team[TEAM_SIZE], struct bender *solo) {
    // is solo alive?
    int s_alive = 1;
    if (solo->health <= 0) {
        s_alive = 0;
    }
    
    // is anyone on the team alive?
    int t_alive = 0;
    int i = 0;
    while (i < TEAM_SIZE) {
        if (team[i].health > 0) {
            t_alive = 1;
        }
        i++;
    }
    
    return s_alive * t_alive;
}

// Print the Bender's name and element
void declare_element(struct bender *b) {
    printf(
        "%s wields the element of %s\n",
        b->name,
        b->element
    );
}

