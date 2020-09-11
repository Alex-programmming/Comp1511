///
// DO NOT CHANGE THIS FILE
//
// You do not submit this file. This file is not marked.
// If you think you need to change this file you have
// misunderstood the assignment - ask in the course forum.
//
// Assignment 2 19T3 COMP1511: Pokedex
// pokemon.c
//
// Version 2.0.0: Release

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "pokemon.h"

const static char *types[] = {
    [NONE_TYPE]     = "None",
    [NORMAL_TYPE]   = "Normal",
    [FIRE_TYPE]     = "Fire",
    [FIGHTING_TYPE] = "Fighting",
    [WATER_TYPE]    = "Water",
    [FLYING_TYPE]   = "Flying",
    [GRASS_TYPE]    = "Grass",
    [POISON_TYPE]   = "Poison",
    [ELECTRIC_TYPE] = "Electric",
    [GROUND_TYPE]   = "Ground",
    [PSYCHIC_TYPE]  = "Psychic",
    [ROCK_TYPE]     = "Rock",
    [ICE_TYPE]      = "Ice",
    [BUG_TYPE]      = "Bug",
    [DRAGON_TYPE]   = "Dragon",
    [GHOST_TYPE]    = "Ghost",
    [DARK_TYPE]     = "Dark",
    [STEEL_TYPE]    = "Steel",
    [FAIRY_TYPE]    = "Fairy",
};

#define POKEMON_MAGIC_NUMBER 0xDEADBEEF


////////////////////////////////////////////////////////////////////////
//                           struct pokemon                           //
////////////////////////////////////////////////////////////////////////

// This is the struct that stores all of the internal information about
// a Pokemon.
//
// Because this struct is in pokemon.c (not pokemon.h), you cannot
// access it directly from pokedex.c
//
// _This is intentional_, because you should only interact with Pokemon
// via the functions in pokemon.h, rather than trying to access the
// struct directly.
//
// If you get the following error:
//    error: incomplete definition of type 'struct pokemon'
// you must make sure that you are only interacting with Pokemon via the
// functions in pokemon.h (e.g. pokemon_id, pokemon_name, etc).
struct pokemon {
    int          magic_number;
    int          pokemon_id;
    char         *name;
    double       height;
    double       weight;
    pokemon_type type1;
    pokemon_type type2;
};

// Helper functions. These can only be called from pokemon.c (this file),
// not pokedex.c or test_pokedex.c.
static int valid_character(int c);
static int valid_pokemon_type(pokemon_type type);
static void check_valid_pokemon(Pokemon pokemon, char *function_name);
static void die(char *function_name, char *message);
static char *check_address_is_heap_pointer(void *p, size_t size);

////////////////////////////////////////////////////////////////////////
//      See pokemon.h for details about all of the functions below.   //
////////////////////////////////////////////////////////////////////////

// Create a new Pokemon, given its pokemon_id, name, height, weight, and
// type(s).
//
// See the comments above new_pokemon in pokemon.h for the full details.
Pokemon new_pokemon(int pokemon_id, char *name, double height,
    double weight, pokemon_type type1, pokemon_type type2) {

    if (pokemon_id < 0) {
        die("new_pokemon", "invalid pokemon_id");
    }

    if (!valid_pokemon_type(type1)) {
        die("new_pokemon", "type1 is invalid");
    }

    if (!valid_pokemon_type(type2)) {
        die("new_pokemon", "type2 is invalid");
    }

    if (type1 == NONE_TYPE) {
        die("new_pokemon", "type1 is NONE_TYPE");
    }

    if (type1 == type2) {
        die("new_pokemon", "type1 and type2 must be different");
    }

    Pokemon new_pokemon = malloc(sizeof(struct pokemon));
    assert(new_pokemon != NULL);

    new_pokemon->magic_number = POKEMON_MAGIC_NUMBER;
    new_pokemon->pokemon_id = pokemon_id;
    new_pokemon->name = strdup(name);
    assert(name != NULL);
    new_pokemon->height = height;
    new_pokemon->weight = weight;
    new_pokemon->type1 = type1;
    new_pokemon->type2 = type2;
    return new_pokemon;
}

// Destroy the specified `pokemon`.
void destroy_pokemon(Pokemon pokemon) {
    check_valid_pokemon(pokemon, "destroy_pokemon");
    free(pokemon->name);
    free(pokemon);
}

// Return the pokemon_id of the specified `pokemon`.
int pokemon_id(Pokemon pokemon) {
    check_valid_pokemon(pokemon, "pokemon_id");
    return pokemon->pokemon_id;
}

// Return the pokemon_name of the specified `pokemon`.
char *pokemon_name(Pokemon pokemon) {
    check_valid_pokemon(pokemon, "pokemon_name");
    return pokemon->name;
}

// Return the pokemon_height of the specified `pokemon`.
double pokemon_height(Pokemon pokemon) {
    check_valid_pokemon(pokemon, "pokemon_height");
    return pokemon->height;
}

// Return the pokemon_weight of the specified `pokemon`.
double pokemon_weight(Pokemon pokemon) {
    check_valid_pokemon(pokemon, "pokemon_weight");
    return pokemon->weight;
}

