// Assignment 2 19T3 COMP1511: Pokedex
// pokedex.c
//
// This program was written by Peiting Xie (z5248181)
// on 14/11/2019
//
// Version 2.0.0: Release

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// Note you are not allowed to use <string.h> in this assignment
// There are some techniques we would like you to learn to code
// that the string library trivialises.

// ----------------------------------------------
// Add any extra #includes your code needs here.
// ----------------------------------------------

#include "pokedex.h"
#define SIZE 1000

// ----------------------------------------------
// Add your own #defines here.
// ----------------------------------------------


// Note you are not permitted to use arrays in struct pokedex,
// you must use a linked list.
//
// The only exception is that char arrays are permitted for
// search_pokemon and functions it may call, as well as the string
// returned by pokemon_name (from pokemon.h).
//
// You will need to add fields to struct pokedex.
// You may change or delete the head field.
struct pokedex {
    struct pokenode *head;
    struct pokenode *curr;
    struct pokenode *last;
};


// You don't have to use the provided struct pokenode, you are free to
// make your own struct instead.
//
// If you use the provided struct pokenode, you will need to add fields
// to it to store other information.
struct pokenode {
    struct pokenode *prev;
    struct pokenode *evolved;
    Pokemon pokemon;
    int hasbeenFound;
    struct pokenode *next;
};


// ----------------------------------------------
// Add your own structs here.
// ----------------------------------------------




// ----------------------------------------------
// Add prototypes for your own functions here.
static int is_same_pokemon(Pokedex pokedex, Pokemon second);
static int StringCompare(const char *str1,const char *str2);
static void printnodeEvo(struct pokenode *tmp, Pokedex pokedex);
static char *stringcopy(char *dst, const char *from);
Pokedex AddToNewPokedex(Pokedex pokedex, struct pokenode *newnode);
static int stringlength(char *string);
static int ToCapitalletter(int number);
static int chMatching(char *string, char *input);
struct pokenode *copiednode(struct pokenode *fromnode);
static void type1_exist(
struct pokenode *curr1, struct pokenode *curr2, int *value1);
static void type2_exist(
struct pokenode *curr1, struct pokenode *curr2, int *value2);
static int first_type_matched(struct pokenode *tmp1, struct pokenode *tmp2);
static int second_type_matched(struct pokenode *tmp1, struct pokenode *tmp2);
static void id_matched(
struct pokenode *tmp, struct pokenode *newnode, int *exit);
static void addnewnode_at_end(
int exit, Pokedex pokedex, struct pokenode *newnode);
static void addnewnode_at_curr(
struct pokenode *newnode, struct pokenode *curr, int *adding, int *value);
static void second_type_not_none(Pokemon pokemon);
static struct pokenode *new_pokenode(Pokemon pokemon);
Pokedex putinPokedex(Pokedex pokedex, struct pokenode *newPokenode);
Pokedex putinPokedexOrdered(Pokedex pokedex, struct pokenode *newPokenode);  
static void check_set(int i, struct pokenode *curr1, int value5, int *value3, 
    int *value4);
static void set_found1(int value1, int *value5, int *i, 
    struct pokonode *curr1);
static void set_found2(int value2, int *value5, int *i, 
    struct pokonode *curr1);
static void set_found3(int value1, int value3, int *value5, int *i, 
    struct pokonode *curr1);
static void set_found4(int value1, int value2, int value3, int value4, 
    int *value5, int *i, struct pokonode *curr1);
// ----------------------------------------------

// Creates a new pokenode struct and returns a pointer to it.


// You need to implement the following functions in their stages.
// In other words, replace the lines calling fprintf & exit with your code.
// You can find descriptions of what each function should do in pokedex.h


// Creates a new Pokedex, and returns a pointer to it.
// Note: you will need to modify this function.
Pokedex new_pokedex(void) {
    // Malloc memory for a new Pokedex, and check that the memory
    // allocation succeeded.
    Pokedex new_pokedex = malloc(sizeof(struct pokedex));
    assert(new_pokedex != NULL);
    new_pokedex->head = NULL;
    new_pokedex->curr = NULL;
    new_pokedex->last = NULL;
    // Set the head of the linked list to be NULL.
    // (i.e. set the Pokedex to be empty)
    new_pokedex->head = NULL;

    // TODO: Add your own code here.

    return new_pokedex;
}

