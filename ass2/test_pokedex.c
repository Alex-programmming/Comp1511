// Assignment 2 19T3 COMP1511: Pokedex
// test_pokedex.c
//
// This file allows you to automatically test the functions you
// implement in pokedex.c.
//
// This program was written by Haoheng Duan (z5248147)
// on 16/11/2019
//
// Head Comment: This program is used to test whether the founctions
// in pokedex work correctly by using assert.
//
// Version 1.0.0: Assignment released.

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "pokedex.h"



// Sample data on Bulbasaur, the Pokemon with pokemon_id 1.
#define BULBASAUR_ID 1
#define BULBASAUR_NAME "Bulbasaur"
#define BULBASAUR_HEIGHT 0.7
#define BULBASAUR_WEIGHT 6.9
#define BULBASAUR_FIRST_TYPE GRASS_TYPE
#define BULBASAUR_SECOND_TYPE POISON_TYPE

// Sample data on Ivysaur, the Pokemon with pokemon_id 2.
#define IVYSAUR_ID 2
#define IVYSAUR_NAME "Ivysaur"
#define IVYSAUR_HEIGHT 1.0
#define IVYSAUR_WEIGHT 13.0
#define IVYSAUR_FIRST_TYPE GRASS_TYPE
#define IVYSAUR_SECOND_TYPE POISON_TYPE




// Tests for Pokedex functions from pokedex.c.
static void test_new_pokedex(void);
static void test_add_pokemon(void);
static void test_get_found_pokemon(void);
static void test_next_pokemon(void);
static void test_detail_pokemon(void);
static void test_get_current_pokemon(void);
static void test_find_current_pokemon(void);
static void test_print_pokemon(void);
static void test_prev_pokemon(void);
static void test_change_current_pokemon(void);
static void test_remove_pokemon(void);
static void test_show_types(void);
static void test_go_exploring(void);
static void test_count_total_pokemon(void);
static void test_count_found_pokemon(void);
static void test_add_pokemon_evolution(void);
static void test_show_evolutions(void);
static void test_get_next_evolution(void);
static void test_get_pokemon_of_type(void);
static void test_search_pokemon(void);

// Helper functions for creating/comparing Pokemon.
static Pokemon create_bulbasaur(void);
static Pokemon create_ivysaur(void);
static int is_same_pokemon(Pokemon first, Pokemon second);
static int is_copied_pokemon(Pokemon first, Pokemon second);



int main(int argc, char *argv[]) {
    printf("Welcome to the COMP1511 Pokedex Tests!\n");

    printf("\n==================== Pokedex Tests ====================\n");

    test_new_pokedex();
    test_add_pokemon();
    test_next_pokemon();
    test_get_found_pokemon(); 
    test_detail_pokemon();
    test_get_current_pokemon();
    test_find_current_pokemon();
    test_print_pokemon();
    test_prev_pokemon();
    test_change_current_pokemon();
    test_remove_pokemon();
    test_show_types();
    test_go_exploring();
    test_count_total_pokemon();
    test_count_found_pokemon();
    test_add_pokemon_evolution();
    test_show_evolutions();
    test_get_next_evolution();
    test_get_pokemon_of_type();
    test_search_pokemon();

    printf("\nAll Pokedex tests passed, you are Awesome!\n");
}


////////////////////////////////////////////////////////////////////////
//                     Pokedex Test Functions                         //
////////////////////////////////////////////////////////////////////////

// `test_new_pokedex` checks whether the new_pokedex and destroy_pokedex
// functions work correctly, to the extent that it can.
//
// It does this by creating a new Pokedex, checking that it's not NULL,
// then calling destroy_pokedex.
//
// Note that it isn't possible to check whether destroy_pokedex has
// successfully destroyed/freed the Pokedex, so the best we can do is to
// call the function and make sure that it doesn't crash..
static void test_new_pokedex(void) {
    printf("\n>> Testing new_pokedex\n");

    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();

    printf("       --> Checking that the returned Pokedex is not NULL\n");
    assert(pokedex != NULL);

    printf("    ... Destroying the Pokedex\n");
    destroy_pokedex(pokedex);

    printf(">> Passed new_pokedex tests!\n");
}

