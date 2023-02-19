#include "persona.h"

persona *crea_persona(char *nome, char *cognome, char *indirizzo, int ntel) {
  persona *p = new persona;
  int l = strlen(nome) + 1;
  p->nome = new char[l];
  strncpy(p->nome, nome, l);
  l = strlen(cognome) + 1;
  p->cognome = new char[l];
  strncpy(p->cognome, cognome, l);
  l = strlen(indirizzo) + 1;
  p->indirizzo = new char[l];
  strncpy(p->indirizzo, indirizzo, l);
  p->ntel = ntel;
  return p;
}

persona *leggi_persona() {
  persona *p;
  char nome[MAX_DIM];
  char cognome[MAX_DIM];
  char indirizzo[MAX_DIM];
  int tel;

  cout << "Nome: ";
  cin >> nome;
  cout << "Cognome: ";
  cin >> cognome;
  cout << "Indirizzo: ";
  cin >> indirizzo;
  cout << "N. tel: ";
  cin >> tel;

  p = crea_persona(nome, cognome, indirizzo, tel);

  return p;
}

void stampa_persona(persona *p) {
  cout << "vvvvvvvvvvvvvvvvvvvv\n";
  cout << p->nome << endl;
  cout << p->cognome << endl;
  cout << p->indirizzo << endl;
  cout << p->ntel << endl;
  cout << "^^^^^^^^^^^^^^^^^^^^\n";
}
