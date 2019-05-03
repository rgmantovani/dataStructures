
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

void enfileira(Item x, FilaDinamica *fila) {
  Ponteiro aux;
  aux = (Ponteiro) malloc(sizeof(NoFila));
  aux->item = x;
  
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

void desenfileira(FilaDinamica *fila, Item *x) {
  if(estaVazia(fila)) {
    printf("Erro: elemento nao foi inserido, porque a fila esta cheia.\n");
  } else {
    *x = fila->inicio->item;
    
    Ponteiro aux;
    aux = fila->inicio;
    fila->inicio = fila->inicio->proximo;
    free(aux);
    fila->tamanho--;
  }
}

void imprimeFila(FilaDinamica *fila) {
  printf("Fila = {");
  Ponteiro ptr;
  for(ptr = fila->inicio; ptr != NULL; ptr = ptr->proximo) {
    printf("%d ", ptr->item.chave);
  }
  printf("}\n");
}

Item inicioFila(FilaDinamica *fila) {
  Item ret = fila->inicio->item;
  return(ret);
}

Item fimFila(FilaDinamica *fila) {
  Item ret = fila->fim->item;
  return(ret);
}
