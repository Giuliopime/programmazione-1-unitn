#ifndef CODA_H
#define CODA_H

// inizializza la coda e altri valori rilevanti, se necessario
void init();

// inserimento di un elemento nella sotto-coda con meno elementi
bool enqueue(int);

// assegna al parametro (passato per riferimento) il valore del primo elemento della sotto-coda del primo sportello
bool firstS1(int&);

// assegna al parametro (passato per riferimento) il valore del primo elemento della sotto-coda del secondo sportello
bool firstS2(int&);

// rimuove il primo elemento della sotto-coda del primo sportello
bool dequeueS1();

// rimuove il primo elemento della sotto-coda del secondo sportello
bool dequeueS2();

// de-inizializza la coda e dealloca eventuale memoria dinamica, se necessario
void deinit();

// stampa a video tutti gli elementi delle due sotto-code
void print();


#endif