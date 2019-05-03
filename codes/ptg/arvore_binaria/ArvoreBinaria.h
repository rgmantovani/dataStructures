//
//  ArvoreBinaria.h

#ifndef ArvoreBinaria_h
#define ArvoreBinaria_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
    int chave;
} Item;

typedef struct NodeTree *PonteiroArvore;

typedef struct NoArvore {
    Item elemento;
    PonteiroArvore left;
    PonteiroArvore right;
} NoArvore;

int numeroNosArvore(PonteiroArvore *node);
int alturaArvore(PonteiroArvore *node);
void iniciaArvore(PonteiroArvore *node);
void destroiArvore(PonteiroArvore *node);
void preOrdem(PonteiroArvore *node);
void posOrdem(PonteiroArvore *node);
void EmOrdem(PonteiroArvore *node);
bool insereItem(PonteiroArvore *node, Item x);
bool procuraItem(PonteiroArvore *node, int key, Item *ret);
bool estaVazia(PonteiroArvore *node);
bool removeItem(PonteiroArvore *node, int key);
PonteiroArvore maximo(PonteiroArvore *node);
PonteiroArvore maximoIterativo(PonteiroArvore *node);
PonteiroArvore minimo(PonteiroArvore *node);
PonteiroArvore minimoIterativo(PonteiroArvore *node);
PonteiroArvore getMinAux(PonteiroArvore *node); //usado na remoção
PonteiroArvore getMaxAux(PonteiroArvore *node); //usado na remoção

#endif /* ArvoreBinaria_h */
