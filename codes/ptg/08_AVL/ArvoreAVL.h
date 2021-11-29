//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

#ifndef ArvoreAVL_h
#define ArvoreAVL_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//---------------------------------------------------------------------------------
// Tipos
//---------------------------------------------------------------------------------

typedef struct NoAVL *PtrNoAVL;

typedef struct NoAVL {
  int chave;
  PtrNoAVL direita;
  PtrNoAVL esquerda;
  //fator de balanceamento
  int altura;
} NoAVL;

//---------------------------------------------------------------------------------
// Funcoes
//---------------------------------------------------------------------------------

void iniciaArvoreAVL(PtrNoAVL *node);
void preOrdemArvoreAVL(PtrNoAVL *node);
void posOrdemArvoreAVL(PtrNoAVL *node);
void emOrdemArvoreAVL(PtrNoAVL *node);
void destroiArvoreAVL(PtrNoAVL *node);
void rotacaoSimplesEsquerda(PtrNoAVL *node);
void rotacaoDuplaEsquerda(PtrNoAVL *node);
void rotacaoSimplesDireita(PtrNoAVL *node);
void rotacaoDuplaDireita(PtrNoAVL *node);
void aplicarRotacoes(PtrNoAVL *node);
bool estaVaziaArvoreAVL(PtrNoAVL *node);
bool pesquisaArvoreAVL(PtrNoAVL *node, int x);
bool insereArvoreAVL(PtrNoAVL *node, int x);
bool removeArvoreAVL(PtrNoAVL *node, int x);
int profundidadeArvoreAVL(PtrNoAVL *node);
int alturaArvoreAVL(PtrNoAVL node);
int atualizaAlturaArvoreAVL( PtrNoAVL esquerda, PtrNoAVL direita);
PtrNoAVL getMaxAuxArvoreAVL (PtrNoAVL *node);

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

#endif /* ArvoreAVL_h */

//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------
