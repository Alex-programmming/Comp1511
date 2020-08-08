// Assignment 2 19T1 COMP1511: Pokedex
// pokedex.c
//
// This program was written by TUAN HO (z5261243)
// on 17/4/2019
//
// Version 1.0.0: Assignment released.
// Version 1.0.1: Minor clarifications about `struct pokenode`.
// Version 1.1.0: Moved destroy_pokedex function to correct location.

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "pokedex.h"

#define STR_LENGTH_MAX          1024

struct pokedex {
    struct pokenode *head;
    struct pokenode *last;
    struct pokenode *current;
};

struct pokenode {
    struct pokenode           *next;
    struct pokenode           *prev;
    Pokemon                 pokemon;
    int                  isFoundYet; 
    struct pokenode *evolvedPokemon;
};

struct substring {
    struct charNode   *head;
    int              length;
};
struct charNode {
    struct charNode *next;
    int                ch;
};


static int is_alphabet(int ch);
static int areSamePokemonNodes(struct pokenode *pokenode1, 
                                struct pokenode *pokenode2);

static int toLower(int ch);
static int toUpper(int ch);
int isAlphabet(int ch);
int strings_equal(char *string1, char *string2);
int string_length(char *string);
int strings_equal(char *string1, char *string2);
int stringsConstEqual(const char *string1, const char *string2);

static int strLength(char str[]);
int constStrLength(const char *string);

void lowerCaseStr(char []);

static const char *get_first_type_name(struct pokenode *examplePokenode);
static const char *get_second_type_name(struct pokenode *examplePokenode);

static int existInString(char *str, char *substring);
int isIdInBetween(struct pokenode *smallNode, 
                struct pokenode *testNode,
                struct pokenode *bigNode);

static void replaceAsterisks(int length);
static void printId(int num);
static int isIdExisted(Pokedex pokedex, int id);
static void printPokenodeInEvol(struct pokenode *examplePokenode);
static void deleteEvoledPokemon(Pokedex pokedex, 
                                struct pokenode *deletedPokemon);
static int doesPokenodeHaveType(pokemon_type type, 
                                struct pokenode *scannedPokenode);
struct pokenode *copiedPokenode(struct pokenode *basePokenode);

static struct pokenode *createNewPokenode(Pokemon pokemon);
Pokedex addToPokedex(Pokedex pokedex, struct pokenode *newPokenode);
Pokedex addToOrderedPokedex(Pokedex pokedex, struct pokenode *newPokenode);

Pokedex new_pokedex(void) {
    Pokedex new_pokedex = malloc(sizeof (struct pokedex));
    assert(new_pokedex != NULL);
    new_pokedex->head = NULL;
    new_pokedex->last = NULL;
    new_pokedex->current = NULL;
    return new_pokedex;
}

////////////////////////////////////////////////////////////////////////
//                         Stage 1 Functions                          //
////////////////////////////////////////////////////////////////////////

// Add a new Pokemon to the Pokedex.
void add_pokemon(Pokedex pokedex, Pokemon pokemon) {
    struct pokenode *newPokenode = createNewPokenode(pokemon);
    pokedex = addToPokedex(pokedex, newPokenode);
    
}

// Print out the details of the currently selected Pokemon in the form
void detail_pokemon(Pokedex pokedex) {
    if (pokedex->head != NULL) {
        if (pokedex->current->isFoundYet == 1) {
            printf("Id: ");
            printId(pokemon_id(pokedex->current->pokemon));
            printf("\n");
            printf("Name: %s\n", pokemon_name(pokedex->current->pokemon));
            printf("Height: %.1lfm\n", pokemon_height(pokedex->current->pokemon));
            printf("Weight: %.1lfkg\n", pokemon_weight(pokedex->current->pokemon));
            const char *first_type_name = get_first_type_name(pokedex->current);
            printf("Type: %s ", first_type_name);
            const char *second_type_name = get_second_type_name(pokedex->current);
            if (stringsConstEqual(second_type_name, "None") != 1) {
                printf("%s", second_type_name);
            }
            printf("\n");
        } else {
            printf("Id: ");
            printId(pokemon_id(pokedex->current->pokemon));
            printf("\n");
            // Any Pokemon not yet 'found' should have its name replaced with
            // asterisks.
            printf("Name: ");
            replaceAsterisks(strLength(pokemon_name(pokedex->current->pokemon)));
            printf("\n");
            printf("Height: --\n");
            printf("Weight: --\n");
            printf("Type: --\n");
        }
    }
}
// Return the currently selected Pokemon 
Pokemon get_current_pokemon(Pokedex pokedex) {
    return pokedex->current->pokemon;
}

