// First look at multi-file projects
// This code is an adaptation of a live stream on pointers and structs

// Marc Chee (marc.chee@unsw.edu.au)

// This demo shows how we include a header file so that we can use its
// functionality in our main here

#include "person.h"

int main(void) {
    Person batman = create_person("Batman");
    display_person(batman);
    
    give_power("Ninjitsu", batman);
    give_power("Tech gadgets", batman);
    give_power("Brooding", batman);
    give_power("Gravelly Christian Bale Voice", batman);
        
    display_person(batman);
    
    // Free our memory now that we're not going to use it
    free_person(batman);
}
