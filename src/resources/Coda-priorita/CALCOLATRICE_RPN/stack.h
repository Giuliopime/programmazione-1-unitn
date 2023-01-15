#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

// Necessario per push/top
#include "entry.h"

void init();
void deinit();
retval push(const entry &);
retval top(entry &);
retval pop();
void print();
int length();

#endif
