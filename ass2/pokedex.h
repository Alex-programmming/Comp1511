//
// DO NOT CHANGE THIS FILE
//
// You do not submit this file. This file is not marked.
// If you think you need to change this file you have
// misunderstood the assignment - ask in the course forum.
//
// Assignment 2 19T3 COMP1511: Pokedex
// pokedex.h
//
// You must not change this file.
//
// Version 2.0.0: Release
// Version 2.0.1: Fix detail_pokemon comment to have 1 dp for height.

#include "pokemon.h"

#ifndef _POKEDEX_H_
#define _POKEDEX_H_

typedef struct pokedex *Pokedex;

#define DOES_NOT_EVOLVE (-64)

// Create a new Pokedex and return a pointer to it.
// The pointer is to a malloced piece of memory, and it is the caller's
// responsibility to call 'destroy_pokedex' to free that memory.
Pokedex new_pokedex(void);

////////////////////////////////////////////////////////////////////////
//                         Stage 1 Functions                          //
////////////////////////////////////////////////////////////////////////

// Add a new Pokemon to the Pokedex.
// Note: just adding the Pokemon to the Pokedex does not mean it has
// been 'found'.
//
// The new Pokemon should be added to the end of the Pokedex (i.e.
// directly after the Pokemon that was added when add_pokemon was last
// called).
//
// When the first Pokemon is added to the Pokédex, the currently
// selected Pokemon becomes this Pokemon.
//
// The currently selected Pokemon remains the first Pokemon that was
// inserted into the Pokedex, until the `change_current_pokemon`,
// `next_pokemon`, or `prev_pokemon` functions are called.
//
// If there is already a Pokemon in the Pokedex with the same pokemon_id
// as this Pokemon, the function should print an appropriate error
// message and exit the program.
//
// Pokedex Order:
// --------------
// The Pokemon in the Pokedex are stored in the order in which they were
// added, i.e. the first Pokemon in the Pokedex will be the first
// Pokemon that was added, the second Pokemon in the Pokedex will be the
// second Pokemon that was added etc, and the last Pokemon in the
// Pokedex will be the Pokemon that was added most recently.
//
// For example, if Pikachu (#025) was added into an empty Pokedex, the
// Pokedex would now contain Pikachu at the start of the list, and
// Pikachu would be the currently selected Pokemon.
//
// [Start of Pokedex]
// #025: Pikachu <-- currently selected Pokemon
// [End of Pokedex]
//
// If Squirtle (#007) was then added, it would be the second Pokemon in
// the Pokedex, after Pikachu. The currently selected Pokemon would
// remain Pikachu.
//
// [Start of Pokedex]
// #025: Pikachu <-- currently selected Pokemon
// #003: Squirtle
// [End of Pokedex]
//
// If Diglett (#050) was then added, it would be the third Pokemon in the
// Pokedex, after Squirtle.
//
// [Start of Pokedex]
// #025: Pikachu <-- currently selected Pokemon
// #003: Squirtle
// #050: Diglett
// [End of Pokedex]
void add_pokemon(Pokedex pokedex, Pokemon pokemon);

// Print out the details of the currently selected Pokemon in the form:
//   ID: 007
//   Name: Squirtle
//   Height: 0.5m
//   Weight: 9.0kg
//   Type: Water
//
// If the Pokemon has not been found, the output should be:
//   ID: 007
//   Name: ********
//   Height: --
//   Weight: --
//   Type: --
//
// There should be exactly as many asterisks as there are characters in the
// Pokemon's name
//
// If the Pokemon has multiple types, they should be separated by a space:
//   ID: 006
//   Name: Charizard
//   Height: 1.7m
//   Weight: 90.5kg
//   Type: Fire Flying
void detail_pokemon(Pokedex pokedex);

// Return the currently selected Pokemon (i.e. the pointer to the
// pokemon struct, which was originally passed in to new_pokemon).
//
// The currently selected Pokemon starts out as the first Pokemon that
// was added to the Pokedex, and can be changed by calling the functions
// you will implement in Stage 2 (e.g. `next_pokemon`).
//
// See the `test_next_pokemon` function in test_pokedex.c for a concrete
// example of this function being used.
//
// If the Pokedex is empty, this function should print an appropriate
// error message and exit the program.
Pokemon get_current_pokemon(Pokedex pokedex);

// Sets the currently selected Pokemon to be 'found'.
//
// (see the assignment spec for more details on what being 'found' means)
//
// If there are no Pokemon in the Pokedex, this function does nothing.
void find_current_pokemon(Pokedex pokedex);

