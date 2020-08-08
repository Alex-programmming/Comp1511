// z5248147
// Starting code for COMP1511 lab exercises
// Haoheng Duan

#include <stdio.h>
#include <string.h>

#define MAX_SPECIES_NAME_LENGTH 128
#define MAX_SIGHTINGS 10000

// a struct to represent the date
// a whale pod sighting was made

struct date {
    int year;
    int month;
    int day;
};

// a struct to represent a sighting
// of a pod (group) of whales

struct pod {
    struct date when;
    int         how_many;
    char        species[MAX_SPECIES_NAME_LENGTH];
};


int read_sightings_file(char filename[], int len, struct pod sightings[len]);
int read_sighting(FILE *f, struct pod *w);
int read_date(FILE *f, struct date *d);

void species_count(char species[], int n_sightings, 
struct pod sightings[n_sightings],
                   int *n_pods, int *n_whales);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <file> <species>\n", argv[0]);
        return 1;
    }
    char *filename = argv[1];
    char *species = argv[2];

    struct pod whale_sightings[MAX_SIGHTINGS];
    int n_sightings = read_sightings_file(filename, MAX_SIGHTINGS, 
    whale_sightings);

    if (n_sightings < 1) {
        return 1;
    }

    int pod_count;
    int whale_count;
    species_count(species, n_sightings, whale_sightings, &pod_count, 
    &whale_count);
    printf("%d %s pods containing %d whales in %s\n", pod_count, species, 
    whale_count, filename);

    return 0;
}

//
// number of pods of the specified species assigned to *n_pods
// total number of whales of the specified species assigned to *n_whales
//
void species_count(char species[], int n_sightings, 
struct pod sightings[n_sightings], int *n_pods, int *n_whales) {
    int i = 0;
    int counter = 0;
    int whales =  0;
    while (i < n_sightings) {
        if (strcmp(sightings[i].species, species) == 0) {
            counter++;
            whales += sightings[i].how_many;
        }
        i++;
    }
    
    
    
    *n_pods = counter;
    *n_whales = whales;
}


//
// DO NOT CHANGE THE FUNCTIONS BELOW HERE
//

// return number of sightings read from filename
// -1 is returned if there is an error

int read_sightings_file(char filename[], int len, struct pod sightings[len]) {
    FILE *f = fopen(filename, "r");
    if (f == NULL) {
        fprintf(stderr, "error: file '%s' can not open\n", filename);
        return -1;
    }

    int n_sightings = 0;
    while (read_sighting(f, &sightings[n_sightings]) == 1 && 
    n_sightings < len) {
        n_sightings = n_sightings + 1;
    }

    fclose(f);
    return n_sightings;
}


// return 1 if a sighting can be read, 0 otherwise

int read_sighting(FILE *f, struct pod *s) {
    if (read_date(f, &(s->when)) != 1) {
        return 0;
    }
    if (fscanf(f, "%d", &(s->how_many)) != 1) {
        return 0;
    }
    fgetc(f);
    if (fgets(s->species, MAX_SPECIES_NAME_LENGTH, f) == NULL) {
        return 0;
    }

    // finish string at '\n' if there is one
    char *newline_ptr = strchr(s->species, '\n');
    if (newline_ptr != NULL) {
        *newline_ptr = '\0';
    }

    // also finish string at '\r' if there is one - files from Windows  will
    newline_ptr = strchr(s->species, '\r');
    if (newline_ptr != NULL) {
        *newline_ptr = '\0';
    }
    return 1;
}


// return 1 if a date can be read, 0 otherwise

int read_date(FILE *f, struct date *d) {
    int n_scanned = fscanf(f, "%d/%d/%d", &(d->year), &(d->month), &(d->day));
    return n_scanned == 3;
}