// Create a new pokenode struct and returns a pointer to it.
//
// This function should allocate memory for a pokenode, set its pokemon
// pointer to point to the specified pokemon, and return a pointer to
// the allocated memory.
static struct pokenode *new_pokenode(Pokemon pokemon) {
    struct pokenode* NewPokemon = malloc(sizeof(struct pokenode));
    NewPokemon->prev = NULL;
    NewPokemon->next = NULL;
    NewPokemon->pokemon = pokemon;
    NewPokemon->evolved = NULL;
    NewPokemon->hasbeenFound = 0;    

    //printf("The new_pokenode function has not been implemented yet!\n");

    return NewPokemon;
}

//////////////////////////////////////////////////////////////////////
//                         Stage 1 Functions                        //
//////////////////////////////////////////////////////////////////////

// Add a new Pokemon to the Pokedex.
void add_pokemon(Pokedex pokedex, Pokemon pokemon) {
    
    // Note: you should use the new_pokenode function here, and add
    // the newly-created pokenode to the end of the linked list of
    // pokenodes in the Pokedex.
    struct pokenode *newPokemon = new_pokenode(pokemon);
    int exit = 0;
    // check that if the pokedex is empty
    // if the pokedex is empty, directly add the pokemon to the pokedex. 
    if (pokedex->head == NULL) {
        pokedex->head = newPokemon;
        pokedex->last = newPokemon;
        pokedex->last->prev = NULL;
        pokedex->curr = newPokemon;
    } else {
        // if the pokedex is not empty, find the correct position.
        // then add the pokemon to that position.
        struct pokenode *tmp = pokedex->head;
        while (tmp != NULL) {
            if (pokemon_id(tmp->pokemon) == pokemon_id(newPokemon->pokemon)) {
                exit = 1; 
            } 
            tmp = tmp->next;
        }
        // check that if the pokemon has been add before.
        if (exit == 1) {
            printf("\n");
            printf("ID has existed!");
        } else {
            struct pokenode *tmp1 = pokedex->last;
            pokedex->last->next = newPokemon;
            pokedex->last = newPokemon;
            pokedex->last->prev = tmp1;
        }
    }
    pokedex->last->next = NULL;
}

           
            
                
        
               
                        
    //fprintf(stderr, "exiting because you have not implemented the add_pokemon function\n");
    //exit(1);


// Print out the details of the currently selected Pokemon.
void detail_pokemon(Pokedex pokedex) {
    Pokemon pokemon = get_current_pokemon(pokedex);
    // check that if the pokedex is empty
    // if the pokedex is not empty, output the pokemons' details
    if (pokedex != NULL) {
        // check that if the pokemon has been Found before. 
        // if so, print its full name.
        if (pokedex->curr->hasbeenFound == 1) {
            printf("ID: %.3d\n", pokemon_id(pokedex->curr->pokemon));
            printf("Name: %s\n", pokemon_name(pokedex->curr->pokemon));
            printf("Height: %.1lfm\n", pokemon_height(pokedex->curr->pokemon));
            printf("Weight: %.1lfkg\n", pokemon_weight(pokedex->curr->pokemon));
            printf("Type: %s ", 
            pokemon_type_to_string(pokemon_first_type(pokemon)));
            if (pokemon_type_to_string(pokemon_second_type(pokemon)) != NULL) {
                second_type_not_none(pokemon);    
            }
            printf("\n");
        } else {
            printf("ID: %.3d\n", 
                pokemon_id(pokedex->curr->pokemon));
            printf("Name: ");
            // if the pokemon has not been found, calculate the length of name.
            int i = 0;            
            while (pokemon_name(pokemon)[i] != '\0') {
                i++;
            }
            i--;
            while (i >= 0) {
                printf("*");
                i--;
            }
            printf("\n");
            printf("Height: --\n");
            printf("Weight: --\n");
            printf("Type: --\n");
        }
    }            
}

