#include "dynamicStack.h"

void init(DynamicStack *stack) {
  stack->top = NULL;
  stack->size = 0;
}

int size(DynamicStack *stack) {
  return(stack->size);
}

bool isEmpty(DynamicStack *stack) {
  return(stack->size == 0);
}

void push(Object obj, DynamicStack *stack) {
    
  PtrStackNode aux;
  aux = (PtrStackNode) malloc(sizeof(StackNode));
  aux->obj = obj;
  aux->next = stack->top;
  stack->top = aux;
  stack->size++;

}

void pop(DynamicStack *stack, Object *obj) {
    
  if(isEmpty(stack)) {
    printf(" * Erro: pilha esta vazia - elemento nao removido! \n");
  } else {
        
    *obj = stack->top->obj;
        
    PtrStackNode aux;
    aux = stack->top;
    stack->top = stack->top->next;
        
    free(aux);
    stack->size--;
  }
}

void top(DynamicStack *stack, Object *item) {
  if(isEmpty(stack)) {
    printf(" * Erro: pilha esta vazia - nao ha elemento no topo! \n");
  } else {
    *item = stack->top->obj;
  }
}

void print(DynamicStack *stack) {
  printf("Pilha = {");
  PtrStackNode ptr;
  for(ptr = stack->top; ptr != NULL; ptr = ptr->next) {
    printf("%d ", ptr->obj.key);
  }
  printf("}\n");
}

void destroy(DynamicStack *stack) {
  printf("@Destroying stack!\n");
  PtrStackNode remover;
  while(stack->top!= NULL) {
    remover = stack->top;
    stack->top = stack->top->next;
    free(remover);
  }
}

void destroy2(DynamicStack *stack) {
  printf("@Destroying stack!\n");
  Object aux;
  while (!isEmpty(stack)) {
    pop(stack, &aux);
  }
}
