#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ArvoreBinaria.c>

//---------------------------------------------------
//---------------------------------------------------

int main(int argc, const char * argv[]) {

  // arvore = referencia
  PtrNoArvore raiz;

  // inicializacao da arvore
  iniciaArvore(&raiz);

  if(estaVaziaArvore(&raiz)) {
    printf("Árvore está vazia\n");
  }

  insereArvore(&raiz, 5);
  insereArvore(&raiz, 4);
  insereArvore(&raiz, 3);
  insereArvore(&raiz, 2);
  insereArvore(&raiz, 7);
  insereArvore(&raiz, 6);
  insereArvore(&raiz, 8);
  insereArvore(&raiz, 9);

  if(!estaVaziaArvore(&raiz)) {
    printf("Existem elementos aqui dentro\n");
  }

  // [5, 4, 3, 2, 7, 6, 8, 9]
  printf("Percurso PreOrdem = ");
  percursoPreOrdem(&raiz);
  printf("\n");

  // [2, 3, 4, 6, 9, 8, 7, 5]
  printf("Percurso PosOrdem = ");
  percursoPosOrdem(&raiz);
  printf("\n");

  // [2, 3, 4, 5, 6, 7, 8, 9]
  printf("Percurso EmOrdem =  ");
  percursoEmOrdem(&raiz);
  printf("\n");

  printf("Percurso EmOrdem2 = ");
  percursoEmOrdemContraria(&raiz);
  printf("\n");

  printf("-------------------------\n");

  int consultas[6] = {7, 11, 2, 14, 0, -5};
  //                   V, F, V, F, F, F
  for(int i = 0; i < 6; i++) {
    printf("Verificando: %d -> ", consultas[i]);
    if(pesquisaArvore(&raiz, consultas[i])) {
      printf("achei\n");
    } else {
      printf("não achei\n");
    }
  }
  printf("-------------------------\n");
  // 5, 4, 3, 2, 7, 6, 8, 9
  printf("Percurso PreOrdem = ");
  percursoPreOrdem(&raiz);
  printf("\n");

  removeArvore(&raiz, 6); // folha

  // imprime, esq, direita
  // 5, 4, 3, 2, 7, 8, 9
  printf("Percurso PreOrdem = ");
  percursoPreOrdem(&raiz);
  printf("\n");

  removeArvore(&raiz, 5); // tem as duas subarvore
  // 4, 3, 2, 7, 8 9
  printf("Percurso PreOrdem = ");
  percursoPreOrdem(&raiz);
  printf("\n");

  removeArvore(&raiz, 3); // sub-esq, n tem dir
  // 4, 2, 7, 8, 9
  printf("Percurso PreOrdem = ");
  percursoPreOrdem(&raiz);
  printf("\n");

  removeArvore(&raiz, 8); // sub-dir, n tem es
  //4, 2, 7, 9
  printf("Percurso PreOrdem = ");
  percursoPreOrdem(&raiz);
  printf("\n");

  removeArvore(&raiz, 4); //raiz (maior esquerda)
  // 2, 7, 9
  printf("Percurso PreOrdem = ");
  percursoPreOrdem(&raiz);
  printf("\n");

  printf("-------------------------\n");

  destroiArvore(&raiz);
  if(estaVaziaArvore(&raiz)) {
    printf("Cortei a árvore!\n");
  }
  printf("-------------------------\n");
  return 0;
}

//---------------------------------------------------
//---------------------------------------------------
