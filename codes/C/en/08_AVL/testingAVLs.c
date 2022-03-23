#include "AVLTrees.h"

int main(int argc, const char * argv[]) {

  PointerNodeTree root;
  initAVLTree(&root);

  if(!isEmptyAVLTree(&root)) {
    printf("* Arvore não está vazia\n");
  } else {
    printf("* Arvore está vazia\n");
  }

  int array[] = {30,40,24,58,48,26,11,13,14};

 for(i = 0; i < 9; i ++) {
   x.key = array[i];
   insertAVLTree(&root, x);
   printAVLTree(&root);
 }

 preOrder(&root);
 printf("\n------------------\n");
 posOrder(&root);
 printf("\n------------------\n");
 inOrder(&root);
 printf("\n------------------\n");

 int tofind[] = {13,14,15,12,4,5,3,1};
 for(i = 0; i < 8; i ++) {
   searchAVLTree(&root,tofind[i]);
 }

 printf("\n Removendo elementos ... \n");
 printAVLTree(&root);
 int toRemove[] = {1,17,8,9,16,15,14};
 for(i = 0; i <7; i++) {
   printf(" - Removendo: %d\n", toRemove[i]);
   removeAVL(&root,toRemove[i]);
   printAVLTree(&root);
 }

 printf("\n ! Destruindo a arvore ... \n");
 destroyAVLTree(&root);
 if(!isEmptyAVLTree(&root)) {
   printf("* Arvore não está vazia\n");
 } else {
   printf("* Arvore está vazia\n");
 }

  return 0;
}
