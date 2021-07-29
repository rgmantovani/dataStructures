//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

#include "ArvoreBinaria.h"

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

void iniciaArvoreBinaria(PtrNoArvoreBinaria *node) {
  *node = NULL;
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

bool estaVaziaArvoreBinaria(PtrNoArvoreBinaria *node) {
  return(*node == NULL);
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

bool insereArvoreBinaria(PtrNoArvoreBinaria *node, int x) {

  if(*node == NULL) {
    (*node) = (PtrNoArvoreBinaria)malloc(sizeof(NoArvoreBinaria));
    (*node)->filhoDireita = (*node)->filhoEsquerda = NULL;
    (*node)->x = x;
    return(true);
  }

  if((*node)->x == x) return(false);

  if((*node)->x > x) {
    return(insereArvoreBinaria(&(*node)->filhoEsquerda, x));
  } else {
    return(insereArvoreBinaria(&(*node)->filhoDireita, x));
  }
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

bool pesquisaArvoreBinaria(PtrNoArvoreBinaria *node, int x) {
 
  if(*node == NULL)     return(false);
  if((*node)->x == x) return(true);

  
  if((*node)->x > x){
    return(pesquisaArvoreBinaria(&(*node)->filhoEsquerda, x));
  } else {
    return(pesquisaArvoreBinaria(&(*node)->filhoDireita, x));
  }
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

void destroiArvoreBinaria(PtrNoArvoreBinaria *node) {
  if((*node) != NULL) {
    destroiArvoreBinaria(&(*node)->filhoEsquerda);
    destroiArvoreBinaria(&(*node)->filhoDireita);
    free(*node);
    *node = NULL;
  }
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

int tamanhoArvoreBinaria(PtrNoArvoreBinaria *node) {
  if ((*node) == NULL) return 0;
  else {
    return(tamanhoArvoreBinaria(&(*node)->filhoEsquerda) + 1 +
           tamanhoArvoreBinaria(&(*node)->filhoDireita));
  }
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

int profundidadeArvoreBinaria(PtrNoArvoreBinaria *node){
  if ((*node) == NULL) return 0;
  else {
   
    int lDepth = profundidadeArvoreBinaria(&(*node)->filhoEsquerda);
    int rDepth = profundidadeArvoreBinaria(&(*node)->filhoDireita);

    if (lDepth > rDepth) return(lDepth+1);
    else                 return(rDepth+1);
  }
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

PtrNoArvoreBinaria maximoArvoreBinaria(PtrNoArvoreBinaria *node) {
  PtrNoArvoreBinaria ret;
  if((*node)->filhoDireita == NULL) {
    ret = (*node);
    return(ret);
  }
  return(maximoArvoreBinaria(&(*node)->filhoDireita));
}

PtrNoArvoreBinaria maximoArvoreBinariaIterativo(PtrNoArvoreBinaria *node) {
  PtrNoArvoreBinaria ret = (*node);
  while(ret->filhoDireita != NULL) {
    ret = ret->filhoDireita;
  }
  return(ret);
}

PtrNoArvoreBinaria minimoArvoreBinaria(PtrNoArvoreBinaria *node) {
  PtrNoArvoreBinaria ret = (*node);
  if((*node)->filhoEsquerda == NULL) {
    ret = (*node);
    return(ret);
  }
  return(minimoArvoreBinaria(&(*node)->filhoEsquerda));
}

PtrNoArvoreBinaria minimoArvoreBinariaIterativo(PtrNoArvoreBinaria *node) {
  PtrNoArvoreBinaria ret = (*node);
  while(ret->filhoEsquerda != NULL) {
    ret = ret->filhoEsquerda;
  }
  return(ret);
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

void preOrdemArvoreBinaria(PtrNoArvoreBinaria *node) {
  if(*node == NULL) return;
  printf("%d ", (*node)->x);
  preOrdemArvoreBinaria(&(*node)->filhoEsquerda);
  preOrdemArvoreBinaria(&(*node)->filhoDireita);
}

void posOrdemArvoreBinaria(PtrNoArvoreBinaria *node) {
  if(*node == NULL) return;
  posOrdemArvoreBinaria(&(*node)->filhoEsquerda);
  posOrdemArvoreBinaria(&(*node)->filhoDireita);
  printf("%d ", (*node)->x);
}

void EmOrdemArvoreBinaria(PtrNoArvoreBinaria *node) {
  if(*node == NULL) return;
  EmOrdemArvoreBinaria(&(*node)->filhoEsquerda);
  printf("%d ", (*node)->x);
  EmOrdemArvoreBinaria(&(*node)->filhoDireita);
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

PtrNoArvoreBinaria getMaxAuxArvoreBinaria (PtrNoArvoreBinaria *node) {
  PtrNoArvoreBinaria ret;
  if((*node)->filhoDireita == NULL) {
    ret = (*node);
    (*node) = (*node)->filhoEsquerda;
    return(ret);
  }
  return(getMaxAuxArvoreBinaria(&(*node)->filhoDireita));
}

PtrNoArvoreBinaria getMinAuxArvoreBinaria (PtrNoArvoreBinaria *node) {
  PtrNoArvoreBinaria ret;
  if((*node)->filhoEsquerda == NULL) {
    ret = (*node);
    (*node) = (*node)->filhoDireita;
    return(ret);
  }
  return(getMinAuxArvoreBinaria(&(*node)->filhoEsquerda));
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

bool removeArvoreBinaria(PtrNoArvoreBinaria *node, int key) {
  
  if((*node) == NULL) return (false);

  if((*node)->x == key) {
    PtrNoArvoreBinaria tmp = (*node);
    if((*node)->filhoEsquerda == NULL) {
      (*node) = (*node)->filhoDireita;
    }
    else if((*node)->filhoDireita == NULL) {
        (*node) = (*node)->filhoEsquerda;
    } else {
      tmp = getMaxAuxArvoreBinaria(&(*node)->filhoEsquerda);
      (*node)->x = tmp->x;
    }
    free(tmp);
    return true;
  }
  
  if((*node)->x > key){
    return(removeArvoreBinaria(&(*node)->filhoEsquerda, key));
  } else {
    return(removeArvoreBinaria(&(*node)->filhoDireita, key));
  }
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------
