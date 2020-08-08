
struct pokenode {
    ...
}

struct pokedex {
    ...
}

typedef struct pokenode *Pokenode;

// Remember to malloc the struct pokenode NOT the Pokenode!
Pokenode new = malloc(sizeof(struct pokenode));