// `test_add_pokemon` checks whether the add_pokemon function works
// correctly.
//
// It does this by creating the Pokemon Bulbasaur (using the helper
// functions in this file and the provided code in pokemon.c), and
// calling add_pokemon to add it to the Pokedex.
//
// Some of the ways that you could extend these test would include:
//   - adding additional Pokemon other than just Bulbasaur,
//   - checking whether the currently selected Pokemon is correctly set,
//   - checking that functions such as `count_total_pokemon` return the
//     correct result after more Pokemon are added,
//   - ... and more!
static void test_add_pokemon(void) {
    printf("\n>> Testing add_pokemon\n");

    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();

    printf("    ... Creating Bulbasaur\n");
    Pokemon bulbasaur = create_bulbasaur();

    printf("    ... Adding Bulbasaur to the Pokedex\n");
    add_pokemon(pokedex, bulbasaur);

    printf("    ... Destroying the Pokedex\n");
    destroy_pokedex(pokedex);

    printf(">> Passed add_pokemon tests!\n");
}

// `test_next_pokemon` checks whether the next_pokemon function works
// correctly.
//
// It does this by creating two Pokemon: Bulbasaur and Ivysaur (using
// the helper functions in this file and the provided code in pokemon.c).
//
// It then adds these to the Pokedex, then checks that calling the
// next_pokemon function changes the currently selected Pokemon from
// Bulbasaur to Ivysaur.
//
// Some of the ways that you could extend these tests would include:
//   - adding even more Pokemon to the Pokedex,
//   - calling the next_pokemon function when there is no "next" Pokemon,
//   - calling the next_pokemon function when there are no Pokemon in
//     the Pokedex,
//   - ... and more!
static void test_next_pokemon(void) {
    printf("\n>> Testing next_pokemon\n");

    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();

    printf("    ... Creating Bulbasaur and Ivysaur\n");
    Pokemon bulbasaur = create_bulbasaur();
    Pokemon ivysaur = create_ivysaur();

    printf("    ... Adding Bulbasaur and Ivysaur to the Pokedex\n");
    add_pokemon(pokedex, bulbasaur);
    add_pokemon(pokedex, ivysaur);

    printf("       --> Checking that the current Pokemon is Bulbasaur\n");
    assert(is_same_pokemon(get_current_pokemon(pokedex), bulbasaur));

    printf("    ... Moving to the next pokemon\n");
    next_pokemon(pokedex);

    printf("       --> Checking that the current Pokemon is Ivysaur\n");
    assert(is_same_pokemon(get_current_pokemon(pokedex), ivysaur));

    printf("    ... Destroying the Pokedex\n");
    destroy_pokedex(pokedex);

    printf(">> Passed next_pokemon tests!\n");
}

// `test_get_found_pokemon` checks whether the get_found_pokemon
// function works correctly.
//
// It does this by creating two Pokemon: Bulbasaur and Ivysaur (using
// the helper functions in this file and the provided code in pokemon.c).
//
// It then adds these to the Pokedex, sets Bulbasaur to be found, and
// then calls the get_found_pokemon function to get all of the Pokemon
// which have been found (which should be just the one, Bulbasaur).
//
// Some of the ways that you could extend these tests would include:
//   - calling the get_found_pokemon function on an empty Pokedex,
//   - calling the get_found_pokemon function on a Pokedex where none of
//     the Pokemon have been found,
//   - checking that the Pokemon in the new Pokedex are in ascending
//     order of pokemon_id (regardless of the order that they appeared
//     in the original Pokedex),
//   - checking that the currently selected Pokemon in the returned
//     Pokedex has been set correctly,
//   - checking that the original Pokedex has not been modified,
//   - ... and more!
static void test_get_found_pokemon(void) {
    printf("\n>> Testing get_found_pokemon\n");

    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();

    printf("    ... Creating Bulbasaur and Ivysaur\n");
    Pokemon bulbasaur = create_bulbasaur();
    Pokemon ivysaur = create_ivysaur();

    printf("    ... Adding Bulbasaur and Ivysaur to the Pokedex\n");
    add_pokemon(pokedex, bulbasaur);
    add_pokemon(pokedex, ivysaur);

    printf("       --> Checking that the current Pokemon is Bulbasaur\n");
    assert(get_current_pokemon(pokedex) == bulbasaur);
    
    printf("    ... Setting Bulbasaur to be found\n");
    find_current_pokemon(pokedex);

    printf("    ... Getting all found Pokemon\n");
    Pokedex found_pokedex = get_found_pokemon(pokedex);

    printf("       --> Checking the correct Pokemon were copied and returned\n");
    assert(count_total_pokemon(found_pokedex) == 1);
    assert(count_found_pokemon(found_pokedex) == 1);
    assert(is_copied_pokemon(get_current_pokemon(found_pokedex), bulbasaur));

    printf("    ... Destroying both Pokedexes\n");
    destroy_pokedex(pokedex);
    destroy_pokedex(found_pokedex);

    printf(">> Passed get_found_pokemon tests!\n");
}


