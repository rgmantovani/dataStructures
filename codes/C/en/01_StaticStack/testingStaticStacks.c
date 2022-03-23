#include <stdio.h>
#include "StaticStacks.h"

int main(int argc, const char * argv[]) {

  StaticStack stack;

  initStaticStack(&stack);

  int toInsert[] = {1, 3, 4, 67, 9, -1, 2, 3};

  for(int i = 0; i < 8; i++){
    pushStaticStack(&stack, toInsert[i]);
    printStaticStack(&stack);
  }

  int top = topStaticStack(&stack);
  printf("Top = %d\n", top);

  int sizeStack = sizeOfStaticStack(&stack);
  printf("Stack size = %d\n", sizeStack);

  int toRemove;
  for(int i = 0; i < sizeStack; i++){
    popStaticStack(&stack, &toRemove);
    printStaticStack(&stack);
  }

  return 0;
}
