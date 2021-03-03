#ifndef dynamicStack_h
#define dynamicStack_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int key;
} Object;

typedef struct StackNode *PtrStackNode;

typedef struct StackNode{
    Object obj;
    PtrStackNode next;
} StackNode;

typedef struct {
    PtrStackNode top;
    int size;
} DynamicStack;

void init(DynamicStack *stack);
bool isEmpty(DynamicStack *stack);
void push(Object obj, DynamicStack *stack);
void pop(DynamicStack *stack, Object *obj);
int size(DynamicStack *stack);
void top(DynamicStack *stack, Object *obj);
void print(DynamicStack *stack);
void destroy(DynamicStack *stack);
void destroy2(DynamicStack *stack);

#endif /* dynamicStack_h */
