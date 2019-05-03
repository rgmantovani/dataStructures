
#include "staticQueue.h"

void initQueue(StaticQueue *queue) {
  queue->start = 0;
  queue->end = -1;
  queue->size = 0;
}

//incrementa o indice do vetor da fila
int increaseIndex(int i) {
  return (i+1) % MAXTAM;
}

int sizeQueue(StaticQueue *queue) {
  return (queue->size);
}

int isEmpty(StaticQueue *queue) {
  return(queue->size == 0);
//  return(queue->start > queue->end);
}

int isFull(StaticQueue *queue) {
  return(queue->size == MAXTAM);
}

void enqueue(Item x, StaticQueue *queue) {
  if(isFull(queue)) {
    printf("Erro: elemento nao foi inserido, porque a fila esta cheia.\n");
  } else {
    queue->end = increaseIndex(queue->end);
    queue->array[queue->end] = x;
    queue->size++;
  }
}

Item first(StaticQueue *queue) {
    Item ret = queue->array[queue->start];
    return(ret);
}

void dequeue(StaticQueue *queue, Item *x) {
  if(isEmpty(queue)){
    printf("Erro: elemento nao foi removido, porque a fila esta cheia.\n");
  } else {
    *x = queue->array[queue->start];
    queue->start = increaseIndex(queue->start);
    queue->size--;
  }
}

Item last(StaticQueue *queue) {
  Item ret = queue->array[queue->end];
  return(ret);
}

void printQueue(StaticQueue *queue) {
  printf("Fila = {");
  int n = sizeQueue(queue);
  for(int i = 0; i < n; i++) {
    int index = (queue->start + i) % MAXTAM;
    printf("%d ", queue->array[index].key);
  }
  printf("}\n");
}
