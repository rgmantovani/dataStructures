#ifndef staticQueue_h
#define staticQueue_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//---------------------------------------------------------------------------------
// Types
//---------------------------------------------------------------------------------

#define MAXTAM  5

typedef struct {
  int array[MAXTAM];
  int size;
  int start;
  int end;
} StaticQueue;

//---------------------------------------------------------------------------------
// Functions
//---------------------------------------------------------------------------------

void initStaticQueue(StaticQueue *queue);
void enqueueStaticQueue(StaticQueue *queue, int x);
void printStaticQueue(StaticQueue *queue);
bool isEmptyStaticQueue(StaticQueue *queue);
bool isFullStaticQueue(StaticQueue *queue);
int sizeOfStaticQueue(StaticQueue *queue);
int increaseIndex(int i);
int dequeueStaticQueue(StaticQueue *queue);
int firstStaticQueue(StaticQueue *queue);
int lastStaticQueue(StaticQueue *queue);

#endif /* staticQueue_h */
