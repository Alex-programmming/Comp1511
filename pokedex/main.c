//
// DO NOT CHANGE THIS FILE
//
// You do not submit this file. This file is not marked.
// If you think you need to change this file you have
// misunderstood the assignment - ask in the course forum.
//
// Assignment 2 19T3 COMP1511: Pokedex
// main.c
//
// Version 2.0.0: Release
//
// This file allows you to interactively test the functions you
// implement in pokedex.c

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "pokedex.h"

#define MAX_LINE    1024

#define ADD_COMMAND            'a'
#define PRINT_COMMAND          'p'
#define DETAILS_COMMAND        'd'
#define GET_COMMAND            'g'
#define NEXT_COMMAND           '>'
#define PREV_COMMAND           '<'
#define CHANGE_CURR_COMMAND    'm'
#define REMOVE_COMMAND         'r'
#define SHOW_TYPES_COMMAND     'y'
#define EXPLORE_COMMAND        'x'
#define SET_FOUND_COMMAND      'f'
#define COUNT_FOUND_COMMAND    'c'
#define COUNT_TOTAL_COMMAND    't'
#define EVOLUTION_COMMAND      'e'
#define SHOW_EVOLUTION_COMMAND 's'
#define HELP_COMMAND           '?'
#define QUIT_COMMAND           'q'
#define NEXT_EVOLUTION_COMMAND 'n'
#define GET_FOUND_COMMAND      'F'
#define SEARCH_COMMAND         'S'
#define GET_TYPE_COMMAND       'T'

static int run_command(Pokedex pokedex, char *line);

void explore_pokedex(Pokedex pokedex);
static void print_welcome_msg(void);
static void show_help(void);
static int get_command(char *command, int max_command_length);

static void do_add(Pokedex pokedex, char *line);
static void do_print(Pokedex pokedex);
static void do_get(Pokedex pokedex);
static void do_details(Pokedex pokedex);
static void do_next(Pokedex pokedex);
static void do_prev(Pokedex pokedex);
static void do_change_curr(Pokedex pokedex, char *line);
static void do_remove(Pokedex pokedex);
static void do_show_types(Pokedex pokedex);
static void do_explore(Pokedex pokedex);
static void do_set_found(Pokedex pokedex);
static void do_count_found(Pokedex pokedex);
static void do_count_total(Pokedex pokedex);
static void do_evolution(Pokedex pokedex, char *line);
static void do_show_evolutions(Pokedex pokedex);
static void do_next_evolution(Pokedex pokedex) ;
static void do_get_found(Pokedex pokedex);
static void do_get_type(Pokedex pokedex, char *line);
static void do_search(Pokedex pokedex, char *line);
static void do_quit(void);

int main(void) {
    explore_pokedex(NULL);
    return 0;
}


void explore_pokedex(Pokedex supplied_pokedex) {
    Pokedex pokedex = supplied_pokedex;
    if (pokedex == NULL) {
        print_welcome_msg();
        pokedex = new_pokedex();
    } else {
        printf("Enter '%c' to return to previous pokedex\n", QUIT_COMMAND);
    }

    char line[MAX_LINE];
    while (get_command(line, MAX_LINE) && run_command(pokedex, line)) {
    }

    destroy_pokedex(pokedex);

    if (supplied_pokedex != NULL) {
        printf("Returning to previous pokedex.\n");
    }
}

int run_command(Pokedex pokedex, char *line) {
    // skip white space at start of line
    // (pointer arithmetic would be more concise)
    int start = 0;
    while (isspace(line[start])) {
        start = start + 1;
    }

    int cmd = line[start];
    int next = start;

    if (line[start] != '\0') {
        next = start + 1;
        while (isspace(line[next])) {
            next = next + 1;
        }
    }

    if (cmd == ADD_COMMAND) {
        do_add(pokedex, &line[next]);
    } else if (cmd == PRINT_COMMAND) {
        do_print(pokedex);
    } else if (cmd == DETAILS_COMMAND) {
        do_details(pokedex);
    } else if (cmd == GET_COMMAND) {
        do_get(pokedex);
    } else if (cmd == NEXT_COMMAND) {
        do_next(pokedex);
    } else if (cmd == PREV_COMMAND) {
        do_prev(pokedex);
    } else if (cmd == CHANGE_CURR_COMMAND) {
        do_change_curr(pokedex, &line[next]);
    } else if (cmd == REMOVE_COMMAND) {
        do_remove(pokedex);
    } else if (cmd == SHOW_TYPES_COMMAND) {
        do_show_types(pokedex);
    } else if (cmd == EXPLORE_COMMAND) {
        do_explore(pokedex);
    } else if (cmd == SET_FOUND_COMMAND) {
        do_set_found(pokedex);
    } else if (cmd == COUNT_FOUND_COMMAND) {
        do_count_found(pokedex);
    } else if (cmd == COUNT_TOTAL_COMMAND) {
        do_count_total(pokedex);
    } else if (cmd == EVOLUTION_COMMAND) {
        do_evolution(pokedex, &line[next]);
    } else if (cmd == SHOW_EVOLUTION_COMMAND) {
        do_show_evolutions(pokedex);
    } else if (cmd == NEXT_EVOLUTION_COMMAND) {
        do_next_evolution(pokedex);
    } else if (cmd == GET_FOUND_COMMAND) {
        do_get_found(pokedex);
    } else if (cmd == SEARCH_COMMAND) {
        do_search(pokedex, &line[next]);
    } else if (cmd == GET_TYPE_COMMAND) {
        do_get_type(pokedex, &line[next]);
    } else if (cmd == QUIT_COMMAND) {
        do_quit();
    } else if (cmd == HELP_COMMAND) {
        show_help();
    } else if (cmd == '\0') {
        // Don't do anything, just print the prompt again.
    } else {
        printf("Unknown Command '%c'\n", cmd);
        printf("Type '%c' for a list of commands\n", HELP_COMMAND);
    }

    return cmd != QUIT_COMMAND;
}

