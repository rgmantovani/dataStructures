
#ifndef AVLTrees_h
#define AVLTrees_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/******************************************************************************/
/******************************************************************************/

typedef struct {
  int key;
} Item;

typedef struct NodeTree *PointerNodeTree;

typedef struct NodeTree {
  Item element;
  PointerNodeTree right;
  PointerNodeTree left;
  int height;
} NodeTree;

/******************************************************************************/
/******************************************************************************/
// Queue to print Tree and its correspondent levels

typedef struct NodeQueue *Pointer;

typedef struct NodeQueue{
  PointerNodeTree node;
  Pointer next;
  int level;
} NodeQueue;

typedef struct {
  Pointer start;
  Pointer end;
  int size;
} DynamicQueue;

void initQueue(DynamicQueue *queue);
void enqueue(PointerNodeTree x, DynamicQueue *queue, int level);
PointerNodeTree dequeue(DynamicQueue *queue, int* level);
void printQueue(DynamicQueue *queue);
int isEmpty(DynamicQueue *queue);
int size(DynamicQueue *queue);
PointerNodeTree first(DynamicQueue *queue);
PointerNodeTree last(DynamicQueue *queue);

/******************************************************************************/
/******************************************************************************/

//AVL functions

void initAVLTree(PointerNodeTree *node);
bool isEmptyAVLTree(PointerNodeTree *node);

void preOrder(PointerNodeTree *node);
void posOrder(PointerNodeTree *node);
void inOrder(PointerNodeTree *node);

int depthAVLTree(PointerNodeTree *node);
int updateHeight( PointerNodeTree left, PointerNodeTree right);
int heightAVLTree(PointerNodeTree node);

bool searchAVLTree(PointerNodeTree *node, int key);
void destroyAVLTree(PointerNodeTree *node);

void applyRotations(PointerNodeTree *node);
void singleLeftRotation(PointerNodeTree *node);
void doubleLeftRotation(PointerNodeTree *node);
void singleRightRotation(PointerNodeTree *node);
void doubleRightRotation(PointerNodeTree *node);

bool insertAVLTree(PointerNodeTree *node, Item x);
void printAVLTree(PointerNodeTree *root);

PointerNodeTree getMaxAux (PointerNodeTree *node);
bool removeAVL(PointerNodeTree *node, int key);

/******************************************************************************/
/******************************************************************************/

#endif /* AVLTrees_h */
