// Assignment 2 19T3 COMP1511: Pokedex
// pokedex.c
//
// This program was written by Haoheng Duan (z5248147)
// on 16/11/2019

// Head Comment: This program contains functions that are called in main.c.
// These functions will print or change the properties of each pokemon or 
// the whole pokedex.

// Version 2.0.0: Release


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


// ----------------------------------------------

#include "pokedex.h"
#include <stdbool.h>


// ----------------------------------------------

#define FOUND 1
#define NOT_FOUND 0
#define CASE_DIFFERENCE ('a'-'A')
#define MAX_LINE 1024

//------------------------------------------------
struct pokedex {
    struct pokenode *head;
    struct pokenode *tail;
    struct pokenode *current_selected;

};


struct pokenode {
    Pokemon pokemon;
    struct pokenode *next;
    int findOrNot;
    struct pokenode *previous;
    struct pokenode *evolution;
    
};

//----------------------------------------------

// Compare if the strings are different to each other
static int compareString(const char *string1,const char *string2);

// Print the evolution of currently selected pokemon
static void printEvolution(struct pokenode *curr);

// Add pokenode to pokedex
static Pokedex addPokenodeToPokedex(Pokedex pokedex, struct pokenode *newPoke);

// Print the details of current selected pokemon
static void print_detail(Pokedex pokedex, Pokemon pokemon);

// Clone an existed pokenode
static struct pokenode *clone_pokenode(struct pokenode *original);

// Add pokenode to pokedex in order of the pokemon id
static Pokedex addPokenodeInOrder(Pokedex pokedex, struct pokenode *newPoke);

// Copy an original string to a new string
static char *copyString(char *newString, const char *original);

// Insert a pokonode in the middle of pokedex in the order of pokemon id
static void insertInMiddle(Pokedex pokedex, struct pokenode *newPoke);

// Search pokemon that contain given string appearing in its name in pokedex
static void searchInLoop(struct pokenode *curr, Pokedex newPokedex, char *text);

// Set the first not-yet-found Pokemon of each type to be found.
static void setFound(Pokedex pokedex, struct pokenode *largeLoop, 
    char seted_type[MAX_LINE][MAX_LINE], int *i, bool *flag);

// Creates a new pokenode struct and returns a pointer to it.
static struct pokenode *new_pokenode(Pokemon pokemon);

// Creates a new Pokedex, and returns a pointer to it.
Pokedex new_pokedex(void) {
    // Malloc memory for a new Pokedex, and check that the memory
    // allocation succeeded.
    Pokedex pokedex = malloc(sizeof(struct pokedex));
    assert(pokedex != NULL);

    // Set the head of the linked list to be NULL.
    // (i.e. set the Pokedex to be empty)
    pokedex->head = NULL;
    pokedex->tail = NULL;
    pokedex->current_selected = NULL;
    return pokedex;
}

// Create a new pokenode struct and returns a pointer to it.
// This function should allocate memory for a pokenode, set its pokemon
// pointer to point to the specified pokemon, and return a pointer to
// the allocated memory.
static struct pokenode *new_pokenode(Pokemon pokemon) {
    struct pokenode *newPoke = malloc(sizeof(struct pokenode));
    newPoke->pokemon = pokemon;
    newPoke->next = NULL;
    newPoke->previous = NULL;
    newPoke->findOrNot = NOT_FOUND;
    newPoke->evolution = NULL;
    return newPoke;
}

//////////////////////////////////////////////////////////////////////
//                         Stage 1 Functions                        //
//////////////////////////////////////////////////////////////////////

// Add a new Pokemon to the Pokedex.
void add_pokemon(Pokedex pokedex, Pokemon pokemon) {
    struct pokenode *newPoke = new_pokenode(pokemon);
    addPokenodeToPokedex(pokedex, newPoke);
}


// Print out the details of the currently selected Pokemon.
void detail_pokemon(Pokedex pokedex) {
    Pokemon pokemon = get_current_pokemon(pokedex);
    // Print the details of current selected pokemon
    print_detail(pokedex, pokemon);
}


