#include <iostream>

using namespace std;

// Struttura lista di interi
struct nodo {
  int dato;
  nodo *next;
};

// Calcolo della lunghezza di una lista
int length(nodo *s) {
  int result = 0;

  for (; s != NULL; s = s->next)
    result++;
  return result;
}

// Dealloca la memoria della lista
void delete_list(nodo *&s) {
  // Alla fine la lista e' vuota. Passaggio per riferimento.
  while (s != NULL) {
    // Salvo il valore del nodo corrente
    nodo *t = s;
    // Avanzo al nodo sucessivo
    s = s->next;
    // Dealloco il nodo salvato
    delete t;
  }
}

// Stampa contenuto della lista
void stampa(nodo *s) {
  int i = 0;
  while (s != NULL) {
    cout << "Elemento " << i++ << " = " << s->dato << endl;
    s = s->next;
  }
}

void insert_first(nodo *&s, int d) {
  // Creo il nuovo nodo e memorizzo il valore utilizzando costruttore
  // ad un solo argomento
  nodo *n = new nodo;
  n->dato = d;
  // Il campo next di n punta a s
  n->next = s;
  // s punt a nuovo nodo n
  s = n;
}

void insert_last(nodo *&s, int d) {
  nodo *n = new nodo;
  n->dato = d;
  n->next = NULL;

  // Se la lista e' vuota, allora s dovra' puntare al nuovo nodo
  if (s == NULL) {
    s = n;
  } else {
    // Cerco l'ultimo elemento, q->next qui e' lecito perche' siamo
    // sicuri che s e' diverso da NULL
    nodo *q = s;
    while (q->next != NULL) {
      q = q->next;
    }
    // Una volta trovato ultimo elemento campo next punta al nodo nuvo.
    q->next = n;
  }
}

void insert_order(nodo *&s, int d) {
  if ((s == NULL) || (s->dato >= d)) {
    // s->dato e' lecito. Se arrivo qui vuol dire che primo disgiunto
    // era falso, e quindi s diverso da NULL
    insert_first(s, d);
  } else {
    nodo *q = s;

    while ((q->next != NULL) && (q->next->dato <= d)) {
      // Qui siamo sicuri che q != NULL, inoltre se prima condizione
      // e' soddisfatta possiamo accedere al campo dato del nodo
      // successvo. Infatti e' diverso da NULL
      q = q->next;
    }
    nodo *r = new nodo;
    r->dato = d;
    r->next = q->next;
    q->next = r;
  }
}

void remove_first(nodo *&s) {
  if (s != NULL) {
    nodo *t = s;
    s = s->next;
    delete t;
  }
}

void remove_element(nodo *&p, int d) {
  if (p != NULL) {
    nodo *q = p;
    if (q->dato == d) {
      p = p->next;
      delete q;
    } else {
      while (q->next != NULL) {
        if (q->next->dato == d) {
          nodo *r = q->next;
          q->next = q->next->next;
          delete r;
          return;
        }
        if (q->next != NULL) {
          q = q->next;
        }
      }
    }
  }
}

// Reverse con side effect sulla lista originaria
nodo *reverse(nodo *x) {
  nodo *t;
  nodo *y = x;
  nodo *r = NULL;

  while (y != NULL) {
    t = y->next;
    y->next = r;
    r = y;
    y = t;
  }
  return r;
}

// Costruzione della lista rovesciata costruendo una lista nuova
nodo *reverse_copia(nodo *x) {
  nodo *r = NULL;

  while (x != NULL) {
    nodo *t = new nodo;
    t->dato = x->dato;
    t->next = r;
    r = t;
    x = x->next;
  }
  return r;
}

// Ricerca a e ritorna l'elemento n-esimo se esite
nodo *get_n(nodo *s, int n) {
  // Se richiedo di prendere elemento con indice negativo ritorno NULL
  if (n < 0)
    return NULL;
  int i;
  for (i = 0; ((i < n) && (s != NULL)); i++) {
    s = s->next;
  }
  // A questo punto se i == n, allora s punta la punto
  // giusto. Altrimenti s punta a NULL e lo possiamo ritornare.
  return s;
}

// Ritornare il nodo che precede un nodo x
nodo *prec(nodo *s, nodo *x) {
  // primo ed unico elemento uguale a x
  if (s == x)
    return x;
  // primo e unico elemento e' differente da x
  if ((s == NULL) && (s->next == NULL))
    return NULL;

  nodo *t = s;       // nodo precedente al nodo corrente che sto cercando,
                     // inizializzato al primo elemento della lista
  nodo *l = s->next; // nodo che uso per scorrere la lista,
                     // inizializzato al secondo elemento della
                     // lista.

  while ((l != NULL) && (l != x)) {
    // Modifico l e t per rispettare il loro significato, ovvero che t
    // punta l nodo che precede l
    t = l;
    l = l->next;
  }
  // raggiunto ultimo elemento e non c'e' nulla
  if (l == NULL)
    return NULL;
  return t;
}

nodo *concat_se_ricorsiva(nodo *s1, nodo *s2) {
  if (s1 == NULL)
    return s2;
  s1->next = concat_se_ricorsiva(s1->next, s2);
  return s1;
}

nodo *concat_se_iterativa(nodo *s1, nodo *s2) {
  if (s1 == NULL)
    return s2;
  if (s2 == NULL)
    return s1;

  nodo *p = s1;

  while ((p != NULL) && (p->next != NULL))
    p = p->next;

  p->next = s2;

  return s1;
}

nodo *copy_seq(nodo *s) {
  if (s == NULL)
    return NULL;
  nodo *t = new nodo;
  t->dato = s->dato;
  t->next = copy_seq(s->next);
  return t;
}

nodo *concat_nose(nodo *s1, nodo *s2) {
  if (s1 == NULL)
    return copy_seq(s2);
  if (s2 == NULL)
    return copy_seq(s1);

  nodo *cs1 = copy_seq(s1);
  nodo *cs2 = copy_seq(s2);

  nodo *p;

  for (p = cs1; ((p != NULL) && (p->next != NULL)); p = p->next)
    ;

  p->next = cs2;

  return cs1;
}

nodo *concat_nose_recur(nodo *s1, nodo *s2) {
  if (s1 == NULL)
    return copy_seq(s2);

  nodo *t = new nodo;
  t->dato = s1->dato;
  t->next = concat_nose_recur(s1->next, s2);
  return t;
}

int main() {
  nodo *L1 = NULL;

  for (int i = 0; i < 10; i++) {
    int d = rand() % 100;

    cout << "Inserting number " << d << endl;
    nodo *t = new nodo;
    t->dato = d;
    t->next = L1;
    L1 = t;
  }
  cout << "La lista L1 creata e':" << endl;
  stampa(L1);

  nodo *L2 = NULL;

  for (int i = 0; i < 20; i++) {
    int d = rand() % 100;

    cout << "Inserting number " << d << endl;
    nodo *t = new nodo;
    t->dato = d;
    t->next = L2;
    L2 = t;
  }
  cout << "La lista L2 creata e':" << endl;
  stampa(L2);

  // Provare ad inserire qui le funzioni definite prima

  delete_list(L2);
  delete_list(L1);
}
