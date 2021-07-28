#include <stdio.h>
#include "DynamicStack.h"

int main(int argc, const char * argv[]) {

  DynamicStack stack;

  initDynamicStack(&stack);

  int toInsert[] = {1, 3, 4, 67, 9, -1, 2, 3};

  for(int i = 0; i < 8; i++){
    pushDynamicStack(&stack, toInsert[i]);
    printDynamicStack(&stack);
  }

  int top;
  topDynamicStack(&stack, &top);
  printf("Top = %d\n", top);

  int sizeStack = sizeOfDynamicStack(&stack);
  printf("Stack size = %d\n", sizeStack);

  int toRemove;
  for(int i = 0; i < sizeStack; i++){
    popDynamicStack(&stack, &toRemove);
    printDynamicStack(&stack);
  }

  destroyDynamicStack(&stack);

  if(isEmptyDynamicStack(&stack)) {
      printf("There are no more elements!\n");
  }

  return 0;
}