// Return the currently selected Pokemon.
Pokemon get_current_pokemon(Pokedex pokedex) {
    if (pokedex->current_selected != NULL) {
        return pokedex->current_selected->pokemon;
    } else {
        printf("The Pokedex is empty, please add Pokemon\n");
        exit(1);
    }
}


// Sets the currently selected Pokemon to be 'found'.
void find_current_pokemon(Pokedex pokedex) {
    if (pokedex->current_selected != NULL) {
        pokedex->current_selected->findOrNot = FOUND;
    } else {
        exit(1);
    }
}


// Print out all of the Pokemon in the Pokedex.
void print_pokemon(Pokedex pokedex) {
    struct pokenode *curr = pokedex->head;
    while (curr != NULL) {
        if (curr == pokedex->current_selected) {
            printf("--> ");
        } else {
            printf("    ");
        }
        printf("#%.3d: ", pokemon_id(curr->pokemon));
        if (curr->findOrNot == NOT_FOUND) {
            // Count the length of the pokemon name
            int i;
            for (i = 0; pokemon_name(curr->pokemon) [i] != '\0'; i++);
            int j;
            for (j = 0; j < i; j++) {
                printf("*");
            }
            printf("\n");
        } else {
            printf("%s\n", pokemon_name(curr->pokemon));
        }
        curr = curr->next;
    }
}
//////////////////////////////////////////////////////////////////////
//                         Stage 2 Functions                        //
//////////////////////////////////////////////////////////////////////

// Change the currently selected Pokemon to be the next Pokemon in the Pokedex.
void next_pokemon(Pokedex pokedex) {
    // If there are no Pokemon in the Pokedex, this function does nothing.
    if (pokedex->head != NULL) {
        // If there is no next Pokemon, the current Pokemon is unchanged.
        if (pokedex->current_selected->next != NULL) {
            pokedex->current_selected = pokedex->current_selected->next;
        }
    }
}


// Change the currently selected Pokemon to be the previous Pokemon in the Pokedex.
void prev_pokemon(Pokedex pokedex) {
    // If there are no Pokemon in the Pokedex, this function does nothing.
    if (pokedex->head != NULL) {
        // If there is no previous Pokemon, the current Pokemon is unchanged.
        if (pokedex->current_selected->previous != NULL) {
            pokedex->current_selected = pokedex->current_selected->previous;
        }
    }
}


// Change the currently selected Pokemon to be the Pokemon with the ID `id`.
void change_current_pokemon(Pokedex pokedex, int id) {
    struct pokenode *curr = pokedex->head;
    // Flag is used to exit the loop
    bool flag = false;
    while (curr != NULL && flag == false) {
        if (pokemon_id(curr->pokemon) == id) {
            flag = true;
            pokedex->current_selected = curr;
        }
        curr = curr->next;
    }
}


// Remove the currently selected Pokemon from the Pokedex.
void remove_pokemon(Pokedex pokedex) {
    // If there are no Pokemon in the Pokedex, this function does nothing.
    if (pokedex->head != NULL) {  
        struct pokenode *currentNode = pokedex->current_selected;
        struct pokenode *previousNode = pokedex->current_selected->previous;
        struct pokenode *nextNode = pokedex->current_selected->next;
        // If the removed Pokemon was the only Pokemon in the Pokedex, the
        // currently selected Pokemon should become NULL.
        if (nextNode == NULL && previousNode == NULL) {
            destroy_pokemon(currentNode->pokemon);
            free(currentNode);
            pokedex->head = NULL;
        } else if (nextNode != NULL && previousNode == NULL) {            
            // At the beginning of the pokedex
            nextNode->previous = NULL;
            pokedex->head = pokedex->head->next;
            destroy_pokemon(currentNode->pokemon);
            free(currentNode);
            pokedex->current_selected = nextNode;
        } else if (nextNode != NULL && previousNode != NULL) {    
            // At the middle of the pokedex
            nextNode->previous = previousNode;
            previousNode->next = nextNode;
            destroy_pokemon(currentNode->pokemon);
            free(currentNode);
            pokedex->current_selected = nextNode;     
        } else if (previousNode != NULL && nextNode == NULL) {
            // At the end of the pokedex
            previousNode->next = NULL;
            pokedex->tail = pokedex->tail->previous;
            destroy_pokemon(currentNode->pokemon);
            free(currentNode);
            pokedex->current_selected = previousNode;
        }
    }
}


