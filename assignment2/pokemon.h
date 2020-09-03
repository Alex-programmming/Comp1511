//
// DO NOT CHANGE THIS FILE
//
// You do not submit this file. This file is not marked.
// If you think you need to change this file you have
// misunderstood the assignment - ask in the course forum.
//
// Assignment 2 19T3 COMP1511: Pokedex
// pokemon.h
//
// Version 2.0.0 Release

#ifndef _POKEMON_H_
#define _POKEMON_H_

//////////////////////////////////////////////////////////////////////
//                     enum pokemon_type                            //
//////////////////////////////////////////////////////////////////////

// The enum "pokemon_type" provides named constants that can be used.
//
// An enum is a collection of constants that works just like:
// #define NONE_TYPE    0
// #define NORMAL_TYPE  1
// #define FIRE_TYPE    2
// ...
//
// Note that you should access the types via the ALL_CAPS names, e.g.
// NORMAL_TYPE or FIRE_TYPE, rather than trying to use a the numbers
// directly.
//
// Also note that the types below are not strings, i.e. your code should
// use NORMAL_TYPE, not "NORMAL_TYPE".
typedef enum pokemon_type {
    INVALID_TYPE = -1,
    NONE_TYPE,
    NORMAL_TYPE,
    FIRE_TYPE,
    FIGHTING_TYPE,
    WATER_TYPE,
    FLYING_TYPE,
    GRASS_TYPE,
    POISON_TYPE,
    ELECTRIC_TYPE,
    GROUND_TYPE,
    PSYCHIC_TYPE,
    ROCK_TYPE,
    ICE_TYPE,
    BUG_TYPE,
    DRAGON_TYPE,
    GHOST_TYPE,
    DARK_TYPE,
    STEEL_TYPE,
    FAIRY_TYPE,
    MAX_TYPE
} pokemon_type;


//////////////////////////////////////////////////////////////////////
//                 typedef struct pokemon *Pokemon                  //
//////////////////////////////////////////////////////////////////////

// typedef declares that the type "Pokemon" is the same as the type
// "pointer to a pokemon struct".
//
// pokemon.h does not show what "struct pokemon" is, it only knows that
// it can store the memory address of that struct.
// The actual definition of "struct pokemon" is in pokemon.c
//
// This means that the program does not know anything about the fields
// in the pokemon struct. For example, our main.c cannot use the
// expression: "pokemon->pokemon_id" because it does not know that
// a Pokemon has a pokemon_id field.
//
// The only way to access the pokemon struct is through functions
// available in pokemon.h
// 
// If you see the following error:
// error: incomplete definition of type 'struct pokemon'
//
// This means that the program has tried to access the struct directly
// instead of through the pokemon.h functions.
typedef struct pokemon *Pokemon;


//////////////////////////////////////////////////////////////////////
//                        Pokemon functions                         //
//////////////////////////////////////////////////////////////////////

// Create a new Pokemon, given its pokemon_id, name, height, weight, and
// type(s).
//
// The pokemon_id must be an integer, zero or higher (i.e. >= 0).
//
// The name must consist only of uppercase letters, lowercase letters,
// spaces (' ') and hyphens ('-').
//
// If an input name contains any invalid characters, the function should
// print an error message explaining the issue and exit the program.
//
// A Pokemon must have one type (type1) and may have a type2. If it only
// has one type, type2 should be NONE_TYPE
//
// The two types will match one of the pokemon_type enum described above.
// They should be used with their CONSTANT names, which can also be 
// stored as integers.
//
// The following inputs are invalid for types:
// * if "type1" is NONE_TYPE - Every Pokemon must have at least one type
// * if "type1" and "type2" are the same type
// * if either type is not a pokemon_type (values that are not in the enum
//       like AIR_TYPE or EARTH_TYPE)
//
// If any of these invalid inputs are found, the function should
// print an appropriate error message and exit the program.
//
// Weight is given in kilograms, and height is given in metres.
//
// Example: new_pokemon(0, "Pikachu", 12, 2.5, ELECTRIC_TYPE, NONE_TYPE)
Pokemon new_pokemon(int pokemon_id, char *name, double height,
    double weight, pokemon_type type1, pokemon_type type2);

// Free the memory used for a given Pokemon.
void destroy_pokemon(Pokemon pokemon);

// Create a clone of the input Pokemon.
//
// The cloned Pokemon will copy the attributes of the original Pokemon
// (e.g. same pokemon_id, same name, etc).
//
// The clone and the original will exist in two different memory
// locations. They are completely separate copies of the same Pokemon
// and deleting either one will have no effect on the other
Pokemon clone_pokemon(Pokemon pokemon);

// Return the pokemon_id of a given Pokemon.
int pokemon_id(Pokemon pokemon);

// Return the name of a given Pokemon.
// The returned string has not been allocated with malloc.
// It should not be changed or freed by the caller.
char *pokemon_name(Pokemon pokemon);

// Return the height of a given Pokemon.
double pokemon_height(Pokemon pokemon);

// Return the weight of a given Pokemon.
double pokemon_weight(Pokemon pokemon);

// Return the first type of a given Pokemon.
pokemon_type pokemon_first_type(Pokemon pokemon);

// Return the second type of a given Pokemon.
// If the Pokemon only has one type, returns NONE_TYPE.
pokemon_type pokemon_second_type(Pokemon pokemon);

// Check whether the specified "name" is a valid name for a Pokemon.
// Returns 1 if all the characters are valid Pokemon name characters.
// Returns 0 if not.
// The name must consist only of uppercase letters, lowercase letters,
// spaces (' ') and hyphens ('-').
int pokemon_valid_name(char *name);


//////////////////////////////////////////////////////////////////////
//                      pokemon_type functions                      //
//////////////////////////////////////////////////////////////////////

// Return the pokemon_type value for the given "type_name".
//
// Example: pokemon_type_from_string("Water") returns WATER_TYPE.
//
// Returns INVALID_TYPE if "type_name" is not a valid Pokemon type.
pokemon_type pokemon_type_from_string(char *type_name);

// Return the string name of the given pokemon_type value.
//
// Example: pokemon_type_to_string(WATER_TYPE) returns "Water".
//
// The returned string has not been allocated with malloc.
// It should not be changed or freed by the caller.
const char *pokemon_type_to_string(pokemon_type type);

#endif // _POKEMON_H_
