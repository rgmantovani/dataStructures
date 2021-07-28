#include <stdio.h>
#include "DynamicQueue.h"

int main(int argc, const char * argv[]) {

  DynamicQueue queue;

  initDynamicQueue(&queue);

  int toInsert[] = {1, 3, 4, 67, 9, -1, 2, 3};

  for(int i = 0; i < 8; i++){
    enqueueDynamicQueue(&queue, toInsert[i]);
    printDynamicQueue(&queue);
  }

  int first, last;

  first = firstDynamicQueue(&queue);
  printf("First = %d\n", first);
  last = lastDynamicQueue(&queue);
  printf("Last = %d\n", last);

  int tam = sizeOfDynamicQueue(&queue);
  printf("Queue Size = %d\n", tam);

  int toRemove;
  for(int i = 0; i < 3; i++){
    dequeueDynamicQueue(&queue, &toRemove);
    printDynamicQueue(&queue);
  }

  destroyDynamicQueue(&queue);

  if(isEmptyDynamicQueue(&queue)) {
    printf("Queue was destroyed\n");
  }

  return 0;
}