// Write your own Pokedex tests here!

// Test detail_pokemon by checking whether it works
static void test_detail_pokemon(void) {
    printf("\n>> Testing detail_pokemon\n");
    
    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();
    
    printf("    ... Creating Bulbasaur and Ivysaur\n");
    Pokemon bulbasaur = create_bulbasaur();
    Pokemon ivysaur = create_ivysaur();
    
    printf("    ... Adding Bulbasaur and Ivysaur to the Pokedex\n");
    add_pokemon(pokedex, bulbasaur);
    add_pokemon(pokedex, ivysaur);
    
    printf(" Print out the details of the currently selected Pokemon\n");
    detail_pokemon(pokedex);
    
    printf("    ... Destroying the Pokedex\n");
    destroy_pokedex(pokedex);

    printf(">> Passed get_found_pokemon tests!\n");
}


// Test get_current_pokemon by comparing the pokemon
static void test_get_current_pokemon(void) {
    printf("\n>> Testing get_current_pokemon\n");
    
    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();
    
    printf("    ... Creating Bulbasaur and Ivysaur\n");
    Pokemon bulbasaur = create_bulbasaur();
    Pokemon ivysaur = create_ivysaur();
    
    printf("    ... Adding Bulbasaur and Ivysaur to the Pokedex\n");
    add_pokemon(pokedex, bulbasaur);
    add_pokemon(pokedex, ivysaur);
    
    printf(" Return the currently selected Pokemon\n");
    Pokemon curr = get_current_pokemon(pokedex);
    
    printf("       --> Checking that the current Pokemon is Bulbasaur\n");
    assert(is_same_pokemon(curr, bulbasaur));
    
    printf("    ... Destroying the Pokedex\n");
    destroy_pokedex(pokedex);

    printf(">> Passed get_found_pokemon tests!\n");
}


// Test find_current_pokemon by comparing the number of found pokemon
static void test_find_current_pokemon(void) {
    printf("\n>> Testing find_current_pokemon\n");
    
    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();
    
    printf("    ... Creating Bulbasaur and Ivysaur\n");
    Pokemon bulbasaur = create_bulbasaur();
    Pokemon ivysaur = create_ivysaur();
    
    printf("    ... Adding Bulbasaur and Ivysaur to the Pokedex\n");
    add_pokemon(pokedex, bulbasaur);
    add_pokemon(pokedex, ivysaur);
    
    printf(" Sets the currently selected Pokemon to be 'found'\n");
    find_current_pokemon(pokedex);
    
    printf("Return the number of Pokemon in the Pokedex that have been found.\n");
    assert(count_found_pokemon(pokedex) == 1);
    
    printf("    ... Destroying the Pokedex\n");
    destroy_pokedex(pokedex);

    printf(">> Passed get_found_pokemon tests!\n");
}


