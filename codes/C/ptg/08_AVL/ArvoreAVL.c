//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

#include "ArvoreAVL.h"

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

void iniciaArvoreAVL(PtrNoAVL *node) {
  *node = NULL;
}

bool estaVaziaArvoreAVL(PtrNoAVL *node) {
  return(*node == NULL);
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------


void preOrdemArvoreAVL(PtrNoAVL *node) {
  if(*node == NULL) return;
  printf("%d ", (*node)->chave);
  preOrdemArvoreAVL(&(*node)->esquerda);
  preOrdemArvoreAVL(&(*node)->direita);
}

void posOrdemArvoreAVL(PtrNoAVL *node) {
  if(*node == NULL) return;
  posOrdemArvoreAVL(&(*node)->esquerda);
  posOrdemArvoreAVL(&(*node)->direita);
  printf("%d ", (*node)->chave);
}

void emOrdemArvoreAVL(PtrNoAVL *node) {
  if(*node == NULL) return;
  emOrdemArvoreAVL(&(*node)->esquerda);
  printf("%d ", (*node)->chave);
  emOrdemArvoreAVL(&(*node)->direita);
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

int profundidadeArvoreAVL(PtrNoAVL *node) {
  if ((*node) == NULL) return 0;
  else {
    int lDepth = profundidadeArvoreAVL(&(*node)->esquerda);
    int rDepth = profundidadeArvoreAVL(&(*node)->direita);
    if (lDepth > rDepth)
      return(lDepth+1);
    else return(rDepth+1);
  }
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

bool pesquisaArvoreAVL(PtrNoAVL *node, int x) {
  
  if(*node == NULL ) {
    printf(" @ Elemento consultado: %d, não existe na arvore\n", x);
    return false;
  }
  if((*node)->chave == x){
    printf(" @ Elemento consultado: %d, existe na arvore\n", x);
    return true;
  }
  if((*node)->chave > x )
    return (pesquisaArvoreAVL(&(*node)->esquerda, x));
  else
    return (pesquisaArvoreAVL(&(*node)->direita, x));
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

void destroiArvoreAVL(PtrNoAVL *node) {
  if((*node) != NULL ) {
    destroiArvoreAVL( &(*node)->esquerda);
    destroiArvoreAVL( &(*node)->direita);
    free(*node);
    *node = NULL;
  }
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

int alturaArvoreAVL(PtrNoAVL node) {
  if(node == NULL) {
    return (0);
  } else {
    return ((node)->altura);
  }
}


//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

int atualizaAlturaArvoreAVL(PtrNoAVL esq, PtrNoAVL dir) {
  
  int ae = alturaArvoreAVL(esq);
  int ad = alturaArvoreAVL(dir);
  
  if(ae > ad) {
    return(ae + 1);
  } else {
    return(ad + 1);
  }
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------
void rotacaoSimplesDireita(PtrNoAVL *node) {
  printf("Rotação simples p direita, com node: %d\n", (*node)->chave);
 
  PtrNoAVL u = (*node)->esquerda;
  (*node)->esquerda = u->direita;
  u->direita = (*node);
  
  //atualizar a altura dos nós modificados (node, u)
  (*node)->altura = atualizaAlturaArvoreAVL((*node)->esquerda, (*node)->direita);
  u->altura = atualizaAlturaArvoreAVL(u->esquerda, u->direita);
  
  //autualizacao da referencia do node
  (*node) = u;
}

void rotacaoSimplesEsquerda (PtrNoAVL *node) {
  printf("Rotação simples p esquerda, com node: %d\n", (*node)->chave);
 
  PtrNoAVL u = (*node)->direita;
  (*node)->direita = u->esquerda;
  u->esquerda = (*node);
  
  //atualizar a altura dos nós modificados (node, u)
  (*node)->altura = atualizaAlturaArvoreAVL((*node)->esquerda, (*node)->direita);
  u->altura = atualizaAlturaArvoreAVL(u->esquerda, u->direita);
  
  //autualizacao da referencia do node
  (*node) = u;
}

void rotacaoDuplaEsquerda (PtrNoAVL *node) {
  printf("Rotação dupla p esquerda, com node: %d\n", (*node)->chave);
   
  PtrNoAVL u, v;
  u = (*node)->direita;
  v = u->esquerda;
  
  (*node)->direita = v->esquerda;
  u->esquerda = v->direita;
  v->esquerda = (*node);
  v->direita = u;
  
  //atualizar a altura dos nós modificados (node, u, v)
  (*node)->altura = atualizaAlturaArvoreAVL((*node)->esquerda, (*node)->direita);
  u->altura = atualizaAlturaArvoreAVL(u->esquerda, u->direita);
  v->altura = atualizaAlturaArvoreAVL(v->esquerda, v->direita);
  
  //autualizacao da referencia do node
  (*node) = v;
}

void rotacaoDuplaDireita (PtrNoAVL *node) {
  printf("Rotação dupla p direita, com node: %d\n", (*node)->chave);
 
  PtrNoAVL u, v;
  u = (*node)->esquerda;
  v = u->direita;
  
  (*node)->esquerda = v->direita;
  u->direita = v->esquerda;
  
  v->direita = (*node);
  v->esquerda = u;
  
  //atualizar a altura dos nós modificados (node, u, v)
  (*node)->altura = atualizaAlturaArvoreAVL((*node)->esquerda, (*node)->direita);
  u->altura = atualizaAlturaArvoreAVL(u->esquerda, u->direita);
  v->altura = atualizaAlturaArvoreAVL(v->esquerda, v->direita);
  
  //autualizacao da referencia do node
  (*node) = v;
}


//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

void aplicarRotacoes(PtrNoAVL *node) {
  
  int ad = alturaArvoreAVL((*node)->direita);
  int ae = alturaArvoreAVL((*node)->esquerda);
  
  // Verificar se é rotacao para direita
  if(ae > ad) {
    PtrNoAVL temp = (*node)->esquerda;
    int temp_ad = alturaArvoreAVL(temp->direita);
    int temp_ae = alturaArvoreAVL(temp->esquerda);
    // temp_ae > ou >= temp_ad
    if(temp_ae > temp_ad) {
      rotacaoSimplesDireita(&(*node));
    } else {
      rotacaoDuplaDireita(&(*node));
    }
  }
  // Senao é rotacao para esquerda
  else { //(ad > ae)
    PtrNoAVL tmp2 = (*node)->direita;
    int tmp2_ad = alturaArvoreAVL(tmp2->direita);
    int tmp2_ae = alturaArvoreAVL(tmp2->esquerda);
    
    if(tmp2_ad > tmp2_ae){
      rotacaoSimplesEsquerda(&(*node));
    } else {
      rotacaoDuplaEsquerda(&(*node));
    }
  }
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

bool insereArvoreAVL(PtrNoAVL *node, int x) {
  
  //1. condicao final da recusao (positiva)
  if((*node) == NULL) {
    (*node) = (PtrNoAVL)malloc(sizeof(NoAVL));
    (*node)->direita = (*node)->esquerda = NULL;
    (*node)->chave = x;
    (*node)->altura = 1;
    return true;
  }

  //2. elemento ja existe
  if((*node)->chave == x) return false;
  
  bool auxiliar;
  
  // 3. Laço de chamadas recusivas
  if(x < (*node)->chave) {
    auxiliar = insereArvoreAVL(&(*node)->esquerda, x);
  } else {
    auxiliar = insereArvoreAVL(&(*node)->direita, x);
  }
  
  // Daqui para baixo começa o codigo só tem na AVL
  // 4. Se o auxiliar for falso, nao houve mudança na arvore
  if(!auxiliar) return (false);
  
  // Se houve modificacao na arvore
  // Precisamos checar o desbalanceamento
  int ae; // altura da sub-arvore da esquerda
  int ad; // altura da sub-arvore da direita
  
  // 5. Calculando as alturas das sub-arvores
  ae = alturaArvoreAVL((*node)->esquerda);
  ad = alturaArvoreAVL((*node)->direita);
 
  // 6. Verificando desbalanceamento
  if((ad - ae) == +2 || (ad - ae) == -2) {
    // desbalancemaneto
    aplicarRotacoes(&(*node));
  }
  
  //7. ajuste da altura do no corrente
  (*node)->altura = atualizaAlturaArvoreAVL((*node)->esquerda, (*node)->direita);
  return(true);
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

PtrNoAVL getMaxAux (PtrNoAVL *node) {
  PtrNoAVL ret;
  if((*node)->direita == NULL) {
    ret = (*node);
    (*node) = (*node)->esquerda; //
    return(ret);
  }
  return(getMaxAux(&(*node)->direita));
}


bool removeArvoreAVL(PtrNoAVL *node, int x) {

  bool test;
  int h_left, h_right;

  if((*node) == NULL) {
    printf("Não existe o elemento %d para ser removido!\n", x);
    return (false);
  }

  // encontrei o que remover ...
  if((*node)->chave == x) {

    PtrNoAVL tmp = (*node);
    // case 1: sub-arvore esquerda é nula (cai aqui se for folha também)
    if((*node)->esquerda == NULL) {
      (*node) = (*node)->direita;
    }
    // case 2: sub-arvore direita é nula (poderia cair aqui tb no caso de folha)
    else if((*node)->direita == NULL) {
      (*node) = (*node)->esquerda;
    } else {
      // case 3: ambas subarvores existem: pegar o maior elemento da sub-arvore da esquerda
      tmp = getMaxAux(&(*node)->esquerda);
      (*node)->chave = tmp->chave;
    }
    free(tmp);
    return true;
  }

  if((*node)->chave > x){
    test = removeArvoreAVL(&(*node)->esquerda, x);
  } else {
    test = removeArvoreAVL(&(*node)->direita, x);
  }

  if(test == false) return (false);
  else {
    h_left  = profundidadeArvoreAVL(&(*node)->esquerda);
    h_right = profundidadeArvoreAVL(&(*node)->direita);

    if( abs(h_left - h_right) == 2 )
      aplicarRotacoes(&(*node));

    (*node)->altura = atualizaAlturaArvoreAVL((*node)->esquerda, (*node)->direita);
    return(true);
  }
}

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

