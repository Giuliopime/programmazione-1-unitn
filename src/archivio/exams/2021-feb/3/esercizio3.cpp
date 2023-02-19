#include <iostream>
#include <cstdlib>

struct nodo {
    int valore;
    nodo* nodoPrecedente;
    nodo* nodoSuccessivo;
};
typedef nodo* lista;

using namespace std;


void inizializza (int arrayDiInteri [], int dimensioneArray);
void stampaLista (lista nodoCorrente);

// Inserire qui la dichiarazione di "creaLista" e "rimuoviNodiAlternati"

lista creaLista(int arrayDiInteri[], int dimensioneArray);

lista rimuoviNodiAlternati(lista nodoIniziale);

void deallocaLista(lista nodoIniziale);

int main() {

    // Non modificare la funzione "main"

    int dimensioneArray = 8;
    int arrayDiInteri[dimensioneArray];
    inizializza(arrayDiInteri, dimensioneArray);

    lista nodoIniziale = creaLista(arrayDiInteri, dimensioneArray);

    cout << "Lista iniziale: ";
    stampaLista(nodoIniziale);

    nodoIniziale = rimuoviNodiAlternati(nodoIniziale);

    cout << "Risultato: ";
    stampaLista(nodoIniziale);
    deallocaLista(nodoIniziale);

    return 0;
}

void inizializza (int arrayDiInteri [], int dimensioneArray) {

    // Non modificare la funzione "inizializza"

    srand(time(NULL));

    for (int i = 0 ; i < dimensioneArray ; i++) {
        arrayDiInteri[i] = i % 3;
    }

    int contatore = dimensioneArray;
    while (contatore > 1) {
       int indice = rand() % contatore;
       contatore--;
       int temp = arrayDiInteri[contatore];
       arrayDiInteri[contatore] = arrayDiInteri[indice];
       arrayDiInteri[indice] = temp;
    }
}

void stampaLista(nodo* nodoCorrente) {

    // Non modificare la funzione "stampaLista"

    while (nodoCorrente != NULL) {
        cout << nodoCorrente->valore << " ";
        nodoCorrente = nodoCorrente->nodoSuccessivo;
    }
    cout << endl;
}


// Inserire qui la definizione di "creaLista", "rimuoviNodiAlternati" e di eventuali altre funzioni ausiliarie
lista creaLista(int arrayDiInteri[], int dimensioneArray) {
    lista primoNodo = nullptr;
    lista lista = nullptr;

    for (int i=0; i<dimensioneArray; i++) {
        if (lista == nullptr) {
            lista = new nodo { arrayDiInteri[i], nullptr, nullptr };
            primoNodo = lista;
        } else {
           lista->nodoSuccessivo = new nodo { arrayDiInteri[i], lista, nullptr };
           lista = lista->nodoSuccessivo;
        }
    }

    return primoNodo;
}

lista rimuoviNodiAlternati(nodo* nodoCorrente) {
  nodo* nodoIniziale = nodoCorrente;

  while (nodoCorrente != nullptr) {
    nodo* nodoSuccessivo = nodoCorrente->nodoSuccessivo;
    nodo* nodoDaConfrontare = nodoSuccessivo == nullptr ? nullptr : nodoSuccessivo->nodoSuccessivo;
    nodo* nodoPrecedente = nodoCorrente->nodoPrecedente;

    if (nodoDaConfrontare != nullptr && nodoCorrente->valore == nodoDaConfrontare->valore) {
      nodo* nodoDaRicollegare = nodoDaConfrontare->nodoSuccessivo;
      delete nodoDaConfrontare;
      delete nodoCorrente;

      if (nodoPrecedente != nullptr) {
        nodoPrecedente->nodoSuccessivo = nodoSuccessivo;
        nodoCorrente = nodoPrecedente->nodoPrecedente == nullptr ? nodoPrecedente : nodoPrecedente->nodoPrecedente;
      }
      else {
        nodoCorrente = nodoSuccessivo;
        nodoIniziale = nodoCorrente;
      }

      nodoSuccessivo->nodoPrecedente = nodoPrecedente;
      nodoSuccessivo->nodoSuccessivo = nodoDaRicollegare;

      if (nodoDaRicollegare != nullptr) {
        nodoDaRicollegare->nodoPrecedente = nodoSuccessivo;
      }
    }
    else {
      nodoCorrente = nodoSuccessivo;
    }
  }

  return nodoIniziale;
}

void deallocaLista(lista nodoIniziale) {
    while(nodoIniziale != nullptr) {
        lista tempNodo = nodoIniziale->nodoSuccessivo;
        delete nodoIniziale;
        nodoIniziale = tempNodo;
    }
}
