
#include "staticQueue.h"

void initQueue(StaticQueue *queue) {
  queue->start = 0;
  queue->end = -1;
  queue->size = 0;
}

int increaseIndex(int i) {
  int newValue = (i+1) % MAXTAM;
  return newValue;
}

int sizeQueue(StaticQueue *queue) {
  return (queue->size);
}

bool isEmpty(StaticQueue *queue) {
  return(queue->size == 0);
}

bool isFull(StaticQueue *queue) {
  return(queue->size == MAXTAM);
}

void enqueue(Object x, StaticQueue *queue) {
  if(isFull(queue)) {
    printf("Erro: elemento nao foi inserido, porque a fila esta cheia.\n");
  } else {
    queue->end = increaseIndex(queue->end);
    queue->array[queue->end] = x;
    queue->size++;
  }
}

Object first(StaticQueue *queue) {
    Object ret = queue->array[queue->start];
    return(ret);
}

Object dequeue(StaticQueue *queue) {
  Object ret = {-99};
  if(isEmpty(queue)){
    printf("Erro: elemento nao foi removido, porque a fila esta vazia.\n");
  } else {
    ret = queue->array[queue->start];
    queue->start = increaseIndex(queue->start);
    queue->size--;
  }
  return(ret);
}

Object last(StaticQueue *queue) {
  Object ret = queue->array[queue->end];
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