// Print out all of the Pokemon in the Pokedex, in the order in which
// they are stored in the Pokedex.
//
// See the comments in add_pokemon for more details about the ordering
// of Pokemon.
//
// The output should match the following form
//
// --> #001: Bulbasaur
//     #004: **********
//     #007: ********
//     #010: Caterpie
//     #013: Weedle
//     #016: Pidgey
//
// An arrow should be displayed next to the currently selected Pokemon.
//
// If a pokemon_id has less than three digits, it should be printed with
// leading '0's.
//
// If it has more than three digits, it should be printed as-is.
//
// --> #001: Bulbasaur
//     #004: **********
//     #007: ********
//     #010: Caterpie
//     #013: Weedle
//     #1263: Jabberwocky
//
// Any Pokemon not yet 'found' should have its name replaced with
// asterisks. There should be exactly the same number of asterisks
// as the number of characters in the Pokemon's name.
//
// The Pokemon should be printed in the order that they were inserted
// into the Pokedex.
void print_pokemon(Pokedex pokedex);

////////////////////////////////////////////////////////////////////////
//                         Stage 2 Functions                          //
////////////////////////////////////////////////////////////////////////

// Change the currently selected Pokemon to be the Pokemon after the
// currently selected Pokemon in the Pokedex, based on the order in
// which the Pokemon are stored in the Pokedex.
//
// See the comments above the add_pokemon function for more details
// about the ordering of Pokemon.
//
// For example, if we had the following Pokedex:
//
// [Start of Pokedex]
// #025: Pikachu <-- currently selected Pokemon
// #003: Squirtle
// #050: Diglett
// [End of Pokedex]
//
// Calling the next_pokemon function would change the currently selected
// Pokemon to be Squirtle:
//
// [Start of Pokedex]
// #025: Pikachu
// #003: Squirtle <-- currently selected Pokemon
// #050: Diglett
// [End of Pokedex]
//
// If there is no next Pokemon, the current Pokemon is unchanged.
//
// If there are no Pokemon in the Pokedex, this function does nothing.
void next_pokemon(Pokedex pokedex);

// Change the currently selected Pokemon to be the Pokemon before the
// currently selected Pokemon in the Pokedex, based on the order in
// which the Pokemon are stored in the Pokedex.
//
// For example, if we had the following Pokedex:
// [Start of Pokedex]
// #025: Pikachu
// #003: Squirtle <-- currently selected Pokemon
// #050: Diglett
// [End of Pokedex]
//
// Calling the prev_pokemon function would change the currently selected
// Pokemon to be Pikachu:
//
// [Start of Pokedex]
// #025: Pikachu <-- currently selected Pokemon
// #003: Squirtle
// #050: Diglett
// [End of Pokedex]
//
// If there is no previous Pokemon, the current Pokemon is unchanged.
//
// If there are no Pokemon in the Pokedex, this function does nothing.
void prev_pokemon(Pokedex pokedex);

// Change the currently selected Pokemon in the Pokedex to be the
// Pokemon with the ID `id`.
//
// If there is no Pokemon with the ID `id`, this function does
// nothing.
void change_current_pokemon(Pokedex pokedex, int id);

// Remove the currently selected Pokemon from the Pokedex.
//
// When the currently selected Pokemon is removed, the new currently
// selected Pokemon should become the Pokemon that was after the removed
// Pokemon.
//
// For example, if we had the following Pokedex:
// [Start of Pokedex]
// #025: Pikachu
// #003: Squirtle <-- currently selected Pokemon
// #050: Diglett
// [End of Pokedex]
//
// Calling the remove_pokemon function would remove Squirtle, leaving us
// with the following Pokedex:
//
// [Start of Pokedex]
// #025: Pikachu
// #050: Diglett <-- currently selected Pokemon
// [End of Pokedex]
//
// If the removed Pokemon was at the end of the Pokedex (i.e. it had no
// Pokemon after it), the new currently selected Pokemon should instead
// become the Pokemon that was before the removed Pokemon.
//
// If the removed Pokemon was the only Pokemon in the Pokedex, the
// currently selected Pokemon should become NULL.
//
// If there are no Pokemon in the Pokedex, this function does nothing.
void remove_pokemon(Pokedex pokedex);

// Destroy the given Pokedex and free all associated memory.
void destroy_pokedex(Pokedex pokedex);

////////////////////////////////////////////////////////////////////////
//                         Stage 3 Functions                          //
////////////////////////////////////////////////////////////////////////

