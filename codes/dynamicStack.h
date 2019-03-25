//
//  dynamicStack.h
//  Created by Rafael Gomes Mantovani on 25/03/19.

#ifndef dynamicStack_h
#define dynamicStack_h

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int key;
    /* outros componentes */
} Item;

typedef struct Node *Pointer;

typedef struct Node{
    Item item;
    Pointer next;
} Node;

typedef struct {
    Pointer top;
    int size;
} DynamicStack;

void init(DynamicStack *pilha);
int isEmpty(DynamicStack *pilha);
void push(Item item, DynamicStack *pilha);
void pop(DynamicStack *pilha, Item *item);
int size(DynamicStack *pilha);
void top(DynamicStack *pilha, Item *item);
void print(DynamicStack *pilha);

#endif /* dynamicStack_h */