// Destroy the given Pokedex and free all associated memory.
void destroy_pokedex(Pokedex pokedex) {
    if (pokedex->head != NULL) {
        struct pokenode *curr = pokedex->head;
        while (curr != NULL) {
            // Free the memory of pokemon
            destroy_pokemon(curr->pokemon);
            if (curr->previous != NULL) {
                //Free previous pokenode
                free(curr->previous);
            }
            curr = curr->next;
        }
        // Free the tail of the pokenode
        free(pokedex->tail);
    }
    free(pokedex);
}

//////////////////////////////////////////////////////////////////////
//                         Stage 3 Functions                        //
//////////////////////////////////////////////////////////////////////

// Print out all of the different types of Pokemon in the Pokedex.
void show_types(Pokedex pokedex) {
    struct pokenode *largeLoop = pokedex->head;
    // Use a large loop to go through the whole pokedex
    while (largeLoop != NULL) {
        struct pokenode *smallLoop = pokedex->head;
        bool flag = false;
        // Check whether type1 exist before
        while (smallLoop != largeLoop && flag == false) {
            if (compareString(pokemon_type_to_string
            (pokemon_first_type(largeLoop->pokemon)), pokemon_type_to_string
            (pokemon_first_type(smallLoop->pokemon))) == 0 || 
            compareString(pokemon_type_to_string
            (pokemon_first_type(largeLoop->pokemon)), pokemon_type_to_string 
            (pokemon_second_type(smallLoop->pokemon))) == 0) {
                flag = true;
            }
            smallLoop = smallLoop->next;
        }
        // Not exist
        if (flag == false) {
            printf("%s\n", pokemon_type_to_string
                (pokemon_first_type(largeLoop->pokemon)));  
        }
        flag = false;
        smallLoop = pokedex->head;
        // Check whether type2 exist before
        while (smallLoop != largeLoop && flag == false) {
            if (compareString(pokemon_type_to_string
            (pokemon_second_type(largeLoop->pokemon)), pokemon_type_to_string
            (pokemon_first_type(smallLoop->pokemon))) == 0 || compareString
            (pokemon_type_to_string(pokemon_second_type(largeLoop->pokemon)), 
             pokemon_type_to_string (pokemon_second_type
            (smallLoop->pokemon))) == 0) {
                flag = true;
            }
            smallLoop = smallLoop->next;
        }
        // Not exist
        if (flag == false) {
            if (compareString(pokemon_type_to_string
                (pokemon_second_type(largeLoop->pokemon)), "None") != 0 ) {
                printf("%s\n", pokemon_type_to_string
                (pokemon_second_type(largeLoop->pokemon)));
            }
        }
        largeLoop = largeLoop->next;  
    }
}


// Set the first not-yet-found Pokemon of each type to be found.
void go_exploring(Pokedex pokedex) {
    struct pokenode *largeLoop = pokedex->head;
    // Use an array to save all the type that is seted to found
    char seted_type[MAX_LINE][MAX_LINE];
    int i = 0;
    bool flag = false;
    // Use a large loop to go through the whole pokedex
    while (largeLoop != NULL) {
        // Set the not found to be found
        if (largeLoop->findOrNot == NOT_FOUND) {
            setFound(pokedex, largeLoop, seted_type, &i, &flag);
        }
        largeLoop = largeLoop->next;
         
    }
}


// Return the total number of Pokemon in the Pokedex.
int count_total_pokemon(Pokedex pokedex) {
    int counter = 0;
    struct pokenode *curr = pokedex->head;
    while (curr != NULL) {
        counter++;
        curr = curr->next;
    }
    return counter;
}


// Return the number of Pokemon in the Pokedex that have been found.
int count_found_pokemon(Pokedex pokedex) {
    int counter = 0;
    struct pokenode *curr = pokedex->head;
    while (curr != NULL) {
        if (curr->findOrNot == FOUND) {
            counter++;
        }
        curr = curr->next;
    }
    return counter;
}

