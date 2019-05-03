#include "pilhaEstatica.h"

void iniciaPilha(pilhaEstatica *pilha) {
  pilha->topo = 0;
}

int estaVazia(pilhaEstatica *pilha) {
  return(pilha->topo == 0);
}

int estaCheia(pilhaEstatica *pilha) {
  return(pilha->topo == MAXTAM-1);
}

void empilha(Item item, pilhaEstatica *pilha) {
  if(estaCheia(pilha)) {
    printf(" * Erro: pilha esta cheia - elemento nao inserido! \n");
  } else {
    pilha->array[ pilha->topo ] = item;
    pilha->topo = pilha->topo + 1;
  }
}

void desempilha(Item *item, pilhaEstatica *pilha) {
  if(estaVazia(pilha)) {
    printf(" * Erro: pilha esta vazia - elemento nao removido! \n");
  } else {
    *item = pilha->array[pilha->topo - 1];
    pilha->topo--;
  }
}

int tamanhoPilha(pilhaEstatica *pilha) {
  return(pilha->topo);
}

Item topo(pilhaEstatica *pilha) {
  Item item = pilha->array[pilha->topo-1];
  return(item);
}

void imprimePilha(pilhaEstatica *pilha) {
  printf("Pilha = {");
  int i;
  for(i = 0; i < tamanhoPilha(pilha); i++) {
    printf("%d ", pilha->array[i].chave);
  }
  printf("}\n");
}
