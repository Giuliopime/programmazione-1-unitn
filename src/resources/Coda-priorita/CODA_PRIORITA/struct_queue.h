#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

#include "message.h"

// La dimensione della coda e' fissata a 10 e allocata in modo statico
static const int dim = 100;
struct queue {
  int head, tail;
  message *elem[dim];
};

enum retval { FAIL, OK };

bool emptyp(const queue &);
bool fullp(const queue &);
void init(queue &);
void deinit(queue &);
retval enqueue(message *, queue &);
retval dequeue(message *&, queue &);
void print(const queue &);

#endif
