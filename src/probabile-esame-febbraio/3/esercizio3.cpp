#include "coda.h"
#include "iostream"

int vincitoreSensoOrario(int n, int k);

int vincitoreSensoAntiorario(int n, int k);

int main() {
  int n = 5;
  int k = 7;
  int orario = vincitoreSensoOrario(n, k);
  int anti = vincitoreSensoAntiorario(n, k);

  std::cout << orario << std::endl;
  std::cout << anti << std::endl;

  return 0;
}

int vincitoreSensoOrario(int n, int k) {
  coda_init();
  int dim = 0;

  for(int i=1;i<=n;i++){
    coda_enqueue(i);
    dim++;
  }
  while(dim!=1){
    int x=k;
    while(x>1){
      int r;
      coda_first(r);
      // pop
      coda_dequeue();
      dim--;

      // push
      coda_enqueue(r);
      dim++;

      x--;
    }
    coda_dequeue();
    dim--;
  }

  int vincitore;
  coda_first(vincitore);

  coda_deinit();

  return vincitore;
}


int vincitoreSensoAntiorario(int n, int k) {
  coda_init();
  int dim = 0;

  coda_enqueue(1);
  dim++;

  for(int i=n;i>=2;i--){
    coda_enqueue(i);
    dim++;
  }
  while(dim!=1){
    int x=k;
    while(x>1){
      int r;
      coda_first(r);
      // pop
      coda_dequeue();
      dim--;

      // push
      coda_enqueue(r);
      dim++;

      x--;
    }
    coda_dequeue();
    dim--;
  }

  int vincitore;
  coda_first(vincitore);

  coda_deinit();

  return vincitore;
}
