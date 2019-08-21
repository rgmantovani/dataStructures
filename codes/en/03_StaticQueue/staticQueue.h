//
//  staticQueue.h
//  staticQueue
//
//  Created by Rafael Gomes Mantovani on 29/03/19.
//  Copyright © 2019 Rafael Gomes Mantovani. All rights reserved.
//

#ifndef staticQueue_h
#define staticQueue_h

#include <stdio.h>
#include <stdlib.h>

#define MAXTAM  5

typedef struct {
  int key;
    /* outros componentes */
} Item;

typedef struct {
  Item array[MAXTAM];
  int size;
  int start;
  int end;
} StaticQueue;

void initQueue(StaticQueue *queue);
int isEmpty(StaticQueue *queue);
int isFull(StaticQueue *queue);
int sizeQueue(StaticQueue *queue);
int increaseIndex(int i);
void enqueue(Item x, StaticQueue *queue);
void dequeue(StaticQueue *queue, Item *x);
void printQueue(StaticQueue *queue);
Item first(StaticQueue *queue);
Item last(StaticQueue *queue);

#endif /* staticQueue_h */