// Return the currently selected Pokemon.
Pokemon get_current_pokemon(Pokedex pokedex) {
    // get to the current position.
    if (pokedex->curr != NULL) {
        return pokedex->curr->pokemon;
    } else {
        printf("The Pokedex is empty yet, please add new!");
        exit(1);
    }
}    
   

// Sets the currently selected Pokemon to be 'found'.
void find_current_pokemon(Pokedex pokedex) {
    pokedex->curr->hasbeenFound = 1;
}
    
    
void print_pokemon(Pokedex pokedex) {
    struct pokenode *tmp = pokedex->head;
    while (tmp != NULL) {
        if (tmp == pokedex->curr) {
            printf("--> ");
        } else {
            printf("    ");
        }
        printf("#%.3d: ", pokemon_id(tmp->pokemon));
        if (tmp->hasbeenFound == 0) {
            int i = 0;
            while (pokemon_name(tmp->pokemon)[i] != '\0') {
                i++;    
            }
            i--;
            while (i >= 0) {
                printf("*");
                i--;
            }
            printf("\n");
        } else {
            printf("%s\n", pokemon_name(tmp->pokemon));
        }
        tmp = tmp->next;
    }
}

                
    

//////////////////////////////////////////////////////////////////////
//                         Stage 2 Functions                        //
//////////////////////////////////////////////////////////////////////

// Change the currently selected Pokemon to be the next Pokemon in the Pokedex.
void next_pokemon(Pokedex pokedex) {
    if (pokedex->head != NULL && pokedex->curr->next != NULL) {
        pokedex->curr = pokedex->curr->next;
    }
    
}

// Change the currently selected Pokemon to be previous Pokemon in the Pokedex.
void prev_pokemon(Pokedex pokedex) {
    if (pokedex->head != NULL && pokedex->curr->prev != NULL) {
        pokedex->curr = pokedex->curr->prev;
    } 
    
}

// Change the currently selected Pokemon to be the Pokemon with the ID `id`.
void change_current_pokemon(Pokedex pokedex, int id) {
    struct pokenode *tmp = pokedex->head;
    // if the pokedex is not empty.
    // match the pokemon's id with the input id and find that position.
    // change the current to that position.
    while (tmp != NULL) {
        if (pokemon_id(tmp->pokemon) == id) {
            pokedex->curr = tmp;
        }
        tmp = tmp->next;
    }   
}   

// Remove the currently selected Pokemon from the Pokedex.
void remove_pokemon(Pokedex pokedex) {
    // check that if the pokedex is not empty.
    if (pokedex->head != NULL) {
        // current position is not the last pokemon in pokedex.
        if (pokedex->curr->next != NULL) {
            struct pokenode *prevnode = pokedex->curr->prev;
            struct pokenode *nextnode = pokedex->curr->next;
            struct pokenode *currnode = pokedex->curr;
            // not the first and not the last
            if (prevnode != NULL) {
                nextnode->prev = prevnode;
                prevnode->next = nextnode;
            } else {
                // current is the first position of the pokedex.
                pokedex->curr->next->prev = NULL;
                pokedex->head = nextnode;
            }
            destroy_pokemon(currnode->pokemon);
            free(currnode);
            pokedex->curr = nextnode;
        } else if (pokedex->curr->prev != NULL && pokedex->curr->next == NULL) {
            // current position is the last position of the pokedex.
            struct pokenode *prevnode = pokedex->curr->prev;
            struct pokenode *currnode = pokedex->curr;
            pokedex->curr = prevnode;
            pokedex->curr->next = NULL;
            destroy_pokemon(currnode->pokemon);
            
            pokedex->last = pokedex->last->prev;
            free(currnode);
        } else if (pokedex->head->prev == NULL && pokedex->head->next == NULL) {
            // there is only one pokemon in the pokedex.
            destroy_pokemon(pokedex->head->pokemon);
            free(pokedex->curr);
            pokedex->head = NULL;
        } 
    }
} 
              

// Destroy the given Pokedex and free all associated memory.
void destroy_pokedex(Pokedex pokedex) {
    if (pokedex->head != NULL) {
        struct pokenode *tmp = pokedex->head;
        while (tmp != NULL) {
            destroy_pokemon(tmp->pokemon);
            if (tmp->prev != NULL) {
                free(tmp->prev);    
            }
            tmp = tmp->next;
        }
        free(pokedex->last);
    }
    free(pokedex);
}

