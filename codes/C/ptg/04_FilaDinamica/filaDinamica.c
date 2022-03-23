//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

#include "FilaDinamica.h"

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

void iniciaFilaDinamica(FilaDinamica *fila) {
  fila->inicio = NULL;
  fila->fim = NULL;
  fila->tamanho = 0;
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

bool estaVaziaFilaDinamica(FilaDinamica *fila) {
  return(fila->tamanho == 0);
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

int tamanhoFilaDinamica(FilaDinamica *fila) {
  return (fila->tamanho);
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

void enfileiraFilaDinamica(FilaDinamica *fila, int x) {
  
  PtrNoFila aux = (PtrNoFila)malloc(sizeof(NoFila));
  aux->x = x;
    
  if(estaVaziaFilaDinamica(fila)) {
    fila->inicio = fila->fim = aux;
    aux->proximo = NULL;
  } else {
    aux->proximo = fila->fim->proximo;
    fila->fim->proximo = aux;
    fila->fim = fila->fim->proximo;
  }
  fila->tamanho++;
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

void desenfileiraFilaDinamica(FilaDinamica *fila, int *x) {
  if(!estaVaziaFilaDinamica(fila)) {
    *x = fila->inicio->x;
    PtrNoFila aux = fila->inicio;
    fila->inicio = fila->inicio->proximo;
    free(aux);
    fila->tamanho--;
  }
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

void imprimeFilaDinamica(FilaDinamica *fila) {
  printf("Fila = {");
  PtrNoFila ptr;
  for(ptr = fila->inicio; ptr != NULL; ptr = ptr->proximo) {
    printf("%d ", ptr->x);
  }
  printf("}\n");
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

int primeiroFilaDinamica(FilaDinamica *fila) {
  return(fila->inicio->x);
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

int ultimoFilaDinamica(FilaDinamica *fila) {
  return(fila->fim->x);
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

void destroiFilaDinamica(FilaDinamica *fila) {
  printf("@Destruindo a fila!\n");
  int remove;
  while(tamanhoFilaDinamica(fila)!=0) {
    desenfileiraFilaDinamica(fila, &remove);
  }
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------
