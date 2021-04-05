
#include "filaDinamica.h"

void iniciaFila(FilaDinamica *fila) {
  fila->inicio = NULL;
  fila->fim = NULL;
  fila->tamanho = 0;
}

int estaVazia(FilaDinamica *fila) {
  return(fila->inicio == NULL);
//  return(fila->tamanho == 0)
}

int tamanhoFila(FilaDinamica *fila) {
  return (fila->tamanho);
}

void enfileira(Objeto x, FilaDinamica *fila) {
  PtrNoFila aux;
  aux = (PtrNoFila) malloc(sizeof(NoFila));
  aux->obj = x;
  
  // primeira insercao
  if(estaVazia(fila)) {
    fila->inicio = fila->fim = aux;
    aux->proximo = NULL;
  } else { 
    aux->proximo = fila->fim->proximo;
    fila->fim->proximo = aux;
    fila->fim = fila->fim->proximo;
  }
  fila->tamanho++;
}

void desenfileira(FilaDinamica *fila, Objeto *x) {
  if(estaVazia(fila)) {
    printf("Erro: elemento nao foi inserido, porque a fila esta cheia.\n");
  } else {
    *x = fila->inicio->obj;
    
    PtrNoFila aux;
    aux = fila->inicio;
    fila->inicio = fila->inicio->proximo;
    free(aux);
    fila->tamanho--;
  }
}

void imprimeFila(FilaDinamica *fila) {
  printf("Fila = {");
  PtrNoFila ptr;
  for(ptr = fila->inicio; ptr != NULL; ptr = ptr->proximo) {
    printf("%d ", ptr->obj.chave);
  }
  printf("}\n");
}

Objeto inicioFila(FilaDinamica *fila) {
  Objeto ret = fila->inicio->obj;
  return(ret);
}

Objeto fimFila(FilaDinamica *fila) {
  Objeto ret = fila->fim->obj;
  return(ret);
}
