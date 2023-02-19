void insert_node(node *x, node *t) {
  t->next = x->next;
  t->next->prev = t;
  t->prev = x;
  x->next = t;
}

node *remove(node *t) {
  t->next->prev = t->prev;
  t->prev->next = t->next;
  t->next = t->prev = NULL;
  return t;
}

void remove(node *t) {
  t->next->prev = t->prev;
  t->prev->next = t->next;

  delete t;
}