//////////////////////////////////////////////////////////////////////
//                         Stage 3 Functions                        //
//////////////////////////////////////////////////////////////////////

// Print out all of the different types of Pokemon in the Pokedex.
void show_types(Pokedex pokedex) {
    struct pokenode *tmp1 = pokedex->head;
    
    while (tmp1 != NULL) {
        int value = 0;
        struct pokenode *tmp2 = pokedex->head;
        while (value == 0 && tmp1 != tmp2) {
            // check that if the first type has been occured before.
            if (first_type_matched(tmp1, tmp2) == 1) {
                value = 1;
            }
            tmp2 = tmp2->next;
        }
        // if this first type has not been occured before.
        if (value == 0) {
            // if so, do not print this type.
            if (StringCompare(pokemon_type_to_string(pokemon_first_type(
            tmp1->pokemon)), "None") != 0 ) {
                printf("%s\n", pokemon_type_to_string(pokemon_first_type(
                tmp1->pokemon)));
            }
        }
        value = 0;
        tmp2 = pokedex->head;
        while (value == 0 && tmp1 != tmp2) {
            // check that if the second has been occured before.
            if (second_type_matched(tmp1, tmp2) == 1) {
                value = 1;
            }
            tmp2 = tmp2->next;
        }
        // if the second type has not occured before.
        
        if (value == 0) {
            // check that if the second type is none.
            if (StringCompare(pokemon_type_to_string(pokemon_second_type(
            tmp1->pokemon)), "None") != 0 ) {
                printf("%s\n", pokemon_type_to_string(pokemon_second_type(
                tmp1->pokemon)));
            }
        }
        tmp1 = tmp1->next;
    }       
}
// Set the first not-yet-found Pokemon of each type to be found.
void go_exploring(Pokedex pokedex) {
    struct pokenode *curr1 = pokedex->head;
    int i = 0;
    // create a 2D string. i store the number and j store the name.
    char type[SIZE][SIZE];
    struct pokenode *tmp = pokedex->head;
    int value5 = 0; 
    while (curr1 != NULL) {
        // found the pokemons that has not been found yet.
        if (curr1->hasbeenFound == 0) {
            int value1 = 0;
            int value2 = 0;
            int value3 = 0;
            int value4 = 0;     
            struct pokenode *curr2 = pokedex->head;
            // check that if the first type of the curr1 has existed, if so
            // change the value1 to 1
            type1_exist(curr1, curr2, &value1);
            curr2 = tmp;
            // if the first type of the curr1 has not occured before.
            // that pokemon has been found yet.
            set_found1(value1, &value5, &i, curr1);
            // check that if second type has occured before.
            type2_exist(curr1, curr2, &value2);
            curr2 = tmp;
            // if the second type has not occured.
            // then add the  first and second type to the 2D array. 
            set_found2(value2, &value5, &i, curr1);
            check_set(i, curr1, value5, &value3, &value4);
            // if the first type has not been copied to the array.
            // copied the current first type to the array.
            set_found3(value1, value3, &value5, &i, curr1);
            // if both the first type and the second has occured before.
            // if the second type is not none.
            // add both the first and the second type to the array.
            set_found4(value1, value2, value3, value4, &value5, &i, curr1);
        }
        curr1 = curr1->next;
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
        if (curr->hasbeenFound == 1) {
            counter++;
        }
        curr = curr->next;
    }
    return counter;
};


//////////////////////////////////////////////////////////////////////
//                         Stage 4 Functions                        //
//////////////////////////////////////////////////////////////////////

