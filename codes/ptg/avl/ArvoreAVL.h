#ifndef ArvoreAVL_h
#define ArvoreAVL_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/******************************************************************************/
/******************************************************************************/

typedef struct {
    int chave;
} Item;

typedef struct NoArvoreAVL *PointeiroArvoreAVL;

typedef struct NoArvoreAVL {
    Item elemento;
    PointeiroArvoreAVL direita;
    PointeiroArvoreAVL esquerda;
    int altura;
} NodeNoArvoreAVLTree;

/******************************************************************************/
/******************************************************************************/

void iniciaArvoreAVL(PointeiroArvoreAVL *node);
bool estaVaziaArvoreAVL(PointeiroArvoreAVL *node);

void preOrdem(PointeiroArvoreAVL *node);
void posOrdem(PointeiroArvoreAVL *node);
void emOrdem(PointeiroArvoreAVL *node);

int alturaArvoreAVL(PointeiroArvoreAVL *node);
int atualizaAlturaArvoreAVL(PointeiroArvoreAVL esquerda, PointeiroArvoreAVL direita);

bool pesquisaArvoreAVL(PointeiroArvoreAVL *node);
void destruirArvoreAVL(PointeiroArvoreAVL *node);

void aplicarRotacoes(PointeiroArvoreAVL *node);

void rotacaoSimplesEsquerda(PointeiroArvoreAVL *node);
void rotacaoSimplesDireita(PointeiroArvoreAVL *node);
void rotacaoDuplaEsquerda(PointeiroArvoreAVL *node);
void rotacaoDuplaDireita(PointeiroArvoreAVL *node);

bool inserirArvoreAVL(PointeiroArvoreAVL *node, Item x);
void imprimeArvoreAVLNivel(PointeiroArvoreAVL *node);


/******************************************************************************/
/******************************************************************************/

#endif /* ArvoreAVL_h */
