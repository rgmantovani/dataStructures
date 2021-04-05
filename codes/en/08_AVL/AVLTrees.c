
#include "AVLTrees.h"

/******************************************************************************/
/******************************************************************************/

void initAVLTree(PointerNodeTree *node) {
  *node = NULL;
}

bool isEmptyAVLTree(PointerNodeTree *node) {
  return(*node == NULL);
}

/******************************************************************************/
/******************************************************************************/

void preOrder(PointerNodeTree *node) {
  if(*node == NULL) return;
  printf("%d ", (*node)->element.key);
  preOrder(&(*node)->left);
  preOrder(&(*node)->right);
}

void posOrder(PointerNodeTree *node) {
  if(*node == NULL) return;
  posOrder(&(*node)->left);
  posOrder(&(*node)->right);
  printf("%d ", (*node)->element.key);
}

void inOrder(PointerNodeTree *node) {
  if(*node == NULL) return;
  inOrder(&(*node)->left);
  printf("%d ", (*node)->element.key);
  inOrder(&(*node)->right);
}

/******************************************************************************/
/******************************************************************************/

int depthAVLTree(PointerNodeTree *node) {
  if ((*node) == NULL) return 0;
  else {
    int lDepth = depthAVLTree(&(*node)->left);
    int rDepth = depthAVLTree(&(*node)->right);
    if (lDepth > rDepth)
      return(lDepth+1);
    else return(rDepth+1);
  }
}

/******************************************************************************/
/******************************************************************************/

bool searchAVLTree(PointerNodeTree *node, int key ) {
  if(*node == NULL ) {
    printf(" @ Elemento consultado: %d, não existe na arvore\n", key);
    return false;
  }
  if((*node)->element.key == key){
    printf(" @ Elemento consultado: %d, existe na arvore\n", key);
    return true;
  }
  if((*node)->element.key > key )
    return (searchAVLTree( &(*node)->left, key));
  else
    return (searchAVLTree( &(*node)->right, key));
}


/******************************************************************************/
/******************************************************************************/

void destroyAVLTree(PointerNodeTree *node) {
  if((*node) != NULL ) {
    destroyAVLTree( &(*node)->left);
    destroyAVLTree( &(*node)->right);
    free(*node);
    *node = NULL;
  }
}

/******************************************************************************/
/******************************************************************************/

int heightAVLTree(PointerNodeTree node) {
  if(node == NULL)
    return (0);
  else
    return(node->height);
}

/******************************************************************************/
/******************************************************************************/

int updateHeight( PointerNodeTree left, PointerNodeTree right) {

  int ae, ad;
  ae = heightAVLTree(left);
  ad = heightAVLTree(right);

  if(ae > ad)
    return(ae + 1);
  else
    return (ad + 1);
 }

/******************************************************************************/
/******************************************************************************/

void singleLeftRotation(PointerNodeTree *node) {

  PointerNodeTree u;
  u = (*node)->right;
  (*node)->right = u->left;
  u->left = (*node);
  (*node)->height = 0;
  
  (*node)->height = updateHeight((*node)->left, (*node)->right);
  u->height = updateHeight(u->left, u->right);
  
  (*node) = u;
}

void doubleLeftRotation(PointerNodeTree *node) {
  
  PointerNodeTree u, v;
  u = (*node)->right;
  v = u->left;
  
  (*node)->right = v->left;
  u->left = v->right;
  v->right = u;
  v->left = (*node);

  (*node)->height = updateHeight((*node)->left, (*node)->right);
  u->height = updateHeight(u->left, u->right);
  v->height = updateHeight(v->left, v->right);
  
  (*node) = v;
}

/******************************************************************************/
/******************************************************************************/

void singleRightRotation(PointerNodeTree *node) {
  PointerNodeTree u;
  u = (*node)->left;
  (*node)->left = u->right;
  u->right = (*node);
  (*node)->height = 0;
  
  (*node)->height = updateHeight((*node)->left, (*node)->right);
  u->height = updateHeight(u->left, u->right);
  
  
  (*node) = u;
}

void doubleRightRotation(PointerNodeTree *node) {

  PointerNodeTree u, v;
  u = (*node)->left;
  v = u->right;

  u->right = v->left;
  v->left = u;

  (*node)->left = v->right;
  v->right = (*node);
  
  (*node)->height = updateHeight((*node)->left, (*node)->right);
  u->height = updateHeight(u->left, u->right);
  v->height = updateHeight(v->left, v->right);
  
  (*node) = v;
}

/******************************************************************************/
/******************************************************************************/

