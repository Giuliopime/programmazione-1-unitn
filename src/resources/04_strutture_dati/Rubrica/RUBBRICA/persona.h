#ifndef PERSONA_H
#define PERSONA_H

using namespace std;
#include <cstring>
#include <iostream>

const int MAX_DIM = 40;

struct persona {
  // char  nome[MAX_DIM];
  char *nome;
  // char  cognome[MAX_DIM];
  char *cognome;
  // char  indirizzo[MAX_DIM];
  char *indirizzo;
  int ntel;
};

persona *crea_persona(char *nome, char *, char *, int);
persona *leggi_persona();
void stampa_persona(persona *p);

#endif
