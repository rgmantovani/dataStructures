//
//  dynamicQueue.h
//  DynamicQueue
//
//  Created by Rafael Gomes Mantovani on 03/04/19.
//  Copyright © 2019 Rafael Gomes Mantovani. All rights reserved.
//

#ifndef dynamicQueue_h
#define dynamicQueue_h

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int key;
    /* outros componentes */
} Item;

typedef struct NodeQueue *Pointer;

typedef struct NodeQueue{
    Item item;
    Pointer next;
} NodeQueue;

typedef struct {
    Pointer start;
    Pointer end;
    int size;
} DynamicQueue;

void initQueue(DynamicQueue *queue);
void enqueue(Item x, DynamicQueue *queue);
void dequeue(DynamicQueue *queue, Item *x);
void printQueue(DynamicQueue *queue);
int isEmpty(DynamicQueue *queue);
int size(DynamicQueue *queue);
Item first(DynamicQueue *queue);
Item last(DynamicQueue *queue);

#endif /* dynamicQueue_h */
