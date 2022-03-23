#include <stdio.h>
#include "PilhaDinamica.h"

int main(int argc, const char * argv[]) {

  PilhaDinamica stack;

  iniciaPilhaDinamica(&stack);

  int toInsert[] = {1, 3, 4, 67, 9, -1, 2, 3};

  for(int i = 0; i < 8; i++){
    empilhaPilhaDinamica(&stack, toInsert[i]);
    imprimePilhaDinamica(&stack);
  }

  int top;
  topoPilhaDinamica(&stack, &top);
  printf("Topo = %d\n", top);

  int sizeStack = tamanhoPilhaDinamica(&stack);
  printf("Tamanho Pilha = %d\n", sizeStack);

  int toRemove;
  for(int i = 0; i < sizeStack; i++){
    desempilhaPilhaDinamica(&stack, &toRemove);
    imprimePilhaDinamica(&stack);
  }

  destroiPilhaDinamica(&stack);
    
  if(estaVaziaPilhaDinamica(&stack)) {
      printf("Não existem mais elementos!\n");
  }
    
  return 0;
}