// Sets the currently selected Pokemon to be 'found'.
void find_current_pokemon(Pokedex pokedex) {
    for (struct pokenode *p = pokedex->head; p != NULL; p = p->next) {
        if (areSamePokemonNodes(p, pokedex->current)) {
            pokedex->current->isFoundYet = 1;
            break;
        }
    }
}

// Print out all of the Pokemon in the Pokedex, in the order in which
// they are stored in the Pokedex.
void print_pokemon(Pokedex pokedex) {
    if (pokedex != NULL && pokedex ->head != NULL) {
        struct pokenode *p;
        for (p = pokedex->head; p != NULL; p = p->next) {
            if (p == pokedex->current) {
                printf("--> ");
            } else {
                printf("    ");
            }
            printf("#");
            printId(pokemon_id(p->pokemon));
            printf(": ");
            if (p->isFoundYet == 1) {
                printf("%s \n", pokemon_name(p->pokemon));
            } else {
                replaceAsterisks(strLength(pokemon_name(p->pokemon)));
                printf("\n");
            }
        }
    }
}

////////////////////////////////////////////////////////////////////////
//                         Stage 2 Functions                          //
////////////////////////////////////////////////////////////////////////

// Change the currently selected Pokemon to be the Pokemon after the
// currently selected Pokemon in the Pokedex, based on the order in
// which the Pokemon are stored in the Pokedex.
void next_pokemon(Pokedex pokedex) {
    // If there are no Pokemon in the Pokedex, this function does nothing.
    if (pokedex->head != NULL) {
        // If there is no next Pokemon, the current Pokemon is unchanged.
        if (pokedex->current->next != NULL) {
            pokedex->current = pokedex->current->next;
        }
    }
}

void prev_pokemon(Pokedex pokedex) {
    // If there are no Pokemon in the Pokedex, this function does nothing.
    if (pokedex->head != NULL) {
        // If there is no previous Pokemon, the current Pokemon is unchanged.
        if (pokedex->current->prev != NULL) {
            pokedex->current = pokedex->current->prev;
        }
    }
}

// Change the currently selected Pokemon in the Pokedex to be the
// Pokemon with the ID `pokemon_id`.
//
// If there is no Pokemon with the ID `pokemon_id`, this function does
// nothing.
void change_current_pokemon(Pokedex pokedex, int IdSelected) {
    struct pokenode *p;
    for (p = pokedex->head; p != NULL; p = p->next) {
        if (pokemon_id(p->pokemon) == IdSelected) {
            pokedex->current = p;
            break;
        }
    }
}
// Remove the currently selected Pokemon from the Pokedex.
void remove_pokemon(Pokedex pokedex) {
    // If there are no Pokemon in the Pokedex, this function does nothing.
    if (pokedex->head != NULL) {
        // If the removed Pokemon was the only Pokemon in the Pokedex, the
        // free the currently selected Pokenode
        if (pokedex->current->next == NULL
            && pokedex->current->prev == NULL) {
            destroy_pokemon(pokedex->head->pokemon);
            free(pokedex->head);
            pokedex->head = NULL;
        } else if (pokedex->current->next != NULL) {
            // When the currently selected Pokemon is removed, the new currently
            // selected Pokemon should become the Pokemon that was after the removed
            // Pokemon.
            struct pokenode *nextNode = pokedex->current->next;
            struct pokenode *prevNode = pokedex->current->prev;
            struct pokenode *currNode = pokedex->current;
            if (prevNode != NULL) {
                prevNode->next = nextNode;
                nextNode->prev = prevNode;
            }
            // If deleting the head of pokedex, change the head to the next node
            if (pokedex->current == pokedex->head) {
                pokedex->head->next->prev = NULL;
                pokedex->head = nextNode;
            }
            deleteEvoledPokemon(pokedex, currNode);
            destroy_pokemon(currNode->pokemon);
            free(currNode);
            pokedex->current = nextNode;
            //print_pokemon(pokedex);
            
        } else if (pokedex->current->prev != NULL) {
            // If the removed Pokemon was at the end of the Pokedex (i.e. it had no
            // Pokemon after it), the new currently selected Pokemon should instead
            // become the Pokemon that was before the removed Pokemon.
            struct pokenode *prevNode = pokedex->current->prev;
            struct pokenode *currentNode = pokedex->current;
            pokedex->current = prevNode;
            pokedex->current->next = NULL;
            // If deleting the last of pokedex, change the last to the previous node
            if (currentNode == pokedex->last) {
                pokedex->last = prevNode;
            }
            deleteEvoledPokemon(pokedex, currentNode);
            destroy_pokemon(currentNode->pokemon);
            free(currentNode);
            currentNode = NULL;
        } 
    }
}

