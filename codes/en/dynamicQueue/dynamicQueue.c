
#include "dynamicQueue.h"

void initQueue(DynamicQueue *queue) {
  queue->start = NULL;
  queue->end = NULL;
  queue->size = 0;
}

int isEmpty(DynamicQueue *queue) {
  return(queue->size == 0);
}

int size(DynamicQueue *queue) {
  return (queue->size);
}

void enqueue(Item x, DynamicQueue *queue) {
  Pointer aux;
  aux = (Pointer) malloc(sizeof(NodeQueue));
  aux->item = x;
    
  // first
  if(isEmpty(queue)) {
    queue->start = queue->end = aux;
    aux->next = NULL;
  } else {
    aux->next = queue->end->next;
    queue->end->next = aux;
    queue->end = queue->end->next;
  }
  queue->size++;
}

void dequeue(DynamicQueue *queue, Item *x) {
  if(isEmpty(queue)) {
    printf("Erro: elemento nao foi inserido, porque a fila esta cheia.\n");
  } else {
    *x = queue->start->item;
        
    Pointer aux;
    aux = queue->start;
    queue->start = queue->start->next;
    free(aux);
    queue->size--;
  }
}

void printQueue(DynamicQueue *queue) {
  printf("Fila = {");
  Pointer ptr;
  for(ptr = queue->start; ptr != NULL; ptr = ptr->next) {
    printf("%d ", ptr->item.key);
  }
  printf("}\n");
}

Item first(DynamicQueue *queue) {
  Item ret = queue->start->item;
  return(ret);
}

Item last(DynamicQueue *queue) {
  Item ret = queue->end->item;
  return(ret);
}