// Add the information that the Pokemon with the ID `from_id` can
// evolve into the Pokemon with the ID `to_id`.
void add_pokemon_evolution(Pokedex pokedex, int from_id, int to_id) {
    struct pokenode *curr = pokedex->head;
    struct pokenode *initialnode = pokedex->head;
    struct pokenode *evolvednode = pokedex->head;
    int value1 = 0;
    int value2 = 0;
    while (curr != NULL) {
        // check that if both from_id and to_id are existed in the pokedex.
        if (pokemon_id(curr->pokemon) == from_id) {
            initialnode = curr;
            value1 = 1;
        }
        if (pokemon_id(curr->pokemon) == to_id) {
            evolvednode = curr;
            value2 = 1;
        }        
        curr = curr->next;
    }    
    // if both ids are existed and they are not the same one.
    if (value1 == 1 && value2 == 1 && from_id != to_id) {
        initialnode->evolved = evolvednode;
    } else {
        printf("Something is wrong!, please check the ids again\n");
        exit(1);
    }    
}

// Show the evolutions of the currently selected Pokemon.
void show_evolutions(Pokedex pokedex) {
    struct pokenode *currnode;
    currnode = pokedex->curr;
    if (currnode != NULL) {
        printnodeEvo(currnode, pokedex);
        currnode = currnode->evolved;
        while (currnode != NULL) {
            printf(" --> ");
            printnodeEvo(currnode, pokedex);
            currnode = currnode->evolved;
        }
        printf("\n");
    }
}




// Return the pokemon_id of the Pokemon that the currently selected
// Pokemon evolves into.
int get_next_evolution(Pokedex pokedex) {
    if (pokedex->head == NULL) {
        printf("The pokedex is empty!\n");
        exit(1);
        return DOES_NOT_EVOLVE;
    } else {
        if (pokedex->curr->evolved == NULL) {
            return DOES_NOT_EVOLVE;
        } else
            return pokemon_id(pokedex->curr->evolved->pokemon);
    }
}
            

//////////////////////////////////////////////////////////////////////
//                         Stage 5 Functions                        //
//////////////////////////////////////////////////////////////////////

// Create a new Pokedex which contains only the Pokemon of a specified
// type from the original Pokedex.
Pokedex get_pokemon_of_type(Pokedex pokedex, pokemon_type type) {
    struct pokenode *tmp = pokedex->head;
    Pokedex newpokedex = new_pokedex();
    while (tmp != NULL) {
        // check that if the type is existed in the pokedex.
        if (pokemon_first_type(tmp->pokemon) == type
        || pokemon_second_type(tmp->pokemon) == type) {
            if (tmp->hasbeenFound == 1) {
                struct pokenode *clonenode = copiednode(tmp); 
                newpokedex = putinPokedex(newpokedex, clonenode);
            }
        }
        tmp = tmp->next;
    }
    return newpokedex;         
}

// Create a new Pokedex which contains only the Pokemon that have
// previously been 'found' from the original Pokedex.
Pokedex get_found_pokemon(Pokedex pokedex) {
    Pokedex newpokedex = new_pokedex();
    struct pokenode *curr = pokedex->head;
    while (curr != NULL) {
        if (curr->hasbeenFound == 1) {
            struct pokenode *clonenode = copiednode(curr);
            newpokedex = AddToNewPokedex(newpokedex, clonenode);
        }
        curr = curr->next;
    }
    return newpokedex;
}

// Create a new Pokedex containing only the Pokemon from the original
// Pokedex which have the given string appearing in its name.
Pokedex search_pokemon(Pokedex pokedex, char *text) {
    Pokedex newpokedex = new_pokedex();     
    struct pokenode *tmp = pokedex->head;
    while (tmp != NULL) {
        // Matching the input character to the name in pokedex.
        if (chMatching(pokemon_name(tmp->pokemon), text) == 1 
        && tmp->hasbeenFound == 1) {
            struct pokenode *clonenode = copiednode(tmp);
            newpokedex = putinPokedex(newpokedex, clonenode);
        }
        if (newpokedex->curr == NULL) {
            newpokedex->curr = tmp;
        }
        tmp = tmp->next;
    }
    return newpokedex;
}
                  

// Add definitions for your own functions here.
// Make them static to limit their scope to this file.