void destroy_pokedex(Pokedex pokedex) {
    if (pokedex->head != NULL) {
        struct pokenode *p;
        for (p = pokedex->head; p != NULL; p = p->next) {
            destroy_pokemon(p->pokemon);
            if (p->prev != NULL) {
                free(p->prev);

            }
        }
        free(pokedex->last);

    }
    free(pokedex);
}

////////////////////////////////////////////////////////////////////////
//                         Stage 3 Functions                          //
////////////////////////////////////////////////////////////////////////

// This function emulates what happens when a player goes out exploring
// and comes across different Pokemon.
void go_exploring(Pokedex pokedex, int seed, int factor, int how_many) {
    int max = factor;
   
    // This process should be repeated until `how_many` Pokemon have been
    // found.
    int pokemonFoundNum = 0;
    srand(seed);
    while (pokemonFoundNum <= how_many) {
        int randomNumber =  rand() % max;
        struct pokenode *p;
        for (p = pokedex->head; p != NULL; p = p->next) {
            if (randomNumber == pokemon_id(p->pokemon)) {
                p->isFoundYet = 1;
                pokemonFoundNum++;
            }
        }
    }
}

// Return the number of Pokemon in the Pokedex that have been found.
int count_found_pokemon(Pokedex pokedex) {
    int count = 0;
    struct pokenode *p;
    for (p = pokedex->head; p != NULL; p = p->next) {
        if (p->isFoundYet == 1) {
            count++;
        }
    }
    return count;
}

// Return the total number of Pokemon in the Pokedex, whether or not
// they have been found.
int count_total_pokemon(Pokedex pokedex) {
    int count = 0;
    struct pokenode *p;
    for (p = pokedex->head; p != NULL; p = p->next) {
        count++;
    }
    return count;
}

////////////////////////////////////////////////////////////////////////
//                         Stage 4 Functions                          //
////////////////////////////////////////////////////////////////////////

// Add the information that the Pokemon with the ID `from_id` can
// evolve into the Pokemon with the ID `to_id`.
void add_pokemon_evolution(Pokedex pokedex, int from_id, int to_id) {

    if (isIdExisted(pokedex, from_id) && isIdExisted(pokedex, to_id)
        && from_id != to_id) {
        struct pokenode *fromPokemon;
        struct pokenode *toPokemon;
        struct pokenode *p;
        for (p = pokedex->head; p != NULL; p = p->next) {
            if (from_id == pokemon_id(p->pokemon)) {
                fromPokemon = p;
            }
            if (to_id == pokemon_id(p->pokemon)) {
                toPokemon = p;
            }
        }
        fromPokemon->evolvedPokemon = toPokemon;
    } else {
        // If there is no Pokemon with the ID `from_id` or `to_id`,
        // or if the provided `from_id` and `to_id` are the same,
        // this function should print an appropriate error message and exit the
        // program.
        printf("The id(s) inputed is/are invalid or do(es) not "
               "exist in the pokedex. The program exits. \n");
        exit(1);
    }
}

// Show the evolutions of the currently selected Pokemon.
// It should include the Pokemon it evolves into (if any), as well as
// any evolutions that its evolved state can evolve into, and so on.
void show_evolutions(Pokedex pokedex) {
    struct pokenode *currentNode;
    currentNode = pokedex->current;
    if (currentNode != NULL) {
        printPokenodeInEvol(currentNode);
        currentNode = currentNode->evolvedPokemon;
        while (currentNode != NULL) {
            printf(" --> ");
            printPokenodeInEvol(currentNode);
            currentNode = currentNode->evolvedPokemon;
        }
        printf("\n");
    }
}