//////////////////////////////////////////////////////////////////////
//                         Stage 4 Functions                        //
//////////////////////////////////////////////////////////////////////

// Add the information that the Pokemon with the ID `from_id` can
// evolve into the Pokemon with the ID `to_id`.
void add_pokemon_evolution(Pokedex pokedex, int from_id, int to_id) {
    struct pokenode *curr = pokedex->head;
    bool from_id_exist = false;
    bool to_id_exist = false;
    struct pokenode *fromNode = pokedex->head;
    struct pokenode *toNode = pokedex->head;
    // Use a loop to find whether the id exists and point to them
    while (curr != NULL) {
        if (from_id == pokemon_id(curr->pokemon)) {  
            fromNode = curr;
            from_id_exist = true;
        }
        if (to_id == pokemon_id(curr->pokemon)) {
            toNode = curr;
            to_id_exist = true;
        }               
        curr = curr->next;
    }
    // If there is no Pokemon with the ID `from_id` or `to_id`,
    // or if the provided `from_id` and `to_id` are the same,
    if (from_id_exist == false || to_id_exist == false || from_id == to_id) {
        printf("The input ids are invalid and the program exits.\n");
        exit(1);
    } else {
        fromNode->evolution = toNode; 
    }
}

// Show the evolutions of the currently selected Pokemon.
void show_evolutions(Pokedex pokedex) {
    struct pokenode *curr = pokedex->current_selected;
    if (curr != NULL) {
        printEvolution(curr);
        curr = curr->evolution;
        while (curr != NULL) {
            printf("--> ");
            printEvolution(curr);
            curr = curr->evolution;
        }
        printf("\n");
    }
}


// Return the pokemon_id of the Pokemon that the currently selected
// Pokemon evolves into.
int get_next_evolution(Pokedex pokedex) {
    if (pokedex->head != NULL) {
        if (pokedex->current_selected->evolution == NULL) {
            return DOES_NOT_EVOLVE;
        } else {
            int id = pokemon_id(pokedex->current_selected->evolution->pokemon);
            return id;
        }
    } else {
        printf("The pokedex is empty, the program exit\n");
        exit(1);
    }
}


//////////////////////////////////////////////////////////////////////
//                         Stage 5 Functions                        //
//////////////////////////////////////////////////////////////////////

// Create a new Pokedex which contains only the Pokemon of a specified
// type from the original Pokedex.
Pokedex get_pokemon_of_type(Pokedex pokedex, pokemon_type type) {
    Pokedex newPokedex = new_pokedex();
    struct pokenode *curr = pokedex->head;
    // If the specified type is NONE_TYPE, INVALID_TYPE, or MAX_TYPE, this
    // function should print an appropriate error message and exit the
    // program.
    if (type != NONE_TYPE && type != INVALID_TYPE && type != MAX_TYPE) {
        while (curr != NULL) {
            // It should be found and type must exist
            if (curr->findOrNot == FOUND && (type == pokemon_first_type
            (curr->pokemon) || type == pokemon_second_type(curr->pokemon))) {
                struct pokenode *newPoke = clone_pokenode(curr);
                newPokedex = addPokenodeToPokedex(newPokedex, newPoke);
            }
            curr = curr->next;
        }
        return newPokedex;
    } else {
        printf("The type is invalid and the program will exit");
        exit(1);
    }
}


// Create a new Pokedex which contains only the Pokemon that have
// previously been 'found' from the original Pokedex.
Pokedex get_found_pokemon(Pokedex pokedex) {
    Pokedex newPokedex = new_pokedex();
    struct pokenode *curr = pokedex->head;
    while (curr != NULL) {
        if (curr->findOrNot == FOUND) {
            struct pokenode *newPoke = clone_pokenode(curr);
            newPokedex = addPokenodeInOrder(newPokedex, newPoke);
        }
        curr = curr->next;
    }
    return newPokedex;
}


