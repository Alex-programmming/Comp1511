// First look at multi-file projects
// This code is an adaptation of a live stream on pointers and structs
//
// Marc Chee (marc.chee@unsw.edu.au). July 2019
//
// A header file like this contains information about a some code.
// It's usually enough to read this to be able to use the code
// without needing to actually delve into the C file.

#define MAX_NAME_LENGTH 50
#define MAX_POWER_LENGTH 50
#define MAX_NUM_POWERS 5 

// This typedef declares that the type "Person" is the same as the type
// "pointer to struct person".
//
// The actual definition of "struct person" is not in person.h (this
// file), it's in person.c
//
// This means that you cannot directly access any of the fields of the
// person struct -- e.g. "person->name" is *invalid*.
typedef struct person *Person;

// Create a person and return a pointer to them
Person create_person(char name[MAX_NAME_LENGTH]);

// Free person frees any memory used for a person
void free_person(Person hero);

// give_power will add a power to a person
// It will add the string to the array of strings
// called powers if the person still has
// space to add powers
void give_power(char power[MAX_POWER_LENGTH], Person hero);

// Displays a person's information
void display_person(Person hero);


