//
//  staticStack.h
//  Stacks
//
//  Created by Rafael Gomes Mantovani on 22/03/19.
//  Copyright © 2019 Rafael Gomes Mantovani. All rights reserved.
//

#ifndef staticStack_h
#define staticStack_h

#include <stdio.h>
#include <stdlib.h>

#define MAXTAM 100

/* tipo abstrato para item, que será inserido na pilha */
typedef struct {
    int key;
    /* podemos adicionar mais coisas aqui */
} Object;

/* tipo abstrato de pilha */
typedef struct {
    Object array[MAXTAM];
    int top;
} StaticStack;


/* funções de manipulação */
void init(StaticStack *stack);
int isEmpty(StaticStack *stack);
int isFull(StaticStack *stack) ;
void push(Object obj, StaticStack *stack);
void pop(StaticStack *stack, Object *obj);
int size(StaticStack *stack);
Object top(StaticStack *stack);
void print(StaticStack *stack);

#endif /* staticStack_h */