void applyRotations(PointerNodeTree *node) {
  
  // left > right --> -2 (right rotations)
  if(heightAVLTree((*node)->left) > heightAVLTree((*node)->right)) {
    PointerNodeTree x = (*node)->left;
    if(heightAVLTree(x->left) >= heightAVLTree(x->right)) {
      printf("rotação simples a direita\n");
      singleRightRotation(&(*node));
    } else {
      printf("rotação dupla a direita\n");
      doubleRightRotation(&(*node));
    }
  } else {
  // right > left --> +2 (left rotations)
    PointerNodeTree y = (*node)->right;
    if(heightAVLTree(y->right) > heightAVLTree(y->left)) {
      printf("rotação simples a esquerda\n");
      singleLeftRotation(&(*node));
    } else {
      printf("rotação dupla a esquerda\n");
      doubleLeftRotation(&(*node));
    }
  }
}

/******************************************************************************/
/******************************************************************************/

bool insertAVLTree(PointerNodeTree *node, Item x) {
  
  if(*node == NULL) {
    (*node) = (PointerNodeTree) malloc(sizeof(NodeTree));
    (*node)->right = (*node)->left = NULL;
    (*node)->element = x;
    (*node)->height = 1;
    printf("\n @ Elemento: %d foi inserido com sucesso.\n", x.key);
    return(true);
  }
  
  if((*node)->element.key == x.key) {
    printf("@ Warning: elemento %d ja existe na arvore. Não foi inserido. \n", x.key);
    return(false);
  }
  
  bool ins;
  if((*node)->element.key > x.key)
    ins = insertAVLTree(&(*node)->left, x);
  else
    ins = insertAVLTree(&(*node)->right, x);
  
  if( ins == false) return (false);
  
  int ae, ad;
  ae = heightAVLTree((*node)->left);
  ad = heightAVLTree((*node)->right);
  
  if((ad - ae == -2) || (ad - ae == 2)) {
    printf("Desbalanceamento ... ");
    applyRotations(&(*node));
  }
  
  (*node)->height = updateHeight((*node)->left, (*node)->right);
  return(true);
}


/******************************************************************************/
/******************************************************************************/

void printAVLTree(PointerNodeTree *root) {

  DynamicQueue queue;
  initQueue(&queue);

  int level = 1;
  int previous;
  int lft, rgt;
  PointerNodeTree node;

  enqueue((*root), &queue, level);
  
  printf("\n------------\nTree:\n");
  while(!isEmpty(&queue)) {
    previous = level;
    node = dequeue(&queue, &level);
    if(previous != level)
      printf("\n");
    
    if(node->right != NULL) {
      rgt = node->right->height;
    } else {
      rgt = 0;
    }
    
    if(node->left != NULL) {
      lft = node->left->height;
    } else {
      lft = 0;
    }
    
    printf("%d(%d),", node->element.key, (rgt - lft));
 
    if(node->left != NULL)
      enqueue(node->left, &queue, level+1);
    if(node->right != NULL)
      enqueue(node->right, &queue, level+1);
  }
  printf("\n------------\n");
}

/******************************************************************************/
/******************************************************************************/

PointerNodeTree getMaxAux (PointerNodeTree *node) {
  PointerNodeTree ret;
  if((*node)->right == NULL) {
    ret = (*node);
    (*node) = (*node)->left; //
    return(ret);
  }
  return(getMaxAux(&(*node)->right));
}

/******************************************************************************/
/******************************************************************************/


bool removeAVL(PointerNodeTree *node, int key) {
  
  bool test;
  int h_left, h_right;
  
  if((*node) == NULL) {
    printf("Não existe o elemento %d para ser removido!\n", key);
    return (false);
  }
  
  // encontrei o que remover ...
  if((*node)->element.key == key) {
  
    PointerNodeTree tmp = (*node);
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
//    tmp = getMinAux(&(*node)->right);
      (*node)->element = tmp->element;
    }
    free(tmp);
    return true;
  }
  
  if((*node)->element.key > key){
    test = removeAVL(&(*node)->left, key);
  } else {
    test = removeAVL(&(*node)->right, key);
  }
  
  if(test == false) return (false);
  else {
    h_left  = depthAVLTree(&(*node)->left);
    h_right = depthAVLTree(&(*node)->right);
    
    if( abs(h_left - h_right) == 2 )
      applyRotations(&(*node));
    
    (*node)->height = updateHeight((*node)->left, (*node)->right);
    return(true);
  }
}

/******************************************************************************/
/******************************************************************************/
