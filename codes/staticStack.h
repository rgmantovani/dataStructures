#ifndef staticStack_h
#define staticStack_h

#include <stdio.h>
#include <stdlib.h>

#define MAXTAM 100

/* tipo abstrato para item, que será inserido na pilha */
typedef struct {
    int key;
    /* podemos adicionar mais coisas aqui */
} Item;

/* tipo abstrato de pilha */
typedef struct {
    Item array[MAXTAM];
    int top;
} StaticStack;

/* funções de manipulação */
void init(StaticStack *pilha);
int isEmpty(StaticStack *pilha);
int isFull(StaticStack *pilha) ;
void push(Item item, StaticStack *pilha);
void pop(StaticStack *pilha, Item *item);
int size(StaticStack *pilha);
Item top(StaticStack *pilha);
void print(StaticStack *pilha);

#endif /* staticStack_h */
