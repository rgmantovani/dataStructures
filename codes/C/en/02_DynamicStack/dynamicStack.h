#ifndef DynamicStack_h
#define DynamicStack_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//---------------------------------------------------------------------------------
// Types
//---------------------------------------------------------------------------------

typedef struct StackNode *PtrStackNode;

typedef struct StackNode{
    int x;
    PtrStackNode next;
} StackNode;

typedef struct {
    PtrStackNode top;
    int size;
} DynamicStack;

//---------------------------------------------------------------------------------
// Functions
//---------------------------------------------------------------------------------

void initDynamicStack(DynamicStack *stack);
bool isEmptyDynamicStack(DynamicStack *stack);
void pushDynamicStack(DynamicStack *stack, int x);
void popDynamicStack(DynamicStack *stack, int *x);
int sizeOfDynamicStack(DynamicStack *stack);
void topDynamicStack(DynamicStack *stack, int *x);
void printDynamicStack(DynamicStack *stack);
void destroyDynamicStack(DynamicStack *stack);
void destroyDynamicStack2(DynamicStack *stack);

#endif /* DynamicStack_h */
