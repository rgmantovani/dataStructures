#ifndef DoubleLinkedList_h
#define DoubleLinkedList_h

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

//---------------------------------------------------------------------------------
// types
//---------------------------------------------------------------------------------

typedef struct NodeList *Pointer;

typedef struct NodeList {
    int element;
    Pointer next;
    Pointer previous;
} NodeList;

typedef struct {
    Pointer first;
    int size;
} DoubleLinkedList;

//---------------------------------------------------------------------------------
//Functions
//---------------------------------------------------------------------------------

void initDoubleList(DoubleLinkedList *list);
void printDoubleList(DoubleLinkedList *list);
void printReverseDoubleList(DoubleLinkedList *list);
void destroyDoubleList(DoubleLinkedList *list);
bool insertDoubleList(DoubleLinkedList *list, int x);
bool isEmptyDoubleList(DoubleLinkedList *list);
bool searchDoubleList(DoubleLinkedList *list, int key);
bool removeDoubleList(DoubleLinkedList *list, int key, int *item);
bool removeFirstDoubleList(DoubleLinkedList *list, int *item);
bool removeLastDoubleList(DoubleLinkedList *list, int *item);
int sizeOfDoubleList(DoubleLinkedList *list);
int firstDoubleList(DoubleLinkedList *list);
int lastDoubleList(DoubleLinkedList *list);

#endif /* DoubleLinkedList_h */

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------
