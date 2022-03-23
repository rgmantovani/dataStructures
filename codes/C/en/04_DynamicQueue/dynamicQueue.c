//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

#include "DynamicQueue.h"

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

void initDynamicQueue(DynamicQueue *queue) {
  queue->start = NULL;
  queue->end = NULL;
  queue->size = 0;
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

bool isEmptyDynamicQueue(DynamicQueue *queue) {
  return(queue->size == 0);
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

int sizeOfDynamicQueue(DynamicQueue *queue) {
  return (queue->size);
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

void enqueueDynamicQueue(DynamicQueue *queue, int x) {
  
  Pointer aux = (Pointer) malloc(sizeof(NodeQueue));
  aux->x = x;
    
  if(isEmptyDynamicQueue(queue)) {
    queue->start = queue->end = aux;
    aux->next = NULL;
  } else {
    aux->next = queue->end->next;
    queue->end->next = aux;
    queue->end = queue->end->next;
  }
  queue->size++;
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

void dequeueDynamicQueue(DynamicQueue *queue, int *x) {
  if(!isEmptyDynamicQueue(queue)) {
    *x = queue->start->x;
    Pointer aux  = queue->start;
    queue->start = queue->start->next;
    free(aux);
    queue->size--;
  }
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

void printDynamicQueue(DynamicQueue *queue) {
  printf("Queue = {");
  Pointer ptr;
  for(ptr = queue->start; ptr != NULL; ptr = ptr->next) {
    printf("%d ", ptr->x);
  }
  printf("}\n");
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

int firstDynamicQueue(DynamicQueue *queue) {
  return(queue->start->x);
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

int lastDynamicQueue(DynamicQueue *queue) {
  return(queue->end->x);
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

void destroyDynamicQueue(DynamicQueue *queue) {
  printf("@Destroying queue!\n");
  int remove;
  while(sizeOfDynamicQueue(queue)!=0) {
    dequeueDynamicQueue(queue, &remove);
  }
}


//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------
