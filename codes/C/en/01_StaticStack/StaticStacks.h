#ifndef staticStack_h
#define staticStack_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//---------------------------------------------------------------------------------
// Types
//---------------------------------------------------------------------------------

#define MAXTAM 100

typedef struct {
    int array[MAXTAM];
    int top;
} StaticStack;

//---------------------------------------------------------------------------------
// Functions
//---------------------------------------------------------------------------------

void initStaticStack(StaticStack *stack);
bool isEmptyStaticStack(StaticStack *stack);
bool isFullStaticStack(StaticStack *stack) ;
void pushStaticStack(StaticStack *stack, int x);
void popStaticStack(StaticStack *stack, int *x);
int sizeOfStaticStack(StaticStack *stack);
int topStaticStack(StaticStack *stack);
void printStaticStack(StaticStack *stack);

#endif /* staticStack_h */

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------
