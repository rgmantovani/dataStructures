#include "staticStack.h"

void init(StaticStack *pilha) {
  pilha->top = 0;
}

int isEmpty(StaticStack *pilha) {
  return(pilha->top == 0);
}

int isFull(StaticStack *pilha) {
  return(pilha->top == MAXTAM-1);
}

void push(Item item, StaticStack *pilha) {
  if(isFull(pilha)) {
    printf(" * Erro: pilha esta cheia - elemento nao inserido! \n");
  } else {
    pilha->array[ pilha->top ] = item;
    pilha->top++;
  }
}

void pop(StaticStack *pilha, Item *item) {
  if(isEmpty(pilha)) {
    printf(" * Erro: pilha esta vazia - elemento nao removido! \n");
  } else {
    *item = pilha->array[pilha->top-1];
    pilha->top--;
  }
}

int size(StaticStack *pilha) {
  return(pilha->top);
}

Item top(StaticStack *pilha) {
  Item item = pilha->array[pilha->top-1];
  return(item);
}

void print(StaticStack *pilha) {
  printf("Pilha = {");
  int i;
  for(i = 0; i < size(pilha); i++) {
    printf("%d ", pilha->array[i].key);
  }
  printf("}\n");
}
