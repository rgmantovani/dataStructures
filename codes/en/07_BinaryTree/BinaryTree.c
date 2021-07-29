//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

#include "BinaryTree.h"

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

void initBinaryTree(PtrBinaryTree *node) {
  *node = NULL;
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

bool isEmptyBinaryTree(PtrBinaryTree *node) {
  return(*node == NULL);
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

bool insertBinaryTree(PtrBinaryTree *node, int x) {

  if(*node == NULL) {
    (*node) = (PtrBinaryTree)malloc(sizeof(NodeBinaryTree));
    (*node)->right = (*node)->left = NULL;
    (*node)->x = x;
    return(true);
  }

  if((*node)->x == x) return(false);

  if((*node)->x > x) {
    return(insertBinaryTree(&(*node)->left, x));
  } else {
    return(insertBinaryTree(&(*node)->right, x));
  }
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

bool searchBinaryTree(PtrBinaryTree *node, int key) {
 
  if(*node == NULL)     return(false);
  if((*node)->x == key) return(true);

  
  if((*node)->x > key){
    return(searchBinaryTree(&(*node)->left, key));
  } else {
    return(searchBinaryTree(&(*node)->right, key));
  }
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

void destroyBinaryTree(PtrBinaryTree *node) {
  if((*node) != NULL) {
    destroyBinaryTree(&(*node)->left);
    destroyBinaryTree(&(*node)->right);
    free(*node);
    *node = NULL;
  }
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

int sizeOfBinaryTree(PtrBinaryTree *node) {
  if ((*node) == NULL) return 0;
  else {
    return(sizeOfBinaryTree(&(*node)->left) + 1 + sizeOfBinaryTree(&(*node)->right));
  }
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

int maxDepthBinaryTree(PtrBinaryTree *node){
  if ((*node) == NULL) return 0;
  else {
   
    int lDepth = maxDepthBinaryTree(&(*node)->left);
    int rDepth = maxDepthBinaryTree(&(*node)->right);

    if (lDepth > rDepth) return(lDepth+1);
    else                 return(rDepth+1);
  }
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

PtrBinaryTree maximumBinaryTree(PtrBinaryTree *node) {
  PtrBinaryTree ret;
  if((*node)->right == NULL) {
    ret = (*node);
    return(ret);
  }
  return(maximumBinaryTree(&(*node)->right));
}

PtrBinaryTree maximumIterativeBinaryTree(PtrBinaryTree *node) {
  PtrBinaryTree ret = (*node);
  while(ret->right != NULL) {
    ret = ret->right;
  }
  return(ret);
}

PtrBinaryTree minimumBinaryTree(PtrBinaryTree *node) {
  PtrBinaryTree ret = (*node);
  if((*node)->left == NULL) {
    ret = (*node);
    return(ret);
  }
  return(minimumBinaryTree(&(*node)->left));
}

PtrBinaryTree minimumIterativeBinaryTree(PtrBinaryTree *node) {
  PtrBinaryTree ret = (*node);
  while(ret->left != NULL) {
    ret = ret->left;
  }
  return(ret);
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

void preOrderBinaryTree(PtrBinaryTree *node) {
  if(*node == NULL) return;
  printf("%d ", (*node)->x);
  preOrderBinaryTree(&(*node)->left);
  preOrderBinaryTree(&(*node)->right);
}

void posOrderBinaryTree(PtrBinaryTree *node) {
  if(*node == NULL) return;
  posOrderBinaryTree(&(*node)->left);
  posOrderBinaryTree(&(*node)->right);
  printf("%d ", (*node)->x);
}

void inOrderBinaryTree(PtrBinaryTree *node) {
  if(*node == NULL) return;
  inOrderBinaryTree(&(*node)->left);
  printf("%d ", (*node)->x);
  inOrderBinaryTree(&(*node)->right);
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

PtrBinaryTree getMaxAuxBinaryTree (PtrBinaryTree *node) {
  PtrBinaryTree ret;
  if((*node)->right == NULL) {
    ret = (*node);
    (*node) = (*node)->left;
    return(ret);
  }
  return(getMaxAuxBinaryTree(&(*node)->right));
}

PtrBinaryTree getMinAuxBinaryTree (PtrBinaryTree *node) {
  PtrBinaryTree ret;
  if((*node)->left == NULL) {
    ret = (*node);
    (*node) = (*node)->right;
    return(ret);
  }
  return(getMinAuxBinaryTree(&(*node)->left));
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

bool removeBinaryTree(PtrBinaryTree *node, int key) {
  
  if((*node) == NULL) return (false);

  if((*node)->x == key) {
    PtrBinaryTree tmp = (*node);
    if((*node)->left == NULL) {
      (*node) = (*node)->right;
    }
    else if((*node)->right == NULL) {
        (*node) = (*node)->left;
    } else {
      tmp = getMaxAuxBinaryTree(&(*node)->left);
      (*node)->x = tmp->x;
    }
    free(tmp);
    return true;
  }
  
  if((*node)->x > key){
    return(removeBinaryTree(&(*node)->left, key));
  } else {
    return(removeBinaryTree(&(*node)->right, key));
  }
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------
