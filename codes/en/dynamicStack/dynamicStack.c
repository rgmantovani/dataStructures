#include "dynamicStack.h"

void init(DynamicStack *pilha) {
  pilha->top = NULL;
  pilha->size = 0;
}

int size(DynamicStack *pilha) {
  return(pilha->size);
}

int isEmpty(DynamicStack *pilha) {
  return(pilha->size == 0);
}

void push(Item item, DynamicStack *pilha) {
    
  Pointer aux;
  aux = (Pointer) malloc(sizeof(Node));
  aux->item = item;
  aux->next = pilha->top;
  pilha->top = aux;
  pilha->size++;

}

void pop(DynamicStack *pilha, Item *item) {
    
  if(isEmpty(pilha)) {
    printf(" * Erro: pilha esta vazia - elemento nao removido! \n");
  } else {
        
    *item = pilha->top->item;
        
    Pointer aux;
    aux = pilha->top;
    pilha->top = pilha->top->next;
        
    free(aux);
    pilha->size--;
  }
}

void top(DynamicStack *pilha, Item *item) {
  if(isEmpty(pilha)) {
    printf(" * Erro: pilha esta vazia - nao ha elemento no topo! \n");
  } else {
    *item = pilha->top->item;
  }
}

void print(DynamicStack *pilha) {
  printf("Pilha = {");
  Pointer ptr;
  for(ptr = pilha->top; ptr != NULL; ptr = ptr->next) {
    printf("%d ", ptr->item.key);
  }
  printf("}\n");
}
