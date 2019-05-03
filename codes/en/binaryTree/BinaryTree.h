//
//  BinaryTree.h
//  BinaryTrees
//
//  Created by Rafael Gomes Mantovani on 25/04/19.
//  Copyright © 2019 Rafael Gomes Mantovani. All rights reserved.
//

#ifndef BinaryTree_h
#define BinaryTree_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
  int key;
} Item;

typedef struct NodeTree *Pointer;

typedef struct NodeTree {
  Item element;
  Pointer left;
  Pointer right;
} NodeTree;

int sizeTree(Pointer *node);
int maxDepth(Pointer *node);
void initTree(Pointer *node);
void destroyTree(Pointer *node);
void preOrder(Pointer *node);
void posOrder(Pointer *node);
void inOrder(Pointer *node);
bool insertItem(Pointer *node, Item x);
bool findItem(Pointer *node, int key, Item *ret);
bool isEmpty(Pointer *node);
bool removeItem(Pointer *node, int key);
Pointer maximum(Pointer *node);
Pointer maximumIterative(Pointer *node);
Pointer minimum(Pointer *node);
Pointer minimumIterative(Pointer *node);
Pointer getMinAux (Pointer *node); //usado na remoção
Pointer getMaxAux (Pointer *node); //usado na remoção

#endif /* BinaryTree_h */
