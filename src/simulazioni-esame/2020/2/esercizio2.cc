#include <iostream>
#include <cstdlib>
#include <cassert>

/*
	Perfetto
*/


struct node {
    char info;
    node * next;
};

void dealloca(node *& s) {
    while(s != NULL) {
        node * t = s;
        s = s->next;
        delete t;
    }
}

void stampa_lista(const char * testo, node * s) {
    std::cout << testo;
    for( ; s!= NULL; s=s->next) {
        std::cout << " " << s->info;
    }
    std::cout << std::endl;
}

// Scrivere qui sotto la dichiarazione della funzione compute_lists ed
// eventuali funzioni accessorie
void compute_lists(const char* stringa, node*& s1, node*& s2);
// Scrivere qui sopra la dichiarazione della funzione compute_lists ed
// eventuali funzioni accessorie

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " \"stringa di caratteri\"" << std::endl;
        exit(1);
    }
    node * s1 = NULL, * s2 = NULL;
    std::cout << "La stringa da analizzare e': " << argv[1] << std::endl;

    compute_lists(argv[1], s1, s2);

    stampa_lista("Lista s1:", s1);
    stampa_lista("Lista s2:", s2);
    dealloca(s1);
    dealloca(s2);
}

// Scrivere qui sotto la definizione della funzione compute_lists ed
// eventuali funzioni accessorie
void compute_lists(const char* stringa, node*& s1, node*& s2){
    char carattere = stringa[0];

    if(carattere == '\0'){
        return;
    }
    else if(carattere >= 'A' && carattere <= 'M'){
        carattere = 'M' - (carattere - 'A') + ('a' - 'A');

        s1 = new node;
        s1->info = carattere;
        compute_lists(stringa+1, s1->next, s2);
        return;
    }
    else if(carattere >= 'N' && carattere <= 'Z'){
        carattere = 'Z' - (carattere - 'N') + ('a' - 'A');
        s2 = new node;
        s2->info = carattere;
        compute_lists(stringa+1, s1, s2->next);
        return;
    }
    else{
        compute_lists(stringa+1, s1, s2);
        return;
    }
}
// Scrivere qui sopra la definizione della funzione compute_lists ed
// eventuali funzioni accessorie
