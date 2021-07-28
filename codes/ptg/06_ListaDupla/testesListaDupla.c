//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

#include <stdio.h>
#include "ListaDuplamenteEncadeada.h"

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------
int main(int argc, const char * argv[]) {
 
  ListaDupla doublelist;
  
  iniciaListaDupla(&doublelist);
  
  if(estaVaziaListaDupla(&doublelist)) {
    printf("Lista dupla está vazia\n");
  }
  
  printf("\n---------------------------\n");
  printf(" *** Testando: inserção elementos \n");
  printf("---------------------------\n");
  
  insereListaDupla(&doublelist, 1);
  insereListaDupla(&doublelist, 20);
  insereListaDupla(&doublelist, 33);
  insereListaDupla(&doublelist, 44);
  insereListaDupla(&doublelist, 57);
  insereListaDupla(&doublelist, 60);
  insereListaDupla(&doublelist, 2);
  insereListaDupla(&doublelist, -1);
  
  printf("\n---------------------------\n");
  printf(" *** Testando: impressão \n");
  printf("---------------------------\n");
  
  imprimeListaDupla(&doublelist);
  imprimeListaDuplaReverso(&doublelist);
  
  printf("\n---------------------------\n");
  printf(" *** Testando: procurando elementos\n");
  printf("---------------------------\n");

  int queries[] = {20, 3, 4, 56, 77};
  for(int i = 0; i < 5; i++) {
    printf("O valor %d ...", queries[i]);
    if(procuraListaDupla(&doublelist, queries[i])) {
      printf(" foi encontrado\n");
    } else {
      printf(" não foi encontrado\n");
    }
  }
  
  printf("\n---------------------------\n");
  printf(" *** Testando: remoção de elementos \n");
  printf("---------------------------\n");

  int toRemove[] = {57, 44, 29, 1, -1};
  int returned;
  
  for(int i = 0; i < 5; i++) {
    removeListaDupla(&doublelist, toRemove[i], &returned);
    imprimeListaDuplaReverso(&doublelist);
  }
  
  printf("\n---------------------------\n");
  destroiListaDupla(&doublelist);
  printf("---------------------------\n");
  
  return 0;
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

