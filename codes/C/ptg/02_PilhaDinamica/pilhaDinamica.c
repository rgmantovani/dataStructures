//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

#include "PilhaDinamica.h"

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

void iniciaPilhaDinamica(PilhaDinamica *pilha) {
  pilha->topo = NULL;
  pilha->tamanho = 0;
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

int tamanhoPilhaDinamica(PilhaDinamica *pilha) {
  return(pilha->tamanho);
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

bool estaVaziaPilhaDinamica(PilhaDinamica *pilha) {
  return(pilha->tamanho == 0);
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

void empilhaPilhaDinamica(PilhaDinamica *pilha, int x) {
  PtrNoPilha aux;
  aux = (PtrNoPilha)malloc(sizeof(NoPilha));
  aux->x = x;
  aux->proximo = pilha->topo;
  pilha->topo = aux;
  pilha->tamanho++;
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

void desempilhaPilhaDinamica(PilhaDinamica *pilha, int *x) {
    
  if(!estaVaziaPilhaDinamica(pilha)) {
    *x = pilha->topo->x;
    PtrNoPilha aux = pilha->topo;
    pilha->topo = pilha->topo->proximo;
    free(aux);
    pilha->tamanho--;
  }
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

void topoPilhaDinamica(PilhaDinamica *pilha, int *x) {
  if(!estaVaziaPilhaDinamica(pilha)) {
    *x = pilha->topo->x;
  }
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

void imprimePilhaDinamica(PilhaDinamica *pilha) {
  printf("Pilha = {");
  PtrNoPilha ptr;
  for(ptr = pilha->topo; ptr != NULL; ptr = ptr->proximo) {
    printf("%d ", ptr->x);
  }
  printf("}\n");
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

void destroiPilhaDinamica(PilhaDinamica *pilha) {
  printf("@Destruindo pilha!\n");
  PtrNoPilha toRemove;
  while(pilha->topo!= NULL) {
    toRemove = pilha->topo;
    pilha->topo = pilha->topo->proximo;
    free(toRemove);
  }
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

void destroiPilhaDinamica2(PilhaDinamica *pilha) {
  printf("@Destruindo pilha!\n");
  int aux;
  while(!estaVaziaPilhaDinamica(pilha)) {
      desempilhaPilhaDinamica(pilha, &aux);
  }
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------