// Create a new Pokedex containing only the Pokemon from the original
// Pokedex which have the given string appearing in its name.
Pokedex search_pokemon(Pokedex pokedex, char *text) {
    Pokedex newPokedex = new_pokedex();
    struct pokenode *curr = pokedex->head;
    while (curr != NULL) {
        if (curr->findOrNot == FOUND) {
            searchInLoop(curr, newPokedex, text);
        }
        curr = curr->next;
    }
    return newPokedex;
}


//-------------------------------------------------------------------------


// Compare if the strings are different to each other
static int compareString(const char *string01, const char *string02) {
    while (*string01 == *string02) {
        assert((string01 != NULL) && (string02 != NULL));                
        if (*string01 == '\0') {
            return 0;
        }
        string01++;
        string02++;
    }
    return *string01 - *string02;
}


// Print the evolution of currently selected pokemon
static void printEvolution(struct pokenode *curr) {
    printf("#%.3d ", pokemon_id(curr->pokemon));
    // Check if found or not
    if (curr->findOrNot == FOUND) {
        printf("%s [%s", pokemon_name(curr->pokemon), 
            pokemon_type_to_string(pokemon_first_type(curr->pokemon)));
        if (compareString(pokemon_type_to_string
        (pokemon_second_type(curr->pokemon)), "None") != 0) {
            printf(", %s", 
            pokemon_type_to_string(pokemon_second_type(curr->pokemon)));
        }
        printf("] ");
    } else {
        printf("???? [????] ");
    }
}


// Add pokenode to pokedex
static Pokedex addPokenodeToPokedex(Pokedex pokedex, struct pokenode *newPoke) {
    bool sameId = false;
    if (pokedex->head == NULL) {
        pokedex->head = newPoke;
        pokedex->tail = newPoke;
        pokedex->tail->previous = NULL;
        pokedex->current_selected = newPoke;
    } else {
        // Used to check whether it has the same id in the pokedex
        struct pokenode *curr = pokedex->head;
        while (curr != NULL) {
            if (pokemon_id(curr->pokemon) == pokemon_id(newPoke->pokemon)) {
                sameId = true; 
            } 
            curr = curr->next;
        }
        if (sameId == true) {
            printf("\nThis id already exists in the list. Please ");
            printf("\ntype p to view all the ids in the list\n");
        } else {
            struct pokenode *temp = pokedex->tail;
            pokedex->tail->next = newPoke;
            pokedex->tail = newPoke;
            pokedex->tail->previous = temp;
        }
    }
    pokedex->tail->next = NULL;
    return pokedex;
}


// Clone an existed pokenode
static struct pokenode *clone_pokenode(struct pokenode *original) {
    struct pokenode *clonePoke = malloc(sizeof(struct pokenode));
    clonePoke->pokemon = clone_pokemon(original->pokemon);
    clonePoke->next = NULL;
    clonePoke->previous = NULL;
    clonePoke->findOrNot = FOUND;
    clonePoke->evolution = NULL;
    return clonePoke;
}


// Add pokenode to pokedex in order of the pokemon id
static Pokedex addPokenodeInOrder(Pokedex pokedex, struct pokenode *newPoke) {
    if (pokedex->head == NULL) {
        pokedex->head = newPoke;
        pokedex->tail = newPoke;
        pokedex->tail->previous = NULL;
        pokedex->current_selected = newPoke;    
    } else {
        // Add pokemon to the end
        if (pokemon_id(newPoke->pokemon) > pokemon_id(pokedex->tail->pokemon)) {
            pokedex = addPokenodeToPokedex(pokedex, newPoke);
        } else if (pokemon_id(newPoke->pokemon) < 
            pokemon_id(pokedex->head->pokemon)) {
            // Add pokemon to the beginning
            newPoke->next = pokedex->head;
            pokedex->head->previous = newPoke;
            pokedex->head = newPoke;
        } else {
            insertInMiddle(pokedex, newPoke);
        }
        pokedex->head->previous = NULL;
        pokedex->current_selected = pokedex->head;
        pokedex->tail->next = NULL;
    }
    return pokedex;
}


