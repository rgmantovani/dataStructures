#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// -------------------------------
/* Ziviani */
typedef struct NoAVL *PtrNoAVL;

typedef struct NoAVL {
  int chave;
  PtrNoAVL dir;
  PtrNoAVL esq;
  //fator de balanceamento
  int altura;
} NoAVL;

// -------------------------------
// -------------------------------

void iniciaAVL(PtrNoAVL *node) {
 *node = NULL;
}

bool estaVaziaAVL(PtrNoAVL *node) {
  return((*node) == NULL);
}

// -------------------------------
// -------------------------------

void emOrdem(PtrNoAVL *node) {
  if((*node) == NULL) return;
  emOrdem(&(*node)->esq);
  printf("%d ", (*node)->chave);
  emOrdem(&(*node)->dir);
}

void preOrdem(PtrNoAVL *node) {
  if((*node) == NULL) return;
  printf("%d ", (*node)->chave);
  preOrdem(&(*node)->esq);
  preOrdem(&(*node)->dir);
}

// -------------------------------
// -------------------------------

int alturaArvoreAVL(PtrNoAVL node) {
  if(node == NULL) {
    return (0);
  } else {
    return ((node)->altura);
  }
}

// -------------------------------
// -------------------------------

int atualizaAltura(PtrNoAVL esq, PtrNoAVL dir) {
  
  int ae = alturaArvoreAVL(esq);
  int ad = alturaArvoreAVL(dir);
  
  if(ae > ad) {
    return(ae + 1);
  } else {
    return(ad + 1);
  }
}

void rotacaoSimplesDireita(PtrNoAVL *node) {
  printf("Rotação simples p direita, com node: %d\n", (*node)->chave);
 
  PtrNoAVL u = (*node)->esq;
  (*node)->esq = u->dir;
  u->dir = (*node);
  
  //atualizar a altura dos nós modificados (node, u)
  (*node)->altura = atualizaAltura((*node)->esq, (*node)->dir);
  u->altura = atualizaAltura(u->esq, u->dir);
  
  //autualizacao da referencia do node
  (*node) = u;
}

void rotacaoSimplesEsquerda (PtrNoAVL *node) {
  printf("Rotação simples p esquerda, com node: %d\n", (*node)->chave);
 
  PtrNoAVL u = (*node)->dir;
  (*node)->dir = u->esq;
  u->esq = (*node);
  
  //atualizar a altura dos nós modificados (node, u)
  (*node)->altura = atualizaAltura((*node)->esq, (*node)->dir);
  u->altura = atualizaAltura(u->esq, u->dir);
  
  //autualizacao da referencia do node
  (*node) = u;
}

void rotacaoDuplaEsquerda (PtrNoAVL *node) {
  printf("Rotação dupla p esquerda, com node: %d\n", (*node)->chave);
   
  PtrNoAVL u, v;
  u = (*node)->dir;
  v = u->esq;
  
  (*node)->dir = v->esq;
  u->esq = v->dir;
  v->esq = (*node);
  v->dir = u;
  
  //atualizar a altura dos nós modificados (node, u, v)
  (*node)->altura = atualizaAltura((*node)->esq, (*node)->dir);
  u->altura = atualizaAltura(u->esq, u->dir);
  v->altura = atualizaAltura(v->esq, v->dir);
  
  //autualizacao da referencia do node
  (*node) = v;
}

void rotacaoDuplaDireita (PtrNoAVL *node) {
  printf("Rotação dupla p direita, com node: %d\n", (*node)->chave);
 
  PtrNoAVL u, v;
  u = (*node)->esq;
  v = u->dir;
  
  (*node)->esq = v->dir;
  u->dir = v->esq;
  
  v->dir = (*node);
  v->esq = u;
  
  //atualizar a altura dos nós modificados (node, u, v)
  (*node)->altura = atualizaAltura((*node)->esq, (*node)->dir);
  u->altura = atualizaAltura(u->esq, u->dir);
  v->altura = atualizaAltura(v->esq, v->dir);
  
  //autualizacao da referencia do node
  (*node) = v;
}

