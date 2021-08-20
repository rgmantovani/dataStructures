#ifndef AVLTree_h
#define AVLTree_h

#include <stdio.h>
#include <stdlib.h>

typedef struct AVLNode* PtrAVLNode;

typedef struct AVLNode {
  int key;
  PtrAVLNode left;
  PtrAVLNode right;
  int height;
} AVLNode;

int max(int a, int b);
int height(PtrAVLNode node);
PtrAVLNode newNode(int key);
PtrAVLNode rightRotate(PtrAVLNode y);
PtrAVLNode leftRotate(PtrAVLNode x);
int getBalance(PtrAVLNode node);
PtrAVLNode insert(PtrAVLNode node, int key);
PtrAVLNode minValueNode(PtrAVLNode node);
PtrAVLNode deleteNode(PtrAVLNode root, int key);

void PreOrdemArvoreAVL(PtrAVLNode root);
void posOrder(PtrAVLNode root);
void inOrder(PtrAVLNode root);

#endif /* AVLTree_h */