// Return the pokemon_id of the Pokemon that the currently selected
// Pokemon evolves into.
int get_next_evolution(Pokedex pokedex) {
    // If the Pokedex is empty, this function should print an appropriate
    // error message and exit the program.
    if (pokedex->head != NULL) {
        if (pokedex->current->evolvedPokemon != NULL) {
            return pokemon_id(pokedex->current->evolvedPokemon->pokemon);
        } else {
            // If the currently selected Pokemon does not evolve, this function
            // should return DOES_NOT_EVOLVE.
            return DOES_NOT_EVOLVE;
        }
    } else {
        printf ("The pokedex is empty. Add some pokemon to execute the action\n");
        exit(1);
        return DOES_NOT_EVOLVE;
    }
}

////////////////////////////////////////////////////////////////////////
//                         Stage 5 Functions                          //
////////////////////////////////////////////////////////////////////////

// Create a new pokedex with a specific type
Pokedex get_pokemon_of_type(Pokedex pokedex, pokemon_type type) {
    Pokedex newPokedex = new_pokedex();
    struct pokenode *p;
    for (p = pokedex->head; p != NULL; p = p->next) {
        if (doesPokenodeHaveType(type, p) && p->isFoundYet == 1) {
            struct pokenode *clonePokenode = copiedPokenode(p);
            newPokedex = addToOrderedPokedex(newPokedex, clonePokenode);
        }
    }
    return newPokedex;
}

// Create a new Pokedex which contains only the Pokemon that have
// previously been 'found' from the original Pokedex.
Pokedex get_found_pokemon(Pokedex pokedex) {
    Pokedex newPokedex = new_pokedex();
    struct pokenode *p;
    for (p = pokedex->head; p != NULL; p = p->next) {
        if (p->isFoundYet == 1) {
            struct pokenode *clonePokenode = copiedPokenode(p);
            newPokedex = addToOrderedPokedex(newPokedex, clonePokenode);
        }
    }
    return newPokedex;
}

// Create a new Pokedex containing only the Pokemon from the original
Pokedex search_pokemon(Pokedex pokedex, char *text) {
    Pokedex newPokedex = new_pokedex();
    struct pokenode *p;
    for (p = pokedex->head; p != NULL; p = p->next) {
        // If a Pokemon has not yet been found, it should not be added to the
        // new Pokedex.
        if (p->isFoundYet == 1 
            && existInString(pokemon_name(p->pokemon), text)) {
            // This function should not alter the original Pokedex.  It should
            // create copies of any Pokemon which are in the original Pokedex, and
            // insert those copies into the new Pokedex.
            struct pokenode *clonePokenode = copiedPokenode(p);
            newPokedex = addToPokedex(newPokedex, clonePokenode);
        }
        if (newPokedex->current == NULL) {
            newPokedex->current = p;
        }
    }
    return newPokedex;
}

// This function is to check if a character is alphabetical
static int is_alphabet(int ch) {
    int is_it = 0;
    if ((ch >= 'A' && ch <= 'Z') 
        || (ch >= 'a' && ch <= 'z')) {
        is_it = 1;
    }
    return is_it;
}
// The function returns the length of the alphabetic string 
static int strLength(char str[]) {
    int i;
    for (i = 0; i < STR_LENGTH_MAX; i++) {
        if (is_alphabet(str[i]) == 0) {
            break;
        }
    }
    return i;
}

// Print the asterisks n times
static void replaceAsterisks(int length) {
    for (int i = 0; i < length; i++) {
        printf("*");
    }
}
// Print Id in in appropriate form
// If a pokemon_id has less than three digits, it should be printed with
// leading '0's.
// If it has more than three digits, it should be printed as-is.
static void printId(int num) {
    if (num >= 100) {
        printf("%d", num);
    } else if (num >= 10) {
        printf("0%d", num);
    } else if (num >= 0) {
        printf("00%d", num);
    }
}
// This function is to check if two pokenodes are same or have the same id
static int areSamePokemonNodes(struct pokenode *pokenode1, 
                                struct pokenode *pokenode2) {
    if (pokemon_id(pokenode1->pokemon) == pokemon_id(pokenode2->pokemon)) {
        return 1;
    } else {
        return 0;
    }
}

