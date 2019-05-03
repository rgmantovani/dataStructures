
#include "filaEstatica.h"

void iniciaFila(FilaEstatica *fila) {
  fila->inicio = 0;
  fila->fim = -1;
  fila->tamanho = 0;
}

//incrementa o indice do vetor da fila
int incrementaIndice(int i) {
  return (i+1) % MAXTAM;
}

int estaVazia(FilaEstatica *fila) {
  return(tamanhoFila(fila) == 0);
}

int estaCheia(FilaEstatica *fila) {
  return(tamanhoFila(fila) == MAXTAM);
}

int tamanhoFila(FilaEstatica *fila) {
  return (fila->tamanho);
}

void enfileira(Item x, FilaEstatica *fila) {
  if(estaCheia(fila)) {
    printf("Erro: elemento nao foi inserido, porque a fila esta cheia.\n");
  } else {
    fila->fim = incrementaIndice(fila->fim);
    fila->array[fila->fim] = x;
    fila->tamanho++;
  }
}

Item inicioFila(FilaEstatica *fila) {
  Item ret = fila->array[fila->inicio];
  return(ret);
}

void desenfileira(FilaEstatica *fila, Item *x) {
  if(estaVazia(fila)){
    printf("Erro: elemento nao foi removido, porque a fila esta cheia.\n");
  } else {
    *x = fila->array[fila->inicio];
    fila->inicio = incrementaIndice(fila->inicio);
    fila->tamanho--;
  }
}

Item fimFila(FilaEstatica *fila) {
  Item ret = fila->array[fila->fim];
  return(ret);
}

void imprimeFila(FilaEstatica *fila) {
  printf("Fila = {");
  int n = tamanhoFila(fila);
  for(int i = 0; i < n; i++) {
    int index = (fila->inicio + i) % MAXTAM;
    printf("%d ", fila->array[index].chave);
  }
  printf("}\n");
}

void imprimeFila2(FilaEstatica *fila){
  
  int iterador = fila->inicio;
  
  if(fila->tamanho == 0) {
     printf("Fila = { }\n");
  } else {
    printf("Fila = { ");
    while(iterador != fila->fim) {
      printf("%d ", fila->array[iterador].chave);
      if(iterador == (MAXTAM-1)) {
        iterador = 0;
      } else {
        iterador++;
      }
    }
    printf("%d}\n", fila->array[fila->fim].chave);
  }
}


void imprimeFila3(FilaEstatica *fila){
  printf("Fila = { ");
  for(int i = fila->inicio; i!= fila->fim; i = incrementaIndice(i)){
    printf("%d ", fila->array[fila->fim].chave);
  }
    printf("%d}\n",fila->array[fila->fim].chave);
}

