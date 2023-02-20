#include <iostream>
#include <cstdlib>
#include <ctime>

#define MAXVALUE 100
#define MAXSIZE 100

// NON MODIFICARE IL CODICE SOTTO FINO A "NON MODIFICARE IL CODICE SOPRA"

struct tree {
  int info;
  tree * left;
  tree * right;
};

void insert(tree * & result, const int num) {
  if (result == NULL) {
    result = new tree;
    *result = {num, NULL, NULL};
  } else if (result->info > num) {
    insert(result->left, num);
  } else {
    insert(result->right, num);
  }
}

tree * crea_tree(const int num) {
  tree * result = NULL;
  for(int i = 0; i < num; i++) {
    insert(result, rand()%MAXVALUE);
  }
  return result;
}

void print_tree(const tree * root){
  if (root != NULL) {
    print_tree(root->right);
    std::cout << " " << root->info;
    print_tree(root->left);
  }
}

void delete_tree(tree * & root) {
  if (root != NULL) {
    delete_tree(root->left);
    delete_tree(root->right);
    delete root;
    root = NULL;
  }
}

void delete_list(list * &l) {
  if (l != NULL) {
    delete_list(l->next);
    delete l;
    l = NULL;
  }
}

void print_list(const list * l) {
  if (l != NULL) {
    std::cout << " " << l->info;
    print_list(l->next);
  }
  else
    std::cout << std::endl;
}

// NON MODIFICARE IL CODICE SOPRA

// Add hereafter the declaration of estrai
void estrai(const tree * root, int*& l1, int*& l2);
// Add here above the declaration of estrai

// NON MODIFICARE IL MAIN
int main(int argc, char ** argv) {
  srand(unsigned(time(0)));
  //
  // Commentare la linea seguente per avere comportamento
  // non-deterministico
  //
  srand(0);
  tree * root = crea_tree(rand()%MAXSIZE);
  std::cout << "Initial tree content: ";
  print_tree(root); std::cout << std::endl;
  list * l1;
  list * l2;
  estrai(root, l1, l2);
  delete_tree(root);
  std::cout << "L1 =";
  print_list(l1);
  std::cout << "L2 =";
  print_list(l2);
  delete_list(l1);
  delete_list(l2);
}
// NON MODIFICARE IL MAIN

// Add hereafter the definition of estrai
void estrai_aux(const tree * root, int*& l1, int*& l2, int& indice1, int& indice2) {
  if (NULL != root) {
    estrai_aux(root->right, l1, l2, indice1, indice2);
    if ((root->info % 2) == 0) {
      l1[indice1] = root->info;
      indice1++;
    } else {
      l2[indice2] = root->info;
      indice2++;
    }
    estrai_aux(root->left, l1, l2, indice1, indice2);
  }
}

void conta_dimensione_array(const tree * root, int& contatore1, int& contatore2) {
  if (NULL != root) {
    conta_dimensione_array(root->right, contatore1, contatore2);
    if ((root->info % 2) == 0) {
      contatore1++;
    } else {
      contatore2++;
    }
    conta_dimensione_array(root->left, contatore1, contatore2);
  }
}

void estrai(const tree * root, int*& l1, int*& l2) {
  int dimensione1 = 0;
  int dimensione2 = 0;

  conta_dimensione_array(root, dimensione1, dimensione2);

  l1 = new int[dimensione1];
  l2 = new int[dimensione2];

  int indice1 = 0;
  int indice2 = 0;
  estrai_aux(root, l1, l2, indice1, indice2);

  // Se vuole l'ultimo elemento?
  // l1 = &l1[dimensione1-1];
  // l2 = &l2[dimensione2-1];
}
// Add here above the definition of estrai
