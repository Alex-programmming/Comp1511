// Author: Finbar Berkon
// Date: October 2019
// Using structs to store information about a pet

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 256
#define MAX_BREED_LENGTH 64

// Define our struct
struct pet {
    char name[MAX_NAME_LENGTH];
    char breed[MAX_BREED_LENGTH];
    int age;
    int weight;
};

void age_fluffy(struct pet *my_pet);

int main(int argc, char *argv[]) {
    // Declare an instance of our struct called my_pet
    struct pet my_pet;

    // Give our struct some values
    strcpy(my_pet.name, argv[1]);
    strcpy(my_pet.breed, argv[2]);
    my_pet.age = strtol(argv[3], NULL, 10);
    my_pet.weight = strtol(argv[4], NULL, 10);
    
    age_fluffy(&my_pet);
    
    // Print the values in our struct
    printf("%s", my_pet.name);
	printf(" is an %s", my_pet.breed);
    printf(" who is %d years old", my_pet.age);
    printf(" and weighs %d grams\n", my_pet.weight);

    return 0;
}

void age_fluffy(struct pet *my_pet) {
    double prev_age = my_pet->age;
    my_pet->age = my_pet->age + 1;
    my_pet->weight = my_pet->age * my_pet->weight / prev_age;
}