// Insert a pokonode in the middle of pokedex in the order of pokemon id
static void insertInMiddle(Pokedex pokedex, struct pokenode *newPoke) {
    struct pokenode *curr = pokedex->head;
    // Flag is used to exit the loop
    bool flag = false;
    while (curr->next != NULL && flag == false) {
        if (pokemon_id(newPoke->pokemon) > pokemon_id(curr->pokemon) &&
        pokemon_id(newPoke->pokemon) < pokemon_id(curr->next->pokemon)) {
            newPoke->previous = curr;
            newPoke->next = curr->next;
            curr->next->previous = newPoke;
            curr->next = newPoke;
            flag = true;
        }              
        curr = curr->next;
    }
}


// Search pokemon that contain given string appearing in its name in pokedex
static void searchInLoop(struct pokenode *curr, Pokedex newPokedex, char *text) 
{ 
    int i;
    char string1[MAX_LINE];
    char string2[MAX_LINE];
    // Change to its lower case and count the length
    for (i = 0; text[i] != '\0'; i++) {
        if (text[i] > 'A' && text[i] < 'Z') {
            string1[i] = text[i] + CASE_DIFFERENCE;
        } else {
            string1[i] = text[i];
        }
    }
    int length1 = i;
    for (i = 0; pokemon_name(curr->pokemon) [i] != '\0'; i++) {
        if (pokemon_name(curr->pokemon) [i] > 'A' && 
            pokemon_name(curr->pokemon) [i] < 'Z') {
            string2[i] = 
            pokemon_name(curr->pokemon) [i] + CASE_DIFFERENCE;
        } else {
            string2[i] = pokemon_name(curr->pokemon) [i];
        }
    }
    int length2 = i;
    // Flag is used to exit the loop and check whether to copy the pokenode
    bool flag = false;
    // Compare the text with every part of the name
    i = 0;
    while (i <= length2 -length1 && flag == false) {
        int counter = 0;
        int j = 0;
        while (j < length1) {
            if (string1[j] == string2[i + j]) {
                counter++;
            }
            j++;
        }
        // If the text appear in the name
        if (counter == length1) {
            flag = true;
        }
        i++;
    }
    if (flag == true) {
        struct pokenode *newPoke = clone_pokenode(curr);
        newPokedex = addPokenodeToPokedex(newPokedex, newPoke);
    }
}


// Copy an original string to a new string
static char *copyString(char *newString, const char *original) {
    char *copy = newString;
    while (*original != '\0') {
        *copy = *original;
        copy++;
        original++;
    }
    *copy = *original;
    return copy;  
}

// Print the details of current selected pokemon
static void print_detail(Pokedex pokedex, Pokemon pokemon) {
    if (pokedex->current_selected != NULL) {
        if (pokedex->current_selected->findOrNot == FOUND) {
            printf("ID: %.3d\n", pokemon_id(pokemon));
            printf("Name: %s\n", pokemon_name(pokemon));
            printf("Height: %.1lfm\n", pokemon_height(pokemon)); 
            printf("Weight: %.1lfkg\n", pokemon_weight(pokemon));    
            printf("Type: %s ", 
                pokemon_type_to_string(pokemon_first_type(pokemon)));
            // 'None' should not be printed
            if (compareString(pokemon_type_to_string
                (pokemon_second_type(pokemon)), "None") != 0) {
                printf("%s", 
                pokemon_type_to_string(pokemon_second_type(pokemon))); 
            }
            printf("\n");
        } else {
            printf("ID: %.3d\n", 
                pokemon_id(pokedex->current_selected->pokemon));
            printf("Name: ");
            // Count the length of the pokemon name
            int i;
            for (i = 0; pokemon_name(pokemon) [i] != '\0'; i++);
            int j;
            for (j = 0; j < i; j++) {
                printf("*");
            }
            printf("\n");
            printf("Height: --\n");
            printf("Weight: --\n");
            printf("Type: --\n");
        }
    }
}




