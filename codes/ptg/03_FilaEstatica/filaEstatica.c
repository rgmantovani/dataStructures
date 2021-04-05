
#include "filaEstatica.h"

void iniciaFila(FilaEstatica *fila) {
  fila->inicio = 0;
  fila->fim = -1;
  fila->tamanho = 0;
}

//incrementa o indice do vetor da fila
int incrementaIndice(int i) {
  int newValue = (i+1) % MAXTAM;
  return (newValue);
}

bool estaVazia(FilaEstatica *fila) {
  return(tamanhoFila(fila) == 0);
}

bool estaCheia(FilaEstatica *fila) {
  return(tamanhoFila(fila) == MAXTAM);
}

int tamanhoFila(FilaEstatica *fila) {
  return (fila->tamanho);
}

void enfileira(Objeto x, FilaEstatica *fila) {
  if(estaCheia(fila)) {
    printf("Erro: elemento nao foi inserido, porque a fila esta cheia.\n");
  } else {
    fila->fim = incrementaIndice(fila->fim);
    fila->array[fila->fim] = x;
    fila->tamanho++;
  }
}

Objeto inicioFila(FilaEstatica *fila) {
  Objeto ret = fila->array[fila->inicio];
  return(ret);
}

Objeto fimFila(FilaEstatica *fila) {
  Objeto ret = fila->array[fila->fim];
  return(ret);
}

Objeto desenfileira(FilaEstatica *fila) {
  Objeto ret = {-99};
  if(estaVazia(fila)){
    printf("Erro: elemento nao foi removido, porque a fila esta vazia.\n");
  } else {
    ret = fila->array[fila->inicio];
    fila->inicio = incrementaIndice(fila->inicio);
    fila->tamanho--;
  }
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


//void imprimeFila(FilaEstatica *fila){
//
//  int i = fila->inicio;
//
//  if(fila->tamanho == 0) {
//     printf("Fila = { }\n");
//  } else {
//    printf("Fila = { ");
//    while(i != fila->fim) {
//      printf("%d ", fila->array[i].chave);
//      if(i == (MAXTAM-1)) {
//        i = 0;
//      } else {
//        i++;
//      }
//    }
//    printf("%d}\n", fila->array[fila->fim].chave);
//  }
//}
