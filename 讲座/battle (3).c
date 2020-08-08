// A Battle Royale player tracker

// This program keeps player names in a linked list
// It shows how to build a list, adding nodes
// and also removing nodes as players are knocked out

// Marc Chee (cs1511@cse.unsw.edu.au), October/November 2019

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 100

struct player {
    struct player *next;
    char name[MAX_NAME];
};

struct player *create_player(struct player *new_next, char new_name[MAX_NAME]);
int print_players(struct player *head);
struct player *insert_player(struct player *insert_after, char new_name[MAX_NAME]);
struct player *insert_alpha(struct player *head, char new_name[MAX_NAME]);
struct player *remove_player(struct player *head, char rem_name[MAX_NAME]);
void free_list(struct player *head);

int main(void) {
    struct player *head = NULL;
    head = insert_alpha(head, "Marc");
    head = insert_alpha(head, "AndrewB");
    head = insert_alpha(head, "Tom");
    head = insert_alpha(head, "Aang");
    head = insert_alpha(head, "Sokka");
    
    // main game loop
    while (print_players(head) > 1) {
        printf("-----------\n");
        printf("Who just got knocked out?\n");
        char ko_name[MAX_NAME];
        fgets(ko_name, MAX_NAME, stdin);
        // slightly dodgy way of removing the \n from the end of the string
        ko_name[strlen(ko_name) - 1] = '\0';
        head = remove_player(head, ko_name);
        printf("-----------\n");
    }
    printf("Has won the Battle Royale!\n");
    free_list(head);
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
int print_players(struct player *head) {
    int player_count = 0;
    struct player *cur_player = head;
    while (cur_player != NULL) {
        printf("%s\n", cur_player->name);
        player_count++;
        cur_player = cur_player->next;
    }
    return player_count;
}

// Insert a player in a linked list after the player "insert_after"
// Will create the new node with the name "new_name"
// Returns a pointer to the node that was just inserted
struct player *insert_player(struct player *insert_after, char new_name[MAX_NAME]) {
    struct player *new_player = create_player(NULL, new_name);
    if (insert_after != NULL) {
        // inserting into a list that's not empty
        new_player->next = insert_after->next;
        insert_after->next = new_player;
    }    
    
    // If the list was empty, we've created a new node with 
    // next == NULL and we're still returning that node
    
    return new_player;
}

// Create and insert a new player named new_name
// into the list starting at head
// Inserts in a roughly alphabetical order (using strcmp)
// Return the head of the list
struct player *insert_alpha(struct player *head, char new_name[MAX_NAME]) {
    // find the position in the list that we want to insert
    struct player *cur_player = head;
    struct player *previous = NULL;
    // This loop stops when it reaches the alphabetically
    // correct position to insert new_name
    while (cur_player != NULL && strcmp(cur_player->name, new_name) <= 0) {
        previous = cur_player;
        cur_player = cur_player->next;
    }
    
    // call the insert function in the right place
    struct player *insert_point = insert_player(previous, new_name);
    // return the head
    if (previous == NULL) {
        // we inserted at the start of the list, we've changed the head
        insert_point->next = head;
        head = insert_point;
    }
    return head;
}

// remove a player that matches rem_name from the list pointed at by head
// return a pointer to the head of the resulting list (even if the first
// element was removed)
struct player *remove_player(struct player *head, char rem_name[MAX_NAME]) {
    // find the player node that matches rem_name
    struct player *cur_player = head;
    struct player *previous = NULL;
    while (cur_player != NULL && strcmp(cur_player->name, rem_name) != 0) {
        previous = cur_player;
        cur_player = cur_player->next;
    }
    if (cur_player != NULL) {
        // we found the right node, remove it
        if (previous == NULL) {
            // we are removing the first element of the list
            head = cur_player->next;
            free(cur_player);
        } else {
            // we are removing an element anywhere but the start of the list
            previous->next = cur_player->next;
            free(cur_player);
        }        
    }
    return head;
}

// Loop through the linked list, freeing all the player nodes
void free_list(struct player *head) {
    struct player *cur_player = head;
    while (cur_player != NULL) {
        struct player *free_player = cur_player;
        cur_player = cur_player->next;
        free(free_player);
    }
}