// Print out all of the different types of Pokemon in the Pokedex.
//
// Each type should only be printed once.
//
// Each type should be printed on a separate line.
//
// The types should be printed in the order that Pokemon with those
// types appear in the Pokedex.
//
// For example, if the Pokedex contained the following Pokemon:
//
// [Start of Pokedex]
// #129: Staryu (Water)
// #025: Pikachu (Electric)
// #072: Slowpoke (Psychic Water) <-- currently selected Pokemon
// #003: Squirtle (Water)
// #050: Diglett (Ground)
// [End of Pokedex]
//
// Your program should print:
//
// Water
// Electric
// Psychic
// Ground
//
// Note that even though multiple Pokemon in the Pokedex are Water type,
// Water was only printed once.
//
// If a Pokemon has more than one type, we consider the first type
// to come earlier in the list of types.
//
// If a Pokemon has more than one type, this function just treats them
// as two separate types (Psychic and Water in the example above are
// treated separately and will be printed on separate lines).
//
// NONE_TYPE should not be printed as a type.
//
// This function will print out types regardless of whether the Pokemon
// have been found or not
void show_types(Pokedex pokedex);

// Set the first not-yet-found Pokemon of each type to be found.
//
// This function will go through the Pokedex and set some Pokemon to found.
// It should set only the first Pokemon that is both not-yet-found and has
// a type that hasn't been found already in this exploration (this function
// call).
//
// For example, if the Pokedex contained the following Pokemon:
//
// [Start of Pokedex]
// #129: ****** (Water)
// #025: ******* (Electric)
// #072: ******** (Psychic Water) <-- currently selected Pokemon
// #003: ******** (Water)
// #050: Diglett (Ground)
// #095: **** (Ground)
// [End of Pokedex]
//
// go_exploring would make the following changes:
//
// [Start of Pokedex]
// #129: Staryu (Water)
// #025: Pikachu (Electric)
// #072: Slowpoke (Psychic Water) <-- currently selected Pokemon
// #003: ******** (Water)
// #050: Diglett (Ground)
// #095: Onix (Ground)
// [End of Pokedex]
//
// Staryu is the first unfound Water Pokemon in the Pokedex so it is set 
// to found.
// Pikachu is the first unfound Electric Pokemon in the Pokedex so it is 
// set to found.
// Slowpoke has the Psychic Type that hasn't been found yet, so it is set
// to found.
// 003, a Water type does not get set to found because we've already found
// a Water Pokemon in this exploration.
// Diglett is already found so it does not affect this exploration.
// Onix is the first unfound Ground Pokemon in the Pokedex so it is set 
// to found.
//
// NONE_TYPE is not considered a type in this function
void go_exploring(Pokedex pokedex);

// Return the total number of Pokemon in the Pokedex, whether or not
// they have been found.
int count_total_pokemon(Pokedex pokedex);

// Return the number of Pokemon in the Pokedex that have been found.
int count_found_pokemon(Pokedex pokedex);

////////////////////////////////////////////////////////////////////////
//                         Stage 4 Functions                          //
////////////////////////////////////////////////////////////////////////

// Add the information that the Pokemon with the ID `from_id` can
// evolve into the Pokemon with the ID `to_id`.
//
// See the evolution chart at https://pokemondb.net/pokedex/squirtle for
// more details
//
// For this assignment you can assume that every Pokemon can only evolve
// into one other Pokemon. If the function is called again with the same
// `from_id`, the new `to_id` will override the previous
// evolution information.
//
// For example, if the function was called three times:
//
// evolve_pokemon(pokedex, 0, 1)
// evolve_pokemon(pokedex, 0, 2)
// evolve_pokemon(pokedex, 0, 3)
//
// The end result of the these three function calls would be that
// Pokemon 0 evolves into Pokemon 3 (rather than 1 or 2).
//
// If there is no Pokemon with the ID `from_id` or `to_id`,
// or if the provided `from_id` and `to_id` are the same,
// this function should print an appropriate error message and exit the
// program.
void add_pokemon_evolution(Pokedex pokedex, int from_id, int to_id);

// Show the evolutions of the currently selected Pokemon.
// It should include the Pokemon it evolves into (if any), as well as
// any evolutions that its evolved state can evolve into, and so on.
//
// For example:
//
// #004 Charmander [Fire] --> #005 Charmeleon [Fire] --> #006 Charizard [Fire, Flying]
//
// If any of the Pokemon have not yet been 'found', their types and names
// should be replaced with "????".
//
// For example, if the Pokedex has found Charmander but not Charmeleon
// or Charizard, the output should be:
//
// #004 Charmander [Fire] --> #005 ???? [????] --> #006 ???? [????]
void show_evolutions(Pokedex pokedex);

// Return the pokemon_id of the Pokemon that the currently selected
// Pokemon evolves into.
//
// If the currently selected Pokemon does not evolve, this function
// should return DOES_NOT_EVOLVE.
//
// If the Pokedex is empty, this function should print an appropriate
// error message and exit the program.
int get_next_evolution(Pokedex pokedex);

////////////////////////////////////////////////////////////////////////
//                         Stage 5 Functions                          //
////////////////////////////////////////////////////////////////////////