static void print_welcome_msg(void) {
    printf(
        "===========================[ Pokédex ]==========================\n"
        "            Welcome to the Pokédex!  How can I help?\n"
        "================================================================\n"
    );
}

static void show_help(void) {
    printf(""
        "============================[ Help ]============================\n"
    );

    printf(""
        "  %c [pokemon_id] [name] [height] [weight] [type1] [type2]\n"
        "    Add a Pokemon to the Pokedex\n",
        ADD_COMMAND
    );
    printf(""
        "  %c\n"
        "    Print all of the Pokemon in the Pokedex (in the order they "
        "were added)\n",
        PRINT_COMMAND
    );
    printf(""
        "  %c\n"
        "    Print currently selected Pokemon\n",
        GET_COMMAND
    );
    printf(""
        "  %c\n"
        "    Display details of the currently selected Pokemon\n",
        DETAILS_COMMAND
    );
    printf(""
        "  %c\n"
        "    Move the cursor to the next Pokemon in the Pokedex\n",
        NEXT_COMMAND
    );
    printf(""
        "  %c\n"
        "    Move the cursor to the previous Pokemon in the Pokedex\n",
        PREV_COMMAND
    );
    printf(""
        "  %c [pokemon_id]\n"
        "    Move the cursor to the Pokemon with the specified pokemon_id\n",
        CHANGE_CURR_COMMAND
    );
    printf(""
        "  %c\n"
        "    Remove the current Pokemon from the Pokedex\n",
        REMOVE_COMMAND
    );
    printf(""
        "  %c\n"
        "    Show Pokemon types\n",
        SHOW_TYPES_COMMAND
    );
    printf(""
        "  %c\n"
        "    Go exploring for Pokemon\n",
        EXPLORE_COMMAND
    );
    printf(""
        "  %c\n"
        "    Set the current Pokemon to be found\n",
        SET_FOUND_COMMAND
    );
    printf(""
        "  %c\n"
        "    Print out the count of Pokemon who have been found\n",
        COUNT_FOUND_COMMAND
    );
    printf(""
        "  %c\n"
        "    Print out the total count of Pokemon in the Pokedex\n",
        COUNT_TOTAL_COMMAND
    );
    printf(""
        "  %c [pokemon_A] [pokemon_B]\n"
        "    Add an evolution from Pokemon A to Pokemon B\n",
        EVOLUTION_COMMAND
    );
    printf(""
        "  %c\n"
        "    Show evolutions of the currently selected Pokemon\n",
        SHOW_EVOLUTION_COMMAND
    );
    printf(""
        "  %c\n"
        "    Show next evolution of current selected Pokemon\n",
        NEXT_EVOLUTION_COMMAND
    );
    printf(""
        "  %c\n"
        "     Create a new Pokedex containing Pokemon that have previously been found\n",
        GET_FOUND_COMMAND
    );
    printf(""
        "  %c [string]\n"
       "     Create a new Pokedex containing Pokemon that have the specified string in their name\n",
        SEARCH_COMMAND
    );
    printf(""
        "  %c [type]\n"
       "     Create a new Pokedex containing Pokemon that have the specified type\n",
        GET_TYPE_COMMAND
    );
    printf(""
        "  %c\n"
        "    Quit\n",
        QUIT_COMMAND
    );
    printf(""
        "  %c\n"
        "    Show help\n",
        HELP_COMMAND
    );
    printf(""
        "================================================================\n"
    );
}

static int get_command(char *command, int max_command_length) {
    printf("Enter command: ");

    if (fgets(command, max_command_length, stdin) == NULL) {
        return 0;
    }

    // remove '\n' if present
    command[strcspn(command, "\n")] = '\0';

    return 1;
}

