#include <stdio.h>
#include "ArvoreBinaria.h"

//---------------------------------------------------
//---------------------------------------------------

int main(int argc, const char * argv[]) {

  PtrNoArvoreBinaria raiz;

  iniciaArvoreBinaria(&raiz);

  if(estaVaziaArvoreBinaria(&raiz)) {
    printf("A arvore está vazia\n");
  }

  insereArvoreBinaria(&raiz, 5);
  insereArvoreBinaria(&raiz, 4);
  insereArvoreBinaria(&raiz, 3);
  insereArvoreBinaria(&raiz, 2);
  insereArvoreBinaria(&raiz, 7);
  insereArvoreBinaria(&raiz, 6);
  insereArvoreBinaria(&raiz, 8);
  insereArvoreBinaria(&raiz, 9);

  if(!estaVaziaArvoreBinaria(&raiz)) {
    printf("Existem elementos na árvore ...\n");
  }

  // [5, 4, 3, 2, 7, 6, 8, 9]
  printf("PreOrdem = ");
  preOrdemArvoreBinaria(&raiz);
  printf("\n");

  // [2, 3, 4, 6, 9, 8, 7, 5]
  printf("PosOrdem = ");
  posOrdemArvoreBinaria(&raiz);
  printf("\n");

  // [2, 3, 4, 5, 6, 7, 8, 9]
  printf("EmOrdem =  ");
  EmOrdemArvoreBinaria(&raiz);
  printf("\n");

  printf("-------------------------\n");

  int queries[6] = {7, 11, 2, 14, 0, -5};
  for(int i = 0; i < 6; i++) {
    printf("Searching: %d -> ", queries[i]);
    if(pesquisaArvoreBinaria(&raiz, queries[i])) {
      printf("achou :)\n");
    } else {
      printf("não achou :/\n");
    }
  }
  printf("-------------------------\n");
  // 5, 4, 3, 2, 7, 6, 8, 9
  printf("PreOrdem = ");
  preOrdemArvoreBinaria(&raiz);
  printf("\n");

  removeArvoreBinaria(&raiz, 6); // leaf

  // imprime, esq, direita
  // 5, 4, 3, 2, 7, 8, 9
  printf("PreOrdem = ");
  preOrdemArvoreBinaria(&raiz);
  printf("\n");

  removeArvoreBinaria(&raiz, 5); // has both subtrees
  // 4, 3, 2, 7, 8 9
  printf("PreOrdem = ");
  preOrdemArvoreBinaria(&raiz);
  printf("\n");

  removeArvoreBinaria(&raiz, 3); // right sutree is null
  // 4, 2, 7, 8, 9
  printf("PreOrdem = ");
  preOrdemArvoreBinaria(&raiz);
  printf("\n");

  removeArvoreBinaria(&raiz, 8); // left subtree is null
  //4, 2, 7, 9
  printf("PreOrdem = ");
  preOrdemArvoreBinaria(&raiz);
  printf("\n");

  removeArvoreBinaria(&raiz, 4); // root
  // 2, 7, 9
  printf("PreOrdem = ");
  preOrdemArvoreBinaria(&raiz);
  printf("\n");

  printf("-------------------------\n");

  destroiArvoreBinaria(&raiz);
  if(!estaVaziaArvoreBinaria(&raiz)) {
    printf("A árvore foi cortada!\n");
  }
  printf("-------------------------\n");
  return 0;
}

//---------------------------------------------------
//---------------------------------------------------