// Create a new Pokedex which contains only the Pokemon of a specified
// type from the original Pokedex.
//
// If a Pokemon has more than one type, only one of its types has to
// match the given type to be included in the Pokedex.
//
// If the specified type is NONE_TYPE, INVALID_TYPE, or MAX_TYPE, this
// function should print an appropriate error message and exit the
// program.
//
// The Pokemon should appear in this Pokedex in the same order as they
// appeared in the original Pokedex.
//
// The new Pokedex's currently selected Pokemon should be the first
// Pokemon in that Pokedex.
//
// For example, if we had the following Pokedex:
//
// [Start of Pokedex]
// #129: Staryu (Water)
// #025: Pikachu (Electric)
// #072: Slowpoke (Psychic Water) <-- currently selected Pokemon
// #003: Squirtle (Water)
// #050: Diglett (Ground)
// [End of Pokedex]
//
// Calling get_pokemon_of_type(pokedex, WATER_TYPE) would result in a
// new Pokedex containing the following Pokemon in the following order:
//
// [Start of Pokedex]
// #129: Staryu (Water) <-- currently selected Pokemon
// #072: Slowpoke (Psychic Water)
// #003: Squirtle (Water)
// [End of Pokedex]
//
// If a Pokemon has not yet been found, it should not be added to the
// new Pokedex.
//
// All attributes should be copied except evolution information: the
// copied Pokemon should behave as if they have no evolutions.
//
// If there are no matching Pokemon, this function should return an
// empty Pokedex.
//
// This function should not alter the original Pokedex. It should create
// copies of any matching Pokemon in the original Pokedex, and insert
// those copies into the new Pokedex.
Pokedex get_pokemon_of_type(Pokedex pokedex, pokemon_type type);

// Create a new Pokedex which contains only the Pokemon that have
// previously been 'found' from the original Pokedex.
//
// The Pokemon should appear in this Pokedex in ascending order of
// pokemon_id (regardless of the order that they appeared in the
// original Pokedex).
//
// The new Pokedex's currently selected Pokemon should be the first
// Pokemon in that Pokedex (i.e. the Pokemon with the lowest pokemon_id).
//
// For example, if we had the following Pokedex:
//
// [Start of Pokedex]
// #129: ******
// #025: Pikachu
// #072: Slowpoke <-- currently selected Pokemon
// #003: Squirtle
// #050: *******
// [End of Pokedex]
//
// Calling get_found_pokemon would result in a new Pokedex containing
// the following Pokemon in the following order:
//
// [Start of Pokedex]
// #003: Squirtle <-- currently selected Pokemon
// #025: Pikachu
// #072: Slowpoke
// [End of Pokedex]
//
// All attributes should be copied except evolution information: the
// copied Pokemon should behave as if they have no evolutions.
//
// If there are no matching Pokemon, this function should return an
// empty Pokedex.
//
// This function should not alter the original Pokedex.  It should
// create copies of any Pokemon which are in the original Pokedex, and
// insert those copies into the new Pokedex.
Pokedex get_found_pokemon(Pokedex pokedex);

// Create a new Pokedex containing only the Pokemon from the original
// Pokedex which have the given string appearing in its name.
// (e.g. if the text provided is 'basau' then 'Bulbasaur' should be one
// of the Pokemon in the returned Pokedex)
//
// The text provided is not case sensitive,  e.g. if the text provided
// is 'bulb', then 'Bulbasaur' should be one of the Pokemon in the
// returned Pokedex.
//
// If a Pokemon has not yet been found, it should not be added to the
// new Pokedex.
//
// The new Pokedex's currently selected Pokemon should be the first
// Pokemon in that Pokedex.
//
// The Pokemon should appear in this Pokedex in the same order as they
// appeared in the original Pokedex.
//
// For example, if we had the following Pokedex:
//
// [Start of Pokedex]
// #129: Staryu
// #060: Polywag
// #025: Pikachu
// #072: Slowpoke <-- currently selected Pokemon
// #003: Squirtle
// #011: Metapod
// #050: Diglett
// #124: Vaporeon
// [End of Pokedex]
//
// Calling search_pokemon(pokedex, "po") would result in a new Pokedex
// containing the following Pokemon in the following order:
//
// [Start of Pokedex]
// #060: Polywag <-- currently selected Pokemon
// #072: Slowpoke
// #011: Metapod
// #124: Vaporeon
// [End of Pokedex]
//
// All attributes should be copied except evolution information: the
// copied Pokemon should behave as if they have no evolutions.
//
// If there are no matching Pokemon, this function should return an
// empty Pokedex.
//
// This function should not alter the original Pokedex.  It should
// create copies of any Pokemon which are in the original Pokedex, and
// insert those copies into the new Pokedex.
//
// !! You must not call any functions from string.h in this function !!
Pokedex search_pokemon(Pokedex pokedex, char *text);

#endif //  _POKEDEX_H_