// Return the first type of the specified `pokemon`.
pokemon_type pokemon_first_type(Pokemon pokemon) {
    check_valid_pokemon(pokemon, "pokemon_first_type");
    return pokemon->type1;
}

// Return the second type of the specified `pokemon`.
pokemon_type pokemon_second_type(Pokemon pokemon) {
    check_valid_pokemon(pokemon, "pokemon_second_type");
    return pokemon->type2;
}

// Return a clone of the specified `pokemon`.
Pokemon clone_pokemon(Pokemon pokemon) {
    check_valid_pokemon(pokemon, "clone_pokemon");
    return new_pokemon(
        pokemon->pokemon_id,
        pokemon->name,
        pokemon->height,
        pokemon->weight,
        pokemon->type1,
        pokemon->type2
    );
}

// Check whether `name` is a valid name for a Pokemon.
// Valid names consist of letters, spaces, and dashes.
// See the `valid_character` function below for more details.
int pokemon_valid_name(char *name) {
    for (int i = 0; name[i] != '\0'; i++) {
        if (!valid_character(name[i])) {
            return 0;
        }
    }
    return 1;
}


////////////////////////////////////////////////////////////////////////
//                 Helper functions (for pokemon.c)                   //
////////////////////////////////////////////////////////////////////////

// Check whether 'c' is a valid character to have in a Pokemon name.
// Names can have: space (' '), dash ('-'), and upper/lowercase letters.
static int valid_character(int c) {
    return (c == ' ' ||
            c == '-' ||
            (c >= 'a' && c <= 'z') ||
            (c >= 'A' && c <= 'Z')
    );
}

// Determine the pokemon_type associated with the given string.
// For example: "Fire" or "fire" would return FIRE_TYPE.
//
// If there is no matching pokemon_type, the function returns
// INVALID_TYPE.
pokemon_type pokemon_type_from_string(char *str) {
    for (int i = 0; i < sizeof(types) / sizeof(types[0]); i++) {
        if (strcasecmp(types[i], str) == 0) {
            return (pokemon_type) i;
        }

    }
    return INVALID_TYPE;
}

// Convert a pokemon_type into its corresponding string.
// For example: pokemon_type_to_string(FIRE_TYPE) would return "Fire".
const char *pokemon_type_to_string(pokemon_type type) {
    assert(valid_pokemon_type(type));
    return types[type];
}

// Check whether `type` is a valid pokemon_type.
static int valid_pokemon_type(pokemon_type type) {
    return type > INVALID_TYPE && type < MAX_TYPE;
}

// Check whether `pokemon` is a valid Pokemon.
//
// A "valid Pokemon" means a Pokemon that was returned from calling the
// `new_pokemon` function, and which has not been freed etc.
//
// If your code results in an error here, make sure that you're only
// ever using `new_pokemon` (or `clone_pokemon`) to create Pokemon.
//
// You should never try to create a Pokemon yourself directly using
// malloc, nor should you try to access the struct fields directly.
//
// The only way that you can and should interact with a Pokemon is via
// the functions in pokemon.h (e.g. `new_pokemon`, `pokemon_id`, etc).
static void check_valid_pokemon(Pokemon pokemon, char *function_name) {
    if (pokemon == NULL) {
        die(function_name, "pokemon is NULL");
    }

    char *error = check_address_is_heap_pointer(pokemon, sizeof *pokemon);
    if (error != NULL) {
        die(function_name, error);
    }

    if (pokemon->magic_number != POKEMON_MAGIC_NUMBER) {
        die(function_name, "invalid pokemon (make sure you "
            "are using new_pokemon() when you create a new Pokemon)");
    }
}

static void die(char *function_name, char *message) {
    fprintf(stderr, "%s: %s\n", function_name, message);
    exit(1);
}


////////////////////////////////////////////////////////////////////////
//   Note: You are not expected to understand the following code.     //
//   It uses complex internal compiler features to detect errors.     //
////////////////////////////////////////////////////////////////////////

#ifdef __has_feature
// detect clang address-sanitizer
#if __has_feature(address_sanitizer)
// clang address-sanitizer
#define HAVE_ASAN
#endif
#endif

// detect gcc address-sanitizer
#ifdef __SANITIZE_ADDRESS__
#define HAVE_ASAN
#endif

#ifdef HAVE_ASAN
#include <sanitizer/asan_interface.h>
#include <stdint.h>
#include <string.h>
#endif

// return NULL if p is valid pointer to a malloc'ed region of size `size`
// otherwise return string describing pointer

static char *check_address_is_heap_pointer(void *p, size_t size) {
#ifdef HAVE_ASAN
    if (p == NULL) {
        return NULL;
    }
    if ((sizeof(p) == 8 && (uintptr_t)p == 0xbebebebebebebebe)
            || (sizeof(p) == 4 && (uintptr_t)p == 0xbebebebe)) {
        return "pokemon is uninitialized";
    }
    if (__asan_region_is_poisoned(p, size)) {
        return "pokemon is invalid  (hint: make sure it hasn't been "
               "freed + it's a valid pointer)";
    }
    char name[8]; // unused but required by __asan_locate_address
    void *region_address;
    size_t region_size;
    if (strcmp(__asan_locate_address(p, name, sizeof name,
            &region_address, &region_size), "heap") != 0) {
        return "pokemon is invalid (not from malloc)";
    }
#endif
    return NULL;
}