// Test print pokemon by checking whether it work correctly
static void test_print_pokemon(void) {
    printf("\n>> Testing print_pokemon\n");
    
    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();
    
    printf("    ... Creating Bulbasaur and Ivysaur\n");
    Pokemon bulbasaur = create_bulbasaur();
    Pokemon ivysaur = create_ivysaur();
    
    printf("    ... Adding Bulbasaur and Ivysaur to the Pokedex\n");
    add_pokemon(pokedex, bulbasaur);
    add_pokemon(pokedex, ivysaur);
    
    printf(" Print out all of the Pokemon in the Pokedex\n");
    print_pokemon(pokedex);
    
    printf("    ... Destroying the Pokedex\n");
    destroy_pokedex(pokedex);

    printf(">> Passed get_found_pokemon tests!\n");
}


// Test prev_pokemon by comparing the pokemon
static void test_prev_pokemon(void) {
    printf("\n>> Testing prev_pokemon\n");
    
    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();
    
    printf("    ... Creating Bulbasaur and Ivysaur\n");
    Pokemon bulbasaur = create_bulbasaur();
    Pokemon ivysaur = create_ivysaur();

    printf("    ... Adding Bulbasaur and Ivysaur to the Pokedex\n");
    add_pokemon(pokedex, bulbasaur);
    add_pokemon(pokedex, ivysaur);

    printf("       --> Checking that the current Pokemon is Bulbasaur\n");
    assert(is_same_pokemon(get_current_pokemon(pokedex), bulbasaur));

    printf("    ... Moving to the next pokemon\n");
    next_pokemon(pokedex);

    printf("       --> Checking that the current Pokemon is Ivysaur\n");
    assert(is_same_pokemon(get_current_pokemon(pokedex), ivysaur));
    
    printf("    ... Moving to the previous pokemon\n");
    prev_pokemon(pokedex);
    
    printf("       --> Checking that the current Pokemon is Bulbasaur\n");
    assert(is_same_pokemon(get_current_pokemon(pokedex), bulbasaur));
    
    printf("    ... Destroying the Pokedex\n");
    destroy_pokedex(pokedex);

    printf(">> Passed get_found_pokemon tests!\n");
}


// Test change_current_pokemon by comparing the pokemon
static void test_change_current_pokemon(void) {
    printf("\n>> Testing change_current_pokemon\n");
    
    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();
    
    printf("    ... Creating Bulbasaur and Ivysaur\n");
    Pokemon bulbasaur = create_bulbasaur();
    Pokemon ivysaur = create_ivysaur();

    printf("    ... Adding Bulbasaur and Ivysaur to the Pokedex\n");
    add_pokemon(pokedex, bulbasaur);
    add_pokemon(pokedex, ivysaur);

    printf("       --> Checking that the current Pokemon is Bulbasaur\n");
    assert(is_same_pokemon(get_current_pokemon(pokedex), bulbasaur));
    
    printf(" Change the current Pokemon to Ivysaur\n");
    change_current_pokemon(pokedex, IVYSAUR_ID);
    
    printf("       --> Checking that the current Pokemon is Ivysaur\n");
    assert(is_same_pokemon(get_current_pokemon(pokedex), ivysaur));
    
    printf("    ... Destroying the Pokedex\n");
    destroy_pokedex(pokedex);

    printf(">> Passed get_found_pokemon tests!\n");
}


// Test remove_pokemon by comparing the number of total
static void test_remove_pokemon(void) {
    printf("\n>> Testing remove_pokemon\n");
    
    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();
    
    printf("    ... Creating Bulbasaur and Ivysaur\n");
    Pokemon bulbasaur = create_bulbasaur();
    Pokemon ivysaur = create_ivysaur();

    printf("    ... Adding Bulbasaur and Ivysaur to the Pokedex\n");
    add_pokemon(pokedex, bulbasaur);
    add_pokemon(pokedex, ivysaur);
    
    printf("Remove Balbasaur from the Pokedex.\n");
    remove_pokemon(pokedex);
    
    printf("       --> Checking that the current Pokemon is Ivysaur\n");
    assert(is_same_pokemon(get_current_pokemon(pokedex), ivysaur));
    
    printf("       --> Checking the correct number of Pokemon\n");
    assert(count_total_pokemon(pokedex) == 1);
    
    printf("    ... Destroying the Pokedex\n");
    destroy_pokedex(pokedex);

    printf(">> Passed get_found_pokemon tests!\n");
}