// This function is to check if an id has been used 
static int isIdExisted(Pokedex pokedex, int id) {
    int used = 0;
    struct pokenode *p;
    for (p = pokedex->head; p != NULL; p = p->next) {
        if (pokemon_id(p->pokemon) == id) {
            used = 1;
        }
    }
    return used;
}
// This function is to check if pokenode has id in between other 2 nodes'
int isIdInBetween(struct pokenode *smallNode, 
                struct pokenode *testNode,
                struct pokenode *bigNode) {
    if ((pokemon_id(testNode->pokemon) > pokemon_id(smallNode->pokemon))
        && (pokemon_id(testNode->pokemon) < pokemon_id(bigNode->pokemon))) {
        return 1;
    } else {
        return 0;
    }
}
// Print approriate pokenode form when showing the evolutions
static void printPokenodeInEvol(struct pokenode *examplePokenode) {
    printf("#");
    printId(pokemon_id(examplePokenode->pokemon));
    printf(" ");
    if (examplePokenode->isFoundYet == 1) {
        printf("%s ", pokemon_name(examplePokenode->pokemon));
        const char *first_type_name = get_first_type_name(examplePokenode);
        printf("[%s ", first_type_name);
        const char *second_type_name = get_second_type_name(examplePokenode);
        if (stringsConstEqual(second_type_name,"None") != 0) {
            printf("%s", second_type_name);
        }
        printf("]");
    } else {
        printf("???? [????]");
    }
}
// Get pokemon first type name
static const char *get_first_type_name(struct pokenode *examplePokenode) {
    return pokemon_type_to_string(pokemon_first_type(examplePokenode->pokemon));
}
// Get pokemon second type name
static const char *get_second_type_name(struct pokenode *examplePokenode) {
    return pokemon_type_to_string(pokemon_second_type(examplePokenode->pokemon));
}

// Update the evolved Pokemon to NULL in the pokedex when it's deleted
static void deleteEvoledPokemon(Pokedex pokedex, struct pokenode *deletedPokemon) {
    struct pokenode *p;
    for (p = pokedex->head; p != NULL; p = p->next) {
        if  (p->evolvedPokemon == deletedPokemon) {
            p->evolvedPokemon = NULL;
        }
    }
}

// Create a new pokenode
static struct pokenode *createNewPokenode(Pokemon pokemon) {
    struct pokenode *newPokemon = malloc(sizeof (struct pokenode));
    newPokemon->next = NULL;
    newPokemon->prev = NULL;
    newPokemon->pokemon = pokemon;
    newPokemon->evolvedPokemon = NULL;
    newPokemon->isFoundYet = 0;
    return newPokemon;
}

// Clone a pokenode
// This function is different from the one above as it only 
// copies the information of the pokemon
struct pokenode *copiedPokenode(struct pokenode *basePokenode) {
    struct pokenode *clone = malloc(sizeof(struct pokenode));
    clone->pokemon = clone_pokemon(basePokenode->pokemon);
    clone->next = NULL;
    clone->isFoundYet = 1;
    clone->prev = NULL;
    clone->evolvedPokemon = NULL;
    return clone;
}

// Add the pokenode to the end of the pokedex
Pokedex addToPokedex(Pokedex pokedex, struct pokenode *newPokenode) {
    if (pokedex->head == NULL) {
        pokedex->head = newPokenode;
        pokedex->last = newPokenode;
        pokedex->last->prev = NULL;
        pokedex->current = newPokenode;
    } else {
        // If the new pokemon has the same as exited ones, print error message
        if (isIdExisted(pokedex, pokemon_id(newPokenode->pokemon))) {
            printf("\nThe id %d is ", pokemon_id(newPokenode->pokemon));
            printf("already used; thus your ");
            printf("pokemon has not been added!\n");
            printf("\nType command 'p' to view existed ");
            printf("ids change into approriate id \n");
        } else {
            struct pokenode *tempNode;
            tempNode = pokedex->last;
            pokedex->last->next = newPokenode;
            pokedex->last = newPokenode;
            pokedex->last->prev = tempNode;
        }
    }
    pokedex->last->next = NULL;
    return pokedex;
}

// This function is to check if the pokenode has the needed type
static int doesPokenodeHaveType(pokemon_type type, 
                                struct pokenode *scannedPokenode) {
    if (pokemon_first_type(scannedPokenode->pokemon) == type
        || pokemon_second_type(scannedPokenode->pokemon) == type) {
        return 1;
    } else {
        return 0;
    }
}