static void do_add(Pokedex pokedex, char *line) {
    int pokemon_id;
    double height, weight;
    char name[MAX_LINE] = {0};
    char type_name1[MAX_LINE] = {0};
    char type_name2[MAX_LINE] = "None";

    int items_read = sscanf(line, "%d%s%lf%lf%s%s", &pokemon_id,
        name, &height, &weight, type_name1, type_name2);

    if (items_read < 5) {
        printf("Invalid Add Command\n");
        return;
    }

    if (pokemon_id < 0) {
        printf("Invalid pokemon_id\n");
    }

    if (!pokemon_valid_name(name)) {
        printf("Invalid name\n");
        return;
    }

    pokemon_type type1 = pokemon_type_from_string(type_name1);
    pokemon_type type2 = pokemon_type_from_string(type_name2);

    if (type1 == INVALID_TYPE || type1 == NONE_TYPE) {
        printf("Invalid type1\n");
        return;
    }

    if (type2 == INVALID_TYPE) {
        printf("Invalid type2\n");
        return;
    }

    Pokemon pokemon = new_pokemon(pokemon_id, name, height, weight, type1, type2);

    add_pokemon(pokedex, pokemon);
    printf("Added %s to the Pokedex!\n", name);
}

static void do_print(Pokedex pokedex) {
    print_pokemon(pokedex);
}

static void do_details(Pokedex pokedex) {
    detail_pokemon(pokedex);
}

static void do_get(Pokedex pokedex) {
    Pokemon current = get_current_pokemon(pokedex);
    if (current != NULL) {
        printf("Currently selected Pokemon: #%d (%s)\n",
            pokemon_id(current), pokemon_name(current));
    } else {
        printf("No current Pokemon\n");
    }
}

static void do_next(Pokedex pokedex) {
    next_pokemon(pokedex);
}

static void do_prev(Pokedex pokedex) {
    prev_pokemon(pokedex);
}

static void do_change_curr(Pokedex pokedex, char *line) {
    int pokemon_id;
    if (sscanf(line, "%d", &pokemon_id) != 1) {
        printf("Invalid Change Current Command\n");
        return;
    }
    change_current_pokemon(pokedex, pokemon_id);
}

static void do_remove(Pokedex pokedex) {
    remove_pokemon(pokedex);
}

static void do_show_types(Pokedex pokedex) {
    show_types(pokedex);
}

static void do_explore(Pokedex pokedex) {
    go_exploring(pokedex);
}

static void do_set_found(Pokedex pokedex) {
    find_current_pokemon(pokedex);
}

static void do_count_found(Pokedex pokedex) {
    printf("Total Found Pokemon: %d\n", count_found_pokemon(pokedex));
}

static void do_count_total(Pokedex pokedex) {
    printf("Total Pokemon: %d\n", count_total_pokemon(pokedex));
}

static void do_evolution(Pokedex pokedex, char *line) {
    int pokemonA, pokemonB;
    if (sscanf(line, "%d%d", &pokemonA, &pokemonB) != 2) {
        printf("Invalid Evolution Command\n");
        return;
    }

    add_pokemon_evolution(pokedex, pokemonA, pokemonB);
}

static void do_show_evolutions(Pokedex pokedex) {
    show_evolutions(pokedex);
}

static void do_next_evolution(Pokedex pokedex) {
    int id = get_next_evolution(pokedex);
    if (id == DOES_NOT_EVOLVE) {
        printf("DOES_NOT_EVOLVE\n");
    } else {
        printf("ID: %03d\n", id);
    }
}

static void do_get_found(Pokedex pokedex) {
    Pokedex new_pokedex = get_found_pokemon(pokedex);
    printf("Switching to explore the Pokedex get_found_pokemon returned\n");
    explore_pokedex(new_pokedex);
}

static void do_get_type(Pokedex pokedex, char *line) {
    pokemon_type type = pokemon_type_from_string(line);

    if (type == INVALID_TYPE || type == NONE_TYPE || type == MAX_TYPE) {
        printf("Invalid type\n");
        return;
    }
    Pokedex new_pokedex = get_pokemon_of_type(pokedex, type);
    printf("Switching to explore the Pokedex get_pokemon_of_type %s returned\n", line);
    explore_pokedex(new_pokedex);
}

static void do_search(Pokedex pokedex, char *line) {
    if (line[0]) {
        Pokedex new_pokedex = search_pokemon(pokedex, line);
        printf("Switching to explore the Pokedex search_pokemon \"%s\" returned\n", line);
        explore_pokedex(new_pokedex);
    } else {
        printf("Invalid Search Command\n");
    }
}

static void do_quit(void) {
    printf("Goodbye.\n");
}