// put the newPokenode to the pokedex.
Pokedex putinPokedex(Pokedex pokedex, struct pokenode *newPokenode) {
    if (pokedex->head == NULL) {
        pokedex->head = newPokenode;
        pokedex->last = newPokenode;
        pokedex->curr = newPokenode;
    } else {
        if (is_same_pokemon(pokedex,newPokenode->pokemon)) {
            fprintf(stderr, " This Pokemon hasbeenFound before\n");
        } else {
            struct pokenode *tmp;
            tmp = pokedex->last;
            pokedex->last->next = newPokenode;
            pokedex->last = newPokenode;
            pokedex->last->prev = tmp;
        }
    }
    pokedex->last->next = NULL;
    return pokedex;
}
// check that if the pokemons are the same.
static int is_same_pokemon(Pokedex pokedex, Pokemon second) {
    int occur = 0;
    struct pokenode *p = pokedex->head;
    //first->pokemon = head;
    while (p != NULL) {
        if (pokemon_id(p->pokemon) == pokemon_id(second)) {
            occur = 1;
        }
        p = p->next;
    }
    return occur;
}

// compare the length of the two length.
static int StringCompare(const char *string1, const char *string2) {
    while (*string1 == *string2) {
        assert((string1 != NULL) && (string2 != NULL));                
        if (*string1 == '\0') {
            return 0;
        }            
        string1++;
        string2++;
    }
    return *string1 - *string2;
}
// print the evolution process.
static void printnodeEvo(struct pokenode *tmp, Pokedex pokedex) {
    printf("#");
    printf("%.3d", pokemon_id(tmp->pokemon));
    printf(" ");
    if (tmp->hasbeenFound == 1) {
        printf("[%s ", pokemon_name(tmp->pokemon));
        const char *pokemon_first_type_name = pokemon_type_to_string(
        pokemon_first_type(tmp->pokemon));
        printf("%s", pokemon_first_type_name);
        const char *pokemon_second_type_name = pokemon_type_to_string(
        pokemon_second_type(tmp->pokemon));    
        if (StringCompare(pokemon_second_type_name, "None") != 0) {
            printf(", %s", pokemon_second_type_name);
        }
        printf("]");
    }    else {
        printf("???? [????]");
    }
}
// copy the string to a new place.
static char *stringcopy(char *dst, const char *from) {
    char *tmp = dst;
    while (*from != '\0') {
        *tmp = *from;
        tmp++;
        from++;
    }
    *tmp = *from;
   
    return tmp;  
}
// add the newnode to the new pokedex.
Pokedex AddToNewPokedex(Pokedex pokedex, struct pokenode *newnode) {
    if (pokedex->head == NULL) {
        pokedex->head = newnode;
        pokedex->last = newnode;
        pokedex->last->prev = NULL;
        pokedex->curr = newnode;
    } else {        
        int value = 0;
        int adding = 0;
        if (pokedex->head != pokedex->last) {
            struct pokenode *curr = pokedex->head;
            while (curr->next != NULL && value == 0) {
                addnewnode_at_curr(newnode, curr, &adding, &value);
                curr = curr->next;
            }
        }      
        int new_id = pokemon_id(newnode->pokemon);
        if (adding == 0 && (new_id > pokemon_id(pokedex->last->pokemon))) {
            int exit = 0;
            if (pokedex->head == NULL) {
                pokedex->head = newnode;
                pokedex->last = newnode;
                pokedex->last->prev = NULL;
                pokedex->curr = newnode;
            } else {
                struct pokenode *tmp = pokedex->head;
                
                id_matched(tmp, newnode, &exit);
                addnewnode_at_end(exit, pokedex, newnode);
            }
            pokedex->last->next = NULL;
            adding = 1;
        } else if (adding == 0 && (new_id < pokemon_id(pokedex->head->pokemon))) {
            newnode->next =pokedex->head;
            //newnode->prev = NULL;
            pokedex->head = newnode;
            newnode->next->prev = newnode;
        }
    }
    pokedex->head->prev = NULL;
    pokedex->curr = pokedex->head;
    pokedex->last->next = NULL;
    return pokedex;
}

