
#include "ArvoreAVL.h"

int main(int argc, const char * argv[]) {

  PtrNoAVL raiz;
  iniciaArvoreAVL(&raiz);

  if(!estaVaziaArvoreAVL(&raiz)) {
    printf("* Arvore não está vazia\n");
  } else {
    printf("* Arvore está vazia\n");
  }

  int array[] = {30,40,24,58,48,26,11,13,14};

  int i, x;
  for(i = 0; i < 9; i ++) {
    x = array[i];
    insereArvoreAVL(&raiz, x);
    printf("Arvore = {");
    emOrdemArvoreAVL(&raiz);
    printf("}\n");
 }

  preOrdemArvoreAVL(&raiz);
  printf("\n------------------\n");
  posOrdemArvoreAVL(&raiz);
  printf("\n------------------\n");
  emOrdemArvoreAVL(&raiz);
  printf("\n------------------\n");

 int tofind[] = {13,14,15,12,4,5,3,1};
 for(i = 0; i < 8; i ++) {
   pesquisaArvoreAVL(&raiz,tofind[i]);
 }

 printf("\n Removendo elementos ... \n");
 int toRemove[] = {1,17,8,9,16,15,14};
 for(i = 0; i <7; i++) {
   printf(" - Removendo: %d\n", toRemove[i]);
   removeArvoreAVL(&raiz,toRemove[i]);
   printf("Arvore = {");
   emOrdemArvoreAVL(&raiz);
   printf("}\n");
 }

 printf("\n ! Destruindo a arvore ... \n");
 destroiArvoreAVL(&raiz);
 if(!estaVaziaArvoreAVL(&raiz)) {
   printf("* Arvore não está vazia\n");
 } else {
   printf("* Arvore está vazia\n");
 }

  return 0;
}
