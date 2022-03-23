#include <stdio.h>
#include "PilhaEstatica.h"

int main(int argc, const char * argv[]) {
 
  PilhaEstatica stack;
  
  iniciaPilhaEstatica(&stack);
  
  int toInsert[] = {1, 3, 4, 67, 9, -1, 2, 3};
  
  for(int i = 0; i < 8; i++){
    empilhaPilhaEstatica(&stack, toInsert[i]);
    imprimePilhaEstatica(&stack);
  }
  
  int topo = topoPilhaEstatica(&stack);
  printf("Topo = %d\n", topo);
  
  int tam = tamanhoPilhaEstatica(&stack);
  printf("Tamanho Pilha = %d\n", tam);
  
  int toRemove;
  for(int i = 0; i < tam; i++){
    desempilhaPilhaEstatica(&stack, &toRemove);
    imprimePilhaEstatica(&stack);
  }
  
  return 0;
}
