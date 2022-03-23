#ifndef DynamicQueue_h
#define DynamicQueue_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//---------------------------------------------------------------------------------
// Types
//---------------------------------------------------------------------------------

typedef struct NodeQueue *Pointer;

typedef struct NodeQueue{
    int x;
    Pointer next;
} NodeQueue;

typedef struct {
    Pointer start;
    Pointer end;
    int size;
} DynamicQueue;

//---------------------------------------------------------------------------------
// Functions
//---------------------------------------------------------------------------------

void initDynamicQueue(DynamicQueue *queue);
void enqueueDynamicQueue(DynamicQueue *queue, int x);
void dequeueDynamicQueue(DynamicQueue *queue, int *x);
void printDynamicQueue(DynamicQueue *queue);
void destroyDynamicQueue(DynamicQueue *queue);
bool isEmptyDynamicQueue(DynamicQueue *queue);
int sizeOfDynamicQueue(DynamicQueue *queue);
int firstDynamicQueue(DynamicQueue *queue);
int lastDynamicQueue(DynamicQueue *queue);

#endif /* DynamicQueue_h */
