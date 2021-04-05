#include "staticStack.h"

void init(StaticStack *stack) {
  stack->top = 0;
}

bool isEmpty(StaticStack *stack) {
  return(stack->top == 0);
}

bool isFull(StaticStack *stack) {
  return(stack->top == MAXTAM-1);
}

void push(Object obj, StaticStack *stack) {
  if(isFull(stack)) {
    printf(" * Erro: pilha esta cheia - elemento nao inserido! \n");
  } else {
    stack->array[ stack->top ] = obj;
    stack->top++;
  }
}

void pop(StaticStack *stack, Object *obj) {
  if(isEmpty(stack)) {
    printf(" * Erro: pilha esta vazia - elemento nao removido! \n");
  } else {
    *obj = stack->array[stack->top-1];
    stack->top--;
  }
}

int size(StaticStack *stack) {
  return(stack->top);
}

Object top(StaticStack *stack) {
  Object obj = stack->array[stack->top-1];
  return(obj);
}

void print(StaticStack *stack) {
  printf("Pilha = {");
  int i;
  for(i = 0; i < size(stack); i++) {
    printf("%d ", stack->array[i].key);
  }
  printf("}\n");
}
