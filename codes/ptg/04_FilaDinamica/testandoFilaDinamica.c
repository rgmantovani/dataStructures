#include <stdio.h>
#include "FilaDinamica.h"

int main(int argc, const char * argv[]) {

  FilaDinamica queue;

  iniciaFilaDinamica(&queue);

  int toInsert[] = {1, 3, 4, 67, 9, -1, 2, 3};

  for(int i = 0; i < 8; i++){
    enfileiraFilaDinamica(&queue, toInsert[i]);
    imprimeFilaDinamica(&queue);
  }

  int first, last;

  first = primeiroFilaDinamica(&queue);
  printf("Primeiro = %d\n", first);
  last = ultimoFilaDinamica(&queue);
  printf("Ultimo = %d\n", last);

  int tam = tamanhoFilaDinamica(&queue);
  printf("Tamanho da Fila = %d\n", tam);

  int toRemove;
  for(int i = 0; i < 3; i++){
    desenfileiraFilaDinamica(&queue, &toRemove);
    imprimeFilaDinamica(&queue);
  }

  destroiFilaDinamica(&queue);
  
  if(estaVaziaFilaDinamica(&queue)) {
    printf("A Fila foi destruída.\n");
  }
  
  return 0;
}
