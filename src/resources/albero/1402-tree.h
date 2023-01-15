#ifndef TREE_H
#define TREE_H

struct nodo;

typedef nodo *tree;

struct nodo {
  key_value *kv;
  tree left;
  tree right;
};

void init(tree &);
tree inserisci(tree, key_value *);
tree cerca(tree, int);
void stampa_ordinata(tree);

#endif
