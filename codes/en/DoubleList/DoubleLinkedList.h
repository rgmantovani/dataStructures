//
//  DoubleLinkedList.h
//  Created by Rafael Gomes Mantovani on 15/04/19.
//

#ifndef DoubleLinkedList_h
#define DoubleLinkedList_h

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct  {
    int key;
} Item;

typedef struct NodeList *Pointer;

typedef struct NodeList {
    Item element;
    Pointer next;
    Pointer previous;
} NodeList;

typedef struct {
    Pointer first;
    int size;
} DoubleLinkedList;

void initList(DoubleLinkedList *list);
void printList(DoubleLinkedList *list);
void printInverseList(DoubleLinkedList *list);
void destroyList(DoubleLinkedList *list);
bool insert(DoubleLinkedList *list, Item x);
bool isEmpty(DoubleLinkedList *list);
bool search(DoubleLinkedList *list, int key);
bool removeElement(DoubleLinkedList *list, int key, Item *item);
bool removeFirst(DoubleLinkedList *list, Item *item);
bool removeLast(DoubleLinkedList *list, Item *item);
int sizeOfList(DoubleLinkedList *list);
Item first(DoubleLinkedList *list);
Item last(DoubleLinkedList *list);

#endif /* DoubleLinkedList_h */
