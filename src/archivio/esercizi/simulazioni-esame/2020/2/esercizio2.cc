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
char toLowercase(char toCompute);
char get_computed_char(char toCompute, char lowerBound, char upperBound);

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

char toLowercase(const char toCompute) {
    return char(toCompute + ('a' - 'A'));
}

char get_computed_char(const char toCompute, const char lowerBound, const char upperBound) {
    return toLowercase(char(upperBound - (toCompute - lowerBound)));
}

void compute_lists(const char* stringa, node*& s1, node*& s2) {
    if (stringa[0] ==  '\0')
        return;
    else if (stringa[0] >=  'A' && stringa[0] <=  'M') {
        s1 = new node{
            get_computed_char(stringa[0], 'A', 'M'),
            NULL
        };
        compute_lists(stringa + 1, s1->next, s2);
    } else if (stringa[0] >=  'N' && stringa[0] <=  'Z') {
        s2 = new node {
            get_computed_char(stringa[0], 'N', 'Z'),
            NULL
        };
        compute_lists(stringa + 1, s1, s2->next);
    } else
        compute_lists(stringa + 1, s1, s2);
}