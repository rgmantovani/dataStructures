//
//  DynamicList.h
//  Lists
//
//  Created by Rafael Gomes Mantovani on 05/04/19.

#ifndef DynamicList_h
#define DynamicList_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct  {
    int key;
//    char *name;
} Object;

typedef struct NodeList *Pointer;

typedef struct NodeList {
  Object element;
  Pointer next;
} NodeList;

typedef struct {
  Pointer first;
  int size;
} List;


void initList(List *list);
void insert(List *list, Object x);
void printList(List *list);
void destroyList(List *list);
bool isEmpty(List *list);
bool search(List *list, int key);
bool searchFaster(List *list, int key);
int size(List *list);
void removeElement(List *list, int key, Object *item);
void removeFirst(List *list, Object *item);
void removeLast(List *list, Object *item);
Object first(List *list);
Object last(List *list);

#endif /* DynamicList_h */
