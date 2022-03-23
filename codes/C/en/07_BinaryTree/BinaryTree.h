#ifndef BinaryTree_h
#define BinaryTree_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//---------------------------------------------------------------------------------
// types
//---------------------------------------------------------------------------------

typedef struct NodeBinaryTree *PtrBinaryTree;

typedef struct NodeBinaryTree {
  int x;
  PtrBinaryTree left;
  PtrBinaryTree right;
} NodeBinaryTree;

//---------------------------------------------------------------------------------
// functions
//---------------------------------------------------------------------------------

int sizeOfBinaryTree(PtrBinaryTree *node);
int maxDepthBinaryTree(PtrBinaryTree *node);
void initBinaryTree(PtrBinaryTree *node);
void destroyBinaryTree(PtrBinaryTree *node);
void preOrderBinaryTree(PtrBinaryTree *node);
void posOrderBinaryTree(PtrBinaryTree *node);
void inOrderBinaryTree(PtrBinaryTree *node);
bool insertBinaryTree(PtrBinaryTree *node, int x);
bool searchBinaryTree(PtrBinaryTree *node, int key);
bool isEmptyBinaryTree(PtrBinaryTree *node);
bool removeBinaryTree(PtrBinaryTree *node, int key);
PtrBinaryTree maximumBinaryTree(PtrBinaryTree *node);
PtrBinaryTree maximumIterativeBinaryTree(PtrBinaryTree *node);
PtrBinaryTree minimumBinaryTree(PtrBinaryTree *node);
PtrBinaryTree minimumIterativeBinaryTree(PtrBinaryTree *node);
PtrBinaryTree getMinAuxBinaryTree(PtrBinaryTree *node);
PtrBinaryTree getMaxAuxBinaryTree(PtrBinaryTree *node); 

#endif /* BinaryTree_h */

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------
