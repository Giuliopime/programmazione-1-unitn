#include "iostream"

using namespace std;

int main() {
   // La da il prof
}

tree* inserisci(tree* t, int numero) {
  if (t == NULL) {
    t = new nodo;
    t->p = p;
    t->left = NULL;
    t->right = NULL;
  } else if (numero < t->info)
    t->left = inserisci(t->left, p);
  else
    t->right = inserisci(t->right, p);
  return t;
}

tree* estrai_aux(const list* lista, tree* tree) {
   if (lista != null) {
      lista = estrai_aux(lista, tree);
      
      
      if (lista->info % 2 == 0) {
         tree = inserisci(tree, lista->info);
      }
   }

   return lista;
}

tree* estrai(const list* lista) {
   tree* tree = estrai_aux(lista, nullptr);

   return tree;
}

/**
 * SE INVECE CHIEDE DA ALBERO A ALBERO
 */
tree* estrai_aux(const tree* t, tree* nuovoTree) {
   if (t != NULL) {
      nuovoTree = estrai_aux(t->left, nuovoTree);

      if (t->info % 2 == 0 && t->info != 0) {
         nuovoTree = inserisci(nuovoTree, t->info);
      }

      nuovoTree = estrai_aux(t->right, nuovoTree);
   }

   return nuovoTree;
}
