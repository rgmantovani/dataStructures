//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

#include <stdio.h>
#include "ListaOrdenada.h"

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

int main(int argc, const char * argv[]) {
 
  ListaOrdenada list;
  
  iniciaListaOrdenada(&list);
  
  if(estaVaziaListaOrdenada(&list)) {
    printf("A lista está vazia\n");
  }
  
  printf("\n---------------------------\n");
  printf(" *** Testando: inserção de elementos \n");
  printf("---------------------------\n");
  
  insereListaOrdenada(&list, 1);
  imprimeListaOrdenada(&list);
  insereListaOrdenada(&list, 20);
  imprimeListaOrdenada(&list);
  insereListaOrdenada(&list, 33);
  imprimeListaOrdenada(&list);
  insereListaOrdenada(&list, 44);
  imprimeListaOrdenada(&list);
  insereListaOrdenada(&list, 57);
  imprimeListaOrdenada(&list);
  insereListaOrdenada(&list, 60);
  imprimeListaOrdenada(&list);
  insereListaOrdenada(&list, 2);
  imprimeListaOrdenada(&list);
  insereListaOrdenada(&list, -1);
  imprimeListaOrdenada(&list);

  printf("\n---------------------------\n");
  printf(" *** Testando: impressão \n");
  printf("---------------------------\n");
  
  imprimeListaOrdenada(&list);
  
  int tam = tamanhoListaOrdenada(&list);
  printf("Tamanho da lista: %d\n", tam);
  int first = primeiroListaOrdenada(&list);
  printf("Primeiro: %d\n", first);
  int last = ultimoListaOrdenada(&list);
  printf("Ultimo: %d\n", last);
    
  printf("\n---------------------------\n");
  printf(" *** Testando: pesquisa de elementos \n");
  printf("---------------------------\n");

  int queries[] = {20, 3, 4, 56, 77};
  for(int i = 0; i < 5; i++) {
    printf("Valor %d ...", queries[i]);
    if(pesquisaOtimizadaListaOrdenada(&list, queries[i])) {
      printf(" foi encontando\n");
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
    removeListaOrdenada(&list, toRemove[i], &returned);
    imprimeListaOrdenada(&list);
  }
  
  printf("\n---------------------------\n");
  destroiListaOrdenada(&list);
  if(estaVaziaListaOrdenada(&list)) {
    printf("A lista foi destruída.\n");
  }
  printf("---------------------------\n");
  
  return 0;
}