// Test show_types by checking whether it work correctly
static void test_show_types(void) {
    printf("\n>> Testing show_types\n");
    
    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();
    
    printf("    ... Creating Bulbasaur and Ivysaur\n");
    Pokemon bulbasaur = create_bulbasaur();
    Pokemon ivysaur = create_ivysaur();

    printf("    ... Adding Bulbasaur and Ivysaur to the Pokedex\n");
    add_pokemon(pokedex, bulbasaur);
    add_pokemon(pokedex, ivysaur);
    
    printf("Print out all of the different types of Pokemon in the Pokedex.\n");
    show_types(pokedex);
    
    printf("    ... Destroying the Pokedex\n");
    destroy_pokedex(pokedex);

    printf(">> Passed get_found_pokemon tests!\n");
}


// Test go_exploring by comparing the number of found pokemon
static void test_go_exploring(void) {
    printf("\n>> Testing go_exploring\n");
    
    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();
    
    printf("    ... Creating Bulbasaur and Ivysaur\n");
    Pokemon bulbasaur = create_bulbasaur();
    Pokemon ivysaur = create_ivysaur();

    printf("    ... Adding Bulbasaur and Ivysaur to the Pokedex\n");
    add_pokemon(pokedex, bulbasaur);
    add_pokemon(pokedex, ivysaur);
    
    printf("Set the first not-yet-found Pokemon of each type to be found.\n");
    go_exploring(pokedex);
    
    printf("Return the number of Pokemon in the Pokedex that have been found.\n");
    assert(count_found_pokemon(pokedex) == 1);
    
    printf("    ... Destroying the Pokedex\n");
    destroy_pokedex(pokedex);

    printf(">> Passed get_found_pokemon tests!\n");
}


// Test count_total_pokemon by checking the number of pokemon
static void test_count_total_pokemon(void) {
    printf("\n>> Testing count_total_pokemon\n");
    
    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();
    
    printf("    ... Creating Bulbasaur and Ivysaur\n");
    Pokemon bulbasaur = create_bulbasaur();
    Pokemon ivysaur = create_ivysaur();

    printf("    ... Adding Bulbasaur and Ivysaur to the Pokedex\n");
    add_pokemon(pokedex, bulbasaur);
    add_pokemon(pokedex, ivysaur);
    
    printf("       --> Checking the correct number of Pokemon\n");
    assert(count_total_pokemon(pokedex) == 2);
    
    printf("    ... Destroying the Pokedex\n");
    destroy_pokedex(pokedex);

    printf(">> Passed get_found_pokemon tests!\n");
}


// Test count_found_pokemon by checking the number of pokemon
static void test_count_found_pokemon(void) {
    printf("\n>> Testing count_found_pokemon\n");
    
    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();
    
    printf("    ... Creating Bulbasaur and Ivysaur\n");
    Pokemon bulbasaur = create_bulbasaur();
    Pokemon ivysaur = create_ivysaur();

    printf("    ... Adding Bulbasaur and Ivysaur to the Pokedex\n");
    add_pokemon(pokedex, bulbasaur);
    add_pokemon(pokedex, ivysaur);
    
    printf(" Sets the currently selected Pokemon to be 'found'\n");
    find_current_pokemon(pokedex);
    
    printf("       --> Checking the correct number of found Pokemon\n");
    assert(count_found_pokemon(pokedex) == 1);
    
    printf("    ... Destroying the Pokedex\n");
    destroy_pokedex(pokedex);

    printf(">> Passed get_found_pokemon tests!\n");
}


// Test add_pokemon_evolution by comparing the id
static void test_add_pokemon_evolution(void) {
    printf("\n>> Testing add_pokemon_evolution\n");
    
    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();
    
    printf("    ... Creating Bulbasaur and Ivysaur\n");
    Pokemon bulbasaur = create_bulbasaur();
    Pokemon ivysaur = create_ivysaur();

    printf("    ... Adding Bulbasaur and Ivysaur to the Pokedex\n");
    add_pokemon(pokedex, bulbasaur);
    add_pokemon(pokedex, ivysaur);
    
    printf(" Add evolution to Pokemon\n");
    add_pokemon_evolution(pokedex, BULBASAUR_ID, IVYSAUR_ID);
    
    printf(" Check the evolution is correct\n");
    assert(get_next_evolution(pokedex) == IVYSAUR_ID);
    
    printf("    ... Destroying the Pokedex\n");
    destroy_pokedex(pokedex);

    printf(">> Passed get_found_pokemon tests!\n");
}


