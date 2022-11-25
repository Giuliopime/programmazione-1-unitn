#include "coda.h"
#include <iostream>

int queue[11];
int s1Count;
int s2Count;

// inizializza la coda e altri valori rilevanti, se necessario
void init() {
    s1Count = 0;
    s2Count = 0;
}

// inserimento di un elemento nella sotto-coda con meno elementi
bool enqueue(int toEnqueue) {
    if (s1Count + s2Count >= 11)
        return false;

    if (s1Count <= s2Count) {
        queue[s1Count] = toEnqueue;
        s1Count++;
    } else {
        queue[10 - s2Count] = toEnqueue;
        s2Count++;
    }

    return true;
}

// assegna al parametro (passato per riferimento) il valore del primo elemento della sotto-coda del primo sportello
bool firstS1(int& first) {
    if (s1Count > 0) {
        first = queue[0];
        return true;
    } else
        return false;
}

// assegna al parametro (passato per riferimento) il valore del primo elemento della sotto-coda del secondo sportello
bool firstS2(int& first) {
    if (s2Count > 0) {
        first = queue[10];
        return true;
    } else
        return false;
}

// rimuove il primo elemento della sotto-coda del primo sportello
bool dequeueS1() {
    if (s1Count > 0) {
        for (int i=0; i<s1Count; i++) {
            if (i ==  s1Count - 1)
                queue[i] = 0;
            else
                queue[i] = queue[i+1];
        }
        s1Count--;
        return true;
    } else
        return false;
}

// rimuove il primo elemento della sotto-coda del secondo sportello
bool dequeueS2() {
    if (s2Count > 0) {
        for (int i=10; i > (11 - s2Count); i--) {
            if (i ==  10 - s2Count)
                queue[i] = 0;
            else
                queue[i] = queue[i-1];
        }
        s2Count--;
        return true;
    } else
        return false;
}

// de-inizializza la coda e dealloca eventuale memoria dinamica, se necessario
void deinit() {
    for (int i=0; i< 11; i++)
        queue[i] = 0;
    s1Count = 0;
    s2Count = 0;
}

// stampa a video tutti gli elementi delle due sotto-code
void print() {
    std::cout << "Primo sportello:";
    if (s1Count ==  0)
        std::cout << " vuoto!" << std::endl;
    else {
        for (int i = 0; i < s1Count; i++)
            std::cout << " " << queue[i];
        std::cout << std::endl;
    }

    std::cout << "Secondo sportello:";
    if (s2Count ==  0)
        std::cout << " vuoto!" << std::endl;
    else {
        for (int i = 10; i > 10 - s2Count; i--)
            std::cout << " " << queue[i];
        std::cout << std::endl;
    }
}