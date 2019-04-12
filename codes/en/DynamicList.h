//
//  DynamicList.h
//  Lists
//
//  Created by Rafael Gomes Mantovani on 05/04/19.

#ifndef DynamicList_h
#define DynamicList_h

#include <stdio.h>
#include <stdlib.h>

typedef struct  {
    int key;
//    char *name;
} Item;

typedef struct NodeList *Pointer;

typedef struct NodeList {
  Item element;
  Pointer next;
} NodeList;

typedef struct {
  Pointer first;
  int size;
} List;


void initList(List *list);
void insert(List *list, Item x);
void printList(List *list);
void destroyList(List *list);
int isEmpty(List *list);
int search(List *list, int key);
int searchFaster(List *list, int key);
int size(List *list);
void removeElement(List *list, int key, Item *item);
void removeFirst(List *list, Item *item);
void removeLast(List *list, Item *item);
Item first(List *list);
Item last(List *list);

#endif /* DynamicList_h */
