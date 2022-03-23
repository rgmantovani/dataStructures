#include <stdio.h>
#include "FilaEstatica.h"

int main(int argc, const char * argv[]) {
 
  FilaEstatica queue;
  
  iniciaFilaEstatica(&queue);
  
  int toInsert[] = {1, 3, 4, 67, 9, -1, 2, 3};
  
  for(int i = 0; i < 8; i++){
    enfileiraFilaEstatica(&queue, toInsert[i]);
    imprimeFilaEstatica(&queue);
  }
  
  int first, last;
  
  first = primeiroFilaEstatica(&queue);
  printf("Primeiro = %d\n", first);
  last = ultimoFilaEstatica(&queue);
  printf("Ultimo = %d\n", last);
   
  int tam = tamanhoFilaEstatica(&queue);
  printf("Tamanho da Fila = %d\n", tam);
  
  int toRemove;
  for(int i = 0; i < tam; i++){
    toRemove = desenfileiraFilaEstatica(&queue);
    imprimeFilaEstatica(&queue);
  }
  
  return 0;
}
