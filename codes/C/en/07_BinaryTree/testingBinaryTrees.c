#include <stdio.h>
#include "BinaryTree.h"

//---------------------------------------------------
//---------------------------------------------------

int main(int argc, const char * argv[]) {

  PtrBinaryTree root;

  initBinaryTree(&root);

  if(isEmptyBinaryTree(&root)) {
    printf("The tree is empty\n");
  }

  insertBinaryTree(&root, 5);
  insertBinaryTree(&root, 4);
  insertBinaryTree(&root, 3);
  insertBinaryTree(&root, 2);
  insertBinaryTree(&root, 7);
  insertBinaryTree(&root, 6);
  insertBinaryTree(&root, 8);
  insertBinaryTree(&root, 9);

  if(!isEmptyBinaryTree(&root)) {
    printf("There are elements ...\n");
  }

  // [5, 4, 3, 2, 7, 6, 8, 9]
  printf("PreOrder = ");
  preOrderBinaryTree(&root);
  printf("\n");

  // [2, 3, 4, 6, 9, 8, 7, 5]
  printf("PosOrder = ");
  posOrderBinaryTree(&root);
  printf("\n");

  // [2, 3, 4, 5, 6, 7, 8, 9]
  printf("inOrder =  ");
  inOrderBinaryTree(&root);
  printf("\n");

  printf("-------------------------\n");

  int queries[6] = {7, 11, 2, 14, 0, -5};
  for(int i = 0; i < 6; i++) {
    printf("Searching: %d -> ", queries[i]);
    if(searchBinaryTree(&root, queries[i])) {
      printf("found :)\n");
    } else {
      printf("not found :/\n");
    }
  }
  printf("-------------------------\n");
  // 5, 4, 3, 2, 7, 6, 8, 9
  printf("PreOrder = ");
  preOrderBinaryTree(&root);
  printf("\n");

  removeBinaryTree(&root, 6); // leaf

  // imprime, esq, direita
  // 5, 4, 3, 2, 7, 8, 9
  printf("PreOrder = ");
  preOrderBinaryTree(&root);
  printf("\n");

  removeBinaryTree(&root, 5); // has both subtrees
  // 4, 3, 2, 7, 8 9
  printf("PreOrder = ");
  preOrderBinaryTree(&root);
  printf("\n");

  removeBinaryTree(&root, 3); // right sutree is null
  // 4, 2, 7, 8, 9
  printf("PreOrder = ");
  preOrderBinaryTree(&root);
  printf("\n");

  removeBinaryTree(&root, 8); // left subtree is null
  //4, 2, 7, 9
  printf("PreOrder = ");
  preOrderBinaryTree(&root);
  printf("\n");

  removeBinaryTree(&root, 4); // root
  // 2, 7, 9
  printf("PreOrder = ");
  preOrderBinaryTree(&root);
  printf("\n");

  printf("-------------------------\n");

  destroyBinaryTree(&root);
  if(isEmptyBinaryTree(&root)) {
    printf("The tree is empty!\n");
  }
  printf("-------------------------\n");
  return 0;
}

//---------------------------------------------------
//---------------------------------------------------