// Test show_evolutions by checking whether it works
static void test_show_evolutions(void) {
    printf("\n>> Testing show_evolutions\n");
    
    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();
    
    printf("    ... Creating Bulbasaur and Ivysaur\n");
    Pokemon bulbasaur = create_bulbasaur();
    Pokemon ivysaur = create_ivysaur();

    printf("    ... Adding Bulbasaur and Ivysaur to the Pokedex\n");
    add_pokemon(pokedex, bulbasaur);
    add_pokemon(pokedex, ivysaur);
    
    printf("Show the evolutions of the currently selected Pokemon.\n");
    show_evolutions(pokedex);
    
    printf("    ... Destroying the Pokedex\n");
    destroy_pokedex(pokedex);

    printf(">> Passed get_found_pokemon tests!\n");
}

// Test get_next_evolution by comparing the id
static void test_get_next_evolution(void) {
    printf("\n>> Testing get_next_evolution\n");
    
    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();
    
    printf("    ... Creating Bulbasaur and Ivysaur\n");
    Pokemon bulbasaur = create_bulbasaur();
    Pokemon ivysaur = create_ivysaur();

    printf("    ... Adding Bulbasaur and Ivysaur to the Pokedex\n");
    add_pokemon(pokedex, bulbasaur);
    add_pokemon(pokedex, ivysaur);
    
    printf(" Add evolution to Pokemon\n");
    add_pokemon_evolution(pokedex, BULBASAUR_ID, IVYSAUR_ID);
    
    printf(" Check whether the evolution is correct\n");
    assert(get_next_evolution(pokedex) == IVYSAUR_ID);
    
    printf("    ... Destroying the Pokedex\n");
    destroy_pokedex(pokedex);

    printf(">> Passed get_found_pokemon tests!\n");
}


// Test get_pokemon_of_type by checking the number of pokemons
static void test_get_pokemon_of_type(void) {
    printf("\n>> Testing get_pokemon_of_type\n");
    
    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();
    
    printf("    ... Creating Bulbasaur and Ivysaur\n");
    Pokemon bulbasaur = create_bulbasaur();
    Pokemon ivysaur = create_ivysaur();

    printf("    ... Adding Bulbasaur and Ivysaur to the Pokedex\n");
    add_pokemon(pokedex, bulbasaur);
    add_pokemon(pokedex, ivysaur);
    
    printf("       --> Checking that the current Pokemon is Bulbasaur\n");
    assert(is_same_pokemon(get_current_pokemon(pokedex), bulbasaur));
    
    printf(" Set the current pokemon to be found\n");
    find_current_pokemon(pokedex);
    
    printf("    ... Moving to the next pokemon\n");
    next_pokemon(pokedex);
    
    printf("       --> Checking that the current Pokemon is Ivysaur\n");
    assert(is_same_pokemon(get_current_pokemon(pokedex), ivysaur));
    
    printf(" Set the current pokemon to be found\n");
    find_current_pokemon(pokedex);
    
    printf("    ... Getting all found Pokemon that have type poison\n");
    Pokedex type_pokedex = get_pokemon_of_type(pokedex, IVYSAUR_SECOND_TYPE);

    printf("       --> Checking the correct Pokemon were copied and returned\n");
    assert(count_total_pokemon(type_pokedex) == 2);
    assert(count_found_pokemon(type_pokedex) == 2);
    assert(is_copied_pokemon(get_current_pokemon(type_pokedex), bulbasaur));
    
    printf("    ... Destroying both Pokedexes\n");
    destroy_pokedex(pokedex);
    destroy_pokedex(type_pokedex);

    printf(">> Passed get_found_pokemon tests!\n");
}


