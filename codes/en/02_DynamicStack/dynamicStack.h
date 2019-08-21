#ifndef dynamicStack_h
#define dynamicStack_h

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int key;
} Object;

typedef struct StackNode *Pointer;

typedef struct StackNode{
    Object obj;
    Pointer next;
} StackNode;

typedef struct {
    Pointer top;
    int size;
} DynamicStack;

void init(DynamicStack *stack);
int isEmpty(DynamicStack *stack);
void push(Object obj, DynamicStack *stack);
void pop(DynamicStack *stack, Object *obj);
int size(DynamicStack *stack);
void top(DynamicStack *stack, Object *obj);
void print(DynamicStack *stack);

#endif /* dynamicStack_h */
