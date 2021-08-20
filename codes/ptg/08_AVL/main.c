#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "AVLTree.h"

//-----------------------------------------
//-----------------------------------------

int main(int argc, const char * argv[]) {
  
  PtrAVLNode root = NULL;
  
  if(root == NULL) {
    printf("Arvore está vazia\n");
  }
  
  root = insert(root, 77);
  printf("PreOrdem = {");
  PreOrdemArvoreAVL(root);
  printf("}\n");

  root = insert(root, 12);
  printf("PreOrdem = {");
  PreOrdemArvoreAVL(root);
  printf("}\n");

  // 12, 10, 77 - Rotação simples p direita
  root = insert(root, 10);
  printf("PreOrdem = {");
  PreOrdemArvoreAVL(root);
  printf("}\n");

  // 12, 10, 5, 77
  root = insert(root, 5);
  printf("PreOrdem = {");
  PreOrdemArvoreAVL(root);
  printf("}\n");
  
  // 12, 7, 5, 10, 77 -> Rotação dupla p direita
  root = insert(root, 7);
  printf("PreOrdem = {");
  PreOrdemArvoreAVL(root);
  printf("}\n");
  
  //12, 7, 5, 10, 77, 80
  root = insert(root, 80);
  printf("PreOrdem = {");
  PreOrdemArvoreAVL(root);
  printf("}\n");
  
  //12, 7, 5, 10, 78, 77, 80 --> rotacao dupla p esquerda
  root = insert(root, 78);
  printf("PreOrdem = {");
  PreOrdemArvoreAVL(root);
  printf("}\n");
  

  // 12, 7, 5, 10, 78, 77, 90, 80, 100 -> rotacao simples p esquerda
  root = insert(root, 90);
  root = insert(root, 100);
  printf("PreOrdem = {");
  PreOrdemArvoreAVL(root);
  printf("}\n");
  
  root = insert(root, 2);
  root = insert(root, 1);
  printf("PreOrdem = {");
  PreOrdemArvoreAVL(root);
  printf("}\n");


  //12, 7, 2, 1, 5, 10, 78, 77, 90, 80, 100
//  = {12 7 2 1 5 10 78 77 90 80 100 }
  printf("PreOrdem = {");
  PreOrdemArvoreAVL(root);
  printf("}\n");
  
  // remove 12
  root = deleteNode(root, 12);
  printf("PreOrdem = {");
  PreOrdemArvoreAVL(root);
  printf("}\n");
  
//  destroiArvoreAVL(&raiz);
  return 0;
}

//-----------------------------------------
//-----------------------------------------