// Set the first not-yet-found Pokemon of each type to be found.
static void setFound(Pokedex pokedex, struct pokenode *largeLoop, 
char seted_type[MAX_LINE][MAX_LINE], int *i, bool *flag) {
    struct pokenode *smallLoop = pokedex->head;
    bool type1_exist = false;
    bool type2_exist = false;
    bool type1_set = false;
    bool type2_set = false;
    // Check whether the type1 exist
    while (smallLoop != largeLoop) {
        if (compareString(pokemon_type_to_string
        (pokemon_first_type(largeLoop->pokemon)), pokemon_type_to_string
        (pokemon_first_type(smallLoop->pokemon))) == 0 || compareString
        (pokemon_type_to_string(pokemon_first_type(largeLoop->pokemon)), 
        pokemon_type_to_string (pokemon_second_type(smallLoop->pokemon))) == 0) 
        {
            type1_exist = true;
        }
        
        smallLoop = smallLoop->next;
    }
    // Check whether the type2 exist
    smallLoop = pokedex->head;
    while (smallLoop != largeLoop) {
        if (compareString(pokemon_type_to_string
        (pokemon_second_type(largeLoop->pokemon)), pokemon_type_to_string
        (pokemon_first_type(smallLoop->pokemon))) == 0 || compareString
        (pokemon_type_to_string(pokemon_second_type(largeLoop->pokemon)), 
        pokemon_type_to_string (pokemon_second_type(smallLoop->pokemon))) 
        == 0)
        {
            type2_exist = true;
        }
         
        smallLoop = smallLoop->next;
    }
    // Check whether the type1 or type2 has been set to found
    // Use a flag because the comparison needs to begin after 
    // the types have been stored in the array
    int j = 1;
    while (j <= *i && *flag == true) {
        if (compareString(pokemon_type_to_string
        (pokemon_first_type(largeLoop->pokemon)), seted_type[j]) == 0) {
            type1_set = true;                 
        }
        if (compareString(pokemon_type_to_string
            (pokemon_second_type(largeLoop->pokemon)), "None") != 0) {
            if (compareString(pokemon_type_to_string(pokemon_second_type
            (largeLoop->pokemon)), seted_type[j]) == 0) {
                type2_set = true;                    
            }
        }
        j++;
    }
    // The first type appear first time
    if (type1_exist == false) {
        largeLoop->findOrNot = FOUND;
        copyString(seted_type[++*i], pokemon_type_to_string
            (pokemon_first_type(largeLoop->pokemon)));
        if (compareString(pokemon_type_to_string
            (pokemon_second_type(largeLoop->pokemon)), "None") != 0) {
            copyString(seted_type[++*i], pokemon_type_to_string
            (pokemon_second_type(largeLoop->pokemon)));
        }
        *flag = true;
    } 
    // The second type appear first time
    if (type2_exist == false && compareString(pokemon_type_to_string
            (pokemon_second_type(largeLoop->pokemon)), "None") != 0) {
        largeLoop->findOrNot = FOUND;
        copyString(seted_type[++*i], pokemon_type_to_string
            (pokemon_first_type(largeLoop->pokemon)));
        copyString(seted_type[++*i], pokemon_type_to_string
            (pokemon_second_type(largeLoop->pokemon)));
        *flag = true;
    }
    // The first type has appeared but not set as found
    if (type1_exist == true && compareString(pokemon_type_to_string
       (pokemon_second_type(largeLoop->pokemon)), "None") == 0 && 
        type1_set == false) {
        largeLoop->findOrNot = FOUND;
        copyString(seted_type[++*i], pokemon_type_to_string
            (pokemon_first_type(largeLoop->pokemon)));
        *flag = true;
    }  
    // Both types have appeared and at least one is not set as found
    if ((type1_set == false || type2_set == false) && 
        compareString(pokemon_type_to_string
       (pokemon_second_type(largeLoop->pokemon)), "None") != 0) {
        if (type1_exist == true && type2_exist == true) {
            largeLoop->findOrNot = FOUND;
            copyString(seted_type[++*i], pokemon_type_to_string
                (pokemon_first_type(largeLoop->pokemon)));
            copyString(seted_type[++*i], pokemon_type_to_string
                (pokemon_second_type(largeLoop->pokemon)));
            *flag = true;
        }
    }  
}


