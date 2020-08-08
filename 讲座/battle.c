// A Battle Royale player tracker

// This program keeps player names in a linked list
// It shows how to build a list, adding nodes
// and also removing nodes as players are knocked out

// Marc Chee (cs1511@cse.unsw.edu.au), October 2019

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 100

struct player {
    struct player *next;
    char name[MAX_NAME];
};

struct player *create_player(struct player *new_next, char new_name[MAX_NAME]);
void print_players(struct player *head);
struct player *insert_player(struct player *insert_after, char new_name[MAX_NAME]);

int main(void) {
    struct player *head = NULL;
    head = create_player(head, "Marc");
    head = create_player(head, "AndrewB");
    head = create_player(head, "Tom");
    head = create_player(head, "Aang");
    head = create_player(head, "Sokka");
    
    print_players(head);
    
    return 0;
}

// Allocate memory for a player
// Initialise the player with new_next and new_name
// Return a pointer to the player that was just created
struct player *create_player(struct player *new_next, char new_name[MAX_NAME]) {
    struct player *new_player = malloc(sizeof(struct player));
    new_player->next = new_next;
    strcpy(new_player->name, new_name);
    return new_player;
}

// Loop through the list from head
// print out the names of each player in the list
void print_players(struct player *head) {
    struct player *cur_player = head;
    while (cur_player != NULL) {
        printf("%s\n", cur_player->name);
        cur_player = cur_player->next;
    }
}