// check that if the first type of the current pokemon is the unique one.
static void type1_exist(struct pokenode *curr1, struct pokenode *curr2, int *value1) {
    while (curr1 != curr2 && curr2 != NULL) {
        if (StringCompare(
            pokemon_type_to_string(pokemon_first_type(curr1->pokemon)), 
            pokemon_type_to_string(pokemon_first_type(curr2->pokemon))
            ) == 0 || StringCompare(pokemon_type_to_string(
            pokemon_first_type(curr1->pokemon)), 
            pokemon_type_to_string(pokemon_second_type(curr2->pokemon))
            ) == 0) {
            *value1 = 1;
        }
        curr2 = curr2->next;
    }
}
// check that if the second type of the current pokemon is the unique one.
static void type2_exist(
struct pokenode *curr1, struct pokenode *curr2, int *value2) {
    while (curr1 != curr2 && curr2 != NULL) {
        if (StringCompare(
            pokemon_type_to_string(pokemon_second_type(curr1->pokemon)), 
            pokemon_type_to_string(pokemon_first_type(curr2->pokemon))
            ) == 0 || StringCompare(pokemon_type_to_string(
            pokemon_second_type(curr1->pokemon)), 
            pokemon_type_to_string(pokemon_second_type(curr2->pokemon))
            ) == 0) {
            *value2 = 1;
        }
        curr2 = curr2->next;
    }
}
// check that if the first type of two pokemons are the same.
static int first_type_matched(struct pokenode *tmp1, struct pokenode *tmp2) {
    if (StringCompare(pokemon_type_to_string(
        pokemon_first_type(tmp1->pokemon)), pokemon_type_to_string(
        pokemon_first_type(tmp2->pokemon))) == 0 || StringCompare(
        pokemon_type_to_string(pokemon_first_type(tmp1->pokemon)), 
        pokemon_type_to_string(pokemon_second_type(tmp2->pokemon))) == 0) {
        return 1;
    } else {
        return 0;
    }
}
// check that if the second types of the two pokemon are the same.
static int second_type_matched(struct pokenode *tmp1, struct pokenode *tmp2) {
    if (StringCompare(pokemon_type_to_string(
        pokemon_second_type(tmp1->pokemon)), pokemon_type_to_string(
        pokemon_first_type(tmp2->pokemon))) == 0 || StringCompare(
        pokemon_type_to_string(pokemon_second_type(tmp1->pokemon)), 
        pokemon_type_to_string(pokemon_second_type(tmp2->pokemon))) == 0) {
        return 1;
    } else {
        return 0;
    }
}
        
// count the length of the string.
static int stringlength(char *string) {
    int counter = 0;
    while (string[counter] != '\0') {
        counter++;
    }
    return counter;
}
// check that if the ids of the two pokemons are the same.
static void id_matched(
struct pokenode *tmp, struct pokenode *newnode, int *exit) {
    while (tmp != NULL) {
        if (pokemon_id(tmp->pokemon) == pokemon_id(newnode->pokemon)) {
            *exit = 1; 
        } 
        tmp = tmp->next;
    }
}
// add a new node to the end of the pokedex.
static void addnewnode_at_end(
int exit, Pokedex pokedex, struct pokenode *newnode) {
    if (exit == 1) {
        printf("\n");
        printf("ID has existed!");
    } else {
        struct pokenode *tmp1 = pokedex->last;
        pokedex->last->next = newnode;
        pokedex->last = newnode;
        pokedex->last->prev = tmp1;
    }
}
// change all the small letters to the Captial letters.
static int ToCapitalletter(int number) {
    int newnumber = number;  
    if (number >= 97 && number <= 122) {
        newnumber = number - 32;
    }
    return newnumber;
}

// check that if there exists same character between the input character and
// the name of pokemons in the pokedex.
static int chMatching(char *string, char *input) {
    int i = 0;
    int counter = 0;
    int value = 0;
    while (i <= stringlength(string) - stringlength(input)  && value == 0) {
        
        int j = 0;
        while (j < stringlength(input)) {
            if (ToCapitalletter(string[i + j]) == ToCapitalletter(input[j])) {
                counter++; 
            }
            j++;
        }
        if (stringlength(input) == counter) {
            value = 1;
        } else {
            counter = 0;
        }
        i++;
    }
    if (counter != 0) {
        return 1;
    } else {
        return 0;
    }
}
// copy a pokenode 
struct pokenode *copiednode(struct pokenode *fromnode) {
    struct pokenode *copy = malloc(sizeof(struct pokenode));
    copy->next = NULL;
    copy->prev = NULL;
    copy->pokemon = clone_pokemon(fromnode->pokemon);
    copy->evolved = NULL;
    copy->hasbeenFound = 1;
    return copy;
}
// add a new node at current position.
static void addnewnode_at_curr(
struct pokenode *newnode, struct pokenode *curr, int *adding, int *value) {