// Test search_pokemon founction by checking the number of pokemons
static void test_search_pokemon(void) {
    printf("\n>> Testing search_pokemon\n");
    
    printf("    ... Creating a new Pokedex\n");
    Pokedex pokedex = new_pokedex();
    
    printf("    ... Creating Bulbasaur and Ivysaur\n");
    Pokemon bulbasaur = create_bulbasaur();
    Pokemon ivysaur = create_ivysaur();

    printf("    ... Adding Bulbasaur and Ivysaur to the Pokedex\n");
    add_pokemon(pokedex, bulbasaur);
    add_pokemon(pokedex, ivysaur);
    
    printf("       --> Checking that the current Pokemon is Bulbasaur\n");
    assert(is_same_pokemon(get_current_pokemon(pokedex), bulbasaur));
    
    printf(" Set the current pokemon to be found\n");
    find_current_pokemon(pokedex);
    
    printf("    ... Moving to the next pokemon\n");
    next_pokemon(pokedex);
    
    printf("       --> Checking that the current Pokemon is Ivysaur\n");
    assert(is_same_pokemon(get_current_pokemon(pokedex), ivysaur));
    
    printf(" Set the current pokemon to be found\n");
    find_current_pokemon(pokedex);
    
    printf("    ... Getting all found Pokemon that have 'saur'\n");
    Pokedex search_pokedex = search_pokemon(pokedex, "saur");

    printf("       --> Checking the correct Pokemon were copied and returned\n");
    assert(count_total_pokemon(search_pokedex) == 2);
    assert(count_found_pokemon(search_pokedex) == 2);
    assert(is_copied_pokemon(get_current_pokemon(search_pokedex), bulbasaur));
    
    printf("    ... Destroying both Pokedexes\n");
    destroy_pokedex(pokedex);
    destroy_pokedex(search_pokedex);

    printf(">> Passed get_found_pokemon tests!\n");
}

////////////////////////////////////////////////////////////////////////
//                     Helper Functions                               //
////////////////////////////////////////////////////////////////////////

// Helper function to create Bulbasaur for testing purposes.
static Pokemon create_bulbasaur(void) {
    Pokemon pokemon = new_pokemon(
            BULBASAUR_ID, BULBASAUR_NAME,
            BULBASAUR_HEIGHT, BULBASAUR_WEIGHT,
            BULBASAUR_FIRST_TYPE,
            BULBASAUR_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to create Ivysaur for testing purposes.
static Pokemon create_ivysaur(void) {
    Pokemon pokemon = new_pokemon(
            IVYSAUR_ID, IVYSAUR_NAME,
            IVYSAUR_HEIGHT, IVYSAUR_WEIGHT,
            IVYSAUR_FIRST_TYPE,
            IVYSAUR_SECOND_TYPE
    );
    return pokemon;
}

// Helper function to compare whether two Pokemon are the same.
// This checks that the two pointers contain the same address, i.e.
// they are both pointing to the same pokemon struct in memory.
//
// Pokemon ivysaur = new_pokemon(0, 'ivysaur', 1.0, 13.0, GRASS_TYPE, POISON_TYPE)
// Pokemon also_ivysaur = ivysaur
// is_same_pokemon(ivysaur, also_ivysaur) == TRUE
static int is_same_pokemon(Pokemon first, Pokemon second) {
    return first == second;
}

// Helper function to compare whether one Pokemon is a *copy* of
// another, based on whether their attributes match (e.g. pokemon_id,
// height, weight, etc).
// 
// It also checks that the pointers do *not* match -- i.e. that the
// pointers aren't both pointing to the same pokemon struct in memory.
// If the pointers both contain the same address, then the second
// Pokemon is not a *copy* of the first Pokemon.
// 
// This function doesn't (yet) check that the Pokemon's names match
// (but perhaps you could add that check yourself...).
static int is_copied_pokemon(Pokemon first, Pokemon second) {
    return (pokemon_id(first) == pokemon_id(second))
    &&  (first != second)
    &&  (pokemon_height(first) == pokemon_height(second))
    &&  (pokemon_weight(first) == pokemon_weight(second))
    &&  (pokemon_first_type(first) == pokemon_first_type(second))
    &&  (pokemon_second_type(first) == pokemon_second_type(second));
}

