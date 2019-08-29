#ifndef staticQueue_h
#define staticQueue_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXTAM  5

typedef struct {
  int key;
    /* outros componentes */
} Object;

typedef struct {
  Object array[MAXTAM];
  int size;
  int start;
  int end;
} StaticQueue;

void initQueue(StaticQueue *queue);
void enqueue(Object x, StaticQueue *queue);
void printQueue(StaticQueue *queue);
bool isEmpty(StaticQueue *queue);
bool isFull(StaticQueue *queue);
int sizeQueue(StaticQueue *queue);
int increaseIndex(int i);
Object dequeue(StaticQueue *queue);
Object first(StaticQueue *queue);
Object last(StaticQueue *queue);

#endif /* staticQueue_h */
