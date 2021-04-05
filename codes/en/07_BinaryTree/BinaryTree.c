//****************************************************************************
//****************************************************************************

#include "BinaryTree.h"

void initTree(PtrTree *node) {
  *node = NULL;
}

//****************************************************************************
//****************************************************************************

bool isEmpty(PtrTree *node) {
  return(*node == NULL);
}

//****************************************************************************
//****************************************************************************

bool insertItem(PtrTree *node, Object x) {

  if(*node == NULL) {
    (*node) = (PtrTree) malloc(sizeof(NodeTree));
    (*node)->right = (*node)->left = NULL;
    (*node)->element = x;
    printf(" @ Elemento: %d foi inserido com sucesso.\n", x.key);
    return(true);
  }

  if((*node)->element.key == x.key) {
    printf("@ Warning: elemento %d ja existe na arvore. Não foi inserido. \n", x.key);
    return(false);
  }

  if((*node)->element.key > x.key) {
    return(insertItem(&(*node)->left, x));
  } else {
    return(insertItem(&(*node)->right, x));
  }
}

//****************************************************************************
//****************************************************************************


bool findItem(PtrTree *node, int key, Object *ret) {
  if(*node == NULL) {
    printf(" # Elemento % d não está na arvore.\n", key);
    return(false);
  }
  if((*node)->element.key == key) {
    *ret = (*node)->element;
    printf(" # Elemento: %d, foi encontado na arvore.\n", key);
    return(true);
  }
  if((*node)->element.key > key){
    return(findItem(&(*node)->left, key, ret));
  } else {
    return(findItem(&(*node)->right, key, ret));
  }
}

//****************************************************************************
//****************************************************************************

void destroyTree(PtrTree *node) {
  if((*node) != NULL) {
    destroyTree(&(*node)->left);
    destroyTree(&(*node)->right);
    free(*node);
    *node = NULL;
  }
}

//****************************************************************************
//****************************************************************************

int sizeTree(PtrTree *node) {
  if ((*node) == NULL) return 0;
  else {
    return(sizeTree(&(*node)->left) + 1 + sizeTree(&(*node)->right));
  }
}

//****************************************************************************
//****************************************************************************


int maxDepth(PtrTree *node) {
  if ((*node) == NULL) return 0;
  else {
   
    int lDepth = maxDepth(&(*node)->left);
    int rDepth = maxDepth(&(*node)->right);

    if (lDepth > rDepth)
      return(lDepth+1);
    else return(rDepth+1);
  }
}

//****************************************************************************
//****************************************************************************


PtrTree maximum(PtrTree *node) {
  PtrTree ret;
  if((*node)->right == NULL) {
    ret = (*node);
    return(ret);
  }
  return(maximum(&(*node)->right));
}

PtrTree maximumIterative(PtrTree *node) {
  PtrTree ret = (*node);
  while(ret->right != NULL) {
    ret = ret->right;
  }
  return(ret);
}

PtrTree minimum(PtrTree *node) {
  PtrTree ret = (*node);
  if((*node)->left == NULL) {
    ret = (*node);
    return(ret);
  }
  return(minimum(&(*node)->left));
}

PtrTree minimumIterative(PtrTree *node) {
  PtrTree ret = (*node);
  while(ret->left != NULL) {
    ret = ret->left;
  }
  return(ret);
}

//****************************************************************************
//****************************************************************************


void preOrder(PtrTree *node) {
  if(*node == NULL) return;
  printf("%d ", (*node)->element.key);
  preOrder(&(*node)->left);
  preOrder(&(*node)->right);
}

void posOrder(PtrTree *node) {
  if(*node == NULL) return;
  posOrder(&(*node)->left);
  posOrder(&(*node)->right);
  printf("%d ", (*node)->element.key);
}

void inOrder(PtrTree *node) {
  if(*node == NULL) return;
  inOrder(&(*node)->left);
  printf("%d ", (*node)->element.key);
  inOrder(&(*node)->right);
}
//****************************************************************************
//****************************************************************************


PtrTree getMaxAux (PtrTree *node) {
  PtrTree ret;
  if((*node)->right == NULL) {
    ret = (*node);
    (*node) = (*node)->left;
    return(ret);
  }
  return(getMaxAux(&(*node)->right));
}

PtrTree getMinAux (PtrTree *node) {
  PtrTree ret;
  if((*node)->left == NULL) {
    ret = (*node);
    (*node) = (*node)->right;
    return(ret);
  }
  return(getMinAux(&(*node)->left));
}

//****************************************************************************
//****************************************************************************

bool removeItem(PtrTree *node, int key) {
  
  // chegou em uma folha, não tem o que remover
  if((*node) == NULL) {
    printf("Não existe o elemento %d para ser removido!\n", key);
    return (false);
  }
  
  // encontrei o que remover ...
  if((*node)->element.key == key) {
    
    PtrTree tmp = (*node);
    
    // case 1: sub-arvore esquerda é nula (cai aqui se for folha também)
    if((*node)->left == NULL) {
      (*node) = (*node)->right;
    }
    // case 2: sub-arvore direita é nula (poderia cair aqui tb no caso de folha)
    else if((*node)->right == NULL) {
        (*node) = (*node)->left;
    } else {
      // case 3: ambas subarvores existem: pegar o maior elemento da sub-arvore da esquerda
      tmp = getMaxAux(&(*node)->left);
      // tmp = getMinAux(&(*node)->right);
      (*node)->element = tmp->element;
    }
    free(tmp);
    return true;
  }
  
  if((*node)->element.key > key){
    return(removeItem(&(*node)->left, key));
  } else {
    return(removeItem(&(*node)->right, key));
  }
}

//******************************************************************************/
//******************************************************************************/