    if (pokemon_id(newnode->pokemon) > pokemon_id(curr->pokemon) &&
    pokemon_id(newnode->pokemon) < pokemon_id(curr->next->pokemon)) {
        curr->next->prev = newnode;
        newnode->next = curr->next;
        newnode->prev = curr;
        curr->next = newnode;
        *adding = 1;
        *value = 1;
    }
}
// check that if the second type of the pokemon is not none.
static void second_type_not_none(Pokemon pokemon) {
    if (StringCompare(pokemon_type_to_string(
    pokemon_second_type(pokemon)), "None") != 0) {
        printf("%s",  
        pokemon_type_to_string(pokemon_second_type(pokemon)));
    }
}     



static void check_set(int i, struct pokenode *curr1, int value5, int *value3, 
    int *value4) {
    int j = 1;
    // check that if the type has been copied to the array.            
    while (j <= i && value5 == 1) {
        if (StringCompare(pokemon_type_to_string(pokemon_first_type(
        curr1->pokemon)), type[j]) == 0) {
            value3 = 1;
        }
        if (StringCompare(pokemon_type_to_string(pokemon_second_type
        (curr1->pokemon)), "None") != 0) {
            if (StringCompare(pokemon_type_to_string(
            pokemon_second_type(curr1->pokemon)), type[j]) == 0) {
                value4 = 1;
            }
        }
        j++;
    }
}


static void set_found1(int value1, int *value5, int *i, 
    struct pokonode *curr1) {
    if (value1 == 0) {
        curr1->hasbeenFound = 1;
        // add the first type to the 2D string.
        i++;
        stringcopy(type[i], pokemon_type_to_string(
        pokemon_first_type(curr1->pokemon)));
        if (StringCompare(pokemon_type_to_string(pokemon_second_type
        (curr1->pokemon)), "None") != 0) {
            // add the second type to the 2D string.
            i++;
            stringcopy(type[i], pokemon_type_to_string(
            pokemon_second_type(curr1->pokemon)));
        }
        value5 = 1;
    }   
}
 
 
 
static void set_found2(int value2, int *value5, int *i, 
    struct pokonode *curr1) {
    if (value2 == 0 && StringCompare(pokemon_type_to_string(
        pokemon_second_type(curr1->pokemon)), "None") != 0) {
        curr1->hasbeenFound = 1;
        i++;
        stringcopy(type[i], pokemon_type_to_string(
        pokemon_first_type(curr1->pokemon)));
        i++;
        stringcopy(type[i], pokemon_type_to_string(
        pokemon_second_type(curr1->pokemon)));
        value5 = 1;
    }
}




static void set_found3(int value1, int value3, int *value5, int *i, 
    struct pokonode *curr1) {
    if (value3 == 0) {
        if (value1 == 1 && StringCompare(pokemon_type_to_string
           (pokemon_second_type(curr1->pokemon)), "None") == 0) {
            curr1->hasbeenFound = 1;
            i++;
            stringcopy(type[i], pokemon_type_to_string(
            pokemon_first_type(curr1->pokemon)));
            value5 = 1;
        }
    }
}

static void set_found4(int value1, int value2, int value3, int value4, 
    int *value5, int *i, struct pokonode *curr1) {
    if (value1 == 1 && value2 == 1 && StringCompare(pokemon_type_to_string
           (pokemon_second_type(curr1->pokemon)), "None") != 0) {
        if (value3 == 0 || value4 == 0) {
            curr1->hasbeenFound = 1;
            i++;
            stringcopy(type[i], pokemon_type_to_string(pokemon_first_type(
            curr1->pokemon)));        
            i++;
            stringcopy(type[i], pokemon_type_to_string(pokemon_second_type(
            curr1->pokemon)));
            value5 = 1;
        }
    }
}
