typedef struct Tnodo {
  Tdato dato;
  Tnodo *next;
  // costruttori
  // Tnodo(Tdato d);
  // Tnodo(Tdato d, Tnodo *n);
} Tnodo;
typedef Tnodo *ListaSemplicementeConcatenata;

// Ricerca nella lista
Lista ricerca(const Lista ls, Tdato d) {
  Lista temp = ls;
  while (!is_empty_lista(temp)) {
    if (temp->dato.isEqual(d)) {
      return temp;
    }
    temp = temp->next;
  }
  return NULL;
}

// Inserimento in testa
void insert_first(Tnodo *&s, Tdato valore) {
  Tnodo *n = new Tnodo;
  n->dato = valore;
  n->next = s;
  s = n;
}

// Inserimento in coda
void insert_last(Tnodo *&p, Tdato valore) {
  Tnodo *r = new Tnodo;
  r->dato = valore;
  r->next = NULL;
  if (p != NULL) {
    Tnodo *q = p;
    while (q->next != NULL) {
      q = q->next;
    }
    q->next = r;
  } else {
    p = r;
  }
}

// rimozione di un elemento
Tnodo *remove_element(Tnodo *x) {
  Tnodo *y = x->next;
  x->next = y->next;
  y->next = NULL;
  return y;
}

// rimozione in testa
void remove_first(Tnodo *&s) {
  Tnodo *n = s;
  if (s != NULL) {
    s = s->next;
    delete n;
  }
}

// rimozione di un elemento particolare
void search_remove(Tnodo *&p, Tdato val) {
  if (p != NULL) {
    Tnodo *q = p;
    if (q->dato == val) {
      p = p->next;
      delete q;
    } else {
      while (q->next != NULL) {
        if (q->next->dato == val) {
          Tnodo *r = q->next;
          q->next = q->next->next;
          delete r;
          return;
        }
        if (q->next != NULL)
          q = q->next;
      }
    }
  }
}

// rovescia lista
Tnodo *reverse(Tnodo *x) {
  Tnodo *t;
  Tnodo *y = x;
  Tnodo *r = NULL;
  while (y != NULL) {
    t = y->next;
    y->next = r;
    t = y;
    y = t;
  }
  return r;
}
