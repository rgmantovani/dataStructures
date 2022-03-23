#include <stdio.h>
#include "staticQueue.h"

int main(int argc, const char * argv[]) {

  StaticQueue queue;

  initStaticQueue(&queue);

  int toInsert[] = {1, 3, 4, 67, 9, -1, 2, 3};

  for(int i = 0; i < 8; i++){
    enqueueStaticQueue(&queue, toInsert[i]);
    printStaticQueue(&queue);
  }

  int first, last;

  first = firstStaticQueue(&queue);
  printf("First = %d\n", first);
  last = lastStaticQueue(&queue);
  printf("Last = %d\n", last);

  int tam = sizeOfStaticQueue(&queue);
  printf("Queue Size = %d\n", tam);

  int toRemove;
  for(int i = 0; i < tam; i++){
    toRemove = dequeueStaticQueue(&queue);
    printStaticQueue(&queue);
  }

  return 0;
}
