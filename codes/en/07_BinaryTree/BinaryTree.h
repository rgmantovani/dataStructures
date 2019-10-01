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
} Object;

typedef struct NodeTree *PtrTree;

typedef struct NodeTree {
  Object element;
  PtrTree left;
  PtrTree right;
} NodeTree;

int sizeTree(PtrTree *node);
int maxDepth(PtrTree *node);
void initTree(PtrTree *node);
void destroyTree(PtrTree *node);
void preOrder(PtrTree *node);
void posOrder(PtrTree *node);
void inOrder(PtrTree *node);
bool insertItem(PtrTree *node, Object x);
bool findItem(PtrTree *node, int key, Object *ret);
bool isEmpty(PtrTree *node);
bool removeItem(PtrTree *node, int key);
PtrTree maximum(PtrTree *node);
PtrTree maximumIterative(PtrTree *node);
PtrTree minimum(PtrTree *node);
PtrTree minimumIterative(PtrTree *node);
PtrTree getMinAux (PtrTree *node); //usado na remoção
PtrTree getMaxAux (PtrTree *node); //usado na remoção

#endif /* BinaryTree_h */