// This function is to check if a substring exists in a string 
static int existInString(char *str, char *substring) {
    int i, j;
    int sameCharCount = 0;
    for (i = 0; i <= string_length(str) - string_length(substring); i++) {
        for (j = 0; j < string_length(substring); j++) {
            if (toLower(substring[j]) == toLower(str[i + j])) {
                sameCharCount++;
            }
        }
        if (sameCharCount == string_length(substring)) {
            break;
        } else {
            sameCharCount = 0;
        }
    }
    if (sameCharCount != 0) {
        return 1;
    } else {
        return 0;
    }
}

// This function is to add pokenode to the pokedex in the ascending order of the id
Pokedex addToOrderedPokedex(Pokedex pokedex, struct pokenode *newPokenode) {
    if (pokedex->head == NULL) {
        pokedex->head = newPokenode;
        pokedex->last = newPokenode;
        pokedex->last->prev = NULL;
        pokedex->current = newPokenode;
    } else {
        int addedYet = 0;
        // If there were 2 or more pokenodes in the pokedex
        // Find its approriate position based on the id
        if (pokedex->last != pokedex->head) {
            struct pokenode *p;
            for (p = pokedex->head; p->next != NULL; p = p->next) {
                if (isIdInBetween(p, newPokenode, p->next)) {
                    p->next->prev = newPokenode;
                    newPokenode->next = p->next;
                    newPokenode->prev = p;
                    p->next = newPokenode;
                    addedYet = 1;
                    break;
                }
            }
        }
        // If there were only one pokenode in the pokedex and
        // it has the largest id, add it to the pokedex->last
        int newId = pokemon_id(newPokenode->pokemon);
        if (!addedYet && (newId > pokemon_id(pokedex->last->pokemon))) {  
            pokedex = addToPokedex(pokedex, newPokenode);
            addedYet = 1;
        } else if (!addedYet && (newId < pokemon_id(pokedex->head->pokemon))) {
            newPokenode->next = pokedex->head;
            pokedex->head = newPokenode; 
            newPokenode->next->prev = newPokenode;
        }
    
        
    }
    pokedex->head->prev = NULL;
    pokedex->current = pokedex->head;
    pokedex->last->next = NULL;
    return pokedex;
}
// Return if a character is alphabetical
int isAlphabet(int ch) {
    if ((ch >= 'a' && ch <= 'z')
        || (ch >= 'A' && ch <= 'Z')) {
        return 1;
    } else {
        return 0;
    }
}

// Return the length of a string
int string_length(char *string) {
    int counter = 0;
    while (string[counter] != '\0') {
        counter++;
    }
    return counter;
}

// Return the length of a const string
int constStrLength(const char *string) {
    int counter = 0;
    while (string[counter] != '\0') {
        counter++;
    }
    return counter;
}

// Convert a character to lowercase
static int toLower(int ch) {
    int newCh = ch;
    if (isAlphabet(ch)) {
        if (ch >= 'A' && ch <= 'Z') {
            newCh = ch + 32;
        }
    } 
    return newCh;
}
// Convert a character to uppercase
static int toUpper(int ch) {
    int newCh = ch;
    if (isAlphabet(ch)) {
        if (ch >= 'a' && ch <= 'z') {
            newCh = ch - 32;
        }
    } 
    return newCh;
}

// Takes two strings, and determine if they are the same.
// If so returns 1, or 0 otherwise.
int strings_equal(char *string1, char *string2) {
    int is_it = 1;
    int i;
    if (string_length(string1) == string_length(string2)) {
        for (i = 0; i < string_length(string1); i++) {
            if (toLower(string1[i]) != toLower(string2[i])) {
                is_it = 0;
                break;
            }
        }
    } else {
        is_it = 0;
    }
    return is_it;
}

// Takes two constant strings, and determine if they are the same.
// If so returns 1, or 0 otherwise.
int stringsConstEqual(const char *string1, const char *string2) {
    int is_it = 1;
    int i;
    if (constStrLength(string1) == constStrLength(string2)) {
        for (i = 0; i < constStrLength(string1); i++) {
            if (toLower((int) string1[i]) != toLower((int) string2[i])) {
                is_it = 0;
                break;
            }
        }
    } else {
        is_it = 0;
    }
    return is_it;
}

