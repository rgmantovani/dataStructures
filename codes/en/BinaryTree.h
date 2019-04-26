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

void initTree(Pointer *tree);
void destroyTree(Pointer *tree);
void preOrder(Pointer *tree);
void posOrder(Pointer *tree);
void inOrder(Pointer *tree);
bool insertItem(Pointer *tree, Item x);
bool findItem(Pointer *tree, int key, Item *ret);
bool isEmpty(Pointer *tree);
bool removeItem(Pointer *tree, int key, Item *ret);
Pointer maximum(Pointer *tree);
Pointer minimum(Pointer *tree);

#endif /* BinaryTree_h */
