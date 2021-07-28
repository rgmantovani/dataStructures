//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

#include "DynamicStack.h"

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

void initDynamicStack(DynamicStack *stack) {
  stack->top = NULL;
  stack->size = 0;
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

int sizeOfDynamicStack(DynamicStack *stack) {
  return(stack->size);
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

bool isEmptyDynamicStack(DynamicStack *stack) {
  return(stack->size == 0);
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

void pushDynamicStack(DynamicStack *stack, int x) {
  PtrStackNode aux;
  aux = (PtrStackNode)malloc(sizeof(StackNode));
  aux->x = x;
  aux->next = stack->top;
  stack->top = aux;
  stack->size++;
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

void popDynamicStack(DynamicStack *stack, int *x) {
    
  if(!isEmptyDynamicStack(stack)) {
    *x = stack->top->x;
    PtrStackNode aux = stack->top;
    stack->top = stack->top->next;
    free(aux);
    stack->size--;
  }
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

void topDynamicStack(DynamicStack *stack, int *x) {
  if(!isEmptyDynamicStack(stack)) {
    *x = stack->top->x;
  }
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

void printDynamicStack(DynamicStack *stack) {
  printf("Stack = {");
  PtrStackNode ptr;
  for(ptr = stack->top; ptr != NULL; ptr = ptr->next) {
    printf("%d ", ptr->x);
  }
  printf("}\n");
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

void destroyDynamicStack(DynamicStack *stack) {
  printf("@Destroying stack!\n");
  PtrStackNode toRemove;
  while(stack->top!= NULL) {
    toRemove = stack->top;
    stack->top = stack->top->next;
    free(toRemove);
  }
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

void destroyDynamicStack2(DynamicStack *stack) {
  printf("@Destroying stack!\n");
  int aux;
  while(!isEmptyDynamicStack(stack)) {
      popDynamicStack(stack, &aux);
  }
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------