// -------------------------------
// -------------------------------

void AplicarRotacoes(PtrNoAVL *node) {
  
  int ad = alturaArvoreAVL((*node)->dir);
  int ae = alturaArvoreAVL((*node)->esq);
  
  // Verificar se é rotacao para direita
  if(ae > ad) {
    PtrNoAVL temp = (*node)->esq;
    int temp_ad = alturaArvoreAVL(temp->dir);
    int temp_ae = alturaArvoreAVL(temp->esq);
    // temp_ae > ou >= temp_ad
    if(temp_ae > temp_ad) {
      rotacaoSimplesDireita(&(*node));
    } else {
      rotacaoDuplaDireita(&(*node));
    }
  }
  // Senao é rotacao para esquerda
  else { //(ad > ae)
    PtrNoAVL tmp2 = (*node)->dir;
    int tmp2_ad = alturaArvoreAVL(tmp2->dir);
    int tmp2_ae = alturaArvoreAVL(tmp2->esq);
    
    if(tmp2_ad > tmp2_ae){
      rotacaoSimplesEsquerda(&(*node));
    } else {
      rotacaoDuplaEsquerda(&(*node));
    }
  }
}

// -------------------------------
// -------------------------------

// *** Inserção
bool InserirAVL(PtrNoAVL *node, int x) {
  
  //1. condicao final da recusao (positiva)
  if((*node) == NULL) {
    (*node) = (PtrNoAVL)malloc(sizeof(NoAVL));
    (*node)->dir = (*node)->esq = NULL;
    (*node)->chave = x;
    (*node)->altura = 1;
    return true;
  }

  //2. elemento ja existe
  if((*node)->chave == x) return false;
  
  bool auxiliar;
  
  // 3. Laço de chamadas recusivas
  if(x < (*node)->chave) {
    auxiliar = InserirAVL(&(*node)->esq, x);
  } else {
    auxiliar = InserirAVL(&(*node)->dir, x);
  }
  
  // Daqui para baixo começa o codigo só tem na AVL
  // 4. Se o auxiliar for falso, nao houve mudança na arvore
  if(!auxiliar) return (false);
  
  // Se houve modificacao na arvore
  // Precisamos checar o desbalanceamento
  int ae; // altura da sub-arvore da esquerda
  int ad; // altura da sub-arvore da direita
  
  // 5. Calculando as alturas das sub-arvores
  ae = alturaArvoreAVL((*node)->esq);
  ad = alturaArvoreAVL((*node)->dir);
 
  // 6. Verificando desbalanceamento
  if((ad - ae) == +2 || (ad - ae) == -2) {
    // desbalancemaneto
    AplicarRotacoes(&(*node));
  }
  
  //7. ajuste da altura do no corrente
  (*node)->altura = atualizaAltura((*node)->esq, (*node)->dir);
  return(true);
}

// -------------------------------
// -------------------------------

int main(int argc, const char * argv[]) {
  
  // raiz, acesso a estrutura de dados
  PtrNoAVL raiz;

  iniciaAVL(&raiz);
//  if(estaVaziaAVL(&raiz))
//    printf("AVL vazia\n");
  
  InserirAVL(&raiz, 30);
  preOrdem(&raiz);
  printf("\n");
  InserirAVL(&raiz, 20);
  preOrdem(&raiz);
  printf("\n");
  InserirAVL(&raiz, 10);
  preOrdem(&raiz);
  printf("\n");
  InserirAVL(&raiz, 40);
  preOrdem(&raiz);
  printf("\n");
  InserirAVL(&raiz, 50);
  preOrdem(&raiz);
  printf("\n");
  InserirAVL(&raiz, 8);
  preOrdem(&raiz);
  printf("\n");
  InserirAVL(&raiz, 9);
  preOrdem(&raiz);
  printf("\n");
  InserirAVL(&raiz, 60);
  preOrdem(&raiz);
  printf("\n");
  InserirAVL(&raiz, 55);
  preOrdem(&raiz);
  printf("\n");
 
  return 0;
}

// -------------------------------
// -------------------------------
